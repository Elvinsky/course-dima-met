#include <iostream>
#include "src/credsReader/CredsReader.h"
#include "src/models/AbstractUser.h"

int main() {
    AbstractUser user;
    std::cout << user.authoriseUser("john_doe","userpass123");
    return 0;
}