#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class bullet {
private:
    float damage;
    sf::Vector2f velocity;
    float maxSpeed;
    sf::RectangleShape bulletShape;
public:
    bullet();
    sf::RectangleShape& show();
    void receiveVelocity(sf::Vector2f velocityReceived);
    float showMaxspeed();
    sf::Vector2f showSpeed();
    void update();
};

bullet::bullet() {
    this->damage = 50.f;
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->maxSpeed = 2.f;
    this->bulletShape.setSize(sf::Vector2f(10.0f, 10.0f));
    this->bulletShape.setOrigin(sf::Vector2f(5.0f, 5.0f)); // Ajustar a origem para o novo tamanho
    this->bulletShape.setFillColor(sf::Color::Yellow);
    this->bulletShape.setOutlineThickness(1.f);
    this->bulletShape.setOutlineColor(sf::Color::Black);
}

sf::RectangleShape& bullet::show() {
    return this->bulletShape;
}

void bullet::receiveVelocity(sf::Vector2f velocityReceived){
    this->velocity = velocityReceived;
}

float bullet::showMaxspeed(){
    return this->maxSpeed;
}

sf::Vector2f bullet::showSpeed(){
    return this->velocity;
}

void bullet::update() {
    this->bulletShape.move(this->velocity);
}

#endif
