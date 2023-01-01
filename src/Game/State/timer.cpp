#include "timer.hpp"

Timer::Timer(Context& context) :
    //is_pause(false),
    font_timer(context.fonts->get(FONTS::visitor1)),
    sec(0)
{
    text_timer.setFont(font_timer);
    text_timer.setPosition(5, 0);
    text_timer.setCharacterSize(30);
    text_timer.setFillColor(sf::Color::Red);
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
//
//void Timer::pause() {
//    sec = getPlayingTime().asSeconds
//}
//void Timer::resume() {
//
//}

//void Timer::update(bool isPause) {
//     
//}
//void Timer::handleEvent(bool is_pause) {
//        ///*if (ev.type == sf::Event::KeyPressed)
//        //{*/
//        //    if (/*ev.key.code == sf::Keyboard::P && */!is_pause)
//        //    {
//        //        //is_pause = true;
//        //        sec = getPlayingTime().asSeconds();
//        //    }
//        //    else if (/*ev.key.code == sf::Keyboard::P && */is_pause) {
//        //        //is_pause = false;
//        //        clock.restart();
//        //    }
//        ////}
//}

void Timer::draw(sf::RenderWindow& window) {
    sf::Time time = getPlayingTime();
    std::string str = formatTime(time);
    text_timer.setString(str);
    window.draw(text_timer);
}