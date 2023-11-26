//
// Created by mikhn on 25/11/2023.
//

#ifndef COURSE_DIMA_MET_1_ABSTRACTUSER_H
#define COURSE_DIMA_MET_1_ABSTRACTUSER_H


#include <string>

class AbstractUser {
public:
    AbstractUser() = default;
    std::string authoriseUser(const std::string &login, const std::string &password);
    std::string getRole() const;

private:
    std::string role;
};


#endif //COURSE_DIMA_MET_1_ABSTRACTUSER_H
