#pragma once
#include"Piece.h"
class Knight : public Piece
{
public:
	Knight(const sf::Vector2f& position, bool isWhite);
	MoveType Move(const BoardPosition& dest)override;
	
};

