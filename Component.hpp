#pragma once
#include <complex>
#include <string>

class Component {
protected:
    std::string name;
public:
    Component(const std::string& n) : name(n) {}
    virtual std::complex<double> getImpedance(double freq) const = 0;
    virtual std::string toString() const = 0;
    virtual ~Component() {}
};

class Resistor : public Component {
    double resistance;
public:
    Resistor(double r);
    std::complex<double> getImpedance(double freq) const override;
    std::string toString() const override;
};

class Capacitor : public Component {
    double capacitance;
public:
    Capacitor(double c);
    std::complex<double> getImpedance(double freq) const override;
    std::string toString() const override;
};

class Inductor : public Component {
    double inductance;
public:
    Inductor(double l);
    std::complex<double> getImpedance(double freq) const override;
    std::string toString() const override;
};
