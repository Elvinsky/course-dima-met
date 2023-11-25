//
// Created by mikhn on 25/11/2023.
//

#include "AbstractUser.h"

bool AbstractUser::isAuthorised() const {
    return is_authorised;
}

AbstractUser::AbstractUser(const std::string &login, const std::string &password) : login(login), password(password) {}



