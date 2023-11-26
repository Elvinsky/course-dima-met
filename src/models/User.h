//
// Created by mikhn on 25/11/2023.
//

#ifndef COURSE_DIMA_MET_1_USER_H
#define COURSE_DIMA_MET_1_USER_H


#include <string>

class User {
public:
    User() = default;
    std::string authoriseUser(const std::string &login, const std::string &password);
    std::string getRole() const;

private:
    std::string role;
};


#endif //COURSE_DIMA_MET_1_USER_H
