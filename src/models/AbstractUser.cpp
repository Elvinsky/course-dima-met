//
// Created by mikhn on 25/11/2023.
//

#include "AbstractUser.h"

bool AbstractUser::authoriseUser(const std::string &login, const std::string &password) {
    // todo: mock
    this->is_authorised = (login == "admin" && password == "password");
    return this->is_authorised;
}

bool AbstractUser::isAuthorised() const {
    return is_authorised;
}



