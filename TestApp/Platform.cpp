//
//  Platform.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Platform.h"
#include "GameFundamental.h"

Platform::Platform(sf::Vector2f size, sf::Vector2f position, sf::Color col)

{
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setPosition(position);
    body.setFillColor(col);
    _push_weight = 0.5f;
    
    _has_changed = true;
    
}



Platform::~Platform()
{

}


void 
Platform::set_changed()
{
    _has_changed = true;
}


bool 
Platform::is_obj_to_be_redrawn()
{
    if(_has_changed)
    {
        _has_changed = true;
        return true;
    }
    else
    {
        return false;
    }
    
}


void
Platform::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}



Collider
Platform::getCollider()
{
    return Collider(body);
}