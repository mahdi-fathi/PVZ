#include "wallnut.hpp"
Wallnut::Wallnut(RenderWindow &window, Vector2f position) : Plant(window, position)
{
    pos = position;
    if (!plant_texture.loadFromFile(PICS_PATH + "/anime/wallnut/frame_00_delay-0.05s.png"))
    {
        cout << "failde to load file!";
    }
    plant_sprite.setTexture(plant_texture);
    // plant_sprite.setScale(2,2);
    plant_sprite.setPosition(pos);
}

Wallnut::~Wallnut()
{
}
