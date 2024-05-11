#include "game.hpp"

Game::Game(int widht, int height) 
{ 
    player = new Player(window);
    window.create(VideoMode(widht, height), "PVZ");
    window.setVerticalSyncEnabled(true);
    state = IN_GAME;
    if (!background_texture.loadFromFile(PICS_PATH+"bg.png"))
    {
        cout << "file not opened";
        return;
    }
    background_sprite.setTexture(background_texture);
    

}

Game::~Game()
{
    // delete player;
}

void Game::update()
{
    /*Handle Game Logic:
    Update the positions, states, and behaviors of game objects/entities (e.g., player, enemies, projectiles, power-ups)
    based on the elapsed time.*/

    switch (state)
    {
    case IN_GAME:
        player->update();
        break;
    case MAIN_MENU:
        break;
    case PAUSE_MENU:
        break;
    case EXIT:
        break;
    case VICTORY:
        break;
    case GAME_OVER:
        break;
    default:
        break;
    }
}

void Game::process_input()
{
    Event event;
    while(window.pollEvent(event)){
    switch (state)
    {
    case IN_GAME:
        if (event.type == Event::Closed)
        {
            window.close();
        }
        else if (event.type == Event::MouseButtonPressed)
        {
            player->handle_mouse_press(event);
        }
        else if (event.type == Event::MouseButtonReleased)
        {
            player->handle_mouse_release(event);
        }

        break;
    case MAIN_MENU:
        break;
    case PAUSE_MENU:
        break;
    case EXIT:
        break;
    case VICTORY:
        break;
    case GAME_OVER:
        break;
    default:
        break;
    }
}}

void Game::render()
{
    window.clear(Color::White);
    switch (state)
    {
    case IN_GAME:
        window.draw(background_sprite);
        player->render();
        break;
    case MAIN_MENU:
        break;
    case PAUSE_MENU:
        break;
    case EXIT:
        break;
    case VICTORY:
        break;
    case GAME_OVER:
        break;
    default:
        break;
    }
    window.display();
}

void Game::run()
{
    while (window.isOpen() && state != EXIT) 
    {
        process_input();
        update();
        render();
    }
}
