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
    std::cout << "1. Просмотреть все данные" << std::endl;
    std::cout << "2. Поиск и фильтрация" << std::endl;
    std::cout << "3. Сортировка" << std::endl;
    std::cout << "4. Вывести всех иногородних пациентов" << std::endl;
    std::cout << "5. Вывести всех пациентов старше x лет с диагнозом y." << std::endl;
    std::cout << "6. Выход" << std::endl;

    int user_input = std::stoi(this->getUserInput());

    switch (user_input) {
        case 1: {
            this->manip.displayTable();
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
            this->manip.filterBySubstring(substr);
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
                    this->manip.sortByName();
                    this->manip.displayTable();
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
                    this->manip.sortByAge();
                    this->manip.displayTable();
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
            this->manip.getNonResidents();
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
            std::cout << "Введите возраст:" << std::endl;
            int age;
            std::cin >> age;
            std::cout << "Введите диагноз:" << std::endl;
            std::string diagnose;
            std::cin >> diagnose;
            this->manip.filterByAgeAndDiagnose(age, diagnose);
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
        case 6: {
            std::cout << "До свидания!";
            exit(0);
        }
        default:
            std::cout << "Неправильная опция. Возвращаемся в главное меню.";
            this->displayUserMainMenu();
    }
}

void MedicalInfoSystem::displayAdminMainMenu() {
    std::cout << "1. Управление учётными записями" << std::endl;
    std::cout << "2. Управление медицинскими записями" << std::endl;
    std::cout << "3. Вернуться в главное меню" << std::endl;
    std::cout << "4. Выйти" << std::endl;

    int user_input = std::stoi(this->getUserInput());
    switch (user_input) {
        case 1: {
            this->displayAccountManagementMenu();
            break;
        }
        case 2: {
            this->displayMedicalManagementMenu();
            break;
        }
        case 3: {
            this->displayAdminMainMenu();
        }
        case 4: {
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
    this->manip = MedicalInfoManipulator();
    this->manip.parseFile("../medinfo.txt");
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
    this->manip.closeStore();
    std::cout << "До свидания!" << std::endl;
    exit(0);
}

void MedicalInfoSystem::displayAccountManagementMenu() {
    std::cout << "1. Просмотреть все учётные записи" << std::endl;
    std::cout << "2. Добавить учётную запись" << std::endl;
    std::cout << "3. Отредактировать учётную запись" << std::endl;
    std::cout << "4. Удалить учётную запись" << std::endl;
    std::cout << "5. Создать файл учётных записей" << std::endl;
    std::cout << "6. Удалить файл учётных записей" << std::endl;
    std::cout << "7. Выйти" << std::endl;
    int user_input = std::stoi(this->getUserInput());
    switch (user_input) {
        case 1: {
            std::cout << this->creds_store.getAllCreds();
            std::cout << "1. Вернуться в меню управления пользователями" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            int choice = std::stoi(this->getUserInput());
            if (choice == 1) {
                this->displayAccountManagementMenu();
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
            std::cout << "Новый пользователь добавлен. Возвращаемся в меню управления пользователями." << std::endl;
            this->displayAccountManagementMenu();
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
            try {
                this->creds_store.editUser(login, new_password, role);
            } catch (const std::out_of_range &error) {
                std::cout << "Такого пользователя не существует!" << std::endl;
                this->displayAccountManagementMenu();
            }
            std::cout << "Пользователь отредактирован. Возвращаемся в меню управления пользователями." << std::endl;
            this->displayAccountManagementMenu();

        }
        case 4: {
            std::cout << "Введите логин пользователя для удаления:" << std::endl;
            std::string login = this->getUserInput();
            std::cout << "Вы точно хотите удалить пользователя " << login << "?" << std::endl;
            std::cout << "1. Да" << std::endl;
            std::cout << "2. Нет, вернуться в меню управления пользователями." << std::endl;
            std::string confirmation = this->getUserInput();
            if (confirmation == "1") {
                try {
                    this->creds_store.deleteUser(login);
                } catch (const std::out_of_range &error) {
                    std::cout << "Такого пользователя не существует!" << std::endl;
                    this->displayAccountManagementMenu();
                }
                std::cout << "Пользователь удалён. Возвращаемся в главное меню." << std::endl;
            } else {
                std::cout << "Возвращаемся в меню управления пользователями." << std::endl;
            }
            this->displayAccountManagementMenu();
        }
        case 5: {
            std::cout << "Введите названия файла: " << std::endl;
            std::string filename = this->getUserInput();
            this->creds_store.createCredStoreFile(filename);
        }
        case 6: {
            std::cout << "Вы точно хотите удалить файл управления пользователями? " << std::endl;
            std::cout << "1. Да" << std::endl;
            std::cout << "2. Нет, вернуться в меню управления пользователями." << std::endl;
            std::string confirmation = this->getUserInput();
            if (confirmation == "1") {
                this->creds_store.deleteCredStoreFile();
                std::cout << "Файл удалён. Пользоваться приложением дальше нельзя." << std::endl;
                this->displayByeMessage();
            } else {
                std::cout << "Возвращаемся в меню управления пользователями." << std::endl;
            }
            this->displayAccountManagementMenu();
        }
        case 7: {
            this->displayByeMessage();
        }
        default:
            std::cout << "Неправильный номер для действия. Выберете ещё раз!" << std::endl;
            this->displayAccountManagementMenu();

    }
}

void MedicalInfoSystem::displayMedicalManagementMenu() {
    std::cout << "1. Добавить медицинскую запись" << std::endl;
    std::cout << "2. Удалить медицинскую запись" << std::endl;
    std::cout << "3. Отредактировать медицинскую запись" << std::endl;
    std::cout << "4. Показать записи" << std::endl;
    std::cout << "5. Выход" << std::endl;
    int user_input = std::stoi(this->getUserInput());
    switch (user_input) {
        case 1: {
            std::cout << "Введите ФИ пациента" << std::endl;
            std::string full_name = this->getUserInput();
            std::cout << "Введите пол пациента" << std::endl;
            std::string gender = this->getUserInput();
            std::cout << "Введите дату рождения пациента" << std::endl;
            std::string birth_date = this->getUserInput();
            std::cout << "Введите город пациента" << std::endl;
            std::string city = this->getUserInput();
            std::cout << "Введите телефон пациента" << std::endl;
            std::string phone_number = this->getUserInput();
            std::cout << "Введите диагноз пациента" << std::endl;
            std::string diagnosis = this->getUserInput();

            this->manip.addRow(full_name, gender, birth_date, city, phone_number, diagnosis);
            std::cout << "Запись добавлена!" << std::endl;
            this->displayMedicalManagementMenu();
        }
        case 2: {
            std::cout << "Введите имя пациента для удаления:" << std::endl;
            std::string fullname = this->getUserInput();
            std::cout << "Вы точно хотите удалить этого пациента?" << std::endl;
            std::cout << "1. Да" << std::endl;
            std::cout << "2. Нет, вернуться в меню управления пользователями." << std::endl;
            std::string confirmation = this->getUserInput();
            if (confirmation == "1") {
                try {
                    this->manip.deleteRow(fullname);
                } catch (const std::out_of_range &error) {
                    std::cout << "Такой записи не существует!" << std::endl;
                    this->displayMedicalManagementMenu();
                }
                std::cout << "Запись удалена. Возвращаемся в главное меню." << std::endl;
            } else {
                std::cout << "Возвращаемся в меню управления записями." << std::endl;
            }
            this->displayMedicalManagementMenu();
        }
        case 3: {
            std::cout << "Введите ФИ пациента" << std::endl;
            std::string full_name = this->getUserInput();
            std::cout << "Введите пол пациента" << std::endl;
            std::string gender = this->getUserInput();
            std::cout << "Введите дату рождения пациента" << std::endl;
            std::string birth_date = this->getUserInput();
            std::cout << "Введите город пациента" << std::endl;
            std::string city = this->getUserInput();
            std::cout << "Введите телефон пациента" << std::endl;
            std::string phone_number = this->getUserInput();
            std::cout << "Введите диагноз пациента" << std::endl;
            std::string diagnosis = this->getUserInput();

            try {
                this->manip.editRow(full_name, gender, birth_date, city, phone_number, diagnosis);
            } catch (const std::out_of_range &error) {
                std::cout << "Такой записи не существует!" << std::endl;
                this->displayMedicalManagementMenu();
            }
            std::cout << "Запись отредактирована" << std::endl;
            this->displayMedicalManagementMenu();
        }
        case 4: {
            this->manip.displayTable();
            std::cout << "1. Вернуться в главное меню" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            int choice = std::stoi(this->getUserInput());
            if (choice == 1) {
                this->displayMedicalManagementMenu();
            } else {
                std::cout << "До свидания!";
                exit(0);
            }
        }
        case 5: {
            this->displayByeMessage();
        }
        default: {
            std::cout << "Неправильный номер для действия. Выберете ещё раз!" << std::endl;
            this->displayAccountManagementMenu();
        }
    }

}


