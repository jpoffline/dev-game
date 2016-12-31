//
//  Bob.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Bob.h"

Bob::Bob()
{
    // How fast does Bob move?
    set_bob_speed(400);
    
    screen_dims.x = VideoMode::getDesktopMode().width;
    screen_dims.y = VideoMode::getDesktopMode().height;
    
    
    m_y_ground = 0.9*screen_dims.y;
    
    // Set the Bob's starting position
    m_Position.x = 500;
    m_Position.y = m_y_ground;
    

    
    m_Sprite.setFillColor(Color::Green);
    m_Sprite.setSize(Vector2f(100.0f,100.0f));
    m_Sprite.setOrigin(m_Sprite.getSize() / 2.0f);
    
}

void Bob::set_bob_speed(float s)
{
    m_Speed = s;
}

// Make the private spite available to the draw() function
RectangleShape Bob::getSprite()
{
    return m_Sprite;
}

void Bob::moveLeft()
{
    move.left.move();
}

void Bob::moveRight()
{
    move.right.move();
}

void Bob::moveDown()
{
    move.down.move();
}

void Bob::moveUp()
{
    move.up.move();
}

void Bob::stopLeft()
{
    move.left.stop();
}

void Bob::stopRight()
{
    move.right.stop();
}

void Bob::stopDown()
{
    move.down.stop();
}

void Bob::stopUp()
{
    move.up.stop();
}

Vector2f
Bob::get_move_amount(const float& elapsedTime)
{
    Vector2f d;
    d.x = 0.0f;
    d.y = 0.0f;
    
    if (move.right.is_pressed())
    {
        d.x = m_Speed * elapsedTime;
    }
    
    if (move.left.is_pressed())
    {
        d.x = - m_Speed * elapsedTime;
    }
    
    if(move.up.is_pressed())
    {
        d.y = -m_Speed * elapsedTime;
    }
    else if(m_Position.y < m_y_ground)
    {
        d.y += m_Speed * elapsedTime;
    }
    
    if(move.down.is_pressed())
    {
        d.y = m_Speed * elapsedTime;
    }
    
    return d;
    
}


void
Bob::update(float elapsedTime)
{
    
    auto d = get_move_amount(elapsedTime);
    
    
    if((d.x + m_Position.x > 100) &&
       (d.x + m_Position.x < screen_dims.x - 200))
    {
        m_Position.x += d.x;
    }
    
    if((d.y + m_Position.y > 100) &&
       (d.y + m_Position.y < m_y_ground))
    {
        m_Position.y += d.y;
    }

    
    m_Sprite.setPosition(m_Position);
    
}


void
Bob::increment_bob_score()
{
    increment_bob_score(1);
}


void
Bob::increment_bob_score(int c)
{
    score.inc(c);
}


std::string
Bob::get_bob_hud_text()
{
   // return "Pos: " + UTILS::tostr<float>(m_Sprite.getPosition().x) + " " + UTILS::tostr<float>(m_Sprite.getPosition().y);
   return "Number of blocks hit: " + UTILS::tostr<int>(score.get());
}


void
Bob::draw(RenderWindow& window)
{
    window.draw(m_Sprite);
}

