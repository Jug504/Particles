#include "Engine.h"
#include "Particle.h"

#include <iostream>
using namespace std;

Engine::Engine() {
    m_Window.create();
    VideoMode::getDesktopMode();
}

void Engine::run() {
    Clock clock;
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;

    while(m_Window.isOpen()) {
        clock.restart();
        Time time1 = clock.getElapsedTime();
        Time time2 = time1.asSeconds();
        p.input();
        p.update(time2);
        p.draw();
    
    }
}

void Engine::input() {
    Event event;
    
    while (m_Window.pollEvent(event)) {
        
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {   
			m_Window.close();
		}

        if (event.type == Event::Closed) { m_Window.close(); }
            
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                //update here
                for(int i = 0; i < 5; i++) {
                    int numPoints = rand()%(50 - 25)+25;
                    Vector2i position(event.mouseButton.x, event.mouseButton.y);
                    Particle m_particles(m_Window, numPoints, position);//This needs help I don't think I'm doing it right
                }
            }
        }
    }
}

void Engine::update(float dtAsSeconds) {
    for(int i = 0; i < m_particles; i++){
        m_particles.update(m_particles.at(i)); //what is going on here
    }
}

voide Engine::draw() {

}
