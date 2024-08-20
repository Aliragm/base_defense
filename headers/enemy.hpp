#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.hpp"
#include "drops.hpp"

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
    ~Enemy();
    sf::RectangleShape& show();
    static std::vector<Enemy>& showVector();
    static void Spawner();
    void UpdateVelocity(float dt,  sf::Vector2f aimDirNormEnemy);
    static void DrawEnemies(sf::RenderWindow& window);
    const sf::Vector2f& showPos();
    void shoot(sf::Vector2f aimDirNormEnemy, float dt);
    void updateBulletsEnemy(float dt);
    void drawBulletsEnemy(sf::RenderWindow& window);
    drop& showDrop();
};

#endif
