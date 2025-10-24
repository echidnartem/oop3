#ifndef FIGURE_H
#define FIGURE_H


#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <utility>


struct Point {
    double x;
    double y;
};


bool operator==(const Point& a, const Point& b);

class Figure {    
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend bool operator==(const Figure& figure_1, const Figure& figure_2);
    
public:
    virtual Point centre_figure() const;
    explicit operator double() const;
    virtual ~Figure() = default;
    
protected:
    int n;
    std::vector<Point> dots;
    virtual std::istream& read(std::istream& is);
    virtual std::ostream& print(std::ostream& os) const;
    virtual double area() const;
    virtual bool equal(const Figure& other) const = 0;
};

std::istream& operator>>(std::istream& is, Figure& figure);
std::ostream& operator<<(std::ostream& os, const Figure& figure);

bool operator==(const Figure& figure_1, const Figure& figure_2);

#endif