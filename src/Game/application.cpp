#include "application.hpp"

#include "State/menu.hpp"

void Application::run()
{
    gameLoop();
}

Application::Application()
    : WIDTH(1280), HEIGHT(720), FPS(60), is_close(false)
{
    context.fonts->load(FONTS::IBMPlexMono, "./assets/fonts/IBMPlexMono.ttf");
    context.fonts->load(FONTS::Sansation, "./assets/fonts/Sansation.ttf");
    context.fonts->load(FONTS::visitor1, "./assets/fonts/visitor1.ttf");

    context.textures->load(TEXTURES::car, "./assets/images/car.png");
    context.textures->load(TEXTURES::cat1, "./assets/images/cat1.png");
    context.textures->load(TEXTURES::cat2, "./assets/images/cat2.png");
    context.textures->load(TEXTURES::cat3, "./assets/images/cat3.png");
    context.textures->load(TEXTURES::chicken, "./assets/images/chicken.png");
    context.textures->load(TEXTURES::player1, "./assets/images/player1.png");
    context.textures->load(TEXTURES::truck, "./assets/images/truck.png");
    context.textures->load(TEXTURES::welcome_bg, "./assets/images/welcome_bg.png");

    context.sounds->load(SOUNDBUFFERS::jump, "./assets/sounds/jump.wav");

    context.window->create(
        sf::VideoMode(WIDTH, HEIGHT), "Crossy Road", sf::Style::Close);

    context.musics->load(MUSICS::intro, "./assets/sounds/intro.wav");

    if (!icon.loadFromFile("./assets/icon.png"))
        throw std::runtime_error("Application::Application() : cannot open icon file");

    context.window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    context.window->setFramerateLimit(FPS);
    context.window->setKeyRepeatEnabled(false);

    context.states->push(std::make_unique<MenuState>(context));
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
