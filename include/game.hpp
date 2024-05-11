#ifndef GAME_HPP
#define GAME_HPP    
#include "global.hpp"
#include "player.hpp"

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
    Player *player;
    void render();
    void update();
    void process_input();
    void handle_mouse_get();
    void handle_mouse_release();
    Texture background_texture;
    Sprite background_sprite;
public:
    Game(int widht, int height);
    ~Game();
    void run();
};
#endif