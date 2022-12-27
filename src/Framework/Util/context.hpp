#ifndef SRC_FRAMEWORK_UTIL_CONTEXT
#define SRC_FRAMEWORK_UTIL_CONTEXT
#include <memory>

namespace sf
{
    class RenderWindow;
}

class StateStack;

struct Context
{
    std::unique_ptr<StateStack> states;
    std::unique_ptr<sf::RenderWindow> window;

    Context();
};

#endif /* SRC_FRAMEWORK_UTIL_CONTEXT */
