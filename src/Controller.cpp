//
// Created by mikhn on 25/11/2023.
//

#include <iostream>
#include <vector>
#include "Controller.h"

void Controller::run() {
    if (!this->abstractUser.isAuthorised()) {
        this->authUser();
    }
}

void Controller::authUser() {
    std::cout << "Auth menu: \n";
    std::cout << "Enter login: ";
    std::string login;
    std::cout << std::endl;
    std::cin >> login;
    std::cout << "Enter password:";
    std::string password;
    std::cin >> password;
    std::cout << std::endl;
    this->abstractUser = AbstractUser(login, password);

}
