#ifndef GAME_HPP
#define GAME_HPP    
#include "global.hpp"
#include "plant.hpp"
#include "plant_bar.hpp"
#include "field.hpp"

enum State {
    IN_GAME,
    PAUSE_MENU,
    MAIN_MENU,
    GAME_OVER,
    VICTORY,
    LEVEL_SELECT,
    EXIT
};

class Game
{
private:
    State state;
    RenderWindow window;
    vector<unique_ptr<Plant>> plants;
    PlantBar bar;
    Field playground;
    void render();
    void update();
    void process_input();
    void handle_mouse_get();
    void handle_mouse_release();
    void handle_plant_placing();
    Texture background_texture;
    Sprite background_sprite;
public:
    Game(int widht, int height);
    ~Game();
    void run();
};
#endif