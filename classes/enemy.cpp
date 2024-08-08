#include "../headers/enemy.hpp"

std::vector <Enemy> Enemy::enemies;
sf::Clock Enemy::spawnClock; // Inicializa o relógio
int Enemy::spawnCounter = 0;

Enemy::Enemy()  {
    this->life = 100.f;
    this->enemyShape.setSize(sf::Vector2f(20.0f, 20.0f)); // Ajuste de tamanho para melhor visualização
    this->enemyShape.setFillColor(sf::Color::Green);
    this->enemyShape.setOutlineThickness(1.f);
    this->enemyShape.setOutlineColor(sf::Color::Black);
    this->velocity = sf::Vector2f(0.f, 0.f);
}

Enemy::~Enemy() {}

sf::RectangleShape& Enemy::show()   {
    return this->enemyShape;
}

std::vector<Enemy>& Enemy::showVector() {
    return enemies;
}

void Enemy::Spawner()   {
    if (spawnClock.getElapsedTime().asSeconds() >= 2.0f && enemies.size() < 20) { // Verifica se passaram 5 segundos
        Enemy newEnemy;
        int retangleSide = std::rand() % 3 + 1;

        //  Escolhe um dos 4 lados da tela aleatóriamente para spawnar
        if (retangleSide == 1)  {
            newEnemy.show().setPosition(sf::Vector2f(-21, std::rand() % 600));
            enemies.push_back(newEnemy);
            spawnClock.restart();   // Reinicia o relógio após spawnar um inimigo
        }
        else if (retangleSide == 2)  {
            newEnemy.show().setPosition(sf::Vector2f(std::rand() % 800, -21));
            enemies.push_back(newEnemy);
            spawnClock.restart();
        }
        else if (retangleSide == 3)  {
            newEnemy.show().setPosition(sf::Vector2f(801, std::rand() % 600));
            enemies.push_back(newEnemy);
            spawnClock.restart();
        }
        else    {
            newEnemy.show().setPosition(sf::Vector2f(std::rand() % 800, 601));
            enemies.push_back(newEnemy);
            spawnClock.restart();
        }
    }
}

void Enemy::DrawEnemies(sf::RenderWindow &window)   {
    for(size_t i = 0; i < enemies.size(); ++i)  {
        window.draw(enemies[i].show());
    }
}