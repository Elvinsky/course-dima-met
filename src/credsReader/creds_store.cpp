#include "creds_store.h"

CredentialsStore::CredentialsStore(const std::string& filename) {
    ParseFile(filename);
}

void CredentialsStore::ParseFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file - " << filename << std::endl;
        return;
    }

    std::string line;
    std::string role, login, password;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;

        while (iss >> key) {
            if (key == "role:") {
                getline(iss >> std::ws, role);
            } else if (key == "login:") {
                getline(iss >> std::ws, login);
            } else if (key == "password:") {
                getline(iss >> std::ws, password);
            }
        }

        if (!login.empty()) {
            credentials[login] = std::make_pair(password, role);
            login.clear();
        }
    }

    file.close();
}

std::string CredentialsStore::getAllCreds() const {
    std::ostringstream oss;

    for (const auto& entry : credentials) {
        oss << "Логин: " << entry.first << "\t\t" << "Роль: " << entry.second.second << "\n";
    }

    return oss.str();
}

std::string CredentialsStore::GetRole(const std::string& login, const std::string& password) const {
    for (const auto& entry : credentials) {
        if (entry.first == login && entry.second.first == password) {
            return entry.second.second;
        }
    }
    return "";
}
