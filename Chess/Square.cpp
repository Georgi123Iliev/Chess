#include "Square.h"

Square::Square(const sf::Vector2f& position, const sf::Color& color, float size)
{
	square_m.setFillColor(color);
	square_m.setPosition(position);
	square_m.setSize(sf::Vector2f(size, size));

	int i = static_cast<int>(position.y/80.f);
	int j = static_cast<int>(position.x / 80.f);
	/*
	if (i == 1)
	{
		piece_m.reset(new Pawn(position, false));
		status = Black;
	}
	if (i == 6)
	{
		piece_m.reset(new Pawn(position, true));
		status = White;
	}
	if (i == 0 && (j == 1 || j == 6))
	{
		piece_m.reset(new Knight(position, false));
		status = Black;
	}
	if (i == 7 && (j == 1 || j == 6))
	{
		piece_m.reset(new Knight(position, true));
		status = White;
	}
	if (i == 0 && (j == 0 || j == 7))
	{
		piece_m.reset(new Rook(position, false));
		status = Black;
	}
	if (i == 7 && (j == 0 || j == 7))
	{
		piece_m.reset(new Rook(position, true));
		status = White;
	}
	*/
	if (i == 0 && (j == 2 || j == 5))
	{
		piece_m.reset(new Bishop(position, false));
		status = Black;
	}
	if (i == 7 && (j == 2 || j == 5))
	{
		piece_m.reset(new Bishop(position, true));
		status = White;
	}
	if (i == 0&&j==3)
	{
		piece_m.reset(new Queen(position, false));
		status = Black;
	}
	if (i == 7 && j==3)
	{
		piece_m.reset(new Queen(position, true));
		status = White;
	}
}

void Square::operator=(Square&& other) noexcept
{
	status = other.status;
	square_m = std::move(other.square_m);

	piece_m = std::move(other.piece_m);
}

void Square::acceptPiece(Square& other)
{
	status = other.status;
	other.status = Empty;
	piece_m = std::move(other.piece_m);
	other.piece_m = nullptr;
}

Piece* Square::getPiece() const
{
	return piece_m.get();
}

void Square::destroyPiece()
{
	status = Empty;
	auto ptr = piece_m.get();
	piece_m.release();
	delete ptr;	
}
