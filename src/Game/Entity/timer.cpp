#include "timer.hpp"
Timer::Timer(Context& context)
{
    to_text.setFont(context.fonts->get(FONTS::visitor1));
    to_text.setPosition(15, 0);
    to_text.setCharacterSize(40U);
    to_text.setFillColor(sf::Color::Red);
    to_text.setString("00:00:00");
}

void Timer::exitPauseState()
{
    (void)clock.restart();
}

sf::Time Timer::update()
{
    sf::Time dt = clock.restart();
    timer += dt;
    return dt;
}

void Timer::draw(sf::RenderWindow& window)
{
    updateString();
    window.draw(to_text);
}

void Timer::loadGame(std::ifstream& fin)
{
    float seconds;
    fin >> seconds;
    timer = sf::seconds(seconds);
    fin.ignore(1000, '\n');
}

void Timer::saveGame(std::ofstream& fout)
{
    fout << timer.asSeconds() << '\n';
}

void Timer::updateString()
{
    std::stringstream ss;

    unsigned toSec = (unsigned)timer.asSeconds();
    unsigned h = toSec / 3600;
    unsigned m = (toSec - (h * 3600)) / 60;
    unsigned s = toSec - (h * 3600 + m * 60);

    ss << (h < 10 ? "0" : "") + std::to_string(h) << ":";
    ss << (m < 10 ? "0" : "") + std::to_string(m) << ":";
    ss << (s < 10 ? "0" : "") + std::to_string(s);

    to_text.setString(ss.str());
}
