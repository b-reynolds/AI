#include <windows.h>
#include <stdlib.h>
#include <string>
#include "Dog.h"

int main() {

	Dog Dog;

	while(true) {

		std::cout << std::string(25, '=') << std::endl;
		std::cout << "A Dog's Life" << std::endl;
		std::cout << std::string(25, '=') << std::endl;

		for(int i = 0; i < 10; i++) {
			Dog.Current_State->Update(&Dog);
			Sleep(1250);
		}

		system("cls");

	}

}