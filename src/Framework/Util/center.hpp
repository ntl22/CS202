#ifndef SRC_FRAMEWORK_UTIL_CENTER
#define SRC_FRAMEWORK_UTIL_CENTER
#include <SFML/Graphics.hpp>

sf::Vector2f getCenter(sf::FloatRect &object);

void setCenterOrigin(sf::Transformable &object, sf::FloatRect &local_bound);

void setCenterPosition(sf::Transformable &object, sf::FloatRect &global_bound);

#endif /* SRC_FRAMEWORK_UTIL_CENTER */
