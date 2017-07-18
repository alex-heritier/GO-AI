
#include <SFML/Graphics.hpp>

#include "GoDataView.h"
#include "GoGameState.h"

GoDataView::GoDataView(sf::RenderWindow &window, const GoGameState &gs, int width, int height):
    window(window),
    goGameState(gs),
    width(width),
    height(height) {}

void GoDataView::draw()
{
    // Draw background
    sf::RectangleShape bg(sf::Vector2f(400, 600));
    bg.setPosition(0, 0);
    bg.setFillColor(sf::Color(0x33, 0x33, 0x33));
    window.draw(bg);

    sf::Font font;
    font.loadFromFile("/Users/Alex/Desktop/Work/GO-AI/arial.ttf");

    sf::Text title;
    title.setFont(font);
    title.setString("Go-AI Data");
    title.setCharacterSize(20);
    title.setStyle(sf::Text::Bold);
    title.setFillColor(sf::Color::White);
    title.setPosition(10, 10);
    window.draw(title);

    sf::Text whiteScore;
    whiteScore.setFont(font);
    whiteScore.setString(std::string("White score: ") + std::to_string(goGameState.getBlackDead()));
    whiteScore.setCharacterSize(20);
    whiteScore.setStyle(sf::Text::Bold);
    whiteScore.setFillColor(sf::Color::White);
    whiteScore.setPosition(10, 40);
    window.draw(whiteScore);

    sf::Text blackScore;
    blackScore.setFont(font);
    blackScore.setString(std::string("Black score: ") + std::to_string(goGameState.getWhiteDead()));
    blackScore.setCharacterSize(20);
    blackScore.setStyle(sf::Text::Bold);
    blackScore.setFillColor(sf::Color::White);
    blackScore.setPosition(10, 70);
    window.draw(blackScore);
}
