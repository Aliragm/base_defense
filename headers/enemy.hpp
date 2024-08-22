#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.hpp"
#include "drops.hpp"

class Player;
class Base;

class Enemy {
    private:
        float life;
        sf::RectangleShape enemyShape;
        sf::Vector2f velocity;
        float maxSpeed;
        static std::vector<Bullet> bullets;
        static std::vector<Enemy> enemies;
        static sf::Clock spawnClock; // Adiciona um relógio para medir o tempo entre spawns
        static int spawnCounter;
        sf::Clock shootClock;
        drop dropEnemy;
    public:
        Enemy();
        Enemy(sf::Texture *enemyTexture);
        ~Enemy();
        sf::RectangleShape& show();
        static std::vector<Enemy>& showVector();
        static void Spawner(sf::Texture *enemyTexture);
        void UpdateVelocity(float dt,  sf::Vector2f aimDirNormEnemy);
        static void DrawEnemies(sf::RenderWindow& window);
        const sf::Vector2f& showPos();
        void shoot(sf::Vector2f aimDirNormEnemy, float dt, sf::Texture *EnemyBullet);
        void updateBulletsEnemy(float dt, Player& player, Base& base);
        void clearAll();
        void drawBulletsEnemy(sf::RenderWindow& window);
        drop& showDrop();
        void lookAtPlayer(sf::RenderWindow& window, sf::Vector2f playerPos);
};

#endif
