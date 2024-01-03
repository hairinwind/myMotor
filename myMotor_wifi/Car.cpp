#include "Car.h"
#include <iostream>
#include <Arduino.h>
#include <string>

int enA = 14;
int in1 = 12;
int in2 = 27;

int enB = 32;
int in3 = 25;
int in4 = 33;

// 构造函数的实现（如果需要）
Car::Car() {
    Serial.println("Car is consturcting...");
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    Serial.println("Car is consturcted");
}

// 成员函数的实现
void Car::forward(int time) {
    run(100, Forward, 100, Forward, time);
}

void Car::backward(int time) {
    run(100, Backward, 100, Backward, time);
}

void Car::left(int time) {
    run(255, Forward, 100, Forward, time);
}

void Car::right(int time) {
    run(100, Forward, 255, Forward, time);
}

void Car::circle(int time) {
    run(113, Forward, 113, Backward, time);
}

void Car::run(int left, WheelDirection leftWheelDirection, int right, WheelDirection rightWheelDirection, int time) {
    Serial.println("Car:run!");
    Serial.println(wheelDirectionToString(leftWheelDirection).c_str());

    analogWrite(enA, left);
    if (leftWheelDirection == Forward) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    } else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }

    analogWrite(enB, right);
    if (rightWheelDirection == Forward) {
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    } else {
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }

    delay(time);
    stop();
}

void Car::stop() {
    analogWrite(enA, 0);
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

std::string Car::wheelDirectionToString(WheelDirection direction) {
    return (direction == Forward) ? "Forward" : "Backward";
}