//
// Created by mikhn on 25/11/2023.
//

#ifndef COURSE_DIMA_MET_1_ABSTRACTUSER_H
#define COURSE_DIMA_MET_1_ABSTRACTUSER_H


#include <string>

class AbstractUser {
public:
    AbstractUser(const std::string &login, const std::string &password);

    bool isAuthorised() const;


private:
    bool is_authorised;
    std::string login;
    std::string password;

};


#endif //COURSE_DIMA_MET_1_ABSTRACTUSER_H
