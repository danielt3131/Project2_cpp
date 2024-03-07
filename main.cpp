#include <iostream>
#include <string>
#include <vector>
#include "RoadSection.h"
#include "FileHandler.h"
#include "RoadSpeed.h"
#include "RoadVolume.h"

void createRoadSections(std::vector<RoadVolume *> &volumeList, std::vector<RoadSpeed *> &speedList) {
    std::vector<RoadSection *> roadSection;
    for (int i = 0; i < volumeList.size(); i++) {
        for (int j = 0; j < volumeList.size(); ++j) {
            if ((volumeList.at(i)->getDate() == speedList.at(j)->getDate()) && volumeList.at(i)->getTime() == speedList.at(j)->getTime()) {
                RoadSection *section = new RoadSection(volumeList.at(i), speedList.at(j));
                roadSection.push_back(section);
            }
        }
    }
    writeRoadSectionData(roadSection);
    for (RoadSection *i : roadSection) {
        delete i;
    }
    roadSection.clear();
}

int main() {
    std::vector<RoadVolume *> roadVolume;
    std::vector<RoadSpeed *> roadSpeed;
    std::string line;
    std::cout << "Enter Path and Name of Volume Data File" << std::endl;
    std::getline(std::cin, line);
    loadVolumeData(line, roadVolume);
    std::cout << "Enter Path and Name of Speed Data File" << std::endl;
    std::getline(std::cin, line);
    loadSpeedData(line, roadSpeed);
    std::cout << "Road Section Data Created" << std::endl;
    createRoadSections(roadVolume, roadSpeed);

    return 0;
}
