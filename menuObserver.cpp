#include "menuObserver.hpp"
#include "menu.hpp"

menuObserver::menuObserver() {
    
}

void menuObserver::dispatch(int signal) {
    m_events[signal]();
}

void menuObserver::connect(int signal, std::function<void()> slot) {
    m_events[signal] = slot;
}
