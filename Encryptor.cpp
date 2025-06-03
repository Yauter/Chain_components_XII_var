#include "Encryptor.hpp"
#include <fstream>

void Encryptor::encryptAndSave(const std::string& filename, const std::string& data, char key) {
    std::ofstream out(filename);
    for (char c : data) {
        out << static_cast<char>(c ^ key);
    }
    out.close();
}
