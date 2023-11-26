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
                this->displayByeMessage();
            }

        }
        case 2: {
            std::cout << "Введите логин для нового пользователя:" << std::endl;
            std::string new_login = this->getUserInput();
            std::cout << "Введите пароль для нового пользователя:" << std::endl;
            std::string new_password = this->getUserInput();
            std::cout << "Выберете роль пользователя:" << std::endl;
            std::cout << "1. Администратор" << std::endl
                      << "2. Пользователь" << std::endl;
            std::string role = this->getUserInput();
            if (role == "1") {
                role = "admin";
            } else {
                role = "user";
            }
            this->creds_store.addNewUser(new_login, new_password, role);
            std::cout << "Новый пользователь добавлен. Возвращаемся в главное меню." << std::endl;
            this->displayAdminMainMenu();
        }
        case 3: {
            std::cout << "Введите логин пользователя для редактирования:" << std::endl;
            std::string login = this->getUserInput();
            std::cout << "Введите новый пароль:" << std::endl;
            std::string new_password = this->getUserInput();
            std::cout << "Выберете роль пользователя:" << std::endl;
            std::cout << "1. Администратор" << std::endl
                      << "2. Пользователь" << std::endl;
            std::string role = this->getUserInput();
            if (role == "1") {
                role = "admin";
            } else {
                role = "user";
            }
            this->creds_store.editUser(login, new_password, role);
            std::cout << "Пользователь отредактирован. Возвращаемся в главное меню." << std::endl;
            this->displayAdminMainMenu();

        }
        case 4: {
            std::cout << "Введите логин пользователя для удаления:" << std::endl;
            std::string login = this->getUserInput();
            std::cout << "Вы точно хотите удалить пользователя " << login << "?" << std::endl;
            std::cout << "1. Да" << std::endl;
            std::cout << "2. Нет, вернуться в главное меню." << std::endl;
            std::string confirmation = this->getUserInput();
            if (confirmation == "1") {
                this->creds_store.deleteUser(login);
                std::cout << "Пользователь удалён. Возвращаемся в главное меню." << std::endl;
            } else {
                std::cout << "Возвращаемся в главное меню." << std::endl;
            }
            this->displayAdminMainMenu();
        }
        case 5: {
            this->displayByeMessage();
        }
        default:
            std::cout << "Неправильный номер для действия. Выберете ещё раз!" << std::endl;
            this->displayAdminMainMenu();

    }

}

MedicalInfoSystem::MedicalInfoSystem() {
    this->user = User();
    this->creds_store = CredentialsStore("../creds.txt");
}

void MedicalInfoSystem::run() {
    this->displayAuthMenu();
    if (this->user.getRole() == "admin") {
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
            this->displayByeMessage();
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

void MedicalInfoSystem::displayByeMessage() {
    this->creds_store.closeStore();
    std::cout << "До свидания!" << std::endl;
    exit(0);
}


