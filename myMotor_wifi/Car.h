#ifndef CAR_H
#define CAR_H

#include <string>

enum WheelDirection {
    Forward,
    Backward
};

class Car {
private:
    std::string wheelDirectionToString(WheelDirection direction);

public:
    // 构造函数
    Car();

    // 成员函数
    void forward(int time);
    void backward(int time);
    void left(int time);
    void right(int time);
    void circle(int time);
    void run(int left, WheelDirection leftWheelDirection, int right, WheelDirection rightWheelDirection, int time);
    void stop();
    
};

#endif // CAR_H
