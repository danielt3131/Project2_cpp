//
// Created by Daniel on 3/6/2024.
//

#ifndef PROJECT2_CPP_ROADSPEED_H
#define PROJECT2_CPP_ROADSPEED_H


#include <string>

class RoadSpeed {
private:
    std::string date;
    std::string time;
    double speedSensor1;
    double speedSensor2;
public:
    RoadSpeed(const std::string &date, const std::string &time, double speedSensor1, double speedSensor2);

    const std::string &getDate();

    void setDate(const std::string &date);

    const std::string &getTime();

    void setTime(const std::string &time);

    const double getSpeedSensor1();

    void setSpeedSensor1(double speedSensor1);

    const double getSpeedSensor2();

    void setSpeedSensor2(double speedSensor2);

    std::string getFileData();
};


#endif //PROJECT2_CPP_ROADSPEED_H
