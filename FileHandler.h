//
// Created by Daniel on 3/6/2024.
//

#ifndef PROJECT2_CPP_FILEHANDLER_H
#define PROJECT2_CPP_FILEHANDLER_H

#include <vector>
#include "RoadVolume.h"
#include "RoadSpeed.h"
#include "RoadSection.h"

int loadVolumeData(std::string &filename, std::vector<RoadVolume *> &volumeList);
std::vector<std::string> split(std::string& str, char delimiter);
int loadSpeedData(std::string &filename, std::vector<RoadSpeed *> &speedList);
int writeRoadSectionData(std::vector<RoadSection *> sectionList);
#endif //PROJECT2_CPP_FILEHANDLER_H
