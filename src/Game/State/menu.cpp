#include "menu.hpp"

#include <iostream>

MenuState::MenuState(std::shared_ptr<Context> context)
    : context(context) {}

void MenuState::handleEvent(const sf::Event& ev) {}

void MenuState::update(sf::Time dt) {}

void MenuState::draw() {}
