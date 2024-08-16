#ifndef DROPS_H
#define DROPS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
//lembrar de mudar makefile
class drop{
    private:
        float life;
        int ammo;
        float xp;
        bool isLife;
        bool isAmmo;
        bool isXp;
        static std::vector<drop> drops;
        sf::RectangleShape dropShape;
        sf::Clock lifeClock;
    public:
        drop();
        ~drop();
        sf::RectangleShape& show();
        void chooseDrop();
        void spawn(sf::Vector2f pos, drop newDrop);
        void drawDrops(sf::RenderWindow& window);
        float checkTime();
        void checkUndraw();
        std::vector<drop>& showVector();
};

#endif
