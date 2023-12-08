#ifndef COURSE_DIMA_MET_1_MEDICAL_INFO_SYSTEM_H
#define COURSE_DIMA_MET_1_MEDICAL_INFO_SYSTEM_H

#include "../user/user.h"
#include "../creds_store/creds_store.h"
#include "../medical_info_manipulator/medical_info_manipulator.h"

class MedicalInfoSystem {
public:
    MedicalInfoSystem();
    void run();
private:
    void displayAdminMainMenu();
    void displayUserMainMenu();
    void displayAuthMenu();
    static std::string getUserInput();
    void displayByeMessage();
    void displayAccountManagementMenu();
    void displayMedicalManagementMenu();

    User user;
    CredentialsStore creds_store;
    MedicalInfoManipulator manip;

};


#endif
