#pragma once

#include <SFML/Graphics.hpp>

class Planet{
private:
    Planet* Parent;
    float velocity;
    sf::CircleShape self;

public:
    sf::Vector2f prevFramePos;
    Planet();
    Planet(sf::Color& color, Planet* parent,
        float radius, sf::Vector2f pos, float vel);

    void update(float deltaTime);
    void draw(sf::RenderWindow& w);
    sf::Vector2f getPos();
    sf::Vector2f moveDistance();
    void flipVelocity();
    bool pressed(sf::Vector2i& coord);
};
