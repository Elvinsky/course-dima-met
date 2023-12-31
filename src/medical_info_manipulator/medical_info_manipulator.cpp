#include "medical_info_manipulator.h"
#include <algorithm>
#include <iomanip>
#include <stdexcept>

void MedicalInfoManipulator::closeStore() {
    std::ofstream file(this->filename);

    for (const auto& client: clients){
        file << client.fullName << " " << client.gender << " " << client.birthDate
             << " " << client.city << " " << client.phoneNumber << " " << client.diagnosis << std::endl;
    }
    file.close();
}

void MedicalInfoManipulator::parseFile(const std::string &filename) {
    this->filename = filename;
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

void MedicalInfoManipulator::filterBySubstring(const std::string &substring) {
    std::vector<ClientInfo> filteredClients;

    for (const auto &client: clients) {
        if (client.fullName.find(substring) != std::string::npos) {
            filteredClients.push_back(client);
        }
    }
    std::vector <ClientInfo> old_clients = this->clients;
    this->clients = filteredClients;
    this->displayTable();
    this->clients = old_clients;
}


void MedicalInfoManipulator::getNonResidents() {
    std::vector<ClientInfo> non_resident_clients;

    for (const auto &client: clients) {
        if (client.city != "Минск") {
            non_resident_clients.push_back(client);
        }
    }
    std::vector <ClientInfo> old_clients = this->clients;
    this->clients = non_resident_clients;
    this->displayTable();
    this->clients = old_clients;
}

void MedicalInfoManipulator::filterByAgeAndDiagnose(int age, const std::string &diagnose) {
    std::vector<ClientInfo> filtered_clients;
    for (const auto& client : clients) {
        int birthYear = std::stoi(client.birthDate.substr(6, 9));
        int cur_age = 2023 - birthYear;

        if (cur_age > age && client.diagnosis == diagnose) {
            filtered_clients.push_back(client);
        }
    }
    if (filtered_clients.empty()) {
        std::cout << "Ничего не найдено, проверьте фильтры!" << std::endl;
        return;
    }
    std::vector <ClientInfo> old_clients = this->clients;
    this->clients = filtered_clients;
    this->displayTable();
    this->clients = old_clients;
}

void
MedicalInfoManipulator::addRow(const std::string &fullName, const std::string &gender, const std::string &birthDate,
                               const std::string &city, const std::string &phoneNumber, const std::string &diagnosis) {
    ClientInfo new_client = ClientInfo();
    new_client.fullName = fullName;
    new_client.gender = gender;
    new_client.birthDate = birthDate;
    new_client.city = city;
    new_client.phoneNumber = phoneNumber;
    new_client.diagnosis = diagnosis;

    this->clients.push_back(new_client);

}

void MedicalInfoManipulator::deleteRow(const std::string& fullname) {
    auto condition = [fullname](const ClientInfo &client) {
        return client.fullName.find(fullname) != std::string::npos;
    };

    auto it = std::find_if(clients.begin(), clients.end(), condition);

    if (it == clients.end()) {
        throw std::out_of_range("Substring not found in clients");
    }

    clients.erase(it);
}

void
MedicalInfoManipulator::editRow(const std::string &fullName, const std::string &gender,
                                const std::string &birthDate, const std::string &city, const std::string &phoneNumber,
                                const std::string &diagnosis) {
    auto condition = [fullName](const ClientInfo &client) {
        return client.fullName.find(fullName) != std::string::npos;
    };

    auto it = std::find_if(clients.begin(), clients.end(), condition);
    if (it == clients.end()) {
        throw std::out_of_range("Substring not found in clients");
    }
    it->gender = gender;
    it->birthDate = birthDate;
    it->city = city;
    it->phoneNumber = phoneNumber;
    it->diagnosis = diagnosis;
}







