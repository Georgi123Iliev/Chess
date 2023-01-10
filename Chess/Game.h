#pragma once
#include<SFML/Graphics.hpp>
#include"Board.h"
#include<algorithm>


class Game
{
	sf::RenderWindow window_m;
	Board board_m;
	bool WhiteTurn{ true };
	constexpr auto winSize()
	{
		return 640u;
	}
public:
	Game()
		:board_m(static_cast<float>(winSize())), window_m(sf::VideoMode({ winSize(), winSize() }), "Chess")
	{
	
		
	}

	void Run()
	{
		
		while(window_m.isOpen())
		{
			sf::Event event;
			while (window_m.pollEvent(event))
			{
				
				if (event.type == sf::Event::Closed)
					window_m.close();
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						const sf::Vector2f& pos =	static_cast<sf::Vector2f>(sf::Mouse::getPosition(window_m));
					
						
						board_m.clicked(pos,WhiteTurn);
					}
				}
			}

			Render();
		}
		
	}

	void Render()
	{
		window_m.clear();

		std::for_each(CWHOLE(board_m.toDraw()), [this](const std::vector<Square>& row)
		{
				std::for_each(CWHOLE(row), [this](const Square& square) {window_m.draw(square.squareDrawable()); 
				if (square.isEmpty() == false)
					window_m.draw(square.pieceDrawable()); });
		});

		window_m.display();
	}
};

