
#include"Piece.h"
class Rook: public Piece
{

	bool hasMoved{ false };
	[[nodiscard]] bool isValid(const BoardPosition& curr, const BoardPosition& dest) const noexcept;
	[[nodiscard]] bool isPathClear(const BoardPosition& curr, const BoardPosition& dest, const std::vector<std::vector<Status>>& simplifiedBoard) const noexcept;
public:
	Rook() = default;
	Rook(const sf::Vector2f& position, bool isWhite);
	MoveType Move(const BoardPosition& dest) override;
};
