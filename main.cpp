#include <iostream>
#include <vector>
#include <sstream>
#include "Component.hpp"
#include "Logger.hpp"
#include "Encryptor.hpp"

int main() {
    std::vector<Component*> components;
    components.push_back(new Resistor(100));
    components.push_back(new Capacitor(0.000001));
    components.push_back(new Inductor(0.01));

    double freq = 1000;
    std::complex<double> total(0, 0);
    std::stringstream report;

    report << "Impedance calculation at " << freq << " Hz:\n\n";

    for (auto* c : components) {
        auto Z = c->getImpedance(freq);
        report << c->toString() << " => Z = " << Z << "\n";
        total += Z;
    }

    report << "\nTotal Impedance: " << total << "\n";

    std::string result = report.str();
    std::cout << result;

    Encryptor::encryptAndSave("data.enc", result);
    Logger::log("Calculation completed. Data saved to data.enc");

    for (auto* c : components) delete c;
    return 0;
}
