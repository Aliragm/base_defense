#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.hpp"
#include "enemy.hpp"
#include <vector>

class Player    {
    private:
        float life;
        float xp;
        sf::Vector2f velocity;
        Bullet b1;
        std::vector<Bullet> bullets;
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
        void shootBullet(sf::Vector2f aimDirNorm);
        void updateBullets(std::vector<Enemy> &enemies, float dt);
        void drawBullets(sf::RenderWindow &window);
};

#endif
