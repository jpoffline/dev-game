//
//  Screen.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 12/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Screen.h"


ScreenObjects::ScreenObjects(sf::RenderWindow& w, GameFundamental& g)
    : _window(w), _play(true), GF(g)
{
    
}


ScreenObjects::~ScreenObjects()
{

}


bool
ScreenObjects::play()
{
    return _play;
}

void
ScreenObjects::add_player(Player p)
{
    _players.push_back(p);
}


void
ScreenObjects::add_platform(Platform p)
{
    _platforms.push_back(p);
}


void
ScreenObjects::redrawScreen()
{
    
    _window.clear(_screen_bg_colour);
    
    for(auto&player : _players)
    {
        player.Draw(_window);
    }
    
    for(auto&platform : _platforms)
    {
        if(platform.is_obj_to_be_redrawn())
        {
            platform.Draw(_window);
        }
        
    }
    
    _window.display();
    
}


void
ScreenObjects::doCollisions()
{
    
    _collide_players_with_platforms();

    
}


void 
ScreenObjects::_collide_players_with_platforms()
{
    auto player = _players[0].getCollider();
 
    
    for(auto& platform : _platforms)
    {

        bool moved = platform.getCollider().checkCollision(player, platform.get_push_weight());
        if(moved)
        {
            platform.set_changed();
            
        }

    }
    
}



void
ScreenObjects::updatePlayers(float dt)
{
    for(auto&player : _players)
    {
        player.Update(dt);
    }
}




