#include "CredsReader.h"

CredentialsParser::CredentialsParser(const std::string& filename) {
    ParseFile(filename);
}

void CredentialsParser::ParseFile(const std::string& filename) {
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

std::string CredentialsParser::ToString() const {
    std::ostringstream oss;

    for (const auto& entry : credentials) {
        oss << "Login: " << entry.first << "\n";
        oss << "Password: " << entry.second.first << "\n";
        oss << "Role: " << entry.second.second << "\n\n";
    }

    return oss.str();
}