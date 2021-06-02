#pragma once

#include <map>
#include <functional>
#include "eSignals.hpp"

template <typename T>
class observer {
    std::map<eSignals, std::map<int, std::function<void(T&)>>> m_events;
public:
    void connect(int senderID, eSignals signal, std::function<void(T&)> slot);
    void dispatch(T& sender, eSignals signal);
    observer();
};

template <typename T>
observer<T>::observer() {

}

template <typename T>
void observer<T>::dispatch(T& sender, eSignals signal) {
    if(m_events[signal][sender.getID()]) m_events[signal][sender.getID()](sender);
}

template <typename T>
void observer<T>::connect(int senderID, eSignals signal, std::function<void(T&)> slot) {
    m_events[signal][senderID] = slot;
}