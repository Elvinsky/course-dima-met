//
// Created by mikhn on 25/11/2023.
//

#include "User.h"
#include "../credsReader/CredsReader.h"


std::string User::authoriseUser(const std::string &login, const std::string &password) {
    CredentialsParser parser("../creds.txt");
    this->role = parser.GetRole(login,password);
    return this->role;
}

std::string User::getRole() const {
    return role;
}



