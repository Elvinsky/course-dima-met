#ifndef COURSE_DIMA_MET_1_MEDICALINFOSYSTEM_H
#define COURSE_DIMA_MET_1_MEDICALINFOSYSTEM_H

#include "models/AbstractUser.h"

class MedicalInfoSystem {
public:
    void run();
private:
    void displayMainMenu();
    void displayAuthMenu();
    std::string getUserInput();

    AbstractUser user = AbstractUser();

};


#endif
