#include "Gato.h"



Gato::Gato()
{
}


Gato::~Gato()
{

}

void Gato::crearVentana()
{
	window.create(sf::VideoMode(600,600), "Gato");
}

void Gato::setPiezas()
{
	addBoard.setTexture(gameBoard);
	addX.setTexture(pieceX);
	addO.setTexture(pieceO);
}

bool Gato::cargarPiezas()
{
	return (gameBoard.loadFromFile("board.png") && pieceX.loadFromFile("piezax.png") && pieceO.loadFromFile("piezao.png"));
}

/*bool Gato::cargarFont()
{
	return (fontType.loadFromFile("3rd Man.ttf"));
}*/



void Gato::setUserPrompt()
{
	message.setString("Player 1's turn");
	message.setFont(fontType);
	message.setCharacterSize(40);
	//message.setColor(sf::Color::Blue);
	message.move(95, 410);
}

void Gato::coordinaRectangulo()
{
	setCoorRect(square[0], 0, 0, 113, 120);
	setCoorRect(square[1], 126, 0, 262, 120);
	setCoorRect(square[2], 276, 0, 400, 120);

	setCoorRect(square[3], 0, 133, 113, 270);
	setCoorRect(square[4], 126, 133, 262, 270);
	setCoorRect(square[5], 276, 133, 400, 270);

	setCoorRect(square[6], 0, 283, 113, 400);
	setCoorRect(square[7], 126, 283, 262, 400);
	setCoorRect(square[8], 276, 283, 400, 400);
}

void Gato::setCoorRect(sf::IntRect &rect, int left, int top, int width, int height)
{
	rect.left = left;
	rect.top = top;
	rect.width = width;
	rect.height = height;
}

void Gato::setPosPiezas(sf::Vector2i & pos, int left, int top)
{
	pos.x = left;
	pos.y = top;
}

void Gato::posPieza()
{
	setPosPiezas(position[0], 15, 20);
	setPosPiezas(position[1], 162, 20);
	setPosPiezas(position[2], 300, 20);

	setPosPiezas(position[3], 15, 166);
	setPosPiezas(position[4], 162, 166);
	setPosPiezas(position[5], 300, 166);

	setPosPiezas(position[6], 15, 316);
	setPosPiezas(position[7], 162, 316);
	setPosPiezas(position[8], 300, 316);
}

bool Gato::eventoClick(int posTabla)
{
	return event.mouseButton.x >= square[posTabla].left
		&& event.mouseButton.x <= square[posTabla].width
		&& event.mouseButton.y >= square[posTabla].top
		&& event.mouseButton.y <= square[posTabla].height;
}



bool Gato::turno(int turn){

	for (int boardPos = 0; boardPos < 9; boardPos++) {
		if (eventoClick(boardPos)) {
			if (square[boardPos].left != -500) {
				piece[turn] = turn % 2 == 0 ? addX : addO;
				piece[turn].move((float)position[boardPos].x, (float)position[boardPos].y);
				square[boardPos].left = -500;
				updateUserPromt(turn, false);
				return true;
			}
			else {
				updateUserPromt(turn, true);
				return false;
			}
		}
	}
	return false;
		}
	
void Gato::updateUserPromt(int turn, bool invalidPos)
{
	std::string playerPrompt;
	if (invalidPos) {
		playerPrompt = "Ya ha sido tomada esta posicion!";
	}
	else {
		playerPrompt = turn % 2 == 0 ? "Turno de jugador 1" : "Turno de jugador 2";
	}

	message.setString(playerPrompt);
}




void Gato::gameLoop()
{
	int turn = 0;
	setUserPrompt();
	coordinaRectangulo();
	posPieza();

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && turn < 9) {
				if (turno(turn)) {
					turn++;
				}
			}

		}
		window.clear(sf::Color(0, 150, 0));
		window.draw(addBoard);
		window.draw(message);
		for (int pieceIdx = 0; pieceIdx < 9; pieceIdx++)
			window.draw(piece[pieceIdx]);
		window.display();

	}
}
