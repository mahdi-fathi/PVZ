#include "plant.hpp"

Plant::Plant(RenderWindow &window, Vector2f position) : windowptr(&window)
{
    pos = position;
    if (!plant_texture.loadFromFile(PICS_PATH + "ps/" + "ps1.png"))
    {
        cout << "file not opened";
        return;
    }
    plant_sprite.setTexture(plant_texture);
    plant_sprite.setScale(2, 2);
    plant_sprite.setPosition(pos);
}

Plant::~Plant()
{
}

void Plant::render()
{
    windowptr->draw(plant_sprite);
}

void Plant::handle_mouse_press(Event event)
{
    if (event.mouseButton.button == Mouse::Left)
    {
        Vector2f mouse_pos = static_cast<Vector2f>(Mouse::getPosition(*windowptr));
        if (plant_sprite.getGlobalBounds().contains(mouse_pos))
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
        pos.y -= plant_sprite.getGlobalBounds().height / 2;
        pos.x -= plant_sprite.getGlobalBounds().width / 2;
    }
    plant_sprite.setPosition(pos);
}
