#include "splash.hpp"

#include "menu.hpp"

class SplashTask
{
public:
    SplashTask(Context &context);

    ~SplashTask() = default;

    void launch();

    bool isFinished() const;

private:
    sf::Mutex mutex;
    sf::Thread task;

    void loadTask();

    decltype(Context::fonts) &fonts;
    decltype(Context::textures) &textures;
    decltype(Context::sounds) &sounds;
    decltype(Context::musics) &music;

    bool finished;
};

SplashTask::SplashTask(Context &context)
    : task(&SplashTask::loadTask, this),
      fonts(context.fonts),
      textures(context.textures),
      sounds(context.sounds),
      music(context.musics) {}

void SplashTask::launch()
{
    finished = false;
    task.launch();
}

bool SplashTask::isFinished() const
{
    return finished;
}

void SplashTask::loadTask()
{
    sf::Lock lock(mutex);

    /**
     * Load all the assets
     */

    fonts->load(FONTS::IBMPlexMono, "./assets/fonts/IBMPlexMono.ttf");
    fonts->load(FONTS::Sansation, "./assets/fonts/Sansation.ttf");
    fonts->load(FONTS::visitor1, "./assets/fonts/visitor1.ttf");

    textures->load(TEXTURES::car1, "./assets/images/car1.png");
    textures->load(TEXTURES::truck1, "./assets/images/truck1.png");
    textures->load(TEXTURES::player, "./assets/images/player.png");
    textures->load(TEXTURES::welcome_bg, "./assets/images/welcome_bg.jpg");

    sounds->load(SOUNDBUFFERS::jump, "./assets/sounds/jump.wav");

    music->load(MUSICS::intro, "./assets/sounds/intro.wav");

    finished = true;
}

SplashState::SplashState(Context &context)
    : m_context(context)
{
    if (!font.loadFromFile("./assets/fonts/IBMPlexMono.ttf"))
        throw std::runtime_error("SplashState::SplashState() : asset exception");

    text.setFont(font);
    text.setString("Loading...");
    text.setCharacterSize(50U);

    setCenterOrigin(text, text.getLocalBounds());
    sf::FloatRect size(sf::Vector2f(0, 0), sf::Vector2f(m_context.window->getSize()));
    setCenterPosition(text, size);

    task = std::make_unique<SplashTask>(m_context);
    task->launch();
}

void SplashState::handleEvent(const sf::Event &ev) {}

void SplashState::update(sf::Time dt)
{
    if (task->isFinished())
    {
        m_context.states->push(std::make_unique<MenuState>(m_context), true);
    }
}

void SplashState::draw()
{
    m_context.window->draw(text);
}
