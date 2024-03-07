//
// Created by Daniel on 3/6/2024.
//

#include "RoadVolume.h"

RoadVolume::RoadVolume(const std::string &time, int volumeSensor1, int volumeSensor2, int volumeSensor3, int volumeSensor4, const std::string &date) {
    this->date = date;
    this->time = time;
    this->volumeSensor1 = volumeSensor1;
    this->volumeSensor2 = volumeSensor2;
    this->volumeSensor3 = volumeSensor3;
    this->volumeSensor4 = volumeSensor4;
}

const std::string &RoadVolume::getTime() const {
    return time;
}

void RoadVolume::setTime(const std::string &time) {
    this->time = time;
}

int RoadVolume::getVolumeSensor1() const {
    return volumeSensor1;
}

void RoadVolume::setVolumeSensor1(int volumeSensor1) {
    this->volumeSensor1 = volumeSensor1;
}

int RoadVolume::getVolumeSensor2() const {
    return volumeSensor2;
}

void RoadVolume::setVolumeSensor2(int volumeSensor2) {
    this->volumeSensor2 = volumeSensor2;
}

int RoadVolume::getVolumeSensor3() const {
    return volumeSensor3;
}

void RoadVolume::setVolumeSensor3(int volumeSensor3) {
    this->volumeSensor3 = volumeSensor3;
}

int RoadVolume::getVolumeSensor4() const {
    return volumeSensor4;
}

void RoadVolume::setVolumeSensor4(int volumeSensor4) {
    this->volumeSensor4 = volumeSensor4;
}

const std::string &RoadVolume::getDate() const {
    return date;
}

void RoadVolume::setDate(const std::string &date) {
    this->date = date;
}

std::string RoadVolume::getFileData() {
    int strSize = std::snprintf(nullptr, 0, "%d,%d,%d,%d", volumeSensor1, volumeSensor2, volumeSensor3, volumeSensor4) + 1; //Calcuate needed space for allocation
    char *pStr = new char[strSize];
    std::snprintf(pStr, strSize,"%d,%d,%d,%d", volumeSensor1, volumeSensor2, volumeSensor3, volumeSensor4);
    std::string str(pStr, pStr + strSize - 1);
    delete[] pStr;
    return str;
}