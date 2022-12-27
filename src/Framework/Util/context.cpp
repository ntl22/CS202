#include "context.hpp"

#include <SFML/Graphics.hpp>

Context::Context()
{
    window = std::make_unique<sf::RenderWindow>();
}
