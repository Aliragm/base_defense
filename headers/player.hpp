#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.hpp"
#include <vector>

class Enemy;

class Player    {
    private:
        float life;
        float xp;
        int ammo;
        sf::Vector2f velocity;
        Bullet b1;
        std::vector<Bullet> bullets;
        sf::CircleShape PlayerShape;
        sf::RectangleShape Hitbox;
        sf::Sprite PlayerSprite;
        sf::Texture PlayerTexture;
        bool up;
        bool down;
        bool left;
        bool right;
        bool initTexture();

    public:
        Player();
        ~Player();
        sf::CircleShape show();
        sf::RectangleShape showHitbox();
        void processEvents(sf::Keyboard::Key key, bool isPressed);
        void updateVelocity();
        void checkCollisions();
        void shootBullet(sf::Vector2f aimDirNorm);
        void updateBullets(std::vector<Enemy> &enemies, float dt);
        void drawBullets(sf::RenderWindow &window);
        void takeDamage(float damage);
        bool isAlive();
};

#endif
