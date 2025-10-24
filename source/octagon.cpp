#include "../include/octagon.h"


Octagon::Octagon() {
    n = 8;
    dots.resize(8);
}

Octagon::Octagon(std::vector<Point> dots) {
    n = 8;
    this->dots = dots;
    if (this->dots.size() != 8) {
        throw std::invalid_argument("A octagon requires 8 points");
    }
}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        dots = other.dots;
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        dots = std::move(other.dots);
    }
    return *this;
}

bool Octagon::equal(const Figure& other) const {
    const Octagon* oct = dynamic_cast<const Octagon*>(&other);
    if (!oct) return false;
    
    for (int i = 0; i < n; ++i) {
        if (!(dots[i] == oct->dots[i])) {
            return false;
        }
    }
    return true;
}