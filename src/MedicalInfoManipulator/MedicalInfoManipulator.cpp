#include "MedicalInfoManipulator.h"
#include <algorithm>
#include <iomanip>
#include <stdexcept>

MedicalInfoManipulator::MedicalInfoManipulator() {}

MedicalInfoManipulator::~MedicalInfoManipulator() {}

void MedicalInfoManipulator::parseFile(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    this->clients.clear();

    while (!file.eof()) {
        ClientInfo client;
        file >> client.fullName >> client.gender >> client.birthDate
             >> client.city >> client.phoneNumber >> client.diagnosis;
        this->clients.push_back(client);
    }

    file.close();
}

void MedicalInfoManipulator::displayTable() const {
    std::cout
            << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "|" << std::setw(31) << std::left << "Name" << std::setw(8) << std::left << "|Gender"
              << std::setw(16) << std::left
              << "|Birth Date"
              << std::setw(8) << std::left
              << "|City"
              << std::setw(24) << std::left
              << "|Phone Number"
              << std::setw(20) << std::left
              << "|Diagnosis|\n";
    std::cout
            << "---------------------------------------------------------------------------------------------------\n";

    for (const auto &client: this->clients) {
        std::cout << "| " << client.fullName << "\t|"
                  << client.gender << "\t|"
                  << client.birthDate << "\t|"
                  << client.city << "\t|"
                  << client.phoneNumber << "\t|"
                  << client.diagnosis << "\n";
    }

    std::cout
            << "---------------------------------------------------------------------------------------------------\n";
}

void MedicalInfoManipulator::sortByName() {
    std::sort(this->clients.begin(), this->clients.end(), [](const ClientInfo &a, const ClientInfo &b) {
        return a.fullName < b.fullName;
    });
}

void MedicalInfoManipulator::sortByAge() {
    std::sort(this->clients.begin(), this->clients.end(), [](const ClientInfo &a, const ClientInfo &b) {
        try {
            tm tmA = {};
            tmA.tm_mday = std::stoi(a.birthDate.substr(0, 2));
            tmA.tm_mon = std::stoi(a.birthDate.substr(3, 2)) - 1;
            tmA.tm_year = std::stoi(a.birthDate.substr(6, 4)) - 1900;
            std::time_t timeA = std::mktime(&tmA);

            tm tmB = {};
            tmB.tm_mday = std::stoi(b.birthDate.substr(0, 2));
            tmB.tm_mon = std::stoi(b.birthDate.substr(3, 2)) - 1;
            tmB.tm_year = std::stoi(b.birthDate.substr(6, 4)) - 1900;
            std::time_t timeB = std::mktime(&tmB);

            return timeA > timeB;
        } catch (const std::invalid_argument &e) {
            return false;
        }
    });
}


