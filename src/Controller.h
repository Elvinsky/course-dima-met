#ifndef COURSE_DIMA_MET_1_CONTROLLER_H
#define COURSE_DIMA_MET_1_CONTROLLER_H

#include "models/AbstractUser.h"

class Controller {
public:
    void run();
private:
    void authUser();
    AbstractUser abstractUser;
};


#endif
