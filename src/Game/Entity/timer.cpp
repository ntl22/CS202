#include "timer.hpp"

Timer::Timer(Context& context)
{
    to_text.setFont(context.fonts->get(FONTS::visitor1));
    to_text.setPosition(15, 0);
    to_text.setCharacterSize(40U);
    to_text.setFillColor(sf::Color::Red);
    to_text.setString("00:00:00");
}

sf::Time Timer::getPlayingTime() {
    return clock.getElapsedTime();
}
std::string Timer::formatTime(const sf::Time& time) {
    std::stringstream str;
    int s = 0;
    int m = 0;
    int h = 0;

    s = time.asSeconds() + sec;
    h = s / 3600;
    m = (s - (h * 3600)) / 60;
    s = s - (h * 3600 + m * 60);

    if (h < 10)
    {
        str << "0" << h;
    }
    else
    {
        str << h;
    }
    if (m < 10)
    {
        str << ":" << "0" << m;
    }
    else
    {
        str << ":" << m;
    }
    if (s < 10)
    {
        str << ":" << "0" << s;
    }
    else
    {
        str << ":" << s;
    }

    return str.str();
}

bool Timer::isPause() {
    return is_pause;
}

void Timer::pause() {
    is_pause = true;
    sec += clock.restart().asSeconds();
}
void Timer::resume() {
    is_pause = false;
    clock.restart();
}

void Timer::draw(sf::RenderWindow& window)
{
    updateString();
    window.draw(to_text);
}

//void Timer::loadGame(std::ifstream& fin)
//{
//    float seconds;
//    fin >> seconds;
//    timer = sf::seconds(seconds);
//    fin.ignore(1000, '\n');
//}
//
//void Timer::saveGame(std::ofstream& fout)
//{
//    fout << timer.asSeconds() << '\n';
//}

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
