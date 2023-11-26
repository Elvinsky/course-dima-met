//
// Created by mikhn on 25/11/2023.
//

#include "user.h"
#include "../creds_store/creds_store.h"


std::string User::authoriseUser(const std::string &login, const std::string &password) {
    CredentialsStore parser("../creds.txt");
    this->role = parser.getRole(login, password);
    return this->role;
}

std::string User::getRole() const {
    return role;
}



