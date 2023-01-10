#pragma once
#include"Piece.h"
class Queen : public Piece
{
	[[nodiscard]] bool isValid(const BoardPosition& curr, const BoardPosition& dest) const noexcept;
	[[nodiscard]] bool isPathClear(const BoardPosition& curr, const BoardPosition& dest, const std::vector<std::vector<Status>>& simplifiedBoard) const noexcept;
public:
	Queen(const sf::Vector2f& position, bool isWhite);
	MoveType Move(const BoardPosition& dest) override;
};

