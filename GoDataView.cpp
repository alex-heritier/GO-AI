
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
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(1);
    title.setPosition(10, 10);
    window.draw(title);

    sf::Text whiteDead;
    whiteDead.setFont(font);
    whiteDead.setString(std::string("White dead: ") + std::to_string(goGameState.getWhiteDead()));
    whiteDead.setCharacterSize(20);
    whiteDead.setStyle(sf::Text::Bold);
    whiteDead.setFillColor(sf::Color::White);
    whiteDead.setOutlineColor(sf::Color::Black);
    whiteDead.setOutlineThickness(1);
    whiteDead.setPosition(10, 40);
    window.draw(whiteDead);

    sf::Text blackDead;
    blackDead.setFont(font);
    blackDead.setString(std::string("Black dead: ") + std::to_string(goGameState.getBlackDead()));
    blackDead.setCharacterSize(20);
    blackDead.setStyle(sf::Text::Bold);
    blackDead.setFillColor(sf::Color::White);
    blackDead.setOutlineColor(sf::Color::Black);
    blackDead.setOutlineThickness(1);
    blackDead.setPosition(10, 70);
    window.draw(blackDead);

    sf::Text activePlayer;
    activePlayer.setFont(font);
    activePlayer.setString(std::string("Active player: ") + std::string(goGameState.activePlayer ? "White" : "Black"));
    activePlayer.setCharacterSize(20);
    activePlayer.setStyle(sf::Text::Bold);
    activePlayer.setFillColor(sf::Color::White);
    activePlayer.setOutlineColor(sf::Color::Black);
    activePlayer.setOutlineThickness(1);
    activePlayer.setPosition(10, 100);
    window.draw(activePlayer);

    sf::Text turn;
    turn.setFont(font);
    turn.setString(std::string("Turn: ") + std::to_string(goGameState.turn));
    turn.setCharacterSize(20);
    turn.setStyle(sf::Text::Bold);
    turn.setFillColor(sf::Color::White);
    turn.setOutlineColor(sf::Color::Black);
    turn.setOutlineThickness(1);
    turn.setPosition(10, 130);
    window.draw(turn);
}
