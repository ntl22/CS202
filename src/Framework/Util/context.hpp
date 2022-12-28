#ifndef SRC_FRAMEWORK_UTIL_CONTEXT
#define SRC_FRAMEWORK_UTIL_CONTEXT
#include <SFML/Graphics.hpp>
#include <memory>

enum class TEXTURE_LIST;
enum class FONT_LIST;

namespace sf
{
    class RenderWindow;
}

class StateStack;

struct Context
{
    typedef std::shared_ptr<Context> pointer_type;

    std::unique_ptr<StateStack> states;
    std::unique_ptr<sf::RenderWindow> window;

    Context();
};

#endif /* SRC_FRAMEWORK_UTIL_CONTEXT */
