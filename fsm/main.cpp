#include <iostream>
#include "Dog.h"

int main() {

	std::cout << std::string(25, '=') << std::endl;;
	std::cout << "A Dog's Life" << std::endl;
	std::cout << std::string(25, '=') << std::endl;;

	Dog Dog;

	for(int i = 0; i < 20; i++)
		Dog.Live();

	std::cout << std::string(25, '=') << std::endl;;

	std::cin.get();

	return 0;

}