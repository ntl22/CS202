#ifndef SRC_FRAMEWORK_UTIL_CONTEXT
#define SRC_FRAMEWORK_UTIL_CONTEXT
#include <memory>

namespace sf
{
    class RenderWindow;
}

struct Context
{
    typedef std::shared_ptr<Context> pointer;

    std::unique_ptr<sf::RenderWindow> window;

    Context();
};

#endif /* SRC_FRAMEWORK_UTIL_CONTEXT */
