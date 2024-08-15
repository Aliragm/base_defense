#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>

class Base : public sf::RectangleShape  {
    private:
        float health;
        sf::RectangleShape structure;
        sf::Texture BaseTexture;
        bool initTexture();

    public:
        Base();
        ~Base();
        sf::RectangleShape show();
};



#endif
