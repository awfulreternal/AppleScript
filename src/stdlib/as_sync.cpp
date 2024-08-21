#include "as_sync.h"

// Примеры методов для многозадачности
void startThread(void(*func)()) {
    std::thread t(func);
    t.detach();
}
