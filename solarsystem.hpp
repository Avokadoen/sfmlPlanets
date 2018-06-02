#pragma once
#include "planet.hpp"
#include "globals.hpp"
#include <SFML/Graphics.hpp>

class Solarsystem{
private:
    //std::vector<Planet> planets;
    Planet* planets[MAXPLANET];
    int family[MAXPLANET][MAXPLANET-1];
    int planetCount;
public:
    /*
    *@param: make hardcoded system if true
    */
    Solarsystem(bool makePrefab);
    void update(float deltaTime);
    void draw(sf::RenderWindow& w);
    void addPlanet(Planet* p);
    void pressedPlanet(sf::Vector2i& coord);

};
