#ifndef COURSE_DIMA_MET_1_MEDICALINFOSYSTEM_H
#define COURSE_DIMA_MET_1_MEDICALINFOSYSTEM_H

#include "models/User.h"
#include "credsReader/creds_store.h"

class MedicalInfoSystem {
public:
    MedicalInfoSystem();
    void run();
private:
    void displayAdminMainMenu();
    void displayUserMainMenu();
    void displayAuthMenu();
    std::string getUserInput();
    void displayByeMessage();

    User user;
    CredentialsStore creds_store;

};


#endif
