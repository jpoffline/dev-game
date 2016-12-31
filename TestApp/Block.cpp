//
//  Block.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Block.h"

void
Block::init()
{
    body.setOutlineColor(sf::Color::Black);
    body.setOutlineThickness(1.0f);
}

Block::Block(sf::Vector2f size, sf::Vector2f position, sf::Color col)
{

    set_size(size);
    set_origin(size);
    set_position(position);
    set_color(col);
    is_fresh = true;
    init();
}

Block::Block()
{
    is_fresh = true;
    init();
}

bool Block::is_block_fresh()
{
    return is_fresh;
}

void
Block::set_hit(sf::Color col)
{
    set_color(col);
    is_fresh = false;
}

void
Block::set_size(sf::Vector2f s)
{
    body.setSize(s);
}

void
Block::set_position(sf::Vector2f pos)
{
    body.setPosition(pos);
}


void
Block::set_origin(sf::Vector2f size)
{
    body.setOrigin(size / 2.0f);
}

void
Block::set_color(sf::Color col)
{
    body.setFillColor(col);
}


void
Block::draw(sf::RenderWindow &window)
{
    window.draw(body);
}