#ifndef SRC_FRAMEWORK_STATE_MANAGER
#define SRC_FRAMEWORK_STATE_MANAGER
#include "state.hpp"

#include <memory>
#include <vector>

class StateStack
{
public:
    void push(std::unique_ptr<State> state, bool is_replace = false);
    void pop();
    void clear();

    void handleStack();

    std::unique_ptr<State>& getCurrent();
    bool isEmpty() const;

private:
    std::vector<std::unique_ptr<State>> stack;
    std::unique_ptr<State> tmp_ptr;
    bool is_replace, is_push, is_pop, is_clear;
};

#endif /* SRC_FRAMEWORK_STATE_MANAGER */
