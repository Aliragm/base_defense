#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>

class Enemy {
private:
    float life;
    sf::RectangleShape enemyShape;
    static std::vector<Enemy> enemies;
    static sf::Clock spawnClock; // Adiciona um relógio para medir o tempo entre spawns
    static int spawnCounter;
public:
    Enemy();
    ~Enemy();
    sf::RectangleShape& show();
    static std::vector<Enemy>& showVector();
    //dentro do gameloop
    static void Spawner();
    static void DrawEnemies(sf::RenderWindow &window);
};

std::vector<Enemy> Enemy::enemies;
sf::Clock Enemy::spawnClock; // Inicializa o relógio
int Enemy::spawnCounter = 0;

Enemy::Enemy() {
    this->life = 100.f;
    this->enemyShape.setSize(sf::Vector2f(20.0f, 20.0f)); // Ajuste de tamanho para melhor visualização
    this->enemyShape.setFillColor(sf::Color::Green);
    this->enemyShape.setOutlineThickness(1.f);
    this->enemyShape.setOutlineColor(sf::Color::Black);
}

Enemy::~Enemy() {
}

sf::RectangleShape& Enemy::show(){
    return this->enemyShape;
}

std::vector<Enemy>& Enemy::showVector(){
    return enemies;
}

void Enemy::Spawner(){
    if (spawnClock.getElapsedTime().asSeconds() >= 2.0f && enemies.size() < 20) { // Verifica se passaram 5 segundos
        Enemy newEnemy;
        newEnemy.show().setPosition(sf::Vector2f(std::rand() % 800, std::rand() % 600));
        enemies.push_back(newEnemy);
        spawnClock.restart(); // Reinicia o relógio após spawnar um inimigo
    }
}

void Enemy::DrawEnemies(sf::RenderWindow &window){
    for(size_t i = 0; i < enemies.size(); ++i) {
        window.draw(enemies[i].show());
    }
}

#endif
