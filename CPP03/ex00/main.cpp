#include "ClapTrap.hpp"

int main() {
    std::cout << "[ClapTrap Teste Constructors and assignment operator]" << std::endl;
    ClapTrap clapTrapDefault;
    ClapTrap clapTrap("João");
    ClapTrap clapTrapCopy(clapTrap);
    ClapTrap clapTrapAssign;
    clapTrapAssign = clapTrap;

    clapTrapDefault.attack("enemy 0");
    clapTrapDefault.takeDamage(5);
    clapTrapDefault.beRepaired(5);

    clapTrap.attack("enemy 1");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);

    clapTrapCopy.attack("enemy 2");
    clapTrapCopy.takeDamage(5);
    clapTrapCopy.beRepaired(5);

    clapTrapAssign.attack("enemy 3");
    clapTrapAssign.takeDamage(5);
    clapTrapAssign.beRepaired(5);
    std::cout << "[Test ClapTrap without energy]" << std::endl;
    clapTrap.attack("enemy 4");
    clapTrap.attack("enemy 5");
    clapTrap.attack("enemy 6");
    clapTrap.attack("enemy 7");
    clapTrap.attack("enemy 8");
    clapTrap.attack("enemy 9");
    clapTrap.attack("enemy 10");
    clapTrap.attack("enemy 11");
    clapTrap.attack("enemy 12");
    clapTrap.beRepaired(5);
    std::cout << "[Test ClapTrap dead]" << std::endl;
    clapTrapCopy.takeDamage(10);
    clapTrapCopy.attack("enemy 15");
    clapTrapCopy.beRepaired(5);
    std::cout << "[ClapTrap tests Destructors]" << std::endl;
    return 0;
}