#include "field.hpp"

Field::Field()
{
    if (!background_texture.loadFromFile(PICS_PATH + "bg.png"))
    {
        cout << "file not opened";
        return;
    }
    background_sprite.setTexture(background_texture);
    make_grid();
}

Field::~Field()
{
}

void Field::make_grid()
{
    float rows = 5;
    float columns = 9;
    Vector2f top_left = {254, 65};
    // Vector2f down_right = {998, 585};
    // float tile_width = (down_right.x-top_left.x)/columns+6;
    // float tile_height = (down_right.y-top_left.y)/rows+6;
    float tile_width = 86;
    float tile_height = 97;
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            FloatRect tile;
            tile.left = top_left.x + i*tile_width -3;
            tile.top = top_left.y + j*tile_height -3;
            tile.height = tile_height + 3;
            tile.width = tile_width + 3;
            tiles.push_back(tile);
        }
        
    }
    
}
void Field::render(RenderWindow &window){
    window.draw(background_sprite);
    
}