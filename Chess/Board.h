#pragma once
#include<vector>
#include"Pawn.h"
#include"Square.h"

class Board
{
	std::vector<std::vector<Square>> board_m;
	std::vector<std::vector<Status>> simplifiedBoard;
	Piece* toMove_m{ nullptr };

   [[nodiscard]] constexpr bool inBounds(const BoardPosition& pos) const noexcept;
#ifdef _DEBUG
	void outputBoard() const;
#endif // _DEBUG

	
public:
	Board(float WinSize);
	
	
	void clicked(const sf::Vector2f& pos, bool& isWhite);
	const auto& toDraw() const
	{
		return board_m;
	}
	
};

