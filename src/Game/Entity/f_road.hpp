#ifndef SRC_GAME_ENTITY_F_ROAD
#define SRC_GAME_ENTITY_F_ROAD
#include "../../Framework/pch.hpp"
#include "road.hpp"

enum class LANE_TYPE
{
    goal,
    grass,
    street
};

class LaneFactory
{
public:
    static std::unique_ptr<Lane> createLane(float position,
                                            TextureMap &map,
                                            LANE_TYPE lane,
                                            OBJECT_TYPE object = OBJECT_TYPE::NONE,
                                            unsigned speed = 0);
};

#endif /* SRC_GAME_ENTITY_F_ROAD */
