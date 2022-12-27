#ifndef SRC_FRAMEWORK_WIDGET_WIDGET
#define SRC_FRAMEWORK_WIDGET_WIDGET
#include <SFML/Graphics.hpp>

class Widget : public sf::Drawable, private sf::NonCopyable
{
public:
    Widget();

    virtual bool isSelectable() const = 0;

    bool isFocused() const;
    virtual void focus();
    virtual void unfocus();

    virtual bool isActivated();
    virtual void activate();
    virtual void deactivate();

private:
    bool focused, activated;
};

#endif /* SRC_FRAMEWORK_WIDGET_WIDGET */
