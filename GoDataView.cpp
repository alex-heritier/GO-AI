
#include <SFML/Graphics.hpp>

#include "GoDataView.h"
#include "GoGameState.h"

GoDataView::GoDataView(const GoGameState &gs): goGameState(gs) {}

void GoDataView::draw(sf::RenderWindow &window)
{
    sf::RectangleShape shape(sf::Vector2f(400, 600));
    shape.setPosition({0, 0});
    shape.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape);
}
