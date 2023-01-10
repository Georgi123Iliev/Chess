#include "Pawn.h"

constexpr int Pawn::direction()
{
	return isWhite ? -1 : 1;
}

Pawn::Pawn(const sf::Vector2f& position, bool isWhite)
	:Piece(position, isWhite)
{
	if (isWhite)
		sprite.setTexture(resources.WhitePawnTexture());
	else
	{
		sprite.setTexture(resources.BlackPawnTexture());
	}

}

MoveType Pawn::Move(const BoardPosition& dest)
{
	/*
	//get position on board


	BoardPosition curr(this->position);
	auto dist  = dest.i - curr.i;
	//forward movement
	if (curr.j - dest.j == 0)
	{
		if (dist == direction())
		{
			if (simplifiedBoard[dest.i][dest.j] == Empty)
			{
				firstMove = false;

				return Normal;
			}
		}
		else if (firstMove && dist == direction() * 2)
		{
			if (simplifiedBoard[dest.i][dest.j] == Empty && simplifiedBoard[dest.i - direction()][dest.j] == Empty)
			{
				firstMove = false;
				enPassantAble = true;
				return Normal;
			}
		}
	}
	//diagonal taking
	else if (abs(curr.j - dest.j) == 1 && curr.i + direction() == dest.i)
	{
		bool valid = false;
		switch (isWhite)
		{
		case true:
		{
			valid = simplifiedBoard[dest.i][dest.j] == Black;
			break;
		}
		case false:
		{
			valid = simplifiedBoard[dest.i][dest.j] == White;
			break;
		}
		}
		if (valid)
		{
			firstMove = false;

			return Normal;
		}

		//en passant
		switch (isWhite)
		{
		case true:
		{
			valid = simplifiedBoard[dest.i - direction()][dest.j] == Black;
			break;
		}
		case false:
		{
			valid = simplifiedBoard[dest.i - direction()][dest.j] == White;
			break;
		}
		}
		if (valid)
		{
			firstMove = false;

			return EnPassant;
		}
	}
	*/

	return Failed;
}
