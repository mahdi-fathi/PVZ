#include "zombie.hpp"

Zombie::Zombie(RenderWindow &window, int row, vector<FloatRect> tiles) : windowptr(&window)
{
    float y = tiles[row].top - 10;
    float x = 1300;
    pos = {x, y};
    int frame_count = 21;
    for (int i = 0; i < frame_count; i++)
    {
        Texture temp;
        if (i < 10)
        {
            if (!temp.loadFromFile(PICS_PATH + "anime/zombie/frame_0" + to_string(i) + "_delay-0.07s.png"))
            {
                cout << "loading faild";
            }
        }
        else
        {
            if (!temp.loadFromFile(PICS_PATH + "anime/zombie/frame_1" + to_string(i % 10) + "_delay-0.07s.png"))
            {
                cout << "loading faild";
            }
        }
        zombie_textures.push_back(temp);
    }
    if (!zombie_textures.empty())
    {
        for (const Texture &t : zombie_textures)
        {
            Sprite temp;
            temp.setTexture(t);
            temp.setScale(2, 2);
            temp.setPosition(pos);
            zombie_sprites.push_back(temp);
        }
    }
};

Zombie::~Zombie()
{
}

void Zombie::render()
{
    float frame_change_time = 0.07;
    delta_time += clock.restart().asSeconds();
    int frame_index = static_cast<int>(delta_time / frame_change_time) % zombie_sprites.size();
    if (delta_time >= 21)
    {
        delta_time = 0;
    }
    windowptr->draw(zombie_sprites[frame_index]);
}

void Zombie::update()
{
    pos.x -= speed;
    if (!zombie_sprites.empty())
    {
        for (Sprite &zombie_sprite : zombie_sprites)
        {
            zombie_sprite.setPosition(pos);
        }
    }
}
