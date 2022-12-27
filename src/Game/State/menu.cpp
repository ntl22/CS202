#include "menu.hpp"

#include <iostream>

MenuState::MenuState(std::shared_ptr<Context> context)
    : context(context)
{
    title.setOutlineColor(sf::Color::Black);

    if (!title_font.loadFromFile("./assets/fonts/Sansation.ttf"))
        throw std::runtime_error("MenuState::MenuState() : font not button[1]ed");

    title.setString("Crossy road");
    title.setOutlineThickness(5);
    title.setFont(title_font);
    title.setCharacterSize(90U);
    setCenterOrigin(title, title.getLocalBounds());
    title.setPosition(context->window->getView().getCenter() - sf::Vector2f(0.f, 300.f));

    int i;

    for (i = 0; i < 3; i++)
        button[i] = std::make_unique<Button>(context);

    button[0]->setText("PLAY");
    button[0]->setHoverColor(sf::Color(255, 219, 62));
    button[0]->setPosition(context->window->getView().getCenter() - sf::Vector2f(0, 100.f));
    button[0]->setCallback([]()
                           { std::cout << "PLAY" << std::endl; });

    button[1]->setText("LOAD");
    button[1]->setHoverColor(sf::Color(111, 225, 62));
    button[1]->setPosition(context->window->getView().getCenter());
    button[1]->setCallback([]()
                           { std::cout << "LOAD" << std::endl; });

    button[2]->setText("EXIT");
    button[2]->setHoverColor(sf::Color(226, 16, 16));
    button[2]->setPosition(context->window->getView().getCenter() + sf::Vector2f(0, 100.f));
    button[2]->setCallback([this]()
                           { this->context->states->pop(); });
}

void MenuState::handleEvent(const sf::Event &ev)
{
    sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(*context->window));
    int i;

    if (ev.type == sf::Event::MouseMoved)
    {
        for (i = 0; i < 3; i++)
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
            cur = (cur <= 0) ? 2 : (cur - 1);
            break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
            cur = (cur + 1) % 3;
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
    int i;

    for (i = 0; i < 3; i++)
    {
        if (i == cur)
            button[i]->focus();
        else
            button[i]->unfocus();
    }
}

void MenuState::draw()
{
    context->window->draw(title);

    int i;
    for (i = 0; i < 3; i++)
        context->window->draw(*button[i]);
}
