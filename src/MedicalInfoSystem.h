#ifndef COURSE_DIMA_MET_1_MEDICALINFOSYSTEM_H
#define COURSE_DIMA_MET_1_MEDICALINFOSYSTEM_H

#include "models/User.h"

class MedicalInfoSystem {
public:
    void run();

private:
    void displayMainMenu();

    void displayAuthMenu();

    std::string getUserInput();

    User user = User();

};


#endif
