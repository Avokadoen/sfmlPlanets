#include "planet.hpp"
#include "globals.hpp"
#include <iostream>

Planet::Planet(){
    Parent = nullptr;
    prevFramePos = sf::Vector2f(0,0);
}

Planet::Planet(sf::Color& color, Planet* parent,
    float radius, sf::Vector2f pos, float vel){
  self.setFillColor(color);
  self.setOrigin(radius, radius);
  self.setRadius(radius);
  self.setPosition(pos);
  Parent = parent;
  //childs = 0;
  prevFramePos = pos;
  velocity = ONE_RAD * vel;
}

void Planet::update(float deltaTime){
    if(Parent){
        prevFramePos = getPos();

        self.move(Parent->moveDistance());

        sf::Vector2f selfVector = self.getPosition() - Parent->getPos();

        sf::Vector2f rotation;
        float rotAmount = velocity * deltaTime;

        // rotate pos vector
        rotation.x = (selfVector.x * cos(rotAmount)) - (selfVector.y * sin(rotAmount));
        rotation.y = (selfVector.x * sin(rotAmount)) + (selfVector.y * cos(rotAmount));

        // set self pos
        sf::Vector2f newPos = rotation + Parent->getPos();

        self.setPosition(newPos);

    }
}

void Planet::draw(sf::RenderWindow& w){
    w.draw(self);
}

sf::Vector2f Planet::getPos(){
    return self.getPosition();
}

sf::Vector2f Planet::moveDistance(){
    return getPos() - prevFramePos;
}

void Planet::flipVelocity(){
    velocity *= -1;
}
//&& diff.y >= -rad && diff.y <= rad
bool Planet::pressed(sf::Vector2i& coord){
    sf::Vector2f pos = getPos();;
    float rad = self.getRadius();
    std::cout << rad << " ";
    if( coord.x >= pos.x - rad && coord.x <= pos.x + rad && 
        coord.y >= pos.y - rad && coord.y <= pos.y + rad ) {
        std::cout << "hello";
        return true;
    }
    std::cout << "goodbye" << std::endl;
    return false;

}
