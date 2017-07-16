
#include <SFML/Graphics.hpp>

#include "GoDataView.h"
#include "GoGameState.h"

GoDataView::GoDataView(const GoGameState &gs): goGameState(gs) {}

void GoDataView::draw(sf::RenderWindow &window, int width, int height)
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
    title.setColor(sf::Color::White);
    title.setPosition(10, 10);
    window.draw(title);

    sf::Text whiteScore;
    whiteScore.setFont(font);
    whiteScore.setString(std::string("White score: ") + std::to_string(goGameState.getBlackDead()));
    whiteScore.setCharacterSize(20);
    whiteScore.setStyle(sf::Text::Bold);
    whiteScore.setColor(sf::Color::White);
    whiteScore.setPosition(10, 40);
    window.draw(whiteScore);

    sf::Text blackScore;
    blackScore.setFont(font);
    blackScore.setString(std::string("Black score: ") + std::to_string(goGameState.getWhiteDead()));
    blackScore.setCharacterSize(20);
    blackScore.setStyle(sf::Text::Bold);
    blackScore.setColor(sf::Color::White);
    blackScore.setPosition(10, 70);
    window.draw(blackScore);
}
