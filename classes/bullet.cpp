#include "../headers/bullet.hpp"

Bullet::Bullet()    {
    this->damage = 50.f;
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->maxSpeed = 200.f; // Ajuste a velocidade para um valor razoável
    this->bulletShape.setSize(sf::Vector2f(10.0f, 10.0f));
    this->bulletShape.setOrigin(sf::Vector2f(5.0f, 5.0f)); // Ajustar a origem para o novo tamanho
    this->bulletShape.setFillColor(sf::Color::Yellow);
    this->bulletShape.setOutlineThickness(1.f);
    this->bulletShape.setOutlineColor(sf::Color::Black);
    this->isEnemy = false;
}

Bullet::Bullet(float maxSpeed, float damage, sf::Texture *BulletTexture, bool isEnemy) {
    this->damage = damage;
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->maxSpeed = maxSpeed; // Ajuste a velocidade para um valor razoável
    this->bulletShape.setSize(sf::Vector2f(10.0f, 10.0f));
    this->bulletShape.setOrigin(sf::Vector2f(5.0f, 5.0f)); // Ajustar a origem para o novo tamanho
    this->bulletShape.setTexture(BulletTexture);
    this->isEnemy = isEnemy;
}

sf::RectangleShape& Bullet::show()  {
    return this->bulletShape;
}

Bullet::~Bullet()   {}

void Bullet::receiveVelocity(sf::Vector2f velocityReceived){
    this->velocity = velocityReceived;
}

float Bullet::showMaxspeed()    {
    return this->maxSpeed;
}

sf::Vector2f Bullet::showSpeed()    {
    return this->velocity;
}

void Bullet::update(float dt) {
    this->bulletShape.move(this->velocity * dt);
}

float Bullet::showDamage(){
    return this->damage;
}

bool Bullet::showIsEnemy(){
    return this->isEnemy;
}
