#include "../headers/base.hpp"

bool Base::initTexture()   {
    if (!this->BaseTexture.loadFromFile("gfx/Base.png"))
        return 1;

    this->structure.setTexture(&this->BaseTexture);
    return 0;
}

Base::Base()    {
    this->health = 100.f;
    this->structure.setSize(sf::Vector2f(150.f, 150.f));
    this->structure.setOrigin(sf::Vector2f(75.f, 75.f));
    this->structure.setPosition(sf::Vector2f(400.f, 300.f));
    this->initTexture();
    this->structure.setTexture(&this->BaseTexture);
}

Base::~Base()   {}

sf::RectangleShape Base::show() {
    return this->structure;
}

float Base::showHealth(){
    return this->health;
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

void Base::getCured(){
    this->health = 1000.f;
}
