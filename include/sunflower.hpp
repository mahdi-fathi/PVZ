#ifndef SUNFLOWER_HPP
#define SUNFLOWER_HPP
#include "global.hpp"
#include "plant.hpp"
class Sunflower : public Plant
{
private:

public:
    Sunflower(RenderWindow &window, Vector2f position);
    ~Sunflower();
};


#endif