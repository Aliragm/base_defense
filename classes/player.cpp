#include "../headers/player.hpp"
#include <cmath>

bool Player::initTexture()   {
    if (!this->PlayerTexture.loadFromFile("gfx/Ship.png"))
        return 1;
    
    if (!this->PlayerBullet.loadFromFile("gfx/Player_bullet.png"))
        return 1;

    this->PlayerShape.setTexture(&this->PlayerTexture);
    return 0;
}

Player::Player()    {
    this->life = 100;
    this->xp = 0;
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->ammo = 10; // à definir
    this->up = false;
    this->down = false;
    this->left = false;
    this->right = false;
    this->PlayerShape.setRadius(30.f);
    this->PlayerShape.setOrigin(sf::Vector2f(30.f, 30.f));
    this->PlayerShape.setPosition(sf::Vector2f(400.f, 300.f));
    this->MouseTarget.setRadius(5.f);
    this->MouseTarget.setOrigin(sf::Vector2f(2.5f, 2.5f));
    this->MouseTarget.setFillColor(sf::Color::Cyan);
    this->MouseTarget.setOutlineColor(sf::Color::Black);
    this->initTexture();
}

Player::~Player()   {
    this->bullets.clear();
}

sf::CircleShape Player::show()  {
    return this->PlayerShape;
}

void Player::processEvents(sf::Keyboard::Key key, bool isPressed)   {
    if (key == sf::Keyboard::W) {
        this->up = isPressed;
    }
    if (key == sf::Keyboard::S) {
        this->down = isPressed;
    }
    if (key == sf::Keyboard::A) {
        this->left = isPressed;
    }
    if (key == sf::Keyboard::D) {
        this->right = isPressed;
    }
}

void Player::updateVelocity()   {
    this->velocity = sf::Vector2f(0.f, 0.f);

    if(this->up)  {
        this->velocity.y -= 0.25f;
    }
    if(this->down)    {
        this->velocity.y += 0.25f;
    }
    if(this->left)    {
        this->velocity.x -= 0.25f;
    }
    if(this->right)   {
        this->velocity.x += 0.25f;
    }
    this->PlayerShape.move(velocity);
}

void Player::checkCollisions()  {
    if(this->PlayerShape.getPosition().x < 20.f)    {
        this->PlayerShape.setPosition(20.f, this->PlayerShape.getPosition().y); // Teleporta o shape para a direita se ultrapassar o limite esquerdo
    }
    if(this->PlayerShape.getPosition().x > 780.f)   {
        this->PlayerShape.setPosition(780.f, this->PlayerShape.getPosition().y); // Teleporta o shape para a esquerda se ultrapassar o limite direito
    }
    if(this->PlayerShape.getPosition().y < 20.f)    {
        this->PlayerShape.setPosition(this->PlayerShape.getPosition().x, 20.f);
    }
    if(this->PlayerShape.getPosition().y > 580.f)   {
        this->PlayerShape.setPosition(this->PlayerShape.getPosition().x, 580.f);
    }
}

void Player::shootBullet(sf::Vector2f aimDirNorm)   {
    if(ammo == 0){
        std::cout << "n tem bala" << std::endl;
        return;
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Bullet newBullet(500, 50, &this->PlayerBullet);
        newBullet.show().setPosition(this->PlayerShape.getPosition());
        newBullet.receiveVelocity(aimDirNorm * newBullet.showMaxspeed());
        bullets.push_back(newBullet);
        this->ammo -= 1;
    }
}

void Player::updateBullets(std::vector<Enemy> &enemies, float dt, sf::Texture *DropTextures) {
    for (std::vector<Bullet>::iterator bulletIt = bullets.begin(); bulletIt != bullets.end(); ) {
        bulletIt->update(dt);
        if (bulletIt->show().getPosition().x < 0 || bulletIt->show().getPosition().x > 800.f
            || bulletIt->show().getPosition().y < 0 || bulletIt->show().getPosition().y > 600.f) {
            bulletIt = bullets.erase(bulletIt);
        } else {
            bool bulletRemoved = false;
            for (std::vector<Enemy>::iterator enemyIt = enemies.begin(); enemyIt != enemies.end(); ++enemyIt) {
                if (bulletIt->show().getGlobalBounds().intersects(enemyIt->show().getGlobalBounds())) {
                    bulletIt = bullets.erase(bulletIt);
                    enemyIt->showDrop().spawn(enemyIt->show().getPosition(), enemyIt->showDrop(), DropTextures);
                    enemies.erase(enemyIt);
                    bulletRemoved = true;
                    break;
                }
            }
            if (!bulletRemoved) {
                ++bulletIt;
            }
        }
    }
}

void Player::drawBullets(sf::RenderWindow &window)  {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        window.draw(it->show());
    }
}

void Player::lookAtMouse(sf::RenderWindow &window){
    sf::Vector2f position = this->PlayerShape.getPosition();
    sf::Vector2i curPos = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (std::atan2(dy, dx) * 180) / PI + 90;

    this->PlayerShape.setRotation(rotation);
}

sf::Vector2f Player::getPosition()  {
    return this->PlayerShape.getPosition();
}

float Player::showLife(){
    return this->life;
}

float Player::showAmmo(){
    return this->ammo;
}

float Player::showXp(){
    return this->xp;
}

void Player::updateAim(sf::RenderWindow& window){
    this->MouseTarget.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
}

void Player::drawAim(sf::RenderWindow& window){
    window.draw(this->MouseTarget);
}
