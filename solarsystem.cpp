#include "solarsystem.hpp"
#include <iostream>

Solarsystem::Solarsystem(bool makePrefab){

    planetCount = 0;
    if(makePrefab){

        float sunRad = WINDOW_X/12;
        sf::Vector2f sunPos(WINDOW_X/2, WINDOW_Y/2);
        sf::Color sunCol = sf::Color::Yellow;
        Planet* sun;
        sun = new Planet(sunCol, nullptr, sunRad, sunPos, 0);
        addPlanet(sun);

        float earthRad = WINDOW_X/50;
        sf::Vector2f earthPos(WINDOW_X/3.5, WINDOW_Y/3.5);
        sf::Color earthCol = sf::Color::Blue;
        Planet* earth;
        earth = new Planet(earthCol, sun, earthRad, earthPos, 1);
        addPlanet(earth);

        float moonRad = WINDOW_X/80;
        sf::Vector2f moonPos(WINDOW_X/5, WINDOW_Y/5);
        sf::Color moonCol = sf::Color::White;
        Planet* moon;
        moon = new Planet(moonCol, earth, moonRad, moonPos, -2);
        addPlanet(moon);

        float moonmoonRad = WINDOW_X/150;
        sf::Vector2f  moonmoonPos(WINDOW_X/4.5, WINDOW_Y/4.5);
        sf::Color moonmoonCol = sf::Color::Green;
        Planet* moonmoon;
        moonmoon = new Planet(moonmoonCol, moon, moonmoonRad, moonmoonPos, 40);
        addPlanet(moonmoon);

    }
}

void Solarsystem::update(float deltaTime){

    for(int i = 0; i < planetCount; i++){
        planets[i]->update(deltaTime);
    }

}

void Solarsystem::draw(sf::RenderWindow& w){

    for(int i = 0; i < planetCount; i++){
        planets[i]->draw(w);
    }
}

void Solarsystem::addPlanet(Planet* p){
    // TODO: check if already contained
    // TODO: check parents for child
    if(planetCount < MAXPLANET){
        planets[planetCount++] = p;
    }
}

void Solarsystem::pressedPlanet(sf::Vector2i& coord){
    bool found  = false;
    int count   = 0;
    while(!found && count < planetCount){
        found = planets[count++]->pressed(coord);
    }
    if(found){
        planets[count-1]->flipVelocity();
    }
}
