#pragma once

#include <map>
#include <functional>

class menuObserver {
    std::map<int, std::function<void()>> m_events;
public:
    void connect(int signal, std::function<void()> slot);
    void dispatch(int signal);
    menuObserver();
};
