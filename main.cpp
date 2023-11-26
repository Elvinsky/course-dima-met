#include <iostream>
#include "src/credsReader/CredsReader.h"
#include "src/models/AbstractUser.h"
#include "src/MedicalInfoManipulator/MedicakInfoManipulator.h"

int main() {
    MedicalInfoManipulator manip;
    manip.parseFile("../medinfo.txt");
    manip.sortByName();
    manip.displayTable();
     return 0;
}