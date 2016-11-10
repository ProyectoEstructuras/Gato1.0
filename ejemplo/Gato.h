#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Gato
{
private:
	sf::RenderWindow window;
	sf::Texture gameBoard, pieceX, pieceO;
	sf::Sprite addBoard, addX, addO, piece[9];
	sf::Font fontType;
	sf::Text message;
	sf::IntRect square[9];
	sf::Vector2i position[9];
	sf::Event event;
public:
	void crearVentana();
	bool cargarPiezas();
	//bool cargarFont();
	void setPiezas();
	void setUserPrompt();
	void coordinaRectangulo();
	void setCoorRect(sf::IntRect &rect, int left, int top, int width, int height);
	void setPosPiezas(sf::Vector2i &pos, int left, int top);
	void posPieza();
	bool eventoClick(int posTabla);
	bool turno(int turn);
	void updateUserPromt(int turn, bool invalidPos);
	void gameLoop();

	Gato();
	~Gato();
};

