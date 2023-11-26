//
// Created by mikhn on 25/11/2023.
//

#include <iostream>
#include <vector>
#include "MedicalInfoSystem.h"


void MedicalInfoSystem::displayUserMainMenu() {

}

void MedicalInfoSystem::displayAdminMainMenu() {
    std::cout << "1. Просмотреть все учётные записи" << std::endl;
    std::cout << "2. Добавить учётную запись" << std::endl;
    std::cout << "3. Отредактировать учётную запись" << std::endl;
    std::cout << "4. Удалить учётную запись" << std::endl;
    std::cout << "5. Выход" << std::endl;

    int user_input = std::stoi(this->getUserInput());
    // todo: chose smth
    switch (user_input) {
        case 1: {
            std::cout << this->creds_store.getAllCreds();
            std::cout << "1. Вернуться в главное меню" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            int choice = std::stoi(this->getUserInput());
            if (choice == 1) {
                this->displayAdminMainMenu();
            } else {
                std::cout << "До свидания!";
                exit(0);
            }

        }
        case 5: {
            std::cout << "До свидания!";
            exit(0);
        }
        default:
            std::cout << "Under development";

    }

}

MedicalInfoSystem::MedicalInfoSystem() {
    this->user = User();
    this->creds_store = CredentialsStore("../creds.txt");
}

void MedicalInfoSystem::run() {
    this->displayAuthMenu();
    if (this->user.getRole() == "admin")  {
        this->displayAdminMainMenu();
    } else {
        this->displayUserMainMenu();
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
        std::string user_choice = getUserInput();
        if (user_choice == "1") {
            this->displayAuthMenu();
        } else {
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


