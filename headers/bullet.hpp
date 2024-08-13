#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet {
    private:
        float damage;
        sf::Vector2f velocity;
        float maxSpeed;
        sf::RectangleShape bulletShape;
        bool isEnemy;
    public:
        Bullet();
        Bullet(float maxSpeed, float damage, sf::Color color = sf::Color::Yellow, bool isEnemy = false);
        sf::RectangleShape& show();
        void receiveVelocity(sf::Vector2f velocityReceived);
        float showMaxspeed();
        float showDamage();
        bool showIsEnemy();
        sf::Vector2f showSpeed();
        void update(float dt);
};

#endif
