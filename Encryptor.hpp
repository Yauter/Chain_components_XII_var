#pragma once
#include <string>

class Encryptor {
public:
    static void encryptAndSave(const std::string& filename, const std::string& data, char key = 'K');
};
