#include "Queen.h"

[[nodiscard]] bool Queen::isValid(const BoardPosition& curr, const BoardPosition& dest) const noexcept
{
	return (curr.i == dest.i && curr.j != dest.j) || (curr.i != dest.i && curr.j == dest.j) || (!(curr.i == dest.i && curr.j == dest.j)) && (dest.i + dest.j == curr.i + curr.j || (dest.i - dest.j == curr.i - curr.j));
}

[[nodiscard]] bool Queen::isPathClear(const BoardPosition& curr, const BoardPosition& dest, const std::vector<std::vector<Status>>& simplifiedBoard) const noexcept
{
	if (dest.i - dest.j == curr.i - curr.j)
	{
		auto Istart = (dest.i < curr.i ? dest.i : curr.i);
		auto Jstart = (dest.j < curr.j ? dest.j : curr.j);
		auto Iend = dest.i > curr.i ? dest.i : curr.i;
		for (size_t k = Istart, p = Jstart; k < Iend; k++, p++)
		{
			std::cout << k + 1 << " " << p + 1 << std::endl;
			if (((k != curr.i && p != curr.j)&& (k != dest.i && p != dest.j)) && simplifiedBoard[k][p] != Empty)
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
	else if (curr.i == dest.i)
	{
		int start = curr.j > dest.j ? dest.j : curr.j;
		int destination = curr.j > dest.j ? curr.j : dest.j;
		for (auto temp = start + 1; temp < destination; temp++)
		{
			if (simplifiedBoard[dest.i][temp] != Empty)
				return false;
		}
	}
	else
	{
		int start = curr.i > dest.i ? dest.i : curr.i;
		int destination = curr.i > dest.i ? curr.i : dest.i;
		for (auto temp = start + 1; temp < destination; temp++)
		{
			if (simplifiedBoard[temp][dest.j] != Empty)
				return false;
		}
	}
	return true;
}

Queen::Queen(const sf::Vector2f& position, bool isWhite)
	:Piece(position,isWhite)
{
	if (isWhite)
	{
		sprite.setTexture(resources.WhiteQueenTexture());
	}
	else
	{
		sprite.setTexture(resources.BlackQueenTexture());
	}
}

MoveType Queen::Move(const BoardPosition& dest)
{
	/*
	BoardPosition curr(this->position);
	if (isValid(curr,dest) && isPathClear(curr,dest, simplifiedBoard))
		return Normal;
		*/
	return Failed;
}
