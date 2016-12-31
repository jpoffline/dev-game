//
//  GameFundamental.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 14/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "GameFundamental.h"

GameFundamental::GameFundamental() : deltaTime(0.0f)
{

}

GameFundamental::~GameFundamental()
{

}


void GameFundamental::check_window_events(sf::RenderWindow& window)
{
    sf::Event evnt;
    while (window.pollEvent(evnt))
    {
        switch (evnt.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            default: continue;
        }
        
    }
}

bool
GameFundamental::is_object_in_screen(sf::RectangleShape& o)
{
    
    auto xp = o.getPosition().x;
    auto yp = o.getPosition().y + o.getSize().y / 2.0f;
    if(yp > get_screen_height())
    {
        return false;
    }
    else if(xp > get_screen_width())
    {
        return false;
    }
    else if(xp < 0 )
    {
        return false;
    }
    else if(yp < 0 )
    {
        return false;
    }
    else
    {
        return true;
    }
    
    
}



const int
GameFundamental::get_screen_width()
{
    return SCREEN_WIDTH;
}

const int
GameFundamental::get_screen_height()
{
    return SCREEN_HEIGHT;
}

const float&
GameFundamental::get_gravity_strength()
{
    return GRAVITY_STRENGTH;
}

void
GameFundamental::restart_deltaTime()
{
    deltaTime = clock.restart().asSeconds();
}

float
GameFundamental::get_deltaTime()
{
    return deltaTime;
}



