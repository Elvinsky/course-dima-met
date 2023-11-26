#include <iostream>
#include "src/Controller.h"
#include "src/credsReader/CredsReader.h"

int main() {
    CredentialsParser parser("../creds.txt");
    std::cout << parser.ToString();
    return 0;
}