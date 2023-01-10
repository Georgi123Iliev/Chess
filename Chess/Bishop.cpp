#include "Bishop.h"

[[nodiscard]] bool Bishop::isValid(const BoardPosition& curr, const BoardPosition& dest) const noexcept
{
	return (!(curr.i == dest.i && curr.j == dest.j)) && ((dest.i + dest.j == curr.i + curr.j) || (dest.i - dest.j == curr.i - curr.j));
}

[[nodiscard]] bool Bishop::isPathClear(const BoardPosition& curr, const BoardPosition& dest, const std::vector<std::vector<Status>>& simplifiedBoard) const noexcept
{
	if (dest.i - dest.j == curr.i - curr.j)
	{
		auto Istart = (dest.i < curr.i ? dest.i : curr.i);
		auto Jstart = (dest.j < curr.j ? dest.j : curr.j);
		auto Iend = dest.i > curr.i ? dest.i : curr.i;
		for (size_t k = Istart, p = Jstart; k < Iend; k++, p++)
		{
			std::cout << k + 1 << " " << p + 1 << std::endl;
			if (((k != curr.i && p != curr.j) && (k != dest.i && p != dest.j)) && simplifiedBoard[k][p] != Empty)
				return false;
		}
	}
	else if (dest.i + dest.j == curr.i + curr.j)
	{
		auto Istart = (dest.i < curr.i ? dest.i : curr.i);
		auto Jstart = (dest.j > curr.j ? dest.j : curr.j);
		auto Iend = dest.i > curr.i ? dest.i : curr.i;
		for (size_t k = Istart, p = Jstart; k < Iend; k++, p--)
		{
			std::cout << k + 1 << " " << p + 1 << std::endl;
			if (((k != curr.i && p != curr.j) && (k != dest.i && p != dest.j)) && simplifiedBoard[k][p] != Empty)
				return false;
		}
	}
	std::cout << std::endl;
	return true;
}

Bishop::Bishop(const sf::Vector2f& position, bool isWhite)
	:Piece(position,isWhite)
{
	if (isWhite)
		sprite.setTexture(resources.WhiteBishopTexture());
	else
		sprite.setTexture(resources.BlackBishopTexture());
}

MoveType Bishop::Move(const BoardPosition& dest)
{
	//get position on board

	/*
	BoardPosition curr(this->position);
	if(isValid(curr,dest)&&isPathClear(curr,dest, simplifiedBoard))
		return Normal;
		*/
	return Failed;
}
