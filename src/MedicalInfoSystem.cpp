//
// Created by mikhn on 25/11/2023.
//

#include <iostream>
#include <vector>
#include "MedicalInfoSystem.h"


void MedicalInfoSystem::displayMainMenu() {
    std::cout << "Main menu:" << std::endl;
    std::string selected_option = this->getUserInput();
    switch (selected_option) {
        case "1":
    }

}

void MedicalInfoSystem::run() {
    this->displayAuthMenu();
    if (this->user.isAuthorised()) {
        this->displayMainMenu();
    }
}

void MedicalInfoSystem::displayAuthMenu() {
    std::cout << "Auth menu: " << std::endl;
    std::cout << "Enter login: " << std::endl;
    std::string login = this->getUserInput();
    std::cout << "Enter password:" << std::endl;
    std::string password = this->getUserInput();
    bool result = this->user.authoriseUser(login, password);
    if (!result) {
        std::cout << "Wrong credentials, try again!" << std::endl;
        this->displayAuthMenu();
    } else {
        std::cout << "OK!" << std::endl;
    }
}

std::string MedicalInfoSystem::getUserInput() {
    std::string user_input;
    std::cin >> user_input;
    return user_input;
}
