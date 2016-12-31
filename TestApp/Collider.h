//
//  Collider.h
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameFundamental.h"

class Collider : public GameFundamental{

    typedef std::pair<float, float> FPAIRS;

    public:
        
        Collider(sf::RectangleShape& b);
        ~Collider(){};
        
        void Move(float dx, float dy);
        bool checkCollision(Collider& other, float push);
        sf::Vector2f getPosition();
        sf::Vector2f getHalfSize();
        
    private:
        sf::RectangleShape& body;
        float clamp(float push, const float min, const float max);
        bool is_collision_from_intersections(FPAIRS);
        FPAIRS gen_intersections(Collider& other);

        bool _to_redraw;

    
};



