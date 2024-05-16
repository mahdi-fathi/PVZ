#include "plant.hpp"

Plant::Plant(RenderWindow &window, Vector2f position) : windowptr(&window)
{
    pos = position; 
}

Plant::~Plant()
{
}

void Plant::render()
{
    if (is_placed){
    float frame_change_time = 0.02;
    delta_time += clock.restart().asSeconds();
    frame_index = static_cast<int>(delta_time / frame_change_time) % plant_sprites.size();
    if (delta_time >= 59)
    {
        delta_time = 0;
    }
    windowptr->draw(plant_sprites[frame_index]);}
    else
    {
        windowptr->draw(plant_sprites[0]);
    }
    
}

void Plant::handle_mouse_press(Event event)
{
    if (event.mouseButton.button == Mouse::Left)
    {
        Vector2f mouse_pos = static_cast<Vector2f>(Mouse::getPosition(*windowptr));
        if (plant_sprites[0].getGlobalBounds().contains(mouse_pos) && !is_placed)
        {
            is_dragging = true;
        }
    }
}

void Plant::handle_mouse_release(Event event, vector<FloatRect> tiles)
{
    if (event.mouseButton.button == Mouse::Left)
    {
        if (is_dragging)
        {
            is_dragging = false;
            for (long unsigned int i = 0; i < tiles.size(); i++)
            {

                if (tiles[i].contains(pos))
                {
                    float new_width = tiles[i].left;
                    float new_height = tiles[i].top;

                    pos = {new_width, new_height};
                    is_placed = true;
                    plant_tile = i;
                    break;
                }
            }
        }
    }
}

void Plant::update()
{
    if (is_dragging)
    {
        pos = static_cast<Vector2f>(Mouse::getPosition(*windowptr));
        pos.y -= plant_sprites[frame_index].getGlobalBounds().height / 2;
        pos.x -= plant_sprites[frame_index].getGlobalBounds().width / 2;
    }
    for (int i = 0; i < plant_sprites.size(); i++)
    {
    plant_sprites[i].setPosition(pos);
    }
    
}

