#include "widget.hpp"

Widget::Widget() : focused(false), activated(false) {}

bool Widget::isFocused() const { return focused; }

void Widget::focus() { focused = true; }

void Widget::unfocus() { focused = false; }

bool Widget::isActivated() { return activated; }

void Widget::activate() { activated = true; }

void Widget::deactivate() { activated = false; }
