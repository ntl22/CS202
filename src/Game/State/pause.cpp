#include "pause.hpp"

#include "save.hpp"

PauseState::PauseState(Context &context, Timer &timer, bool &exit_ref)
    : m_context(context),
      m_timer(timer),
      is_exit(exit_ref),
      font_pause(context.fonts->get(FONTS::Sansation)),
      cur(-1)
{
    text_pause.setString("PAUSED");
    text_pause.setCharacterSize(100U);
    text_pause.setFont(font_pause);

    sf::Vector2u size = m_context.window->getSize();
    setCenterOrigin(text_pause, text_pause.getLocalBounds());

    text_pause.setPosition(size.x / 2.f, size.y / 2.f - 250.f);

    sf::Vector2f center(context.window->getView().getCenter());

    size_t i;

    for (i = 0; i < 3; i++)
        buttons[i] = std::make_unique<Button>(*context.window,
                                              context.fonts->get(FONTS::visitor1));

    buttons[0]->setText("Continue");
    buttons[0]->setHoverColor(sf::Color(255, 219, 62));
    buttons[0]->setPosition(center - sf::Vector2f(0, 100));
    buttons[0]->setCallback([this]()
                            { m_context.states->pop(); 
                              m_context.musics->pause(false);
                              m_timer.exitPauseState(); });

    buttons[1]->setText("Save game");
    buttons[1]->setHoverColor(sf::Color(111, 225, 62));
    buttons[1]->setPosition(center);
    buttons[1]->setCallback([this]()
                            { m_context.states->push(std::make_unique<SaveState>(m_context)); });

    buttons[2]->setText("Back to menu");
    buttons[2]->setHoverColor(sf::Color(226, 16, 16));
    buttons[2]->setPosition(center + sf::Vector2f(0, 100));
    buttons[2]->setCallback([this]()
                            { is_exit = true; m_context.states->pop(); });
}

void PauseState::handleEvent(const sf::Event &ev)
{
    sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(*m_context.window));
    int i;

    if (ev.type == sf::Event::MouseMoved)
    {
        for (i = 0; i < 3; i++)
        {
            if (buttons[i]->isInWidget(pos))
            {
                cur = i;
                break;
            }
        }
    }
    else if (ev.type == sf::Event::MouseButtonPressed &&
             ev.mouseButton.button == sf::Mouse::Left &&
             cur != -1 &&
             buttons[cur]->isInWidget(pos))
    {
        buttons[cur]->activate();
    }
    else if (ev.type == sf::Event::KeyPressed)
    {
        switch (ev.key.code)
        {
        case sf::Keyboard::W:
        case sf::Keyboard::Up:
            cur = (cur == -1) ? 0 : ((cur <= 0) ? 2 : (cur - 1));
            break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
            cur = (cur + 1) % 3;
            break;
        case sf::Keyboard::Enter:
            if (cur != -1)
                buttons[cur]->activate();
            break;
        default:
            break;
        }
    }
}

void PauseState::update(sf::Time dt)
{
    int i;

    for (i = 0; i < 3; i++)
        i == cur ? buttons[i]->focus() : buttons[i]->unfocus();
}

void PauseState::draw()
{
    m_context.window->draw(text_pause);

    for (auto &button : buttons)
        m_context.window->draw(*button);
}
