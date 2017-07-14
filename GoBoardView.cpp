
#include <SFML/Graphics.hpp>

#include "GoBoardView.h"
#include "GoGameState.h"

GoBoardView::GoBoardView(const GoGameState &gs): goGameState(gs) {}

void GoBoardView::draw(sf::RenderWindow &window)
{
    sf::RectangleShape shape(sf::Vector2f(600, 600));
    shape.setPosition({0, 0});
    shape.setFillColor(sf::Color(0x11, 0x11, 0x11));
    window.draw(shape);
}
