#include "player.hpp"

Player::Player(RenderWindow &window) : windowptr(&window)
{
    Vector2f pos = {100, 20};
    if (!plant_texture.loadFromFile(PICS_PATH + "ps1.png"))
    {
        cout << "file not opened";
        return;
    }
    plant_sprite.setTexture(plant_texture);
    plant_sprite.setScale(2, 2);
    plant_sprite.setPosition(pos);
}

Player::~Player()
{
}

void Player::render()
{
    windowptr->draw(plant_sprite);
}

void Player::handle_mouse_press(Event event)
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

void Player::handle_mouse_release(Event event)
{
    if (event.mouseButton.button == Mouse::Left)
    {
        if (is_dragging)
        {
            is_dragging = false;
        }
    }
}

void Player::update()
{
    if (is_dragging)
    {
        Vector2f pos = static_cast<Vector2f>(Mouse::getPosition(*windowptr));
        plant_sprite.setPosition(pos);
    }
}
