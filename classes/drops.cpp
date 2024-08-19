#include "../headers/drops.hpp"
#include <iostream>

// Inicialização do vetor estático
std::vector<drop> drop::drops;

drop::drop(){
    this->life = 20;
    this->ammo = 5;
    this->xp = 10;
    this->isAmmo = false;
    this->isXp = false;
    this->isLife = false;
    this->dropShape.setSize(sf::Vector2f(10.f, 10.f));
    this->dropShape.setFillColor(sf::Color::Black);
    this->dropShape.setOutlineColor(sf::Color::Red);
    this->lifeClock.restart();
}

drop::~drop(){}

sf::RectangleShape& drop::show(){
    return this->dropShape;
}

void drop::chooseDrop(){
    // Reseta todos os tipos de drop antes de escolher
    this->isAmmo = false;
    this->isXp = false;
    this->isLife = false;

    // Escolhe o tipo de drop
    int choice = std::rand() % 3;
    switch (choice){
    case 0: 
        this->isAmmo = true; 
        this->dropShape.setFillColor(sf::Color::Blue); // Diferenciar visivelmente
        break;
    case 1: 
        this->isXp = true; 
        this->dropShape.setFillColor(sf::Color::Green);
        break;
    case 2: 
        this->isLife = true; 
        this->dropShape.setFillColor(sf::Color::Red);
        break;
    }
}

void drop::spawn(sf::Vector2f pos, drop newDrop){
    newDrop.chooseDrop(); // Escolha o tipo do drop antes de colocá-lo no jogo
    newDrop.lifeClock.restart();
    newDrop.dropShape.setPosition(pos);
    drops.push_back(newDrop);
}

void drop::drawDrops(sf::RenderWindow& window){
    for (std::vector<drop>::iterator it = drops.begin(); it != drops.end(); ++it) {
        window.draw(it->show());
    }
}

float drop::checkTime(){
    return this->lifeClock.getElapsedTime().asSeconds();
}

void drop::checkUndraw(){
    for (std::vector<drop>::iterator it = drops.begin(); it != drops.end(); ) {
        if (it->checkTime() >= 5.0f) {
            it = drops.erase(it);
        } else {
            ++it;
        }
    }
}

std::vector<drop>& drop::showVector(){
    return this->drops;
}
