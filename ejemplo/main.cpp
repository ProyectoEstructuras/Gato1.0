#include <SFML/Graphics.hpp>
#include "Gato.h"

int main() {
	Gato game;
	
	game.setPiezas();
	
	game.crearVentana();
	if (!game.cargarPiezas())
		system("pause");
		return EXIT_FAILURE;

	

	/*if (!game.cargarFont());
	system("pause");
		return EXIT_FAILURE;*/

	game.gameLoop();
	system("pause");
	return EXIT_SUCCESS;
}