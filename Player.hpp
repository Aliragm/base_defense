#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
private:
    float life;
    float xp;
    float cadence;
    sf::Vector2f velocity;
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
    if (key == sf::Keyboard::Up){
        this->up = isPressed;
    }
    if (key == sf::Keyboard::Down){
        this->down = isPressed;
    }
    if (key == sf::Keyboard::Left){
        this->left = isPressed;
    }
    if (key == sf::Keyboard::Right){
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

#endif