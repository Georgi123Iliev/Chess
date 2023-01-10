#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<optional>
#include"Resources.h"
enum MoveType { Normal,Failed,EnPassant, Castle, Promotion };
#define CWHOLE(c) c.cbegin(),c.cend()
enum Status { Empty,White, Black };
class Piece
{
	
protected:
	bool isWhite;
	
	sf::Sprite sprite;
	sf::Vector2f position;

	
	
	

public:
	//return position to destroy and nothing if move is invalid
	virtual MoveType Move(const BoardPosition& dest) = 0;
	const sf::Sprite& drawable() const;
	
	void updatePosition(const sf::Vector2f& position);
	Piece() = default;
	Piece(const sf::Vector2f& position, bool isWhite);
		
	bool IsWhite() const;
	bool enPassantAble{ false };
	const sf::Vector2f& getPos() const;
	
	
};

