#pragma once
#include<SFML/Graphics.hpp>
#include"BoardPosition.h"
class Resources
{
	sf::Texture Wpawn;
	sf::Texture Bpawn;
	sf::Texture Wknight;
	sf::Texture Bknight;
	sf::Texture Wrook;
	sf::Texture Brook;
	sf::Texture Wbishop;
	sf::Texture Bbishop;
	sf::Texture Wqueen;
	sf::Texture Bqueen;
public:
	Resources()
	{
		std::string path = "Textures\\";
	
		if (!Wpawn.loadFromFile(path + "Wpawn" + ".png"))
		{
			//error
		}
		if (!Bpawn.loadFromFile(path + "Bpawn" + ".png"))
		{
			//error
		}
		if (!Wknight.loadFromFile(path + "Wknight" + ".png"))
		{
			//error
		}
		if (!Bknight.loadFromFile(path + "Bknight" + ".png"))
		{
			//error
		}
		if (!Wrook.loadFromFile(path + "Wrook" + ".png"))
		{
			//error
		}
		if (!Brook.loadFromFile(path + "Brook" + ".png"))
		{
			//error
		}
		if (!Wbishop.loadFromFile(path + "Wbishop" + ".png"))
		{
			//error
		}
		if (!Bbishop.loadFromFile(path + "Bbishop" + ".png"))
		{
			//error
		}
		if (!Wqueen.loadFromFile(path + "Wqueen" + ".png"))
		{
			//error
		}
		if (!Bqueen.loadFromFile(path + "Bqueen" + ".png"))
		{
			//error
		}
		
	}
	constexpr const auto& WhitePawnTexture() const
	{
		return Wpawn;
	}
	constexpr const auto& BlackPawnTexture() const
	{
		return Bpawn;
	}
	constexpr const auto& WhiteKnightTexture() const
	{
		return Wknight;
	}
	constexpr const auto& BlackKnightTexture() const
	{
		return Bknight;
	}
	constexpr const auto& WhiteRookTexture() const
	{
		return Wrook;
	}
	constexpr const auto& BlackRookTexture() const
	{
		return Brook;
	}
	constexpr const auto& WhiteBishopTexture() const
	{
		return Wbishop;
	}
	constexpr const auto& BlackBishopTexture() const
	{
		return Bbishop;
	}
	constexpr const auto& WhiteQueenTexture() const
	{
		return Wqueen;
	}
	constexpr const auto& BlackQueenTexture() const
	{
		return Bqueen;
	}
} static resources;

