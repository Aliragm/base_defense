#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include <vector>

class Player {
private:
    float life;
    float xp;
    float cadence;
    sf::Vector2f velocity;
    bullet b1;
    std::vector<bullet> bullets;
    int ammo;
    sf::CircleShape PlayerShape;
    bool up;
    bool down;
    bool left;
    bool right;

public:
    Player();
    ~Player();
    sf::CircleShape show();
    void processEvents(sf::Keyboard::Key key, bool isPressed);
    void updateVelocity();
    void checkCollisions();
    void startAmmo();
    void shootBullet(sf::Vector2f aimDirNorm);
    void updateBullets();
    void drawBullets(sf::RenderWindow &window);
};

Player::Player(){
    this->life = 100;
    this->xp = 0;
    this->cadence = 0; // à definir
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->ammo = 10; // à definir
    this->up = false;
    this->down = false;
    this->left = false;
    this->right = false;
    this->PlayerShape.setRadius(20.f);
    this->PlayerShape.setOrigin(sf::Vector2f(20.f, 20.f));
    this->PlayerShape.setPosition(sf::Vector2f(400.f, 300.f));
    this->PlayerShape.setFillColor(sf::Color::Red);
}

Player::~Player(){
}

sf::CircleShape Player::show(){
    return this->PlayerShape;
}

void Player::processEvents(sf::Keyboard::Key key, bool isPressed){
    if (key == sf::Keyboard::W){
        this->up = isPressed;
    }
    if (key == sf::Keyboard::S){
        this->down = isPressed;
    }
    if (key == sf::Keyboard::A){
        this->left = isPressed;
    }
    if (key == sf::Keyboard::D){
        this->right = isPressed;
    }
}

void Player::updateVelocity(){
    this->velocity = sf::Vector2f(0.f, 0.f);

    if(up){
        this->velocity.y -= 0.25f;
    }
    if(down){
        this->velocity.y += 0.25f;
    }
    if(left){
        this->velocity.x -= 0.25f;
    }
    if(right){
        this->velocity.x += 0.25f;
    }
    this->PlayerShape.move(velocity);
}

void Player::checkCollisions(){
    if(this->PlayerShape.getPosition().x < 20.f){
        this->PlayerShape.setPosition(20.f, this->PlayerShape.getPosition().y); // Teleporta o shape para a direita se ultrapassar o limite esquerdo
    }
    if(this->PlayerShape.getPosition().x > 780.f){
        this->PlayerShape.setPosition(780.f, this->PlayerShape.getPosition().y); // Teleporta o shape para a esquerda se ultrapassar o limite direito
    }
    if(this->PlayerShape.getPosition().y < 20.f){
        this->PlayerShape.setPosition(this->PlayerShape.getPosition().x, 20.f);
    }
    if(this->PlayerShape.getPosition().y > 580.f){
        this->PlayerShape.setPosition(this->PlayerShape.getPosition().x, 580.f);
    }
}

void Player::startAmmo(){
    this->bullets.push_back(this->b1);
}

void Player::shootBullet(sf::Vector2f aimDirNorm){
    if(ammo == 0){
        std::cout << "n tem bala" << std::endl;
        return;
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        bullet newBullet;
        newBullet.show().setPosition(this->PlayerShape.getPosition());
        newBullet.receiveVelocity(aimDirNorm * newBullet.showMaxspeed());
        bullets.push_back(newBullet);
        this->ammo -= 1;
    }
}

void Player::updateBullets() {
    for(size_t i = 0; i < bullets.size(); ++i) {
        bullets[i].update();
    }
}

void Player::drawBullets(sf::RenderWindow &window) {
    for(size_t i = 0; i < bullets.size(); ++i) {
        window.draw(bullets[i].show());
    }
}

#endif