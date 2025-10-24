#ifndef PENTAGON_H
#define PENTAGON_H


#include "figure.h"


class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(std::vector<Point> dots);

    Pentagon& operator=(const Pentagon& right_operand);
    Pentagon& operator=(Pentagon&& right_operand) noexcept;
    
    virtual ~Pentagon() = default;
    
protected:
    virtual bool equal(const Figure& other) const override;
};


#endif