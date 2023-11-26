#include "MedicakInfoManipulator.h"
#include <algorithm>
#include <iomanip>

MedicalInfoManipulator::MedicalInfoManipulator() {}
MedicalInfoManipulator::~MedicalInfoManipulator() {}
void MedicalInfoManipulator::parseFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    clients.clear();

    while (!file.eof()) {
        ClientInfo client;
        file >> client.fullName >> client.gender >> client.birthDate
             >> client.city >> client.phoneNumber >> client.diagnosis;
        clients.push_back(client);
    }

    file.close();
}

void MedicalInfoManipulator::displayTable() const {
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "|"<<std::setw(31)<<std::left<< "Name" << std::setw(8)<<std::left<<"|Gender"
              <<std::setw(16)<<std::left
              <<"|Birth Date"
              <<std::setw(8)<<std::left
              << "|City"
              <<std::setw(24)<<std::left
              <<"|Phone Number"
              <<std::setw(20)<<std::left
              <<"|Diagnosis|\n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";

    for (const auto& client : clients) {
        std::cout << "| " << client.fullName << "\t|"
                  << client.gender << "\t|"
                  << client.birthDate << "\t|"
                  <<client.city << "\t|"
                  <<client.phoneNumber << "\t|"
                  <<client.diagnosis << "\n";
    }

    std::cout << "---------------------------------------------------------------------------------------------------\n";
}

void MedicalInfoManipulator::sortByName() {
    std::sort(clients.begin(), clients.end(), [](const ClientInfo& a, const ClientInfo& b) {
        return a.fullName < b.fullName;
    });
}

void MedicalInfoManipulator::sortByAge() {
    std::sort(clients.begin(), clients.end(), [](const ClientInfo& a, const ClientInfo& b) {
        return a.birthDate > b.birthDate;
    });
}
