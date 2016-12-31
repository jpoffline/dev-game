//
//  Platform.h
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "GameFundamental.h"
#include "ObjectFundamental.h"

class Platform : public GameFundamental {
    
    public:

        Platform(sf::Vector2f size, sf::Vector2f position, sf::Color col);
        ~Platform();
        void Draw(sf::RenderWindow& window);
        Collider getCollider();
        float& get_push_weight(){return _push_weight;}
        void set_push_weight(float w){_push_weight = w;}
    
        void set_changed();
        bool is_obj_to_be_redrawn();
        


    private:
        sf::RectangleShape body;
       
        float _push_weight;
        bool _has_changed;

};



