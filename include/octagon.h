#ifndef OCTAGON_H
#define OCTAGON_H


#include "figure.h"


class Octagon : public Figure {
public:
    Octagon();
    Octagon(std::vector<Point> dots);

    Octagon& operator=(const Octagon& right_operand);
    Octagon& operator=(Octagon&& right_operand) noexcept;
    
    virtual ~Octagon() = default;
    
protected:
    virtual bool equal(const Figure& other) const override;
};


#endif