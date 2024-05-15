#include "sunflower.hpp"
Sunflower::Sunflower(RenderWindow &window, Vector2f position) : Plant(window, position)
{
    pos = position;
    if (!plant_texture.loadFromFile(PICS_PATH + "/anime/sf/frame_00_delay-0.05s.png"))
    {
        cout << "failde to load file!";
    }
    plant_sprite.setTexture(plant_texture);
    // plant_sprite.setScale(,);
    plant_sprite.setPosition(pos);
}

Sunflower::~Sunflower()
{
}
