//
// Created by mikhn on 25/11/2023.
//

#include <iostream>
#include <vector>
#include "MedicalInfoSystem.h"


void MedicalInfoSystem::displayMainMenu() {
    std::cout << "Main menu:" << std::endl;
    std::string selected_option = this->getUserInput();


}

void MedicalInfoSystem::run() {
    this->displayAuthMenu();
    if (this->user.getRole() == "admin" || this->user.getRole() == "user") {
        this->displayMainMenu();
    }
}

void MedicalInfoSystem::displayAuthMenu() {
    std::cout << "Auth menu: " << std::endl;
    std::cout << "Enter login: " << std::endl;
    std::string login = this->getUserInput();
    std::cout << "Enter password:" << std::endl;
    std::string password = this->getUserInput();
    std::string result = this->user.authoriseUser(login, password);
    if (result.empty()) {
        std::cout << "Wrong credentials, try again?" << std::endl;
        std::cout << "1. Try again" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::string user_choice = this->getUserInput();
        if (user_choice == "1") {
            this->displayAuthMenu();
        }
        else {
            std::cout << "Okay, bye!" << std::endl;
            return;
        }
    } else {
        std::cout << "OK!" << std::endl;
    }
}

std::string MedicalInfoSystem::getUserInput() {
    std::string user_input;
    std::cin >> user_input;
    return user_input;
}
