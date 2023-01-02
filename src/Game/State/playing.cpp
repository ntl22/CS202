#include "playing.hpp"

#include "pause.hpp"
#include "finish.hpp"

class LevelUpState : public State
{
public:
    LevelUpState(Context &context, const int &level)
        : next_level("Level " + std::to_string(level) + " is next!",
                     context.fonts->get(FONTS::visitor1), 70U),
          m_context(context)
    {
        next_level.setFillColor(sf::Color::Green);
        setCenterOrigin(next_level, next_level.getLocalBounds());
        next_level.setPosition(context.window->getView().getCenter());
    }

    void handleEvent(const sf::Event &ev)
    {
        if (ev.type == sf::Event::KeyPressed &&
            ev.key.code == sf::Keyboard::Enter)
        {
            m_context.musics->pause(false);
            m_context.states->pop();
        }
    }

    void update(sf::Time dt) {}

    void draw()
    {
        m_context.window->draw(next_level);
    }

private:
    sf::Text next_level;

    Context &m_context;
};

PlayingState::PlayingState(Context &context)
    : m_context(context),
      timer(context),
      is_exit(false),
      is_pause(false),
      world(std::make_unique<World>(context, timer)),
      cur_level(1),
      MAX_LEVEL(5)
{
    m_context.musics->setLoop(true);
    m_context.musics->play(MUSICS::playing);
}

void PlayingState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed)
    {
        if (ev.key.code == sf::Keyboard::P)
        {
            is_pause = true;
            return;
        }
    }
    world->handleEvent(ev);
}

void PlayingState::update(sf::Time dt)
{
    if (is_pause)
    {
        timer.pushPauseState();
        m_context.musics->pause(true);
        m_context.states->push(std::make_unique<PauseState>(m_context, is_exit));
        is_pause = false;
        return;
    }

    if (is_exit)
    {
        m_context.states->pop();
        m_context.musics->play(MUSICS::intro);
        return;
    }

    world->update();
    timer.update();

    if (world->isWin())
    {
        if (cur_level < MAX_LEVEL)
        {
            m_context.musics->setLoop(true);
            std::unique_ptr<World> new_level(new World(m_context, timer));
            cur_level++;
            m_context.musics->pause(true);
            timer.pushPauseState();
            std::swap(new_level, world);
            m_context.states->push(std::make_unique<LevelUpState>(m_context, cur_level));
        }
        else
        {
            m_context.musics->stop();
            m_context.states->push(std::make_unique<FinishState>(m_context), true);
        }
    }

    if (world->isDead())
    {
        m_context.musics->stop();
        m_context.states->push(std::make_unique<FinishState>(m_context, false, false, OBJECT_TYPE::CAT), true);
    }
}

void PlayingState::draw()
{
    world->draw();
}
