#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet {
    private:
        float damage;
        sf::Vector2f velocity;
        float maxSpeed;
        sf::RectangleShape bulletShape;
        sf::Texture BulletTextures;
    public:
        Bullet();
        Bullet(float maxSpeed, float damage, sf::Texture *BulletTextures);
        ~Bullet();
        sf::RectangleShape& show();
        void receiveVelocity(sf::Vector2f velocityReceived);
        float showMaxspeed();
        sf::Vector2f showSpeed();
        void update(float dt);
};

#endif
