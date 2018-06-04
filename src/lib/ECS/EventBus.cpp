//
// Created by k.leyfer on 01.06.2018.
//

#include <iostream>
#include <EventBus.h>

void EventBus::update() {
    std::cout << __FUNCTION__ << std::endl;

    // Protect from invoke() { sendEvent(); } loop.
    unsigned long queueSize = eventQueue.size();

    for (int i = 0; i < queueSize; ++i) {
        BaseEvent *event = eventQueue.front();
        EventType type = event->getType();
        if (listenerMap.find(type) != listenerMap.end()) {
            for (auto *delegate : listenerMap.at(type)) {
                delegate->invoke(event);
            }
        }

        eventQueue.pop();
        delete (event);
    }
}