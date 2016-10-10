#include <iostream>
#include <windows.h>

enum States { Red, Amber, Green };
States State, Prev_State;

void Change_State() {

	switch (State) {
		case Red:
			Prev_State = Red;
			State = Amber;
			break;
		case Amber:
			State = Prev_State == Red ? Green : Red;
			break;
		case Green:
			Prev_State = Green;
			State = Amber;
			break;
		default: break;
	}

}

void Output_State() {

	system("cls");

	switch (State) {
		case Red:
			system("Color 4");
			std::cout << "Red" << std::endl;
			break;
		case Amber:
			system("Color E");
			std::cout << "Amber" << std::endl;
			break;
		case Green:
			system("Color 2");
			std::cout << "Green" << std::endl;
			break;
		default: break;
	}

}

int main() {

	State = Red;
	
	while(true) {

		Output_State();
		Sleep(1000);
		Change_State();

	}

}