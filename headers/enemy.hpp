#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Enemy {
    private:
        float life;
        sf::RectangleShape enemyShape;
        sf::Vector2f velocity;
        static std::vector<Enemy> enemies;
        static sf::Clock spawnClock; // Adiciona um relógio para medir o tempo entre spawns
        static int spawnCounter;
    public:
        Enemy();
        ~Enemy();
        sf::RectangleShape& show();
        static std::vector <Enemy> &showVector();
        //dentro do gameloop
        static void Spawner();
        static void DrawEnemies(sf::RenderWindow &window);
};



#endif
