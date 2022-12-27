#include "context.hpp"

#include <SFML/Graphics.hpp>

#include "../State/manager.hpp"

Context::Context()
{
    states = std::make_unique<StateStack>();
    window = std::make_unique<sf::RenderWindow>();
}
