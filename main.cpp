#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "headers/base.hpp"
#include "headers/player.hpp"
#include "headers/enemy.hpp"
#include "headers/drops.hpp"

int main() {
    std::srand(time(NULL));
    // Variáveis
    sf::RenderWindow window(sf::VideoMode(800, 600), "BaseDefense");
    sf::RectangleShape Background(sf::Vector2f(800.f, 600.f));
    Background.setFillColor(sf::Color::White);
    sf::Texture BackgroundTexture;
    BackgroundTexture.loadFromFile("gfx/Background.png");
    Background.setTexture(&BackgroundTexture);
    sf::Music game_music;
    game_music.openFromFile("gfx/game_music.ogg");
    game_music.setLoop(true);
    game_music.setVolume(50.f);
    game_music.play();
    Base Base;
    Player Player;
    Enemy Enemies;
    drop drops;
    // Vetores
    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    sf::Vector2f aimDirEnemy;
    sf::Vector2f aimDirNormEnemy;
    sf::Vector2f aimDirEnemyMov;
    sf::Vector2f aimDirNormEnemyMov;

    sf::Clock clock;

    // Loop do jogo
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        // Atualização
        if(!Player.isAlive()){
            std::cout << "game over, morreu" << std::endl;
            window.close();
        }
        if(!Base.isAlive()){
            std::cout << "game over, base morreu" << std::endl;
            window.close();
        }
        Player.lookAtMouse(window);
        Player.updateVelocity();
        Player.checkCollisions();
        Player.updateBullets(Enemies.showVector(), dt);
        for (std::vector<Enemy>::iterator it = Enemies.showVector().begin(); it != Enemies.showVector().end(); ++it) {
            it->updateBulletsEnemy(dt, Player, Base);
        }

        playerCenter = Player.show().getPosition();
        mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
        aimDir = mousePosWindow - playerCenter;
        float length = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
        aimDirNorm = aimDir / length;

        // Inimigos atiram
        if (!Enemies.showVector().empty()) {
            for (std::vector<Enemy>::iterator it = Enemies.showVector().begin(); it != Enemies.showVector().end(); ++it) {
                aimDirEnemy = playerCenter - it->showPos();
                float lengthEnemy = sqrt(pow(aimDirEnemy.x, 2) + pow(aimDirEnemy.y, 2));
                if (lengthEnemy != 0) {
                    aimDirNormEnemy = aimDirEnemy / lengthEnemy;
                }
                it->shoot(aimDirNormEnemy, dt);
            }
        }

        // Eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                Player.processEvents(event.key.code, true);
            }
            if (event.type == sf::Event::KeyReleased) {
                Player.processEvents(event.key.code, false);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                Player.shootBullet(aimDirNorm);
            }
        }

        // Desenho
        window.clear();
        window.draw(Background);
        window.draw(Base.show());
        Enemies.Spawner(); // Chama o Spawner para criar os inimigos
        Enemies.DrawEnemies(window); // Desenha os inimigos na janela
        Player.drawBullets(window);
        for (std::vector<Enemy>::iterator it = Enemies.showVector().begin(); it != Enemies.showVector().end(); ++it) {
            it->drawBulletsEnemy(window);
        }
        drops.drawDrops(window);
        window.draw(Player.show());
        //não está otimizado, porém foi assim que eu pensei e consegui
        for (std::vector<Enemy>::iterator it = Enemies.showVector().begin(); it != Enemies.showVector().end(); ++it) {
            aimDirEnemyMov = Player.show().getPosition() - it->showPos();
            float lengthTemp = sqrt(pow(aimDirEnemyMov.x, 2) + pow(aimDirEnemyMov.y, 2));
            aimDirNormEnemyMov = aimDirEnemyMov / lengthTemp;
            it->UpdateVelocity(dt, aimDirNormEnemyMov);
        }
        drops.checkUndraw();
        window.display();
    }

    return 0;
}
