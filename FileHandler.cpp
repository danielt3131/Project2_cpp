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

/**
 *
 * @param filename The filename/filepath to read from
 * @param volumeList The std::vector containing pointers to RoadVolume objects
 * @return 0 / EXIT_SUCCESS if there was no errors otherwise 1 / EXIT_FAILURE
 */
int loadVolumeData(std::string &filename, std::vector<RoadVolume *> &volumeList) {
    std::ifstream fileRead;
    fileRead.open(filename);    // Open input stream
    if (!fileRead) {
        return EXIT_FAILURE;    // If file doesn't exist
    }
    std::string line;
    std::getline(fileRead, line);
    while (std::getline(fileRead, line)) {
        std::vector<std::string> delim = split(line,',');
        int month;
        int day;
        int year;
        if (sscanf(delim[0].c_str(), "%d/%d/%d", &month, &day, &year) != 3) {
            return EXIT_FAILURE;    // Wrong format
        }
        year += 2000;
        if (!((day >= 1 && day <= 31) && (month >= 1 && month <= 12) && (year >= 2000 && year <= 2099))) {
            return EXIT_FAILURE;   // Date in wrong position
        }
        char *pDate = new char[10]; // Allocate memory for snprintf
        sprintf(pDate, "%d/%d/%d", month, day, year); // Format the date
        std::string date(pDate);
        RoadVolume *roadVolume = new RoadVolume(delim[1], std::stoi(delim[2]), std::stoi(delim[3]), std::stoi(delim[4]), std::stoi(delim[5]), date);
        volumeList.push_back(roadVolume);   // Add the newly allocated roadVolume object to the vector
        delete[] pDate; // Deallocate the memory
    }
    fileRead.close();   // Close the input stream
    return EXIT_SUCCESS;
}
/**
 * A method/function to split a string
 * @param str the input string
 * @param delimiter the character to delimit the string str
 * @return the input string delimited stored in a std::vector
 */
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

/**
 *
 * @param filename The filename/filepath to read from
 * @param speedList The std::vector containing pointers to RoadSpeed objects
 * @return 0 / EXIT_SUCCESS if there was no errors otherwise 1 / EXIT_FAILURE
 */
int loadSpeedData(std::string &filename, std::vector<RoadSpeed *> &speedList) {
    std::ifstream fileRead;
    fileRead.open(filename);    // Open input stream
    if (!fileRead) {
        return EXIT_FAILURE;    // If file doesn't exist
    }
    std::string line;
    std::getline(fileRead, line);
    while (std::getline(fileRead, line)) {
        std::vector<std::string> delim = split(line,',');
        int month;
        int day;
        int year;
        if (sscanf(delim[0].c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
            return EXIT_FAILURE;    // Wrong format
        }
        if (!((day >= 1 && day <= 31) && (month >= 1 && month <= 12) && (year >= 2000 && year <= 2099))) {
            return EXIT_FAILURE;   // Date in wrong position
        }
        char *pDate = new char[10]; // Allocate memory for snprintf
        sprintf(pDate, "%d/%d/%d", month, day, year); // Format the date
        std::string date(pDate);
        RoadSpeed *roadSpeed = new RoadSpeed(date, delim[1], std::stod(delim[2]), std::stod(delim[3]));
        speedList.push_back(roadSpeed); // Add the newly allocated roadSpeed object to the vector
        delete[] pDate; // Deallocate the memory
    }
    fileRead.close();   // Close the input stream
    return EXIT_SUCCESS;
}

int writeRoadSectionData(std::vector<RoadSection *> sectionList) {
    std::ofstream outputFile;
    outputFile.open("Road_Section_Data.csv"); //Open output stream
    // Print header
    if (!outputFile) {
        return EXIT_FAILURE;
    }
    outputFile << "Date,Time,Volume_Sensor_2003,Volume_Sensor_2004,Volume_Sensor_2005,Volume_Sensor_2006,Speed_Sensor_2282,Speed_Sensor_2293,Volume_Total,Volume_Avg,Speed_Avg" << std::endl;
    for (int i = 0; i < sectionList.size(); i++) {
        outputFile << sectionList[i]->getFileData() << std::endl;
    }
    outputFile.close(); //Close the output stream
    return EXIT_SUCCESS;
}