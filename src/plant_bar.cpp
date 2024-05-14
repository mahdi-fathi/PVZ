#include "plant_bar.hpp"


PlantBar::PlantBar()
{
    for(int i = 0; i<=3; i++){
        Texture temp;
    if (!temp.loadFromFile(PICS_PATH+"cards/"+"c"+to_string(i)+".png"))
    {
        cout << "file not opened";
        return;
    }
    cards_textures.push_back(temp);
}
    int i = 0;
    for(const Texture &t : cards_textures){
        Sprite temp;
        temp.setTexture(t);
        temp.setScale(0.5,0.5);
        temp.setPosition(10,30+i);
        i+=90;
        cards_sprites.push_back(temp);
    }
}

PlantBar::~PlantBar()
{
    
}

void PlantBar::render(RenderWindow &window){
    for(const Sprite &card : cards_sprites)
    window.draw(card);
}

int PlantBar::check_mouse_press(Event event,RenderWindow &window){
    if (event.mouseButton.button == Mouse::Left){
        Vector2f mouse_pos = static_cast<Vector2f>(Mouse::getPosition(window));
        for (int i = 0; i < cards_sprites.size(); i++)
        {
            if (cards_sprites[i].getGlobalBounds().contains(mouse_pos))
            {
                return i;
            }
        } 
    }
     return -1;
}

Vector2f PlantBar::card_position(int index){
    return cards_sprites[index].getPosition();
}