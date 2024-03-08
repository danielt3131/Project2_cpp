//
// Created by Daniel on 3/6/2024.
//

#include "RoadSpeed.h"

RoadSpeed::RoadSpeed(const std::string &date, const std::string &time, double speedSensor1, double speedSensor2) {
    this->date = date;
    this->time = time;
    this->speedSensor1 = speedSensor1;
    this->speedSensor2 = speedSensor2;
}

const std::string &RoadSpeed::getDate() {
    return date;
}

void RoadSpeed::setDate(const std::string &date) {
    this->date = date;
}

const std::string &RoadSpeed::getTime() {
    return time;
}

void RoadSpeed::setTime(const std::string &time) {
    this->time = time;
}

const double RoadSpeed::getSpeedSensor1() {
    return speedSensor1;
}

void RoadSpeed::setSpeedSensor1(double speedSensor1) {
    this->speedSensor1 = speedSensor1;
}

const double RoadSpeed::getSpeedSensor2() {
    return speedSensor2;
}

void RoadSpeed::setSpeedSensor2(double speedSensor2) {
    this->speedSensor2 = speedSensor2;
}

std::string RoadSpeed::getFileData() {
    int strSize = std::snprintf(nullptr, 0, "%.1lf,%.1lf", speedSensor1, speedSensor2) + 1; //Calculate needed space for allocation
    char *pStr = new char[strSize]; // Allocate memory for snprintf
    std::snprintf(pStr, strSize,"%.1lf,%.1lf", speedSensor1, speedSensor2);
    std::string str(pStr, pStr + strSize - 1);  // Create a C++ string from the snprintf
    delete[] pStr;  // Deallocate memory
    return str; // Return the string str
}