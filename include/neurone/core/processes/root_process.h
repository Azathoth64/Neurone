#ifndef B94B79E8_1151_4D38_BC39_A0A570EDB35D
#define B94B79E8_1151_4D38_BC39_A0A570EDB35D

#include <process.h>

#include <list>
#include <memory>

namespace Neurone::Processes
{
    class ProcessHandler {
    public:
        ProcessHandler() = default;
        ~ProcessHandler();

        void start();
        void stop();
        IProcess* initialize(IProcess* process);
        void update(float delta);

    private:
        std::list<std::shared_ptr<IProcess>> _processes;
    };
}

#endif /* B94B79E8_1151_4D38_BC39_A0A570EDB35D */
