#include "playing.hpp"

PlayingState::PlayingState(std::shared_ptr<Context> context)
    : m_context(context)
{
    sf::FloatRect size(sf::Vector2f(0.f, 0.f), sf::Vector2f(context->window->getSize()));

    if (!testing_font.loadFromFile("./assets/fonts/Sansation.ttf"))
        throw std::runtime_error("PlayingState::PlayState() : cannot load font");
    testing.setFont(testing_font);
    testing.setCharacterSize(30U);
    testing.setString("In Playing State");

    setCenterOrigin(testing, testing.getLocalBounds());
    setCenterPosition(testing, size);
}

void PlayingState::handleEvent(const sf::Event& ev)
{
}

void PlayingState::update(sf::Time dt) {}

void PlayingState::draw()
{
    m_context->window->draw(testing);
}

void PlayingState::pause_game()
{
}
