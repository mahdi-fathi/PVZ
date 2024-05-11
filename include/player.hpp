#include "global.hpp"

class Player
{
private:
    bool is_dragging = false;
    RenderWindow *windowptr;
    Texture plant_texture;
    Sprite plant_sprite;
public:
    Player(RenderWindow &window);
    ~Player();
    void handle_mouse_press(Event event);
    void handle_mouse_release(Event event);
    void update();
    void render();
};
    