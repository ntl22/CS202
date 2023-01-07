#include "loading.hpp"

#include "menu.hpp"
#include "loadingtask.hpp"

LoadingState::LoadingState(Context &context)
    : m_context(context), task(std::make_unique<LoadingTask>(context))
{
    loading_text.setString("Loading...");
    loading_text.setCharacterSize(40U);

    if (!font.loadFromFile("./assets/fonts/IBMPlexMono.ttf"))
        throw std::runtime_error("LoadingState::LoadingState(): invalid file");

    loading_text.setFont(font);
    setCenterOrigin(loading_text, loading_text.getLocalBounds());
    loading_text.setPosition(m_context.window->getView().getCenter());

    task->launchTask();
}

void LoadingState::handleEvent(const sf::Event &ev) {}

void LoadingState::update(sf::Time dt)
{
    if (task->isFinished())
    {
        m_context.states->push(std::make_unique<MenuState>(m_context), true);
    }
}

void LoadingState::draw()
{
    m_context.window->draw(loading_text);
}
