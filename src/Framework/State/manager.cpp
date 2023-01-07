#include "manager.hpp"

void StateStack::push(std::unique_ptr<State> state, bool is_replace)
{
    this->is_replace = is_replace;
    is_push = true;
    tmp_ptr = std::move(state);
}

void StateStack::pop() { is_pop = true; }

void StateStack::clear() { is_clear = true; }

void StateStack::handleStack()
{
    if (is_clear)
    {
        stack.swap(std::vector<std::unique_ptr<State>>());
        is_clear = false;
    }
    if (is_pop && !stack.empty())
    {
        stack.pop_back();
        is_pop = false;
    }
    if (is_push)
    {
        if (is_replace && !stack.empty())
            stack.pop_back();
        stack.push_back(std::move(tmp_ptr));
        is_push = is_replace = false;
    }
}

std::unique_ptr<State> &StateStack::getCurrent()
{
    return stack.back();
}

bool StateStack::isEmpty() const { return stack.empty(); }
