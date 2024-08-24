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
    this->dropShape.setSize(sf::Vector2f(30.0f, 30.0f));
    this->lifeClock.restart();
}

drop::~drop(){}

sf::RectangleShape& drop::show(){
    return this->dropShape;
}

void drop::chooseDrop(sf::Texture* DropTextures){
    // Reseta todos os tipos de drop antes de escolher
    this->isAmmo = false;
    this->isXp = false;
    this->isLife = false;

    // Escolhe o tipo de drop
    int choice = std::rand() % 3;
    switch (choice){
    case 0: 
        this->isAmmo = true; 
        this->dropShape.setSize(sf::Vector2f(9.0f, 30.0f));
        this->dropShape.setTexture(&DropTextures[0]); // Diferenciar visivelmente
        break;
    case 1: 
        this->isXp = true; 
        this->dropShape.setSize(sf::Vector2f(28.0f, 28.0f));
        this->dropShape.setTexture(&DropTextures[1]);
        break;
    case 2: 
        this->isLife = true; 
        this->dropShape.setSize(sf::Vector2f(32.0f, 32.0f));
        this->dropShape.setTexture(&DropTextures[2]);
        break;
    }
}

void drop::spawn(sf::Vector2f pos, drop newDrop, sf::Texture* DropTextures){
    newDrop.chooseDrop(DropTextures); // Escolha o tipo do drop antes de colocá-lo no jogo
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

int drop::showDropType(){
    if(this->isAmmo){
        return 1;
    }
    else if(this->isLife){
        return 2;
    }
    else if(this->isXp){
        return 3;
    }

    return 0;
}

void drop::isTaken(Player& Player){
    for (std::vector<drop>::iterator it = drops.begin(); it != drops.end(); ) {
        if(Player.showHitbox().getGlobalBounds().intersects(it->show().getGlobalBounds())){
            Player.receiveDrop(it->showDropType());
            it = drops.erase(it);
        }
        else{
            it++;
        }
    }
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
