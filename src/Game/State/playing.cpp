#include "playing.hpp"

#include "pause.hpp"
#include "finish.hpp"

PlayingState::PlayingState(Context &context)
    : m_context(context),
      cur_level(1),
      MAX_LEVEL(5),
      speed({2, 4, 6, 8, 10})
{
  m_context.musics->play(MUSICS::playing);

  saveGame = ([this](std::string path)
              { std::ofstream fout(path); });

  loadGame = ([this](std::string path)
              { std::ifstream fin(path); });
}

PlayingState::~PlayingState()
{
  m_context.sounds->removeStoppedSounds();
}

void PlayingState::handleEvent(const sf::Event &ev)
{
  if (ev.type == sf::Event::KeyPressed)
  {
    if (ev.key.code == sf::Keyboard::P)
    {
      m_context.musics->pause(true);
      m_context.states->push(std::make_unique<PauseState>(m_context, saveGame));
    }
  }
}

void PlayingState::update(sf::Time dt)
{
}

void PlayingState::draw()
{
}
