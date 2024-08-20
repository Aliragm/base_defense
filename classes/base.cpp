#include "../headers/base.hpp"

bool Base::initTexture()   {
    if (!this->BaseTexture.loadFromFile("gfx/Base.png"))
        return 1;

    this->structure.setTexture(&this->BaseTexture);
    return 0;
}

Base::Base()    {
    this->health = 100.f;
    this->structure.setSize(sf::Vector2f(250.f, 250.f));
    this->structure.setOrigin(sf::Vector2f(125.f, 125.f));
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
