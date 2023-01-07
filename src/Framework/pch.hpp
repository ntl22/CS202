#ifndef SRC_FRAMEWORK_PCH
#define SRC_FRAMEWORK_PCH
/**
 * SFML Libraries
 */

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

/**
 * C++ Standard Library
 */

#include <string>
#include <stdexcept>
#include <memory>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <array>

/**
 * Framework library
 */

#include "Asset/manager.hpp"
#include "Asset/music.hpp"
#include "Asset/sound.hpp"

#include "State/manager.hpp"
#include "State/state.hpp"

#include "Util/identifier.hpp"
#include "Util/context.hpp"
#include "Util/center.hpp"

#include "Widget/widget.hpp"
#include "Widget/button.hpp"

/**
 * Path name
 */

constexpr char *FOLDER = "info/";
constexpr char *SAVE_FOLDER = "save/";

#endif /* SRC_FRAMEWORK_PCH */
