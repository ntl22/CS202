#include "f_road.hpp"
std::unique_ptr<Lane> LaneFactory::createLane(float position,
                                              TextureMap &map,
                                              LANE_TYPE lane,
                                              OBJECT_TYPE object,
                                              unsigned speed)
{
    switch (lane)
    {
    case LANE_TYPE::goal:
        return std::unique_ptr<Lane>(new GoalLane(position, map));
    case LANE_TYPE::grass:
        return std::unique_ptr<Lane>(new GrassLane(position, map));
    case LANE_TYPE::street:
        return std::unique_ptr<Lane>(new ObstacleLane(position, map, object, speed));
    default:
        throw std::runtime_error("Lane::createLane(): invalid type");
    }
}