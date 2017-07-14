
#include <SFML/Graphics.hpp>

#include "GoDataView.h"
#include "GoGameState.h"

GoDataView::GoDataView(const GoGameState &gs): goGameState(gs) {}

void GoDataView::draw(sf::RenderWindow &window, int width, int height)
{
    sf::RectangleShape shape(sf::Vector2f(400, 600));
    shape.setPosition({0, 0});
    shape.setFillColor(sf::Color(0x33, 0x33, 0x33));
    window.draw(shape);
}
