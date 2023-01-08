#include "playing.hpp"

#include "../Entity/world.hpp"

#include "pause.hpp"
#include "levelup.hpp"
#include "finish.hpp"

PlayingState::PlayingState(Context &context)
    : m_context(context),
      cur_level(1),
      MAX_LEVEL(5),
      speed({2, 4, 6, 8, 10}),
      timer(context)
{
  m_context.musics->play(MUSICS::playing);

  world = std::make_unique<World>(context, timer, speed[0]);

  saveGame = ([this](std::string path) {
    std::ofstream fout(path);
    fout << cur_level << '\n';
    timer.saveGame(fout);
    world->saveGame(fout); });

  loadGame = ([this](std::string path) {         
    std::ifstream fin(path);
    fin >> cur_level;
    fin.ignore(1000, '\n');
    timer.loadGame(fin);

    world = std::make_unique<World>(m_context, timer, speed[cur_level - 1]);
    world->loadGame(fin);
    timer.exitPauseState(); });
}

PlayingState::~PlayingState()
{
  m_context.musics->stop();
  m_context.sounds->removeStoppedSounds();
}

void PlayingState::handleEvent(const sf::Event &ev)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
  {
    m_context.states->push(std::make_unique<PauseState>(m_context, timer, saveGame));
    m_context.states->handleStack();
  }
  else
  {
    world->handleEvent(ev);
  }
}

void PlayingState::update(sf::Time dt)
{
  auto status = world->update(dt);

  if (status.first == STATUS::DEAD)
  {
    m_context.states->push(std::make_unique<FinishState>(m_context, timer.getTime(), status.second), true);
    m_context.states->handleStack();
  }
  else if (status.first == STATUS::WIN)
  {
    if (cur_level < MAX_LEVEL)
    {
      world.swap(std::make_unique<World>(m_context, timer, speed[cur_level]));
      m_context.states->push(std::make_unique<LevelUpState>(m_context, timer, ++cur_level));
      m_context.states->handleStack();
    }
    else
    {
      m_context.states->push(std::make_unique<FinishState>(m_context, timer.getTime()), true);
      m_context.states->handleStack();
    }
  }
}

void PlayingState::draw()
{
  world->draw();
}
