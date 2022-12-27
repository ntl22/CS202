#ifndef SRC_GAME_ENTITY_STATE
#define SRC_GAME_ENTITY_STATE
// TODO: add a state (screen) base class

class State
{
public:
    typedef std::unique_ptr<State> pointer_type;

    virtual ~State() = default;

    /**
     * Prerequisite task of a state
     */

    virtual void handleEvent(const sf::Event& ev) = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void draw() = 0;
};

#endif /* SRC_GAME_ENTITY_STATE */
