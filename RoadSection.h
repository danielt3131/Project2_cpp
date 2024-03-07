//
// Created by Daniel on 3/6/2024.
//

#ifndef PROJECT2_CPP_ROADSECTION_H
#define PROJECT2_CPP_ROADSECTION_H


#include "RoadVolume.h"
#include "RoadSpeed.h"

class RoadSection {
private:
    RoadVolume *roadVolume;
    RoadSpeed *roadSpeed;
    int volumeTotal;
    double volumeAvg;
    double speedAvg;
    int calcVolumeTotal();
    double calcVolumeAvg();
    double calcSpeedAvg();
public:
    RoadSection(RoadVolume *roadVolume, RoadSpeed *roadSpeed);
    ~RoadSection();

    RoadVolume *getRoadVolume();

    void setRoadVolume(RoadVolume *roadVolume);

    RoadSpeed *getRoadSpeed();

    void setRoadSpeed(RoadSpeed *roadSpeed);

    const int getVolumeTotal();

    void setVolumeTotal(int volumeTotal);

    const double getVolumeAvg();

    void setVolumeAvg(double volumeAvg);

    const double getSpeedAvg();

    void setSpeedAvg(double speedAvg);
    std::string getFileData();
};


#endif //PROJECT2_CPP_ROADSECTION_H
