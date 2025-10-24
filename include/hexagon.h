#ifndef HEXAGON_H
#define HEXAGON_H


#include "figure.h"


class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(std::vector<Point> dots);

    Hexagon& operator=(const Hexagon& right_operand);
    Hexagon& operator=(Hexagon&& right_operand) noexcept;
    
    virtual ~Hexagon() = default;

protected:
    virtual bool equal(const Figure& other) const override;
};


#endif