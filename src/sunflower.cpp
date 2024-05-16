#include "sunflower.hpp"
Sunflower::Sunflower(RenderWindow &window, Vector2f position) : Plant(window, position)
{
    pos = position;
    int frame_count = 59;
    for (int i = 0; i < frame_count; i++)
    {
        Texture temp;
        if (i < 10)
        {
            if (!temp.loadFromFile(PICS_PATH + "anime/sf/frame_0" + to_string(i) + "_delay-0.05s.png"))
            {
                cout << "loading faild";
            }
        }
        else
        {
            if (!temp.loadFromFile(PICS_PATH + "anime/sf/frame_" + to_string(i) + "_delay-0.05s.png"))
            {
                cout << "loading faild";
            }
        }
        plant_textures.push_back(temp);
    }
    if (!plant_textures.empty())
    {
        for (const Texture &t : plant_textures)
        {
            Sprite temp;
            temp.setTexture(t);
            // temp.setScale(2, 2);
            temp.setPosition(pos);
            plant_sprites.push_back(temp);
        }
    }
}


Sunflower::~Sunflower()
{
}
