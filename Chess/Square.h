#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Pawn.h"
#include"Knight.h"
#include"Rook.h"
#include"Bishop.h"
#include"Queen.h"
class Square
{
	
	Status status{ Empty };
	bool enPassentAble{ false };
	sf::RectangleShape square_m;
	std::unique_ptr<Piece> piece_m{nullptr};
	
public:
	auto isEmpty() const
	{
		return status==Empty;
	}
	Square(const sf::Vector2f& position, const sf::Color& color, float size);
	
	Square() = default;
	void operator=(Square&& other) noexcept;
	const auto& squareDrawable() const
	{
		return square_m;
	}

	const auto& pieceDrawable() const
	{
		
		if (status==Empty)
			throw std::exception("Attempting to draw nonexistent piece!");

		return piece_m->drawable();
	}
	void acceptPiece(Square& other);
	Piece* getPiece() const;
	void destroyPiece();
	
	const auto& getStatus() const
	{
		return status;
	}
};

