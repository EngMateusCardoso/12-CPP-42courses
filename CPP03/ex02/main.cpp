#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "[ScavTrap tests]" << std::endl;
    ScavTrap scavTrapDefault;
    ScavTrap scavTrap("Zé");
    ScavTrap scavTrapCopy(scavTrap);
    ScavTrap scavTrapAssign;
    scavTrapAssign = scavTrap;

    scavTrapAssign.guardGate();
    scavTrapAssign.attack("ENEMY");
    scavTrapAssign.takeDamage(5);
    scavTrapAssign.beRepaired(5);
    scavTrapAssign.takeDamage(95);
    scavTrapAssign.takeDamage(5);
    scavTrapAssign.attack("ENEMY");

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "[FragTrap tests]" << std::endl;
    FragTrap fragTrapDefault;
    FragTrap fragTrap("Pedro");
    FragTrap fragTrapCopy(fragTrap);
    FragTrap fragTrapAssign;
    fragTrapAssign = fragTrap;

    fragTrapAssign.highFivesGuys();
    fragTrapAssign.attack("ENEMY");
    fragTrapAssign.takeDamage(5);
    fragTrapAssign.beRepaired(5);
    fragTrapAssign.takeDamage(95);
    fragTrapAssign.takeDamage(5);
    fragTrapAssign.attack("ENEMY");

    std::cout << "[ClapTrap and ScavTrap Destructors]" << std::endl;
    return 0;
}