#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP
#include "global.hpp"
#include "plant.hpp"
class Peashooter : public Plant
{
private:
    // void attack();
public:
    Peashooter(RenderWindow &window, Vector2f position);
    ~Peashooter();
};


#endif