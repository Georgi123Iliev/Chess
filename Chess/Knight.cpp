#include "Knight.h"

Knight::Knight(const sf::Vector2f& position, bool isWhite)
	:Piece(position,isWhite)
{
	if (isWhite)
		sprite.setTexture(resources.WhiteKnightTexture());
	else
		sprite.setTexture(resources.BlackKnightTexture());
	
}

MoveType Knight::Move(const BoardPosition& dest)
{
	
	/*

	BoardPosition curr(this->position);

	if (!((dest.i == curr.i - 2 && (dest.j == curr.j + 1 || dest.j == curr.j - 1)) ||
		  (dest.i == curr.i + 2 && (dest.j == curr.j + 1 || dest.j == curr.j - 1)) ||
		(dest.j == curr.j - 2 && (dest.i == curr.i + 1 || dest.i == curr.i - 1)) ||
		(dest.j == curr.j + 2 && (dest.i == curr.i + 1 || dest.i == curr.i - 1))
		))
		return Failed;
*/
	return Normal;
	

}
