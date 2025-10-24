#include "../include/pentagon.h"


Pentagon::Pentagon() {
    n = 5;
    dots.resize(5);
}

Pentagon::Pentagon(std::vector<Point> dots) {
    n = 5;
    this->dots = dots;
    if (this->dots.size() != 5) {
        throw std::invalid_argument("A pentagon requires 5 points");
    }
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        dots = other.dots;
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        dots = std::move(other.dots);
    }
    return *this;
}

bool Pentagon::equal(const Figure& other) const {
    const Pentagon* pentagon = dynamic_cast<const Pentagon*>(&other);
    if (!pentagon) return false;
    
    for (int i = 0; i < n; ++i) {
        if (!(dots[i] == pentagon->dots[i])) {
            return false;
        }
    }
    return true;
}