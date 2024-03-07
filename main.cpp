#include <iostream>
#include <string>
#include <vector>
#include "RoadSection.h"
#include "FileHandler.h"
#include "RoadSpeed.h"
#include "RoadVolume.h"

int createRoadSections(std::vector<RoadVolume *> &volumeList, std::vector<RoadSpeed *> &speedList) {
    std::vector<RoadSection *> roadSection;
    for (int i = 0; i < volumeList.size(); i++) {
        for (int j = 0; j < volumeList.size(); ++j) {
            if ((volumeList.at(i)->getDate() == speedList.at(j)->getDate()) && volumeList.at(i)->getTime() == speedList.at(j)->getTime()) {
                RoadSection *section = new RoadSection(volumeList.at(i), speedList.at(j));
                roadSection.push_back(section);
            }
        }
    }
    if (writeRoadSectionData(roadSection) == 1) {
        for (RoadSection *i : roadSection) {
            delete i;
        }
        roadSection.clear();
        return EXIT_FAILURE;
    }
    for (RoadSection *i : roadSection) {
        delete i;
    }
    roadSection.clear();
    return EXIT_SUCCESS;
}

int main() {
    std::vector<RoadVolume *> roadVolume;
    std::vector<RoadSpeed *> roadSpeed;
    std::string line;
    std::cout << "Enter Path and Name of Volume Data File" << std::endl;
    std::getline(std::cin, line);
    if (loadVolumeData(line, roadVolume) == 1) {
        std::cout << "Error in reading in volume data" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Enter Path and Name of Speed Data File" << std::endl;
    std::getline(std::cin, line);
    if (loadSpeedData(line, roadSpeed) == 1) {
        std::cout << "Error in reading in speed data" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Road Section Data Created" << std::endl;
    if (createRoadSections(roadVolume, roadSpeed) == 1) {
        std::cout << "Invalid perms use chmod & chown" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
