#include "finish.hpp"

#include "playing.hpp"
#include "menu.hpp"

#include <iostream>

FinishState::FinishState(Context &context, sf::Time time, OBJECT_TYPE type)
    : m_context(context),
      final_time(time),
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
        m_context.sounds->play(SOUNDBUFFERS::finish);
        break;
    }

    sf::Vector2f size(m_context.window->getSize());

    updateHighscore(type);

    if (final_time.asSeconds() == 0)
    {
        highscore = sf::Text("No highscore yet!", title_font, 40U);
    }
    else
    {
        highscore = sf::Text("The current highscore is " + formatTime(), title_font, 40U);
    }
    setCenterOrigin(highscore, highscore.getLocalBounds());

    highscore.setPosition(m_context.window->getView().getCenter() - sf::Vector2f(0.f, 150.f));

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
    m_context.window->draw(highscore);

    int i;
    for (i = 0; i < 2; i++)
        m_context.window->draw(*button[i]);
}

void FinishState::updateHighscore(OBJECT_TYPE type)
{
    std::string PATH(FOLDER);

    if (!std::filesystem::exists(PATH))
    {
        std::filesystem::create_directory(PATH);
    }

    bool highscore = false;

    PATH += std::string("highscore.txt");

    if (!std::filesystem::exists(PATH))
    {
        if (type != OBJECT_TYPE::NONE)
        {
            title.setString("Game over");
            title.setOutlineColor(sf::Color::Red);
            final_time = sf::seconds(0);
            return;
        }
        else
        {
            std::ofstream fout(PATH);
            fout << final_time.asSeconds() << '\n';
            highscore = true;
        }
    }

    std::ifstream fin(PATH);
    float prev;
    fin >> prev;
    fin.close();

    highscore = prev >= final_time.asSeconds();

    if (type != OBJECT_TYPE::NONE)
    {
        title.setString("Game over");
        title.setOutlineColor(sf::Color::Red);
        final_time = sf::seconds(prev);
    }
    else if (highscore)
    {
        std::ofstream fout(PATH);
        fout << final_time.asSeconds() << '\n';
        title.setString("New HighScore");
        title.setOutlineColor(sf::Color(255, 181, 8));
    }
    else
    {
        final_time = sf::seconds(prev);
        title.setString("You win");
        title.setOutlineColor(sf::Color::Green);
    }
}

std::string FinishState::formatTime()
{
    std::stringstream ss;

    unsigned toSec = (unsigned)final_time.asSeconds();
    unsigned h = toSec / 3600;
    unsigned m = (toSec - (h * 3600)) / 60;
    unsigned s = toSec - (h * 3600 + m * 60);

    ss << (h < 10 ? "0" : "") + std::to_string(h) << ":";
    ss << (m < 10 ? "0" : "") + std::to_string(m) << ":";
    ss << (s < 10 ? "0" : "") + std::to_string(s);

    return ss.str();
}
