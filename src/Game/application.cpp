#include "application.hpp"

#include "State/loading.hpp"

void Application::run()
{
    gameLoop();
}

Application::Application()
    : WIDTH(1280), HEIGHT(720), FPS(60)
{
    srand((unsigned)time(NULL));
    context.window->create(
        sf::VideoMode(WIDTH, HEIGHT), "Crossy Road", sf::Style::Close);

    if (!icon.loadFromFile("./assets/icon.png"))
        throw std::runtime_error("Application::Application() : cannot open icon file");

    context.window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    context.window->setFramerateLimit(FPS);
    context.window->setKeyRepeatEnabled(false);

    context.states->push(std::make_unique<LoadingState>(context));
}

void Application::gameLoop()
{
    sf::Clock clock;
    while (context.window->isOpen())
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
            context.window->close();
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
