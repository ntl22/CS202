#include "Game/application.hpp"

int main()
{
    try
    {
        srand((unsigned)time(NULL));
        Application app;
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
