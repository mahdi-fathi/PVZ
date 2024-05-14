#ifndef FIELD_HPP
#include "global.hpp"
class Field
{
private:
    Texture background_texture;
    Sprite background_sprite;
    vector<FloatRect> tiles;
    void make_grid();
public:
    Field();
    ~Field();
    void render(RenderWindow &window);
    void update();
    vector<FloatRect> get_grid(){return tiles;}
};



#endif