#include "application.hpp"

#include "State/splash.hpp"

void Application::run()
{
    gameLoop();
}

Application::Application()
    : WIDTH(900), HEIGHT(900), FPS(60), is_close(false)
{
    context.window->create(
        sf::VideoMode(WIDTH, HEIGHT), "Crossy Road", sf::Style::Close);

    if (!icon.loadFromFile("./assets/icon.png"))
        throw std::runtime_error("Application::Application() : cannot open icon file");

    context.window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    context.window->setFramerateLimit(FPS);
    context.window->setKeyRepeatEnabled(false);

    context.states->push(std::make_unique<SplashState>(context));
}

void Application::gameLoop()
{
    sf::Clock clock;
    while (context.window->isOpen() && !is_close)
    {
        context.states->handleStack();
        if (context.states->isEmpty())
            break;

        dt = clock.restart();
        handleEvent();
        update();
        render();
    }
}

void Application::handleEvent()
{
    while (context.window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            is_close = true;
            break;
        default:
            context.states->getCurrent()->handleEvent(ev);
            break;
        }
    }
}

void Application::update()
{
    context.states->getCurrent()->update(dt);
}

void Application::render()
{
    context.window->clear();
    context.states->getCurrent()->draw();
    context.window->display();
}
