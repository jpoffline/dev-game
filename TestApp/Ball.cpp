//
//  Ball.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
    
    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

sf::FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
    return ballShape;
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
    
}

void Ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}

void Ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;
    
    // Move the ball and the bat
    ballShape.setPosition(position);
}