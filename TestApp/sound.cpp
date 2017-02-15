//
//  sound.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 15/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#include "sound.h"
const double TWO_PI = 6.28318;
const unsigned SAMPLES = 44100;
const unsigned SAMPLE_RATE = 44100;
const unsigned AMPLITUDE = 30000;
const double increment = 440./44100;

sf::Int16 gen_sample(const unsigned amplitude, const double x)
{
    return amplitude * (sin(x * TWO_PI) +  sin(x * TWO_PI * 2)+ 0.5 * sin(x * TWO_PI * 0.75));
}



struct MODE
{
    double freq;
    double amplitude = 1.0;
    MODE(double f, unsigned a) : freq(f), amplitude(a){}
};


sf::Int16 gen_sample(const std::vector<MODE>& modes, const unsigned amplitude,const double x)
{
    sf::Int16 base = 1.0;
    for(auto & m : modes)
    {
        base += m.amplitude * sin(x * TWO_PI * m.freq);
    }
    return base * amplitude;
}

int run_sound()
{
    
    sf::Int16 raw[SAMPLES];
    
    

    double x = 0;
    
    std::vector<MODE> modes{
        MODE(0.01, 1.0), MODE(0.06, 1.0)//, MODE(1,1)//, MODE(2.0, 1.0), MODE(3.0, 1.0), MODE(0.1, 1.0)
    };
    
    
    for (unsigned i = 0; i < SAMPLES; i++)
    {
        raw[i] = gen_sample(modes, AMPLITUDE, x);
        x += increment;
    }
    
    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE))
    {
        std::cerr << "Loading failed!" << std::endl;
        return 1;
    }
    
    sf::Sound Sound;
    Sound.setBuffer(Buffer);
    Sound.setLoop(true);
    Sound.play();
    
    while (1)
    {
        sf::sleep(sf::milliseconds(100));
    }
    
    return 0;
}