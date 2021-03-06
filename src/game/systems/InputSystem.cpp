//
// Created by kirill on 02.06.18.
//

#include "InputSystem.h"

InputSystem::InputSystem(World *world) : System(world) {}

void InputSystem::prepare() {
}

void InputSystem::finalize() {
}

Event<PlayerMoveEvent> *InputSystem::getPlayerControlEvent(InputEvent *inputEvent) {
    auto type = inputMap.find(inputEvent->keyCode);
    if (type != inputMap.end()) {
        return new Event<PlayerMoveEvent>(type->second);
    } else {
        return nullptr;
    }
}

void InputSystem::update() {

}

void InputSystem::onInputEvent(InputEvent *event) {
    Event<PlayerMoveEvent> *controlEvent = getPlayerControlEvent(event);
    if (controlEvent != nullptr) {
        getWorld()->getEventBus()->sendEvent(controlEvent);
    }
}
