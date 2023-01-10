#pragma once
#include"Piece.h"


#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
class Pawn :public Piece
{

	//determines whether the pawn moves up or down depending on color
	constexpr int direction();
	
	
	bool firstMove{ true };

public:
	Pawn(const sf::Vector2f& position, bool isWhite);
		
	
	
	MoveType Move(const BoardPosition& dest) override;
	
	
};

