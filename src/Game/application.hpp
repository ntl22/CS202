#ifndef SRC_GAME_APPLICATION
#define SRC_GAME_APPLICATION
#include "../Framework/pch.hpp"

class Application : private sf::NonCopyable
{
public:
    static void run();

private:
    Application();

    void gameLoop();
    void handleEvent();
    void update();
    void render();

    std::shared_ptr<Context> context;
    sf::Image icon;
    sf::Event ev;
    sf::Time dt;

    const unsigned FPS;
    const unsigned WIDTH, HEIGHT;
};

#endif /* SRC_GAME_APPLICATION */
