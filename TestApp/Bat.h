//
//  Bat.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>


class Bat
{
    private:
        sf::Vector2f position;

        // A RectangleShape object
        sf::RectangleShape batShape;

        float batSpeed = .3f;

    public:
        Bat(float startX, float startY);

        sf::FloatRect getPosition();
        sf::RectangleShape getShape();
        void moveLeft();
        void moveRight();
        void update();

};
