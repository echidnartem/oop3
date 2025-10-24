#include "../include/figure.h"


std::istream& operator>>(std::istream& is, Figure& figure) {
    return figure.read(is);
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    return figure.print(os);
}



bool operator==(const Point& a, const Point& b) {
    return std::abs(a.x - b.x) < 1e-9 && std::abs(a.y - b.y) < 1e-9;
}

bool operator==(const Figure& figure_1, const Figure& figure_2) {
    return figure_1.equal(figure_2);
}



Figure::operator double() const {
    return area();
}



double Figure::area() const {
    double area = 0.0;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += dots[i].x * dots[j].y - dots[j].x * dots[i].y;
    }

    return std::abs(area) / 2.0;
}

Point Figure::centre_figure() const {
    Point center = {0, 0};

    for (const auto& dot : dots) {
        center.x += dot.x;
        center.y += dot.y;
    }

    center.x /= n;
    center.y /= n;

    if (abs(center.x) <= 1e-9) center.x = 0;
    if (abs(center.y) <= 1e-9) center.y = 0;

    return center;
}



std::istream& Figure::read(std::istream& is) {
    dots.resize(n);
    for (int i = 0; i < n; ++i) {
        if (!(is >> dots[i].x >> dots[i].y)) {
            throw std::runtime_error("Failed to calculate coordinates of figure points");
        }
    }
    
    return is;
}

std::ostream& Figure::print(std::ostream& os) const {
    for (int i = 0; i < n; ++i) {
        os << '(' << dots[i].x << ", " << dots[i].y << ')';
        if (i < n - 1) os << "\n";
    }

    return os;
}