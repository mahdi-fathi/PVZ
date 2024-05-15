#include "game.hpp"

Game::Game(int widht, int height)
{
    window.create(VideoMode(widht, height), "PVZ");
    window.setVerticalSyncEnabled(true);
    state = IN_GAME;
}

Game::~Game()
{
    // delete plant;
    // delete bar;
}

void Game::update()
{
    /*Handle Game Logic:
    Update the positions, states, and behaviors of game objects/entities (e.g., plant, enemies, projectiles, power-ups)
    based on the elapsed time.*/

    switch (state)
    {
    case IN_GAME:
        if (!plants.empty())
        {
            for (int i = 0; i < plants.size(); i++)
            {
                if (!plants[i]->get_is_placed() && !plants[i]->get_is_dragging())
                {
                    plants.erase(plants.begin() + i);
                }

                plants[i]->update();
            }
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
}

void Game::process_input()
{
    Event event;
    while (window.pollEvent(event))
    {
        switch (state)
        {
        case IN_GAME:
            if (event.type == Event::Closed)
            {
                state = EXIT;
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                if (bar.check_mouse_press(event, window) == 0)
                {
                    unique_ptr<Plant> plant = make_unique<Sunflower>(window, bar.card_position(0));
                    plants.push_back(move(plant));
                }
                if (bar.check_mouse_press(event, window) == 1)
                {
                    unique_ptr<Plant> plant = make_unique<Peashooter>(window, bar.card_position(1));
                    plants.push_back(move(plant));
                }
                // else if (bar.check_mouse_press(event,window) == 3)
                // {
                //     unique_ptr<Plant> plant = make_unique<Plant>(window,bar.card_position(2));
                //     plants.push_back(move(plant));
                // }
                // else if (bar.check_mouse_press(event,window) == 4)
                // {
                //     unique_ptr<Plant> plant = make_unique<Plant>(window,bar.card_position(3));
                //     plants.push_back(move(plant));
                // }
                if (!plants.empty())
                    plants.back()->handle_mouse_press(event);
            }
            else if (event.type == Event::MouseButtonReleased)
            {
                if (!plants.empty())
                {
                    plants.back()->handle_mouse_release(event, playground.get_grid());
                    if (plants.back()->get_plant_tile() == -1)
                    {
                        plants.pop_back();
                        return;
                    }
                    for (int i = 0; i < plants.size()-1; i++)
                    {
                        if (playground.get_grid()[plants.back()->get_plant_tile()].contains(plants[i]->get_position())){
                            plants.pop_back();
                            return;}
                    }
                }
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
    }
}

void Game::render()
{
    window.clear(Color::White);
    switch (state)
    {
    case IN_GAME:
        playground.render(window);
        bar.render(window);
        if (!plants.empty())
        {
            for (int i = 0; i < plants.size(); i++)
            {
                // if (plants[i]->get_is_placed() || plants[i]->get_is_dragging())
                // {
                plants[i]->render(); /* code */
                // }
            }
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
