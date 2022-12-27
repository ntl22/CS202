#ifndef SRC_FRAMEWORK_WIDGET_BUTTON
#define SRC_FRAMEWORK_WIDGET_BUTTON
#include "widget.hpp"

#include <functional>

struct Context;

class Button : public Widget
{
public:
    Button(std::shared_ptr<Context> context);

    void setCallback(std::function<void(void)> callback);
    void setText(const std::string &text);
    void setHoverColor(const sf::Color &color);
    void setPosition(const sf::Vector2f &position);
    sf::Vector2f getSize() const;
    bool isInWidget(const sf::Vector2f &position) const;

    bool isSelectable() const;
    void focus();
    void unfocus();
    void activate();
    void deactivate();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void centerButton();

    sf::Vector2f pos;
    sf::RectangleShape bound;
    sf::Text text;
    sf::Font font;
    sf::Color color;
    std::function<void(void)> callback;

    std::shared_ptr<Context> context;
};

#endif /* SRC_FRAMEWORK_WIDGET_BUTTON */
