//
// Created by Daniel on 3/6/2024.
//

#include "FileHandler.h"
#include "RoadVolume.h"
#include "RoadSpeed.h"
#include "RoadSection.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdio>

int loadVolumeData(std::string &filename, std::vector<RoadVolume *> &volumeList) {
    std::ifstream fileRead;
    fileRead.open(filename);
    if (!fileRead) {
        return EXIT_FAILURE;
    }
    std::string line;
    std::getline(fileRead, line);
    while (std::getline(fileRead, line)) {
        //std::getline(fileRead, line);
        std::vector<std::string> delim = split(line,',');
        int month;
        int day;
        int year;
        if (sscanf(delim[0].c_str(), "%d/%d/%d", &month, &day, &year) != 3) {
            return EXIT_FAILURE;
        }
        year += 2000;
        char *pDate = new char[10];
        sprintf(pDate, "%d/%d/%d", month, day, year);
        std::string date(pDate);
        RoadVolume *roadVolume = new RoadVolume(delim[1], std::stoi(delim[2]), std::stoi(delim[3]), std::stoi(delim[4]), std::stoi(delim[5]), date);
        volumeList.push_back(roadVolume);
        delete[] pDate;
    }
    fileRead.close();
    return EXIT_SUCCESS;
}

std::vector<std::string> split(std::string& str, char delimiter) {
    char *string = new char[str.length() + 1];
    std::vector<std::string> split {};
    memcpy(string, str.c_str(), str.length() + 1);
    char *splitTemp = strtok(string, &delimiter);
    while (splitTemp != nullptr) {
        std::string temp(splitTemp);
        split.push_back(temp);
        splitTemp = strtok(nullptr, &delimiter);
    }
    delete[] string;
    str.clear();
    return split;
}


int loadSpeedData(std::string &filename, std::vector<RoadSpeed *> &speedList) {
    std::ifstream fileRead;
    fileRead.open(filename);
    if (!fileRead) {
        return EXIT_FAILURE;
    }
    std::string line;
    std::getline(fileRead, line);
    while (std::getline(fileRead, line)) {
        //std::getline(fileRead, line);
        std::vector<std::string> delim = split(line,',');
        int month;
        int day;
        int year;
        if (sscanf(delim[0].c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
            return EXIT_FAILURE;
        }
        char *pDate = new char[10];
        sprintf(pDate, "%d/%d/%d", month, day, year);
        std::string date(pDate);
        RoadSpeed *roadSpeed = new RoadSpeed(date, delim[1], std::stod(delim[2]), std::stod(delim[3]));
        speedList.push_back(roadSpeed);
        delete[] pDate;
    }
    fileRead.close();
    return EXIT_SUCCESS;
}

int writeRoadSectionData(std::vector<RoadSection *> sectionList) {
    std::ofstream outputFile;
    outputFile.open("Road_Section_Data.csv");
    // Print header
    if (!outputFile) {
        return EXIT_FAILURE;
    }
    outputFile << "Date,Time,Volume_Sensor_2003,Volume_Sensor_2004,Volume_Sensor_2005,Volume_Sensor_2006,Speed_Sensor_2282,Speed_Sensor_2293,Volume_Total,Volume_Avg,Speed_Avg" << std::endl;
    for (int i = 0; i < sectionList.size(); i++) {
        outputFile << sectionList[i]->getFileData() << std::endl;
    }
    outputFile.close();
    return EXIT_SUCCESS;
}