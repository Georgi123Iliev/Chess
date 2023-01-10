
#include "Rook.h"

[[nodiscard]] bool Rook::isValid(const BoardPosition& curr, const BoardPosition& dest) const noexcept
{
	return (curr.i==dest.i&&curr.j!=dest.j) || (curr.i != dest.i && curr.j == dest.j);
}

[[nodiscard]] bool Rook::isPathClear(const BoardPosition& curr, const BoardPosition& dest, const std::vector<std::vector<Status>>& simplifiedBoard) const noexcept
{

	if (curr.i == dest.i)
	{
		int start = curr.j > dest.j ? dest.j : curr.j;
		int destination = curr.j > dest.j ? curr.j :dest.j;
		for (auto temp=start+1;temp<destination;temp++)
		{
			if (simplifiedBoard[dest.i][temp] != Empty)
				return false;
		}
	}
	else
	{
		int start = curr.i > dest.i ? dest.i : curr.i;
		int destination = curr.i >  dest.i ? curr.i : dest.i;
		for (auto temp = start+1; temp < destination; temp++)
		{
			if (simplifiedBoard[temp][dest.j] != Empty)
				return false;
		}
	}
	return true;
}

Rook::Rook(const sf::Vector2f& position, bool isWhite)
	:Piece(position,isWhite)
{
	if (isWhite)
		sprite.setTexture(resources.WhiteRookTexture());
	else
		sprite.setTexture(resources.BlackRookTexture());
}

MoveType Rook::Move(const BoardPosition& dest)
{
	/*
	//get position on board

	BoardPosition curr(this->position);
	if (isValid(curr,dest) && isPathClear(curr,dest, simplifiedBoard))
	{
		hasMoved = true;
		return Normal;
	}
	*/
	return Failed;
}
