#include "Piece.h"


const sf::Sprite& Piece::drawable() const
{
	return sprite;
}
void Piece::updatePosition(const sf::Vector2f& position)
{
	this->position = position;
	sprite.setPosition(position);
}
Piece::Piece(const sf::Vector2f& position, bool isWhite)
	: position(position), isWhite(isWhite)
{
	sprite.setPosition(position);

}
bool Piece::IsWhite() const
{
	return isWhite;
}

const sf::Vector2f& Piece::getPos() const
{
	return position;
}

