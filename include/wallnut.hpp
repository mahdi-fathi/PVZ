#ifndef WALLNUT_HPP
#define WALLNUT_HPP
#include "global.hpp"
#include "plant.hpp"
class Wallnut : public Plant
{
private:

public:
    Wallnut(RenderWindow &window, Vector2f position);
    ~Wallnut();
};


#endif