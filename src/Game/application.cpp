#include "application.hpp"

void Application::run()
{
    static Application game;
    game.gameLoop();
}

Application::Application()
    : WIDTH(900), HEIGHT(900), FPS(60),
      context(std::make_shared<Context>())
{
    context->window->create(
        sf::VideoMode(WIDTH, HEIGHT), "Crossy Road", sf::Style::Close);

    if (!icon.loadFromFile("./assets/icon.png"))
        throw std::runtime_error("Application::Application() : cannot open icon file");

    context->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    context->window->setFramerateLimit(FPS);
}

void Application::gameLoop()
{
    sf::Clock clock;
    while (context->window->isOpen())
    {
        dt = clock.restart();
        handleEvent();
        update();
        render();
    }
}

void Application::handleEvent()
{
    while (context->window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            context->window->close();
            break;
        default:
            break;
        }
    }
}

void Application::update() {}

void Application::render()
{
    context->window->clear();
    context->window->display();
}
