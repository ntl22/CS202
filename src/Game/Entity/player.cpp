#include "player.hpp"

People::People(Context &context)
    : m_textures(*context.textures),
      m_sound(*context.sounds),
      status(STATUS::PLAYING),
      direction(4),
      MAP_WIDTH(context.window->getSize().x * 1.f),
      MAP_HEIGHT(context.window->getSize().y * 1.f)
{
    direction = 4;

    CELL_HEIGHT = 50;
    CELL_WIDTH = CELL_HEIGHT * 49 / 105;

    position.x = (MAP_WIDTH - CELL_WIDTH) / 2;
    position.y = MAP_HEIGHT - CELL_HEIGHT - 10;

    control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void People::createTexture()
{
    switch (direction)
    {
    case 1:
        sprite.setTexture(m_textures.get(TEXTURES::peopleRight));
        break;
    case 2:
        sprite.setTexture(m_textures.get(TEXTURES::peopleBack));
        break;
    case 3:
        sprite.setTexture(m_textures.get(TEXTURES::peopleLeft));
        break;
    case 4:
        sprite.setTexture(m_textures.get(TEXTURES::peopleFront));
        break;
    }

    sprite.setPosition(position);
    sprite.setScale({CELL_WIDTH / 49.f, CELL_HEIGHT / 90.f});
}

void People::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void People::update(sf::Time dt)
{
    createTexture();
    if (position.y == MAP_HEIGHT - CELL_HEIGHT * 13.f - 10.f)
        status = STATUS::WIN;
}

void People::handleEvent(const sf::Event &ev)
{
    bool moved = 0;

    if (0 == control_keys[0] &&
        1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        MAP_WIDTH - CELL_WIDTH - position.x >= CELL_WIDTH / 2)
    {
        moved = 1;
        direction = 1;
        position.x = std::min(CELL_WIDTH + position.x, MAP_WIDTH - CELL_WIDTH);
    }
    else if (0 == control_keys[1] &&
             1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
             position.y > MAP_HEIGHT - CELL_HEIGHT * 13 - 10)
    {
        moved = 1;
        direction = 2;
        position.y = std::max(position.y - CELL_HEIGHT, 0.f);
    }
    else if (0 == control_keys[2] &&
             1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
             position.x >= CELL_WIDTH / 2)
    {
        moved = 1;
        direction = 3;
        position.x = std::max(position.x - CELL_WIDTH, 0.f);
    }
    else if (0 == control_keys[3] &&
             1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
             position.y < MAP_HEIGHT - CELL_HEIGHT - 10)
    {
        moved = 1;
        direction = 4;
        position.y = std::min(CELL_HEIGHT + position.y, MAP_HEIGHT - CELL_HEIGHT);
    }

    control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    if (1 == moved)
    {
        m_sound.play(SOUNDBUFFERS::jump);
    }
}

STATUS People::getPlayingStatus() const
{
    return status;
}

sf::FloatRect People::getReact() const
{
    return {position.x, position.y, CELL_WIDTH, CELL_HEIGHT};
}

void People::saveGame(std::ofstream &fout)
{
    fout << position.x << '\n'
         << position.y << '\n';
}

void People::loadGame(std::ifstream &fin)
{
    fin >> position.x >> position.y;
    fin.ignore(1000, '\n');
}