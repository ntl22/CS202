#ifndef SRC_FRAMEWORK_UTIL_CONTEXT
#define SRC_FRAMEWORK_UTIL_CONTEXT
#include "../Asset/manager.hpp"
#include "../State/manager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

#include <memory>

enum class FONTS;
enum class TEXTURES;

class StateStack;

struct Context
{
    std::unique_ptr<MediaMachine<TEXTURES, sf::Texture>> textures;
    std::unique_ptr<MediaMachine<FONTS, sf::Font>> fonts;
    std::unique_ptr<StateStack> states;
    std::unique_ptr<sf::RenderWindow> window;

    Context();
};

#endif /* SRC_FRAMEWORK_UTIL_CONTEXT */
