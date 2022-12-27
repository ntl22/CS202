#include "application.hpp"

#include "State/menu.hpp"

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

    context->states->push(std::make_unique<MenuState>(context));
}

void Application::gameLoop()
{
    sf::Clock clock;
    context->states->handleStack();
    while (context->window->isOpen() && !context->states->isEmpty())
    {
        dt = clock.restart();
        handleEvent();
        update();
        render();
        context->states->handleStack();
    }
    context->window->close();
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
            context->states->getCurrent()->handleEvent(ev);
            break;
        }
    }
}

void Application::update() { context->states->getCurrent()->update(dt); }

void Application::render()
{
    context->window->clear();
    context->states->getCurrent()->draw();
    context->window->display();
}
