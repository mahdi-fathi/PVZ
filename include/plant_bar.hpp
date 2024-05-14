#ifndef PLANT_BAR_HPP
#include "global.hpp"
class PlantBar
{
private:
    vector<Texture> cards_textures;
    vector<Sprite> cards_sprites;
public:
    PlantBar(/* args */);
    ~PlantBar();
    void render(RenderWindow &window);
    int check_mouse_press(Event event,RenderWindow &window);
    Vector2f card_position(int index);
    // vector<Sprite> get_card_sprites(){return cards_sprites;}
};

#endif