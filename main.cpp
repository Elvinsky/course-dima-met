#include "src/MedicalInfoManipulator/MedicalInfoManipulator.h"

int main() {
    MedicalInfoManipulator manip;
    manip.parseFile("../medinfo.txt");
    manip.sortByAge();
    manip.displayTable();
    return 0;
}