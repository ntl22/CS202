#include "center.hpp"

sf::Vector2f getCenter(sf::FloatRect &object)
{
    return {object.left + object.width / 2.f,
            object.top + object.height / 2.f};
}

void setCenterOrigin(sf::Transformable &object, sf::FloatRect &local_bound)
{
    object.setOrigin(getCenter(local_bound));
}

void setCenterPosition(sf::Transformable &object, sf::FloatRect &global_bound)
{
    object.setPosition(getCenter(global_bound));
}
