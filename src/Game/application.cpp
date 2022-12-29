#include "application.hpp"

#include "State/menu.hpp"

void Application::run()
{
    static Application game;
    game.gameLoop();
}

Application::Application()
    : WIDTH(1280), HEIGHT(720), FPS(60),
      context(std::make_shared<Context>())
{
    /**
     * Load all the assets
     */

    context->fonts->load(FONTS::IBMPlexMono, "./assets/fonts/IBMPlexMono.ttf");
    context->fonts->load(FONTS::Sansation, "./assets/fonts/Sansation.ttf");
    context->fonts->load(FONTS::visitor1, "./assets/fonts/visitor1.ttf");

    context->textures->load(TEXTURES::car1, "./assets/images/car1.png");
    context->textures->load(TEXTURES::truck1, "./assets/images/truck1.png");
    context->textures->load(TEXTURES::player, "./assets/images/player.png");
    context->textures->load(TEXTURES::welcome_bg, "./assets/images/welcome_bg.jpg");

    context->window->create(
        sf::VideoMode(WIDTH, HEIGHT), "Crossy Road", sf::Style::Close);

    if (!icon.loadFromFile("./assets/icon.png"))
        throw std::runtime_error("Application::Application() : cannot open icon file");

    context->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    context->window->setFramerateLimit(FPS);
    context->window->setKeyRepeatEnabled(false);

    context->states->push(std::make_unique<MenuState>(context));
}

void Application::gameLoop()
{
    sf::Clock clock;
    while (context->window->isOpen())
    {
        context->states->handleStack();
        if (context->states->isEmpty())
            break;

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
            context->states->getCurrent()->handleEvent(ev);
            break;
        }
    }
}

void Application::update()
{
    context->states->getCurrent()->update(dt);
}

void Application::render()
{
    context->window->clear();
    context->states->getCurrent()->draw();
    context->window->display();
}
