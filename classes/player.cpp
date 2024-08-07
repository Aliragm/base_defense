#include "../headers/player.hpp"

Player::Player()    {
    this->life = 100;
    this->xp = 0;
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->ammo = 10; // à definir
    this->up = false;
    this->down = false;
    this->left = false;
    this->right = false;
    this->PlayerShape.setRadius(20.f);
    this->PlayerShape.setOrigin(sf::Vector2f(20.f, 20.f));
    this->PlayerShape.setPosition(sf::Vector2f(400.f, 300.f));
    this->PlayerShape.setFillColor(sf::Color::Red);
}

Player::~Player()   {}

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
        Bullet newBullet;
        newBullet.show().setPosition(this->PlayerShape.getPosition());
        newBullet.receiveVelocity(aimDirNorm * newBullet.showMaxspeed());
        bullets.push_back(newBullet);
        this->ammo -= 1;
    }
}

void Player::updateBullets(std::vector<Enemy> &enemies, float dt) {
    // Remover balas que saíram da tela
    for (size_t i = 0; i < bullets.size(); ) {
        bullets[i].update(dt);
        if (bullets[i].show().getPosition().x < 0 || bullets[i].show().getPosition().x > 800.f
            || bullets[i].show().getPosition().y < 0 || bullets[i].show().getPosition().y > 600.f) {
            bullets.erase(bullets.begin() + i);
        } else {
            // Verificar colisão com inimigos
            bool bulletRemoved = false;
            for (size_t k = 0; k < enemies.size(); ++k) {
                if (bullets[i].show().getGlobalBounds().intersects(enemies[k].show().getGlobalBounds())) {
                    bullets.erase(bullets.begin() + i);
                    enemies.erase(enemies.begin() + k);
                    bulletRemoved = true;
                    break;
                }
            }
            if (!bulletRemoved) {
                ++i;
            }
        }
    }
}


void Player::drawBullets(sf::RenderWindow &window)  {
    for(size_t i = 0; i < bullets.size(); ++i)  {
        window.draw(bullets[i].show());
    }
}