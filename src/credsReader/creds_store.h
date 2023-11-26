#ifndef CREDS_READER_H
#define CREDS_READER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

class CredentialsStore {
public:
    std::unordered_map<std::string, std::pair<std::string, std::string>> credentials;
    CredentialsStore() = default;

    ~CredentialsStore() = default;

    explicit CredentialsStore(const std::string& filename);
    void ParseFile(const std::string& filename);
    std::string getAllCreds() const;
    std::string GetRole(const std::string& login, const std::string& password) const;
    void addNewUser(const std::string& login, const std::string& password, const std::string& role);
    void editUser(const std::string& login, const std::string& password, const std::string& role);
    void deleteUser(const std::string& login);

    void closeStore();

private:
    std::string filename;
};

#endif // CREDS_READER_H
