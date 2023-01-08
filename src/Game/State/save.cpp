#include "save.hpp"

SaveState::SaveState(Context &context, std::function<void(std::string)>& save_f)
    : m_context(context),
      title("Save Game", context.fonts->get(FONTS::visitor1), 60U),
      input_here("Input file name: ", context.fonts->get(FONTS::IBMPlexMono), 30U),
      file_to_gui("", context.fonts->get(FONTS::visitor1), 30U),
      invalid("Error: File name invalid", context.fonts->get(FONTS::visitor1), 30U),
      go_back("Press Esc to go back", context.fonts->get(FONTS::Sansation), 15U),
      save(save_f),
      capacity(10U)
{
    invalid.setFillColor(sf::Color::Transparent);
    file_to_gui.setFillColor(sf::Color::Black);

    setCenterOrigin(title, title.getLocalBounds());
    title.setPosition(context.window->getView().getCenter() - sf::Vector2f(0, 200.f));

    setCenterOrigin(input_here, input_here.getLocalBounds());
    input_here.setPosition(context.window->getView().getCenter() - sf::Vector2f(200.f, 0));

    setCenterOrigin(invalid, invalid.getLocalBounds());
    invalid.setPosition(context.window->getView().getCenter() + sf::Vector2f(0, 200.f));

    go_back.setOrigin({0, go_back.getGlobalBounds().height});
    go_back.setPosition({0, context.window->getSize().y - 10.f});

    input.setFillColor(sf::Color::White);
    input.setSize({300, 40});

    input.setOrigin({0.f, input.getSize().y / 2.f});
    input.setPosition(context.window->getView().getCenter() -
                      sf::Vector2f(20.f, 0));
}

void SaveState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::TextEntered &&
        std::isprint(ev.text.unicode) &&
        file_name.size() < capacity)
    {
        invalid.setFillColor(sf::Color::Transparent);
        file_name.push_back(ev.text.unicode);
    }
    else if (ev.type == sf::Event::KeyPressed)
    {
        switch (ev.key.code)
        {
        case sf::Keyboard::BackSpace:
            if (!file_name.empty())
                file_name.pop_back();
            break;
        case sf::Keyboard::Enter:
            if (!file_name.empty())
            {
                saveGame();
                m_context.states->pop();
            }
            else
            {
                invalid.setFillColor(sf::Color::Red);
            }
            break;
        case sf::Keyboard::Escape:
            m_context.states->pop();
            break;
        default:
            break;
        }
    }
}

void SaveState::update(sf::Time dt)
{
    file_to_gui.setString(file_name);
    setCenterOrigin(file_to_gui, file_to_gui.getLocalBounds());
    setCenterPosition(file_to_gui, input.getGlobalBounds());
}

void SaveState::draw()
{
    m_context.window->draw(title);
    m_context.window->draw(input_here);
    m_context.window->draw(input);
    m_context.window->draw(file_to_gui);
    m_context.window->draw(invalid);
    m_context.window->draw(go_back);
}

void SaveState::saveGame()
{
    std::string PATH(FOLDER);
    if (!std::filesystem::exists(PATH))
        std::filesystem::create_directories(PATH);

    PATH.operator+=(SAVE_FOLDER);

    if (!std::filesystem::exists(PATH))
        std::filesystem::create_directories(PATH);

    std::ofstream fout(PATH + file_name + ".txt");
    fout.close();

    save(PATH + file_name + ".txt");
}