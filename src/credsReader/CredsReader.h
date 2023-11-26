#ifndef CREDS_READER_H
#define CREDS_READER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

class CredentialsParser {
public:
    std::unordered_map<std::string, std::pair<std::string, std::string>> credentials;
    CredentialsParser(const std::string& filename);
    void ParseFile(const std::string& filename);
    std::string ToString() const;
    std::string GetRole(const std::string& login, const std::string& password) const;
};

#endif // CREDS_READER_H
