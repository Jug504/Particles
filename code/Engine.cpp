#include "Engine.h"

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

