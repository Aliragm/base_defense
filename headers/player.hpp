#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.hpp"
#include "enemy.hpp"
#include <vector>

class Player    {
    private:
        float xp;
        int ammo;
        float life;
        sf::Vector2f velocity;
        Bullet b1;
        std::vector<Bullet> bullets;
        sf::CircleShape PlayerShape;
        sf::CircleShape MouseTarget;
        sf::Texture PlayerTexture;
        sf::Texture PlayerBullet;
        bool up;
        bool down;
        bool left;
        bool right;
        bool initTexture();

    public:
        Player();
        ~Player();
        sf::CircleShape show();
        float showLife();
        float showXp();
        float showAmmo();
        void processEvents(sf::Keyboard::Key key, bool isPressed);
        void updateVelocity();
        void checkCollisions();
        void shootBullet(sf::Vector2f aimDirNorm);
        void updateBullets(std::vector<Enemy> &enemies, float dt, sf::Texture *DropTextures);
        void drawBullets(sf::RenderWindow &window);
        void lookAtMouse(sf::RenderWindow &window);
        sf::Vector2f getPosition();
        void updateAim(sf::RenderWindow& window);
        void drawAim(sf::RenderWindow& window);
};

#endif
