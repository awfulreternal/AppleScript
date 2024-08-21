#include "as_threading.h"

namespace as {

Thread::Thread(std::function<void()> func) : thread(func) {}

void Thread::start() {
    thread = std::thread([this] { thread.join(); });
}

void Thread::join() {
    if (thread.joinable()) {
        thread.join();
    }
}

} // namespace as
