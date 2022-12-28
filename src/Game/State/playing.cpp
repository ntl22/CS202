#include "playing.hpp"

PlayingState::PlayingState(std::shared_ptr<Context> context)
    : context(context)
{
    sf::FloatRect size(sf::Vector2f(0.f, 0.f), sf::Vector2f(context->window->getSize()));

    setCenterOrigin(testing, testing.getLocalBounds());
    setCenterPosition(testing, size);
}

void PlayingState::handleEvent(const sf::Event& ev)
{
}

void PlayingState::update(sf::Time dt) {}

void PlayingState::draw()
{
    context->window->draw(testing);
}

void PlayingState::pause_game()
{
}
