//
//  Pong.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include "ResourcePath.hpp"

using namespace sf;

class Pong{
    
    
private:
    
    int windowWidth;
    int windowHeight;
    
    
public:
    Pong();
    ~Pong(){};
    int PlayPong();
};


