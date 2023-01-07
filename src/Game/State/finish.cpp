#include "finish.hpp"

#include "playing.hpp"
#include "menu.hpp"

#include <iostream>

FinishState::FinishState(Context &context,
                         Timer timer,
                         bool is_win,
                         OBJECT_TYPE type)
    : m_context(context),
      m_timer(timer),
      cur(-1),
      title_font(context.fonts->get(FONTS::visitor1))
{
    m_context.musics->pause(true);
    switch (type)
    {
    case (OBJECT_TYPE::CAT):
        m_context.sounds->play(SOUNDBUFFERS::cat);
        break;
    case (OBJECT_TYPE::CHICKEN):
        m_context.sounds->play(SOUNDBUFFERS::chicken);
        break;
    case (OBJECT_TYPE::TRUCK):
    case (OBJECT_TYPE::CAR):
        m_context.sounds->play(SOUNDBUFFERS::car);
        break;
    case (OBJECT_TYPE::NONE):
    default:
        context.sounds->play(SOUNDBUFFERS::finish);
        break;
    }

    sf::Vector2f size(m_context.window->getSize());

    if (is_win && compareTime())
    {
        title.setOutlineColor(sf::Color::Yellow);
        title.setString("New highscore");
    }
    else if (is_win)
    {
        title.setOutlineColor(sf::Color::Green);
        title.setString("You Win!");
    }
    else
    {
        title.setOutlineColor(sf::Color::Red);
        title.setString("Game Over");
    }

    title.setOutlineThickness(5);
    title.setFont(title_font);
    title.setCharacterSize(90U);
    setCenterOrigin(title, title.getLocalBounds());
    title.setPosition(m_context.window->getView().getCenter() - sf::Vector2f(0.f, 250.f));

    int i;

    for (i = 0; i < 2; i++)
        button[i] = std::make_unique<Button>(*m_context.window, m_context.fonts->get(FONTS::visitor1));

    button[0]->setText("PLAY AGAIN");
    button[0]->setHoverColor(sf::Color(255, 219, 62));
    button[0]->setPosition(m_context.window->getView().getCenter() - sf::Vector2f(0, 50.f));
    button[0]->setCallback([this]()
                           { m_context.states->push(std::make_unique<PlayingState>(m_context), true); });

    button[1]->setText("BACK TO MENU");
    button[1]->setHoverColor(sf::Color(111, 225, 62));
    button[1]->setPosition(m_context.window->getView().getCenter() + sf::Vector2f(0, 50.f));
    button[1]->setCallback([this]()
                           { m_context.states->pop(); m_context.musics->play(MUSICS::intro); });

    background.setTexture(m_context.textures->get(TEXTURES::welcome_bg));

    background.scale(
        size.x / background.getLocalBounds().width,
        size.y / background.getLocalBounds().height);
}

FinishState::~FinishState() {}

void FinishState::handleEvent(const sf::Event &ev)
{
    sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(*m_context.window));
    int i;

    if (ev.type == sf::Event::MouseMoved)
    {
        for (i = 0; i < 2; i++)
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
            cur = (cur <= 0) ? 1 : (cur - 1);
            break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
            cur = (cur + 1) % 2;
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

void FinishState::update(sf::Time dt)
{
    int i;

    for (i = 0; i < 2; i++)
    {
        if (i == cur)
            button[i]->focus();
        else
            button[i]->unfocus();
    }
}

void FinishState::draw()
{
    m_context.window->draw(background);
    m_context.window->draw(title);

    int i;
    for (i = 0; i < 2; i++)
        m_context.window->draw(*button[i]);
}

bool FinishState::compareTime()
{
    std::string file_name = std::string(FOLDER) + std::string(HIGHSCORE_FILE);

    if (!std::filesystem::exists(FOLDER))
    {
        std::filesystem::create_directory(FOLDER);
        std::ofstream f_dummy(file_name);
        f_dummy << m_timer.getTime().asSeconds() << '\n';
        return true;
    }

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream f_dummy(file_name);
        f_dummy << m_timer.getTime().asSeconds() << '\n';
        return true;
    }

    float old, time = m_timer.getTime().asSeconds();

    std::ifstream getTime(file_name);
    getTime >> old;
    getTime.close();
    std::filesystem::remove(file_name);

    std::ofstream newTime(file_name);
    newTime << std::min(old, time) << '\n';

    return old > time;
}
