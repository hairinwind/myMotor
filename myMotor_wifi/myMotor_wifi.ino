#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <string>
#include "Car.h"

// check wifi.local
const char* ssid = "<YOUR_WIFI_SSID>";
const char* password = "<YOUR_WIFI_PASSWORD>";

AsyncWebServer server(80);
Car car;

void forwardFunction() {
  // 在这里添加前进的实际功能
  Serial.println("Forwarding...");
  // 这里可以执行你的前进代码
}

void backwardFunction() {
  // 在这里添加后退的实际功能
  Serial.println("Backwarding...");
  // 这里可以执行你的后退代码
}

void setup() {
  Serial.begin(115200);
  Serial.println("STARTING...");

  // 连接WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  // 处理根路径请求
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello, ESP32!");
  });

  // 处理 "/forward" 路径请求
  server.on("/forward", HTTP_GET, [](AsyncWebServerRequest *request){
    String paramValue = request->getParam("time")->value();
    int time = paramValue.toInt();
    car.forward(time);
    request->send(200, "text/plain", "Forwarding...");
  });

  // 处理 "/backward" 路径请求
  server.on("/backward", HTTP_GET, [](AsyncWebServerRequest *request){
    Serial.println("received request... /backward");
    String paramValue = request->getParam("time")->value();
    int time = paramValue.toInt();
    car.backward(time);
    request->send(200, "text/plain", "Backwarding...");
  });

  server.on("/left", HTTP_GET, [](AsyncWebServerRequest *request){
    int time = getIntParameter(request, "time");
    car.left(time);
    request->send(200, "text/plain", "left...");
  });
  
  server.on("/right", HTTP_GET, [](AsyncWebServerRequest *request){
    int time = getIntParameter(request, "time");
    car.right(time);
    request->send(200, "text/plain", "right...");
  });

  server.on("/circle", HTTP_GET, [](AsyncWebServerRequest *request){
    int time = getIntParameter(request, "time");
    car.circle(time);
    request->send(200, "text/plain", "right...");
  });

  // 处理 "/backward" 路径请求
  server.on("/run", HTTP_GET, [](AsyncWebServerRequest *request){
    // 调用后退函数
    int leftSpeed = getIntParameter(request, "left");
    int rightSpeed = getIntParameter(request, "right");
    int time = getIntParameter(request, "time");
    WheelDirection leftDirection = getDirectionParameter(request, "leftDirection");
    WheelDirection rightDirection = getDirectionParameter(request, "rightDirection");
    car.run(leftSpeed, leftDirection, rightSpeed, rightDirection, time);
    request->send(200, "text/plain", "run...");
  });

  // 启动服务器
  server.begin();
}

void loop() {
  // 空循环
}

int getIntParameter(AsyncWebServerRequest *request, String paramName) {
    String paramValue = request->getParam(paramName)->value();
    return paramValue.toInt();
}

WheelDirection getDirectionParameter(AsyncWebServerRequest *request, String paramName) {
    String paramValue = request->getParam(paramName)->value();
    if (paramValue == "B" || paramValue == "b") {
      return Backward;
    }
    return Forward;
}