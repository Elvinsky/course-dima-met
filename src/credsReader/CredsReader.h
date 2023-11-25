// credential_reader.h

#ifndef CREDENTIAL_READER_H
#define CREDENTIAL_READER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class CredentialReader {
public:
    std::vector<std::string> readCredentials(const std::string& filePath);
};

#endif // CREDENTIAL_READER_H
