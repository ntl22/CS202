#include "application.hpp"

void Application::run()
{
    static Application game;
    game.gameLoop();
}

Application::Application()
    : WIDTH(900), HEIGHT(900), TIME_PER_FRAME(sf::seconds(1.f / 60.f))
{
    window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(WIDTH, HEIGHT), "Crossy Road", sf::Style::Close);

    assert(icon.loadFromFile("./assets/icon.png"));

    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Application::gameLoop()
{
    sf::Clock clock;
    sf::Time last_update = sf::Time::Zero;
    while (window->isOpen())
    {
        last_update += clock.restart();
        if (last_update >= TIME_PER_FRAME)
        {
            last_update -= TIME_PER_FRAME;
            handleEvent();
            update();
        }
        render();
    }
}

void Application::handleEvent()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        default:
            break;
        }
    }
}

void Application::update() {}

void Application::render()
{
    window->clear();
    window->display();
}
