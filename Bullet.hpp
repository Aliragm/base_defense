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
    this->maxSpeed = 2.f; // Reduzindo a velocidade máxima
    this->bulletShape.setSize(sf::Vector2f(10.0f, 10.0f)); // Aumenta o tamanho da bala
    this->bulletShape.setOrigin(sf::Vector2f(2.5f, 2.5f)); // Ajusta a origem ao novo tamanho
    this->bulletShape.setFillColor(sf::Color::Yellow);
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