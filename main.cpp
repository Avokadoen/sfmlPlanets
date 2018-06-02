#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "solarsystem.hpp"
#include <iostream>

// TODO: Lag controller som flytter alle barn av planet

int main()
{
    sf::Clock clock;
    sf::Time time;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "SFML works!");

    float totalTime;
    float second;

    Solarsystem solarsystem(true);
    while (window.isOpen())
    {
        time = clock.restart();
        float deltaTime = 4 * time.asSeconds();
        sf::Event event;
        // while there are pending events...
        while (window.pollEvent(event)){
            switch (event.type){
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left){
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        std::cout << std::endl <<mousePosition.x << " " << mousePosition.y << std::endl;
                        solarsystem.pressedPlanet(mousePosition);
                    }
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }
        totalTime += deltaTime;
        second += deltaTime;
        if(second >= 1){
            second -= 1;
            //std::cout << totalTime << std::endl;
        }
        window.clear();

        solarsystem.update(deltaTime);
        solarsystem.draw(window);

        window.display();

    }

    return 0;
}
