#ifndef PLANT_HPP
#define PLANT_HPP
#include "global.hpp"

class Plant
{
protected:
    bool is_dragging = false;
    bool is_placed = false;
    // virtual void attack() = 0; 
    // bool is_spawned = false;
    RenderWindow *windowptr;
    vector<Texture> plant_textures;
    vector<Sprite> plant_sprites;
    int plant_tile;
    Vector2f pos;
    Clock clock;
    float delta_time = 0;
    int frame_index = 0;
public:
    Plant(RenderWindow &window, Vector2f position);
    ~Plant();
    Vector2f get_position(){return pos;}
    // void set_position(Vector2f position){pos = position;}
    bool get_is_dragging(){return is_dragging;}
    bool get_is_placed(){return is_placed;}
    int get_plant_tile(){return is_placed? plant_tile:(-1);}
    void handle_mouse_press(Event event);
    void handle_mouse_release(Event event,vector<FloatRect> tiles);
    void update();
    void render();
};
#endif