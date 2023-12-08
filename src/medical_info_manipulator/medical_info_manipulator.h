//
// Created by mikhn on 26/11/2023.
//

#ifndef COURSE_DIMA_MET_1_MEDICAL_INFO_MANIPULATOR_H
#define COURSE_DIMA_MET_1_MEDICAL_INFO_MANIPULATOR_H


#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

class MedicalInfoManipulator {
public:
    MedicalInfoManipulator();
    ~MedicalInfoManipulator();
    void parseFile(const std::string& filename);
    void displayTable() const;
    void sortByName();
    void sortByAge();
    void filterBySubstring(const std::string &substring);
    void getNonResidents();
    void filterByAgeAndDiagnose(int age, const std::string& diagnose);
private:
    struct ClientInfo {
        std::string fullName;
        std::string gender;
        std::string birthDate;
        std::string city;
        std::string phoneNumber;
        std::string diagnosis;
    };
    std::vector<ClientInfo> clients;
};

#endif //COURSE_DIMA_MET_1_MEDICAL_INFO_MANIPULATOR_H
