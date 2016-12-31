//
//  Player.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Player.h"



void Player::Update(float deltaTime )
{
    
    if(is_object_in_screen(body))
    {
        body.move(_update_via_gravity(deltaTime));
        body.move(_update_from_keyboard(deltaTime));
    }
    
}

sf::Vector2f Player::_update_via_gravity(const float& dt)
{
    sf::Vector2f movement(0.0f, 0.0f);
    movement.y += get_gravity_strength() * dt;
    return movement;
    
}


sf::Vector2f Player::_update_from_keyboard(const float& deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);
    
    
    if(game::control::is_key_pressed_left())
    {
        movement.x -= speed * deltaTime;
    }
    
    if(game::control::is_key_pressed_right())
    {
        movement.x += speed * deltaTime;
    }
    
    if(game::control::is_key_pressed_up())
    {
        movement.y -= speed * deltaTime;
    }
    
    if(game::control::is_key_pressed_down())
    {
        movement.y += speed * deltaTime;
    }
    
    return movement;
}

Player::Player(float s)
    : speed(s), row(0), faceRight(true) 
{
    
    body.setSize(sf::Vector2f(10.0f,10.0f));
    body.setFillColor(sf::Color::Red);
    body.setPosition(50.0f, 50.0f);
    body.setOrigin(body.getSize()/2.0f);
    obj_fundamental = ObjectFundamental();
    
}

Player::~Player()
{
    
}




void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}



Collider Player::getCollider()
{
    return Collider(body);
}








