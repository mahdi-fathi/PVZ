#include "global.hpp"
/*this class is for our plant bar as of now(might also add the players functionalities to it later)*/
class Plant : public Drawable ,public Transformable
{
private:
    Texture plant_texture;
    Sprite plant_sprite;
public:
    Plant(/* args */);
    ~Plant();
};
