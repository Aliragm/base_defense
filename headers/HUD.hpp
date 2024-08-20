#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "player.hpp"
#include "base.hpp"

class HUD {
private:
    sf::Font font;
    sf::Text healthText;
    sf::Text lifeText;
    sf::Text ammoText;
    sf::Text xpText;
    float health;
    int life; 
    int ammo;
    float xp;
public:
    HUD();
    void update(Player& player, Base& base);
    void draw(sf::RenderWindow& window);
};

#endif
