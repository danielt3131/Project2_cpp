//
// Created by Daniel on 3/6/2024.
//

#include "RoadSection.h"
/**
 * Constructor
 * @param roadVolume The pointer to a roadVolume object
 * @param roadSpeed The pointer to a roadSpeed object
 */
RoadSection::RoadSection(RoadVolume *roadVolume, RoadSpeed *roadSpeed) {
    this->roadVolume = roadVolume;
    this->roadSpeed = roadSpeed;
}

RoadVolume *RoadSection::getRoadVolume() {
    return roadVolume;
}

void RoadSection::setRoadVolume(RoadVolume *roadVolume) {
    this->roadVolume = roadVolume;
}

RoadSpeed *RoadSection::getRoadSpeed() {
    return roadSpeed;
}

void RoadSection::setRoadSpeed(RoadSpeed *roadSpeed) {
    this->roadSpeed = roadSpeed;
}

const int RoadSection::getVolumeTotal() {
    return volumeTotal;
}

void RoadSection::setVolumeTotal(int volumeTotal) {
    this->volumeTotal = volumeTotal;
}

const double RoadSection::getVolumeAvg() {
    return volumeAvg;
}

void RoadSection::setVolumeAvg(double volumeAvg) {
    this-> volumeAvg = volumeAvg;
}

const double RoadSection::getSpeedAvg() {
    return speedAvg;
}

void RoadSection::setSpeedAvg(double speedAvg) {
    this->speedAvg = speedAvg;
}

double RoadSection::calcSpeedAvg() {
    return (roadSpeed->getSpeedSensor1() + roadSpeed->getSpeedSensor2()) / 2.0;
}
/**
 * Deconstructor
 * Deallocates memory for the roadSpeed and roadVolume objects
 */
RoadSection::~RoadSection() {
    delete roadVolume;
    delete roadSpeed;
}

std::string RoadSection::getFileData() {
    std::string formatted = roadSpeed->getDate() + "," + roadSpeed->getTime();
    formatted = formatted + "," + roadVolume->getFileData() + "," + roadSpeed->getFileData() + "," + std::to_string(calcVolumeTotal()) + "," + std::to_string(calcVolumeAvg()) + "," + std::to_string(calcSpeedAvg());
    return formatted;
}

int RoadSection::calcVolumeTotal() {
    return roadVolume->getVolumeSensor1() + roadVolume->getVolumeSensor2() + roadVolume->getVolumeSensor3() + roadVolume->getVolumeSensor4();
}

double RoadSection::calcVolumeAvg() {
    return calcVolumeTotal() / 4.0;
}

