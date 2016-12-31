//
//  Collider.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Collider.h"

Collider::Collider(sf::RectangleShape& b)
    : body(b)
{
    
}


void
Collider::Move(float dx, float dy)
{
    
    if(is_object_in_screen(body))
    {
        body.move(dx, dy);
        
    }
}


sf::Vector2f
Collider::getPosition()
{
    return body.getPosition();
}


sf::Vector2f
Collider::getHalfSize()
{
    return body.getSize() / 2.0f;
}

float 
Collider::clamp(float push, const float min, const float max)
{
    return std::min(std::max(push, min), max);
}

bool 
Collider::is_collision_from_intersections(Collider::FPAIRS pairs)
{
    return pairs.first < 0.0f && pairs.second < 0.0f;
}

Collider::FPAIRS
Collider::gen_intersections(Collider& other)
{
    auto otherPosition = other.getPosition();
    auto otherHalfSize = other.getHalfSize();
    auto thisPosition = getPosition();
    auto thisHalfSize = getHalfSize();
    
    
    float deltaX = thisPosition.x - otherPosition.x;
    float deltaY = thisPosition.y - otherPosition.y;
    
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    return std::make_pair(intersectX, intersectY);
}


bool
Collider::checkCollision(Collider& other, float push)
{
    
    auto otherPosition = other.getPosition();
    auto otherHalfSize = other.getHalfSize();
    auto thisPosition = getPosition();
    auto thisHalfSize = getHalfSize();
    
    
    float deltaX = thisPosition.x - otherPosition.x;
    float deltaY = thisPosition.y - otherPosition.y;
    
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    
    auto ints = gen_intersections(other);
    if(intersectX < 0.0f && intersectY < 0.0f)
    {
        auto intersectX = ints.first;
        auto intersectY = ints.second;
        push = clamp(push, 0.0f, 1.0f);

        if(intersectX > intersectY)
        {
            if(deltaX > 0.0f)
            {
                other.Move(intersectX * (1.0f - push), 0.0f);
                Move(- intersectX * push, 0.0f);
            }
            else
            {
                other.Move(- intersectX * (1.0f - push), 0.0f);
                Move(intersectX * push, 0.0f);
            }
        }
        else
        {
            if(deltaY > 0.0f)
            {
                other.Move(0.0f, intersectY * (1.0f - push));
                Move(0.0f,-intersectY * push);
            }
            else
            {
                other.Move(0.0f, - intersectY * (1.0f - push));
                Move(0.0f, intersectY * push);
            }
        }
        
        return true;
    }
    
    
    return false;
    
}