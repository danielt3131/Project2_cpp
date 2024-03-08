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
    int status = EXIT_SUCCESS;
    if (writeRoadSectionData(roadSection) == 1) {
        status = EXIT_FAILURE;
    }
    for (RoadSection *i : roadSection) {
        delete i;
    }
    roadSection.clear();
    return status;
}
/**
 * Main function -> program launch point
 * @return the return status
 */
int main() {
    std::vector<RoadVolume *> roadVolume;
    std::vector<RoadSpeed *> roadSpeed;
    std::string line;
    bool hasProcessed = false;

    while (!hasProcessed) {
        start:
        std::cout << "Enter Path and Name of Volume Data File" << std::endl;
        std::getline(std::cin, line);
        if (loadVolumeData(line, roadVolume) == 1) {
            std::cout << "Error in reading in volume data" << std::endl;
            // Deallocate memory and clear vector
            for (RoadVolume *i : roadVolume) {
                delete i;
            }
            roadVolume.clear();
            goto start;
        }
        std::cout << "Enter Path and Name of Speed Data File" << std::endl;
        std::getline(std::cin, line);
        if (loadSpeedData(line, roadSpeed) == 1) {
            std::cout << "Error in reading in speed data" << std::endl;
            // Deallocate memory and clear vector
            for (RoadVolume *i : roadVolume) {
                delete i;
            }
            roadVolume.clear();
            for (RoadSpeed *i : roadSpeed) {
                delete i;
            }
            roadSpeed.clear();
        }
        hasProcessed = true;
    }

    std::cout << "Road Section Data Created" << std::endl;
    if (createRoadSections(roadVolume, roadSpeed) == 1) {
        std::cout << "Invalid perms use chmod & chown" << std::endl;
        std::cout << "Now exiting" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
