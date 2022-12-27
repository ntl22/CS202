#ifndef SRC_GAME_APPLICATION
#define SRC_GAME_APPLICATION
#include "../Framework/pch.hpp"

#include <memory>

class Application
{
public:
    static void run();

private:
    Application();

    void gameLoop();
    void handleEvent();
    void update();
    void render();

    std::unique_ptr<sf::RenderWindow> window;
    sf::Image icon;
    sf::Event ev;

    const sf::Time TIME_PER_FRAME;
    const unsigned WIDTH, HEIGHT;
};

#endif /* SRC_GAME_APPLICATION */
