#include "save.hpp"

SaveState::SaveState(Context &context)
    : m_context(context),
      title("Save Game", context.fonts->get(FONTS::visitor1), 60U),
      input_here("Input file name: ", context.fonts->get(FONTS::IBMPlexMono), 30U),
      file_to_gui("", context.fonts->get(FONTS::visitor1), 30U),
      capacity(10U)
{
    file_to_gui.setFillColor(sf::Color::Black);

    setCenterOrigin(title, title.getLocalBounds());
    setCenterOrigin(input_here, input_here.getLocalBounds());

    title.setPosition(context.window->getView().getCenter() - sf::Vector2f(0, 200.f));

    input_here.setPosition(context.window->getView().getCenter() - sf::Vector2f(200.f, 0));

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
            saveGame();
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
}
