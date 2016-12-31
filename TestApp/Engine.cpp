//
//  Engine.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Engine.h"


Engine::Engine()
{
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y),
                    "Simple Game Engine",
                    Style::Fullscreen);

    blocks.add_block(Block(sf::Vector2f(100.0f,50.0f), sf::Vector2f(500.0f,500.0f), sf::Color::Blue));
    blocks.add_block(Block(sf::Vector2f(100.0f,50.0f), sf::Vector2f(500.0f,250.0f), sf::Color::Blue));
    blocks.add_block(Block(sf::Vector2f(100.0f,50.0f), sf::Vector2f(200.0f,250.0f), sf::Color::Blue));
    
}


void
Engine::start()
{
    // Timing
    Clock clock;
    
    while (m_Window.isOpen())
    {
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();
        
        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();

        input();
        
        if(run_state.is_ok())
        {
            update(dtAsSeconds);
            draw();
            display();
        }
        else
        {
            m_Window.close();
        }
        
    }
    
}

void
Engine::input()
{
    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
        run_state.kill();
    }
    
    // Handle the player moving
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Bob.moveLeft();
    }
    else
    {
        m_Bob.stopLeft();
    }
    
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Bob.moveRight();
    }
    else
    {
        m_Bob.stopRight();
    }
    
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        m_Bob.moveUp();
    }
    else
    {
        m_Bob.stopUp();
    }
    
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        m_Bob.moveDown();
    }
    else
    {
        m_Bob.stopDown();
    }
    
}



void
Engine::update(float dtAsSeconds)
{
    hud.add_line("Score");
    hud.add_line(m_Bob.get_bob_hud_text());
    m_Bob.update(dtAsSeconds);
    
    auto hits = blocks.check_player_hit_with_blocks<sf::RectangleShape>(m_Bob.getSprite());
    m_Bob.increment_bob_score(hits);
    

    
}



void
Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(Color::White);
    
    // Draw the background
    m_Window.draw(m_BackgroundSprite);
    m_Bob.draw(m_Window);    
    hud.draw(m_Window);
    
    blocks.draw(m_Window);
    
}


void
Engine::display()
{
    // Show everything we have just drawn
    m_Window.display();
}
