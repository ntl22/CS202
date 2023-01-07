#include "load.hpp"

#include "playing.hpp"

LoadState::LoadState(Context &context)
    : m_context(context),
      title("Save Game", context.fonts->get(FONTS::visitor1), 90U),
      input_here("Input file name: ", context.fonts->get(FONTS::IBMPlexMono), 30U),
      file_to_gui("", context.fonts->get(FONTS::visitor1), 30U),
      invalid("The mode is invalid, press Esc to return...",
              context.fonts->get(FONTS::visitor1), 35U),
      capacity(10U)
{
    sf::Vector2f size(m_context.window->getSize());

    file_to_gui.setFillColor(sf::Color::Black);

    setCenterOrigin(title, title.getLocalBounds());
    setCenterOrigin(input_here, input_here.getLocalBounds());

    setCenterOrigin(invalid, invalid.getLocalBounds());
    invalid.setPosition(context.window->getView().getCenter());
    invalid.setFillColor(sf::Color::Red);

    title.setPosition(context.window->getView().getCenter() - sf::Vector2f(0, 200.f));
    title.setFillColor(sf::Color::Green);

    input_here.setPosition(context.window->getView().getCenter() - sf::Vector2f(200.f, 0));
    input_here.setOutlineColor(sf::Color::Black);
    input_here.setOutlineThickness(2);

    input.setFillColor(sf::Color::White);
    input.setSize({300, 40});

    input.setOrigin({0.f, input.getSize().y / 2.f});
    input.setPosition(context.window->getView().getCenter() -
                      sf::Vector2f(20.f, 0));

    background.setTexture(m_context.textures->get(TEXTURES::welcome_bg));

    background.scale(
        size.x / background.getLocalBounds().width,
        size.y / background.getLocalBounds().height);

    std::string PATH(FOLDER);
    PATH.operator+=(SAVE_FOLDER);

    exist = std::filesystem::exists(FOLDER) && std::filesystem::exists(PATH);
}

void LoadState::handleEvent(const sf::Event &ev)
{
    if (!exist)
    {
        if (ev.type == sf::Event::KeyPressed &&
            ev.key.code == sf::Keyboard::Escape)
            m_context.states->pop();
    }
    else
    {
        if (ev.type == sf::Event::TextEntered &&
            std::isprint(ev.text.unicode) &&
            file_name.size() < capacity)
            file_name.push_back(std::toupper(ev.text.unicode));
        else if (ev.type == sf::Event::KeyPressed)
        {
            switch (ev.key.code)
            {
            case sf::Keyboard::BackSpace:
                if (!file_name.empty())
                    file_name.pop_back();
                break;
            case sf::Keyboard::Enter:
                loadGame();
                break;
            default:
                break;
            }
        }
    }
}

void LoadState::update(sf::Time dt)
{
    if (exist)
    {
        file_to_gui.setString(file_name);
        setCenterOrigin(file_to_gui, file_to_gui.getLocalBounds());
        setCenterPosition(file_to_gui, input.getGlobalBounds());
    }
}

void LoadState::draw()
{
    if (exist)
    {
        m_context.window->draw(background);
        m_context.window->draw(title);
        m_context.window->draw(input_here);
        m_context.window->draw(input);
        m_context.window->draw(file_to_gui);
    }
    else
    {
        m_context.window->draw(invalid);
    }
}

void LoadState::loadGame()
{
    std::string PATH(FOLDER);
    PATH.operator+=(SAVE_FOLDER);

    if (std::filesystem::exists(PATH + file_name + ".txt"))
    {
        auto playing = std::make_unique<PlayingState>(m_context);

        playing->loadGame(PATH + file_name + ".txt");

        m_context.states->push(std::move(playing), true);
    }
    else
    {
        invalid.setString("File invalid, press Esc to back to main menu...");
        setCenterOrigin(invalid, invalid.getLocalBounds());
        invalid.setPosition(m_context.window->getView().getCenter());
        exist = false;
    }
}
