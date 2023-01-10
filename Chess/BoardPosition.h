#pragma once
#include<SFML/Graphics.hpp>
class BoardPosition
{
public:
	int i;
	int j;

	BoardPosition(const sf::Vector2f& pos) 
		: i(static_cast<int>(pos.y/80.f)),j(static_cast<int>(pos.x / 80.f))
	{}

	void operator=(const sf::Vector2f& pos)
	{
		i = static_cast<int>(pos.y / 80.f);
		j = static_cast<int>(pos.x / 80.f);
	}
	sf::Vector2f operator() ()
	{
		return { j * 80.f,i * 80.f };
	}
};

