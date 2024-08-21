#ifndef AS_THREADING_H
#define AS_THREADING_H

#include <thread>
#include <functional>

namespace as {

class Thread {
public:
    Thread(std::function<void()> func);
    void start();
    void join();

private:
    std::thread thread;
};

} // namespace as

#endif
