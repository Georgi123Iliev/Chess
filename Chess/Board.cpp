#include "Board.h"

constexpr bool Board::inBounds(const BoardPosition& pos) const noexcept
{
	return pos.i >= 0 && pos.j >= 0 && pos.i < 8 && pos.j < 8;
}
#ifdef _DEBUG
void Board::outputBoard() const
{
	std::for_each(CWHOLE(simplifiedBoard), [](const auto& row)
		{
			std::for_each(CWHOLE(row), [](const auto& square) {std::cout << square << " "; });
			std::cout << "\n";
		});
	std::cout << "\n";
}
#endif // _DEBUG
Board::Board(float WinSize)
{
	//initialize board

	board_m.reserve(8);
	simplifiedBoard.reserve(8);
	float squareSize = WinSize / 8.f;
	for (size_t i = 0; i < 8; i++)
	{
		board_m.push_back(std::vector<Square>(8));
		simplifiedBoard.push_back(std::vector<Status>(8));
		for (size_t j = 0; j < 8; j++)
		{
			sf::Vector2f pos = { j * squareSize,i * squareSize };
			sf::Color color = (i + j) % 2 == 0 ? sf::Color::White : sf::Color{ 165,42,42 };



			board_m[i][j] = { pos,color,squareSize };
			simplifiedBoard[i][j] = board_m[i][j].getStatus();
		}
	}
}

void Board::clicked(const sf::Vector2f& pos, bool& isWhite)
{
	BoardPosition bPos(pos);
	/*
#ifdef _DEBUG
	std::cout << pos.y << " " << pos.x << "\n";
	std::cout << i+1 << " " << j+1 << "\n";
#endif // _DEBUG
	*/
	if (!inBounds(bPos))
		return;

	if (board_m[bPos.i][bPos.j].isEmpty() || board_m[bPos.i][bPos.j].getPiece()->IsWhite() != isWhite)
	{
		if (toMove_m == nullptr)
			return;
		else
		{
			const BoardPosition& oldPos = toMove_m->getPos();

			


			std::for_each(CWHOLE(board_m), [isWhite](const auto& row) {std::for_each(CWHOLE(row), [isWhite](const auto& square) {
				auto piece = square.getPiece();
				if (piece != nullptr && piece->IsWhite() == isWhite)
					piece->enPassantAble = false;


				}); });

			auto moveResult = toMove_m->Move(bPos);
			
			

			if (moveResult==Normal||moveResult==EnPassant)
			{


				if (simplifiedBoard[bPos.i][bPos.j] != Empty)
				{
					board_m[bPos.i][bPos.j].destroyPiece();
					simplifiedBoard[bPos.i][bPos.j] = Empty;
				}
				else if(moveResult==EnPassant)
				{
					int offSet = (isWhite == true ? 1 : -1); //down if white up if black

					if (board_m[bPos.i + offSet][bPos.j].getPiece()->enPassantAble)
					{
						board_m[bPos.i+offSet][bPos.j].destroyPiece();
						simplifiedBoard[bPos.i+offSet][bPos.j] = Empty;
					}
					else return;
				}
				toMove_m->updatePosition(bPos());
				simplifiedBoard[bPos.i][bPos.j] = board_m[oldPos.i][oldPos.j].getStatus();
				board_m[bPos.i][bPos.j].acceptPiece(board_m[oldPos.i][oldPos.j]);
				simplifiedBoard[oldPos.i][oldPos.j] = Empty;
				isWhite = !isWhite;
				
				#ifdef _DEBUG
					outputBoard();
				#endif // _DEBUG
				
			}
			
				toMove_m = nullptr;
		}
	}
	else
	{
		if (board_m[bPos.i][bPos.j].getPiece()->IsWhite() == isWhite)
			toMove_m = board_m[bPos.i][bPos.j].getPiece();
	}


}
