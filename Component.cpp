#include "Component.hpp"
#include <sstream>
#include <iomanip>

const double PI = 3.141592653589793;
const std::complex<double> j(0, 1);

Resistor::Resistor(double r) : Component("Resistor"), resistance(r) {}
std::complex<double> Resistor::getImpedance(double) const {
    return {resistance, 0};
}
std::string Resistor::toString() const {
    return name + ": " + std::to_string(resistance) + " Ohm";
}

Capacitor::Capacitor(double c) : Component("Capacitor"), capacitance(c) {}
std::complex<double> Capacitor::getImpedance(double freq) const {
    return 1.0 / (j * 2.0 * PI * freq * capacitance);
}
std::string Capacitor::toString() const {
    return name + ": " + std::to_string(capacitance) + " F";
}

Inductor::Inductor(double l) : Component("Inductor"), inductance(l) {}
std::complex<double> Inductor::getImpedance(double freq) const {
    return j * 2.0 * PI * freq * inductance;
}
std::string Inductor::toString() const {
    return name + ": " + std::to_string(inductance) + " H";
}
