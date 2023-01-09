#include "menu.hpp"

#include "playing.hpp"
#include "load.hpp"

MenuState::MenuState(Context &context)
    : m_context(context),
      title_font(context.fonts->get(FONTS::visitor1)),
      update_str(false)
{
    sf::Vector2f size(m_context.window->getSize());

    title.setOutlineColor(sf::Color::Black);

    title.setString("Crossy road");
    title.setOutlineThickness(5);
    title.setFont(title_font);
    title.setCharacterSize(90U);
    setCenterOrigin(title, title.getLocalBounds());
    title.setPosition(m_context.window->getView().getCenter() - sf::Vector2f(0.f, 250.f));

    int i;

    for (i = 0; i < 4; i++)
        button[i] = std::make_unique<Button>(*m_context.window, m_context.fonts->get(FONTS::visitor1));

    button[0]->setText("PLAY");
    button[0]->setHoverColor(sf::Color(255, 219, 62));
    button[0]->setPosition(m_context.window->getView().getCenter() - sf::Vector2f(0, 100.f));
    button[0]->setCallback([this]()
                           { m_context.states->push(std::make_unique<PlayingState>(m_context)); });

    button[1]->setText("LOAD");
    button[1]->setHoverColor(sf::Color(111, 225, 62));
    button[1]->setPosition(m_context.window->getView().getCenter());
    button[1]->setCallback([this]()
                           { m_context.states->push(std::make_unique<LoadState>(m_context)); });

    music = m_context.musics->getVolume() ? "MUSIC: ON" : "MUSIC: OFF";

    button[2]->setText(music);
    button[2]->setHoverColor(sf::Color(162, 205, 90));
    button[2]->setPosition(m_context.window->getView().getCenter() + sf::Vector2f(0, 100.f));
    button[2]->setCallback([this]()
                           { 
                            float cur_volume = m_context.musics->getVolume();
                            m_context.musics->stop();
                            m_context.musics->setVolume(cur_volume ? 0.f : 100.f);
                            music = !cur_volume ? "MUSIC: ON" : "MUSIC: OFF";
                            m_context.musics->play(MUSICS::intro);
                            update_str = true; });

    button[3]->setText("EXIT");
    button[3]->setHoverColor(sf::Color(226, 16, 16));
    button[3]->setPosition(m_context.window->getView().getCenter() + sf::Vector2f(0, 200.f));
    button[3]->setCallback([this]()
                           { m_context.states->pop(); });

    m_context.musics->setLoop(true);
    m_context.musics->play(MUSICS::intro);

    background.setTexture(m_context.textures->get(TEXTURES::welcome_bg));

    background.scale(
        size.x / background.getLocalBounds().width,
        size.y / background.getLocalBounds().height);
}

MenuState::~MenuState() {}

void MenuState::handleEvent(const sf::Event &ev)
{
    sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(*m_context.window));
    int i;

    if (ev.type == sf::Event::MouseMoved)
    {
        for (i = 0; i < 4; i++)
        {
            if (button[i]->isInWidget(pos))
            {
                cur = i;
                break;
            }
        }
    }
    else if (ev.type == sf::Event::MouseButtonPressed &&
             ev.mouseButton.button == sf::Mouse::Left &&
             cur != -1 &&
             button[cur]->isInWidget(pos))
    {
        button[cur]->activate();
    }
    else if (ev.type == sf::Event::KeyPressed)
    {
        switch (ev.key.code)
        {
        case sf::Keyboard::W:
        case sf::Keyboard::Up:
            cur = (cur == -1) ? 0 : ((cur <= 0) ? 3 : (cur - 1));
            break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
            cur = (cur + 1) % 4;
            break;
        case sf::Keyboard::Enter:
            if (cur != -1)
                button[cur]->activate();
            break;
        default:
            break;
        }
    }
}

void MenuState::update(sf::Time dt)
{
    if (update_str)
    {
        button[2]->setText(music);
        button[2]->setPosition(m_context.window->getView().getCenter() + sf::Vector2f(0, 100.f));
        update_str = false;
    }

    int i;

    for (i = 0; i < 4; i++)
    {
        if (i == cur)
            button[i]->focus();
        else
            button[i]->unfocus();
    }
}

void MenuState::draw()
{
    m_context.window->draw(background);
    m_context.window->draw(title);

    int i;
    for (i = 0; i < 4; i++)
        m_context.window->draw(*button[i]);
}