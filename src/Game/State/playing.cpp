#include "playing.hpp"

#include "pause.hpp"
#include "finish.hpp"
#include "levelup.hpp"

PlayingState::PlayingState(Context &context)
    : m_context(context),
      timer(context),
      cur_level(1),
      MAX_LEVEL(5),
      speed({2, 4, 6, 8, 10})
{
    world = std::make_unique<World>(timer, context, speed[0]);
    m_context.musics->setLoop(true);
    m_context.musics->play(MUSICS::playing);

    saveGame_func = ([this](std::string path)
                     {
        std::ofstream fout(path);
        fout << cur_level << '\n';
        timer.saveGame(fout);
        world->saveGame(fout); });

    loadGame_func = ([this](std::string path)
                     {
        std::ifstream fin(path);

        fin >> cur_level;
        fin.ignore(1000, '\n');
        timer.loadGame(fin);

        world = std::make_unique<World>(timer, m_context, speed[cur_level - 1]);
        world->loadGame(fin);
        timer.exitPauseState(); });
}

void PlayingState::handleEvent(const sf::Event &ev)
{
    if (ev.type == sf::Event::KeyPressed)
    {
        if (ev.key.code == sf::Keyboard::P)
        {
            m_context.musics->pause(true);
            m_context.states->push(std::make_unique<PauseState>(m_context, timer, saveGame_func));
            m_context.states->handleStack();
            return;
        }
    }
    world->handleEvent(ev);
}

void PlayingState::update(sf::Time dt)
{
    auto status = world->update(dt);

    switch (status.first)
    {
    case STATUS::WIN:
        if (cur_level < MAX_LEVEL)
        {
            m_context.musics->setLoop(true);
            std::unique_ptr<World> new_level(new World(timer, m_context, speed[cur_level]));
            cur_level++;
            m_context.musics->pause(true);
            std::swap(new_level, world);
            m_context.states->push(std::make_unique<LevelUpState>(m_context, timer, cur_level));
            m_context.states->handleStack();
        }
        else
        {
            m_context.musics->stop();
            m_context.states->push(std::make_unique<FinishState>(m_context, timer, true), true);
            m_context.states->handleStack();
        }
        break;
    case STATUS::DEAD:
        m_context.musics->stop();
        m_context.states->push(std::make_unique<FinishState>(m_context, timer, false, status.second), true);
        m_context.states->handleStack();
        break;
    case STATUS::PLAYING:
        break;
    }
}

void PlayingState::draw()
{
    world->draw();
}
