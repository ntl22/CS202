#include "button.hpp"

#include "../Util/context.hpp"
#include "../Util/center.hpp"

Button::Button(sf::RenderWindow &w, const sf::Font &f)
    : window(w), font(f)
{
    bound.setFillColor(sf::Color::Transparent);
    text.setFont(font);
    text.setOutlineThickness(5.f);
    text.setOutlineColor(sf::Color::Black);
    text.setCharacterSize(70U);
}

bool Button::isSelectable() const { return true; }

void Button::focus()
{
    Widget::focus();
    text.setFillColor(color);
}

void Button::unfocus()
{
    Widget::unfocus();
    text.setFillColor(sf::Color::White);
}

void Button::activate()
{
    Widget::activate();
    if (callback)
        callback();
    deactivate();
}

void Button::deactivate()
{
    Widget::deactivate();
    text.setFillColor(isActivated() ? color : sf::Color::White);
}

void Button::setCallback(std::function<void(void)> callback)
{
    this->callback = std::move(callback);
}

void Button::setText(const std::string &text)
{
    this->text.setString(text);
    bound.setSize({this->text.getGlobalBounds().width,
                   this->text.getGlobalBounds().height});
}

void Button::setHoverColor(const sf::Color &color)
{
    this->color = std::move(color);
}

void Button::setPosition(const sf::Vector2f &position)
{
    pos = std::move(position);
    setCenterOrigin(bound, bound.getLocalBounds());
    bound.setPosition(pos);
    centerButton();
}

sf::Vector2f Button::getSize() const
{
    return bound.getSize();
}

bool Button::isInWidget(const sf::Vector2f &position) const
{
    return bound.getGlobalBounds().contains(position);
}

void Button::centerButton()
{
    setCenterOrigin(text, text.getLocalBounds());
    setCenterPosition(text, bound.getGlobalBounds());
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(bound, states);
    target.draw(text, states);
}
