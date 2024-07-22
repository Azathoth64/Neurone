#ifndef NEURONE_PROCESS_HPP
#define NEURONE_PROCESS_HPP

#include <string>
#include <chrono>
#include <functional>
#include <type_traits>
#include <any>
#include <queue>

#include "identifier.h"
#include "signal.h"

namespace Neurone::Processes {

    typedef std::string Label;
    typedef uint32_t Priority;
    typedef std::queue<Signal> Signals;

    
    /// @brief All possible states of the process.
    enum ProcessStage {
        CREATED, // Process are just created
        WORKING, // Processing a some task
        STOPPED, // Process are stopped or completed processing a task
        WAIT     // Process in the waiting mode
    };

    /// @brief Interface of a process class that is responsible for asynchronous load balancing by tasks
    /// @note  The process can also receive signals for wider functionality
    /// @throw `std::invalid_argument` when `setLabel()` takes the empty parameter
    /// @throw `std::runtime_error` when `send()` takes the nullptr to the place of the subject object (`IProcess`) 
    class IProcess {
    private:
        Label        _label;
        Identifier   _identifier;
        Priority     _priority;
        ProcessStage _stage;
        Signals      _signals;

    protected:
        /// @brief  Launches the method who configures the requirements of the process start. 
        /// @param method 
        virtual void __start(std::function<void()> method);

        /// @brief Launches the method who configures the requirements of the process stop.
        /// @param method 
        virtual void __stop(std::function<void()> method);

        /// @brief Launches the method who update the process using the delta time.
        /// @param method 
        virtual void __async_work(std::function<void(float)> method);

        /// @brief Set stage of the process
        /// @param stage 
        virtual void setStage(ProcessStage stage);

    public:
        /// @brief Virtual destructor of the class
        virtual ~IProcess() = default;

        /// @brief Pure virtual method who be call when process appear on the `ProcessHandler`
        virtual void start() = 0;

        /// @brief Pure virtual method who be call when process disappear on the `ProcessHandler`
        virtual void stop()  = 0;
        
        /// @brief Pure virtual method who be call when process updates on the `ProcessHandler`
        /// @param delta 
        virtual void work(float delta) = 0;

        /// @brief Method who make delay between executing the process
        /// @param ms 
        virtual void wait(std::chrono::milliseconds ms);

        /// @brief Receive the signal from the others processes
        /// @param signal 
        virtual inline void receive(const Signal& signal);

        /// @brief Sends the signal to the other process.
        /// @param subject 
        /// @param signal 
        virtual inline void send(IProcess* subject, const Signal& signal);

        virtual void setIdentifier(const Identifier identifier);
        virtual void setLabel(const Label& label);
        virtual void setPriority(Priority priority);

        virtual Identifier  getIdentifier() const;
        virtual Label  getLabel() const;
        virtual ProcessStage getStage() const;
        virtual Priority   getPriority() const;
    };
}

#endif /* NEURONE_PROCESS_HPP */
