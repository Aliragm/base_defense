#include "../headers/enemy.hpp"

std::vector<Enemy> Enemy::enemies;
sf::Clock Enemy::spawnClock; // Inicializa o relógio
int Enemy::spawnCounter = 0;

Enemy::Enemy() {
    this->life = 100.f;
    this->enemyShape.setSize(sf::Vector2f(20.0f, 20.0f)); // Ajuste de tamanho para melhor visualização
    this->enemyShape.setFillColor(sf::Color::Green);
    this->enemyShape.setOutlineThickness(1.f);
    this->enemyShape.setOutlineColor(sf::Color::Black);
    this->enemyShape.setOrigin(20.f, 20.f);
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->shootClock.restart();
}

Enemy::~Enemy() {}

sf::RectangleShape& Enemy::show() {
    return this->enemyShape;
}

std::vector<Enemy>& Enemy::showVector() {
    return enemies;
}

void Enemy::Spawner() {
    if (spawnClock.getElapsedTime().asSeconds() >= 2.0f && enemies.size() < 20) { // Verifica se passaram 2 segundos
        Enemy newEnemy;
        int retangleSide = std::rand() % 4;

        //  Escolhe um dos 4 lados da tela aleatóriamente para spawnar
        if (retangleSide == 0)  {
            newEnemy.show().setPosition(sf::Vector2f(0, std::rand() % 600));
            enemies.push_back(newEnemy);
            spawnClock.restart();   // Reinicia o relógio após spawnar um inimigo
        }
        else if (retangleSide == 1)  {
            newEnemy.show().setPosition(sf::Vector2f(std::rand() % 800, 0));
            enemies.push_back(newEnemy);
            spawnClock.restart();
        }
        else if (retangleSide == 2)  {
            newEnemy.show().setPosition(sf::Vector2f(820, std::rand() % 600));
            enemies.push_back(newEnemy);
            spawnClock.restart();
        }
        else if (retangleSide == 3) {
            newEnemy.show().setPosition(sf::Vector2f(std::rand() % 800, 620));
            enemies.push_back(newEnemy);
            spawnClock.restart();
        }
    }
}

void Enemy::DrawEnemies(sf::RenderWindow& window) {
    for (size_t i = 0; i < enemies.size(); ++i) {
        window.draw(enemies[i].show());
    }
}

const sf::Vector2f& Enemy::showPos() {
    return this->enemyShape.getPosition();
}

void Enemy::shoot(sf::Vector2f aimDirNormEnemy, float dt) {
    // Adicionei um intervalo de tempo para os disparos
    if (shootClock.getElapsedTime().asSeconds() >= 1.0f) { // Ajuste o intervalo conforme necessário
        Bullet newBullet(sf::Color::Red);
        newBullet.show().setPosition(this->enemyShape.getPosition());
        newBullet.receiveVelocity(aimDirNormEnemy * newBullet.showMaxspeed());
        bullets.push_back(newBullet);
        shootClock.restart(); // Reinicia o relógio após disparar uma bala
    }
}

void Enemy::updateBulletsEnemy(float dt) {
    for (size_t i = 0; i < bullets.size(); ++i) {
        bullets[i].update(dt);
        if (bullets[i].show().getPosition().x < 0 || bullets[i].show().getPosition().x > 800.f
            || bullets[i].show().getPosition().y < 0 || bullets[i].show().getPosition().y > 600.f) {
            bullets.erase(bullets.begin() + i);
            i--;
        }
    }
}

void Enemy::drawBulletsEnemy(sf::RenderWindow& window) {
    for (size_t i = 0; i < bullets.size(); ++i) {
        window.draw(bullets[i].show());
    }
}
