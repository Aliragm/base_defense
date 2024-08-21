#include "../headers/enemy.hpp"
#include <cmath>

std::vector<Enemy> Enemy::enemies;
sf::Clock Enemy::spawnClock; // Inicializa o relógio
int Enemy::spawnCounter = 0;
std::vector<Bullet> Enemy::bullets;

Enemy::Enemy() {
    this->life = 100.f;
    this->enemyShape.setSize(sf::Vector2f(20.0f, 20.0f)); // Ajuste de tamanho para melhor visualização
    this->enemyShape.setOrigin(10.f, 10.f);
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->maxSpeed = 100.f;
    this->shootClock.restart();
    this->dropEnemy.chooseDrop();
    this->enemyShape.setFillColor(sf::Color::Green);
    this->enemyShape.setOutlineThickness(1.f);
    this->enemyShape.setOutlineColor(sf::Color::Black);
}

Enemy::Enemy(sf::Texture *enemyTexture) {
    this->life = 100.f;
    this->enemyShape.setSize(sf::Vector2f(40.0f, 40.0f)); // Ajuste de tamanho para melhor visualização
    this->enemyShape.setOrigin(20.f, 20.f);
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->maxSpeed = 100.f;
    this->shootClock.restart();
    this->dropEnemy.chooseDrop();
    this->enemyShape.setTexture(enemyTexture);
}

Enemy::~Enemy() {}

sf::RectangleShape& Enemy::show() {
    return this->enemyShape;
}

std::vector<Enemy>& Enemy::showVector() {
    return enemies;
}

void Enemy::Spawner(sf::Texture *enemyTexture) {
    if (spawnClock.getElapsedTime().asSeconds() >= 2.0f && enemies.size() < 20) { // Verifica se passaram 2 segundos
        Enemy newEnemy(enemyTexture);
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

void Enemy::UpdateVelocity(float dt, sf::Vector2f aimDirNormEnemy){
    this->velocity = aimDirNormEnemy * this->maxSpeed;
    this->enemyShape.move(this->velocity * dt);
}

void Enemy::DrawEnemies(sf::RenderWindow& window) {
    for (std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        window.draw(it->show());
    }
}

const sf::Vector2f& Enemy::showPos() {
    return this->enemyShape.getPosition();
}

void Enemy::shoot(sf::Vector2f aimDirNormEnemy, float dt) {
    // Adicionei um intervalo de tempo para os disparos
    if (shootClock.getElapsedTime().asSeconds() >= 1.0f) { // Ajuste o intervalo conforme necessário
        Bullet newBullet(200, 50, sf::Color::Red);
        newBullet.show().setPosition(this->enemyShape.getPosition());
        newBullet.receiveVelocity(aimDirNormEnemy * newBullet.showMaxspeed());
        bullets.push_back(newBullet);
        shootClock.restart(); // Reinicia o relógio após disparar uma bala
    }
}

void Enemy::updateBulletsEnemy(float dt) {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ) {
        it->update(dt);
        if (it->show().getPosition().x < 0 || it->show().getPosition().x > 800.f
            || it->show().getPosition().y < 0 || it->show().getPosition().y > 600.f) {
            it = bullets.erase(it);
        } else {
            ++it;
        }
    }
}

void Enemy::drawBulletsEnemy(sf::RenderWindow& window) {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        window.draw(it->show());
    }
}

drop& Enemy::showDrop(){
    return this->dropEnemy;
}

void Enemy::lookAtPlayer(sf::RenderWindow& window, sf::Vector2f playerPos)   {
    sf::Vector2f position = this->enemyShape.getPosition();

    const float PI = 3.14159265;

    float dx = playerPos.x - position.x;
    float dy = playerPos.y - position.y;

    float rotation = (std::atan2(dy, dx) * 180) / PI + 90;

    this->enemyShape.setRotation(rotation);
}