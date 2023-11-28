//
// Created by mikhn on 25/11/2023.
//

#include <iostream>
#include <vector>
#include <locale>
#include <codecvt>
#include "medical_info_system.h"
#include "../medical_info_manipulator/medical_info_manipulator.h"


void MedicalInfoSystem::displayUserMainMenu() {
    MedicalInfoManipulator manip;
    manip.parseFile("../medinfo.txt");
    std::cout << "1. Просмотреть все данные" << std::endl;
    std::cout << "2. Поиск и фильтрация" << std::endl;
    std::cout << "3. Сортировка" << std::endl;
    std::cout << "4. Вывести всех иногородних пациентов" << std::endl;
    std::cout << "5. Выход" << std::endl;

    int user_input = std::stoi(this->getUserInput());

    switch (user_input) {
        case 1: {
            manip.displayTable();
            std::cout << "1. Вернуться в главное меню" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            int choice = std::stoi(this->getUserInput());
            if (choice == 1) {
                this->displayUserMainMenu();
            } else {
                std::cout << "До свидания!";
                exit(0);
            }
        }
        case 2: {
            std::cout << "Введите подстроку для поиска" << std::endl;
            std::string substr = this->getUserInput();
            manip.filterBySubstring(substr);
            std::cout << "1. Вернуться в главное меню" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            int choice2 = std::stoi(this->getUserInput());
            if (choice2 == 1) {
                this->displayUserMainMenu();
            } else {
                std::cout << "До свидания!";
                exit(0);
            }
        }
        case 3: {
            std::cout << "1. Сортировка по фамилии" << std::endl;
            std::cout << "2. Соритровка по возрасту" << std::endl;
            std::cout << "3. Выход" << std::endl;

            int choice = std::stoi(this->getUserInput());

            switch (choice) {
                case 1: {
                    manip.sortByName();
                    manip.displayTable();
                    std::cout << "1. Вернуться в главное меню" << std::endl;
                    std::cout << "2. Выйти" << std::endl;
                    int choice2 = std::stoi(this->getUserInput());
                    if (choice2 == 1) {
                        this->displayUserMainMenu();
                    } else {
                        std::cout << "До свидания!";
                        exit(0);
                    }
                }
                case 2: {
                    manip.sortByAge();
                    manip.displayTable();
                    std::cout << "1. Вернуться в главное меню" << std::endl;
                    std::cout << "2. Выйти" << std::endl;
                    int choice2 = std::stoi(this->getUserInput());
                    if (choice2 == 1) {
                        this->displayUserMainMenu();
                    } else {
                        std::cout << "До свидания!";
                        exit(0);
                    }
                }
                case 3: {
                    std::cout << "До свидания!";
                    exit(0);
                }
                default: {
                    std::cout << "Under development";
                }
            }
        }
        case 4: {
            manip.getNonResidents();
            std::cout << "1. Вернуться в главное меню" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            int choice2 = std::stoi(this->getUserInput());
            if (choice2 == 1) {
                this->displayUserMainMenu();
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
            std::cout << "Неправильная опция. Возвращаемся в главное меню.";
            this->displayUserMainMenu();
    }
}

void MedicalInfoSystem::displayAdminMainMenu() {
    std::cout << "1. Просмотреть все учётные записи" << std::endl;
    std::cout << "2. Добавить учётную запись" << std::endl;
    std::cout << "3. Отредактировать учётную запись" << std::endl;
    std::cout << "4. Удалить учётную запись" << std::endl;
    std::cout << "5. Выход" << std::endl;

    int user_input = std::stoi(this->getUserInput());
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
    std::cout << "Меню авторизации: " << std::endl;
    std::cout << "Введите логин: " << std::endl;
    std::string login = this->getUserInput();
    std::cout << "Введите пароль:" << std::endl;
    std::string password = this->getUserInput();
    std::string result = this->user.authoriseUser(login, password);
    if (result.empty()) {
        std::cout << "Неправильные данные! Попробовать ещё раз?" << std::endl;
        std::cout << "1. Авторизация" << std::endl;
        std::cout << "2. Выход" << std::endl;
        std::string user_choice = getUserInput();
        if (user_choice == "1") {
            this->displayAuthMenu();
        } else {
            this->displayByeMessage();
        }
    } else {
        std::cout << "Авторизация успешно!" << std::endl;
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


