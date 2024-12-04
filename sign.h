#ifndef SIGN_H
#define SIGN_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <stdexcept>

struct Coordinates {
    double longitude;
    double latitude;
};

class Sign {
public:
    std::string name;
    unsigned int id;
    Coordinates coordinates;

    Sign() : name(""), id(0), coordinates({ 0.0, 0.0 }) {}

    Sign(const std::string& name, unsigned int id, const Coordinates& coords)
        : name(name), id(id), coordinates(coords) {
    }
};

class SignDatabase {
private:
    std::unordered_map<unsigned int, Sign> signs;

public:
    void addSign(const Sign& sign) {
        if (signs.find(sign.id) != signs.end()) {
            throw std::runtime_error("Sign with this ID already exists.");
        }
        signs[sign.id] = sign;
    }

    void removeSign(unsigned int id) {
        if (signs.find(id) == signs.end()) {
            std::cerr << "Warning: Sign with ID " << id << " does not exist." << std::endl;
            return;
        }
        signs.erase(id);
    }

    Sign findSign(unsigned int id) {
        auto it = signs.find(id);
        if (it == signs.end()) {
            throw std::runtime_error("Sign with this ID does not exist.");
        }
        return it->second;
    }

    void addSigns(const std::vector<Sign>& new_signs) {
        for (const auto& sign : new_signs) {
            addSign(sign);
        }
    }
};

#endif // SIGN_H
