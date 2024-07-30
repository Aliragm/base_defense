#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>

class Base : public sf::RectangleShape {
private:
    float health;
    sf::RectangleShape structure;

public:
    Base();
    ~Base();
    sf::RectangleShape show();
};

Base::Base()
{
    this->health = 100.f;
    this->structure.setSize(sf::Vector2f(250.f, 250.f));
    this->structure.setOrigin(sf::Vector2f(125.f, 125.f));
    this->structure.setPosition(sf::Vector2f(400.f, 300.f));
    this->structure.setFillColor(sf::Color::Transparent);
    this->structure.setOutlineThickness(15.f);
    this->structure.setOutlineColor(sf::Color::Green);
}

Base::~Base()
{
}

sf::RectangleShape Base::show(){
    return this->structure;
}

#endif