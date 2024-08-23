#ifndef DROPS_H
#define DROPS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include "../headers/player.hpp"

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
        void chooseDrop(sf::Texture* DropTextures);
        void spawn(sf::Vector2f pos, drop newDrop, sf::Texture* DropTextures);
        void drawDrops(sf::RenderWindow& window);
        float checkTime();
        void checkUndraw();
        void isTaken(Player& player);
        std::vector<drop>& showVector();
        int showDropType();
};

#endif
