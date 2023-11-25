// credential_reader.cpp

#include "CredsReader.h"

std::vector<std::string> CredentialReader::readCredentials(const std::string& filePath) {
    std::ifstream file(filePath);
    std::vector<std::string> credentials;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key, value;
            iss >> key >> value;
            if (key == "role:" || key == "login:" || key == "password:") {
                credentials.push_back(value);
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }

    return credentials;
}
