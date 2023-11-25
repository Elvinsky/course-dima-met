#include <iostream>
#include "src/Controller.h"
#include "src/credsReader/CredsReader.h"

int main() {
    CredentialReader reader;
    std::vector<std::string> credentials = reader.readCredentials("creds.txt");

    // Displaying the result
    for (const auto& credential : credentials) {
        std::cout << credential << std::endl;
    }
}