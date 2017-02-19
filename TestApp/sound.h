//
//  sound.h
//  TestApp
//
//  Created by Jonathan Pearson on 15/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>


#include "Interactions.h"
#include "fundamental_tones.h"
#include "sound_engines.h"




class SOUND
{
    
    private:
        FUNDAMENTAL_TONES ftones;

    public:
        
        SOUND()
        {
            
        }
    
    
        void youtube();
        void keyboard();
        std::vector<sf::Sound> gen_simple_tone(double freq);
        std::vector<std::vector<sf::Int16> > gen_keyboard_notes();
    
};




