#include "Zombie.hpp"

int	main() {
	std::cout << std::endl;
	std::cout << "----------- TESTING HEAP ALLOCATION -----------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	std::cout << "Calling 'BobZombie' in newZombie function..." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	Zombie* zombie = newZombie("BobZombie");

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Explicit Announce..." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	zombie->announce();

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Explicit Heap Delete..." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	delete zombie;

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "---------- TESTING STACK ALLOCATION -----------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Calling 'JackZombie' in randomChump function..." << std::endl;
	std::cout << "Announce of 'JackZombie' in randomChump function..." << std::endl;
	std::cout << "Implicit Delete of 'JackZombie' with the end of the function..." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	randomChump("JackZombie");

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Instance of Zombie 'JhonZombie'..." << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Zombie zombie2("JhonZombie");

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Explicit Announce of 'JhonZombie'..." << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	zombie2.announce();

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Implicit Delete of 'JhonZombie' with the end of the program..." << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
		
	return (0);
}
