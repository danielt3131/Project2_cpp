//
// Created by Daniel on 3/6/2024.
//

#ifndef PROJECT2_CPP_ROADVOLUME_H
#define PROJECT2_CPP_ROADVOLUME_H


#include <string>

class RoadVolume {
private:
    std::string time;
    int volumeSensor1;
    int volumeSensor2;
    int volumeSensor3;
    int volumeSensor4;
    std::string date;
public:
    RoadVolume(const std::string &time, int volumeSensor1, int volumeSensor2, int volumeSensor3, int volumeSensor4,
               const std::string &date);

    const std::string &getTime() const;

    void setTime(const std::string &time);

    const int getVolumeSensor1();

    void setVolumeSensor1(int volumeSensor1);

    const int getVolumeSensor2();

    void setVolumeSensor2(int volumeSensor2);

    const int getVolumeSensor3();

    void setVolumeSensor3(int volumeSensor3);

    const int getVolumeSensor4();

    void setVolumeSensor4(int volumeSensor4);

    const std::string &getDate();

    void setDate(const std::string &date);
    std::string getFileData();
};


#endif //PROJECT2_CPP_ROADVOLUME_H
