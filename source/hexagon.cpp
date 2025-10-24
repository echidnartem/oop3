#include "../include/hexagon.h"

Hexagon::Hexagon() {
    n = 6;
    dots.resize(6);
}

Hexagon::Hexagon(std::vector<Point> dots) {
    n = 6;
    this->dots = dots;
    if (this->dots.size() != 6) {
        throw std::invalid_argument("A hexagon requires 6 points");
    }
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        dots = other.dots;
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        dots = std::move(other.dots);
    }
    return *this;
}

bool Hexagon::equal(const Figure& other) const {
    const Hexagon* hex = dynamic_cast<const Hexagon*>(&other);
    if (!hex) return false;
    
    for (int i = 0; i < n; ++i) {
        if (!(dots[i] == hex->dots[i])) {
            return false;
        }
    }
    
    return true;
}