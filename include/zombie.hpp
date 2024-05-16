#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include "global.hpp"

class Zombie
{
protected:
    RenderWindow *windowptr;
    vector<Texture> zombie_textures;
    vector<Sprite> zombie_sprites;
    Vector2f pos;
    int mode; //0 for normal and 1 for attacking
    float speed = 1;
    Clock clock;
    float delta_time = 0;
public:
    Zombie(RenderWindow &window, int row, vector<FloatRect> tiles);
    ~Zombie();
    void check_plants(Vector2f plant_position);
    Vector2f get_position(){return pos;}
    void update();
    void render();
};
#endif