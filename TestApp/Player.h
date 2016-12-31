//
//  Player.h
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Interactions.h"
#include "GameFundamental.h"
#include "ObjectFundamental.h"

class Player 
    : public GameFundamental, public ObjectFundamental
{
    
    public:
        Player(float s);
        ~Player();
        void Update(float deltaTime);
        void Draw(sf::RenderWindow& window);
        Collider getCollider();
        ObjectFundamental   obj_fundamental;

        
    private:
        unsigned int        row;
        sf::RectangleShape  body;
        float               speed;
        bool                faceRight;
        
    
        sf::Vector2f _update_from_keyboard(const float& dt);
        sf::Vector2f _update_via_gravity(const float& dt);
    
};







