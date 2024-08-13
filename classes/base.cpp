#include "../headers/base.hpp"

Base::Base()    {
    this->health = 1000.f;
    this->structure.setSize(sf::Vector2f(250.f, 250.f));
    this->structure.setOrigin(sf::Vector2f(125.f, 125.f));
    this->structure.setPosition(sf::Vector2f(400.f, 300.f));
    this->structure.setFillColor(sf::Color::Transparent);
    this->structure.setOutlineThickness(15.f);
    this->structure.setOutlineColor(sf::Color::Green);
}

Base::~Base()   {}

sf::RectangleShape Base::show() {
    return this->structure;
}

void Base::takeDamage(float damage){
    this->health -= damage;
}

bool Base::isAlive(){
    if(health <= 0){
        return false;
    }
    else{
        return true;
    }
}
