#include "Dog.h"

void Hide_Cursor(bool _State) {
	CONSOLE_CURSOR_INFO Cursor_Info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Cursor_Info);
	Cursor_Info.bVisible = !_State;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Cursor_Info);
}

int main() {

	Hide_Cursor(true);

	Dog Dog;

	while(true) {

		std::cout << "====================" << std::endl;
		std::cout << "    A Dog's Life    " << std::endl;
		std::cout << "====================" << std::endl;
		std::cout << "Energy: " << Dog.Energy << std::endl;
		std::cout << "Appetite: " << Dog.Appetite << std::endl;
		std::cout << "Contentment: " << Dog.Contentment << std::endl;
		std::cout << "Cats Chased: " << Dog.Cats_Chased << std::endl;
		std::cout << "====================" << std::endl;

		Dog.Update();

		Sleep(200);
		system("cls");

	}
	
}