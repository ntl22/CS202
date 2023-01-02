#include "timer.hpp"

Timer::Timer(Context &context)
    : tmp_time(sf::Time::Zero),
      font_timer(context.fonts->get(FONTS::visitor1)),
      sec(0), min(0), hour(0), from_pause_state(false)
{
    text_timer.setFont(font_timer);
    text_timer.setPosition(5, 0);
    text_timer.setCharacterSize(30);
    text_timer.setFillColor(sf::Color::Red);
    text_timer.setString(formatTime());
}

void Timer::pushPauseState()
{
    from_pause_state = true;
}

void Timer::update()
{
    if (from_pause_state)
    {
        from_pause_state = false;
        clock.restart();
        return;
    }

    tmp_time += clock.restart();
    while (tmp_time >= sf::seconds(1.f))
    {
        tmp_time -= sf::seconds(1.f);

        ++sec;
        if (sec > 60)
            sec = 0, ++min;
        if (min > 60)
            min = 0, ++hour;
    }
    text_timer.setString(formatTime());
}

std::string Timer::formatTime()
{
    std::stringstream str;
    int s = sec;
    int m = min;
    int h = hour;

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
        str << ":"
            << "0" << m;
    }
    else
    {
        str << ":" << m;
    }
    if (s < 10)
    {
        str << ":"
            << "0" << s;
    }
    else
    {
        str << ":" << s;
    }

    return str.str();
}

void Timer::draw(sf::RenderWindow &window)
{
    window.draw(text_timer);
}