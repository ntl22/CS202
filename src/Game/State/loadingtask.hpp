#ifndef SRC_GAME_STATE_LOADINGTASK
#define SRC_GAME_STATE_LOADINGTASK
#include "../../Framework/pch.hpp"

class LoadingTask
{
public:
    LoadingTask(Context &context);

    void launchTask();
    bool isFinished() const;

private:
    sf::Mutex mutex;
    sf::Thread thread;
    bool is_finished;

    void loadingTask();

    Context tmp;
    Context &m_context;
};

#endif /* SRC_GAME_STATE_LOADINGTASK */
