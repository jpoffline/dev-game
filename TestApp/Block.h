//
//  Block.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "utils.h"
#include <iostream>
#include "Collider.h"

class Block  {
    
public:
    
    Block();
    Block(sf::Vector2f size, sf::Vector2f position, sf::Color col);
    
    void set_size(sf::Vector2f s);
    void set_position(sf::Vector2f pos);
    void set_color(sf::Color col);
    void set_origin(sf::Vector2f);
    void draw(sf::RenderWindow& window);
    sf::RectangleShape& get_body(){return body;};
    void set_hit(sf::Color);
    
    bool is_block_fresh();
    Collider getCollider(){return Collider(body);}
    
private:
    sf::RectangleShape body;
    bool is_fresh;
    void init();

    
};