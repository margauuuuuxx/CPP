#include "../includes/DiamondTrap.class.hpp"

int main()
{
    std::cout << "--- Creating DiamondTrap ---" << std::endl;
    DiamondTrap dt("Diamond");

    std::cout << "\n--- Testing DiamondTrap functionalities ---" << std::endl;

    // Display initial stats
    dt.whoAmI();

    std::cout << "\n--- Performing actions ---" << std::endl;
    dt.attack("enemy target"); // Inherited from ScavTrap
    dt.takeDamage(20);         // Inherited from ClapTrap
    dt.beRepaired(15);         // Inherited from ClapTrap

    std::cout << "\n--- DiamondTrap stats after actions ---" << std::endl;
    dt.whoAmI();

    std::cout << "\n--- Additional Tests for Inheritance ---" << std::endl;

    // Test FragTrap functionality
    std::cout << "Testing FragTrap's highFivesGuys() function:" << std::endl;
    dt.highFivesGuys();

    // Test ScavTrap functionality
    std::cout << "Testing ScavTrap's guardGate() function:" << std::endl;
    dt.guardGate();

    // Test ClapTrap attributes through DiamondTrap
    std::cout << "\nTesting ClapTrap attributes via DiamondTrap:" << std::endl;
    std::cout << "DiamondTrap ClapTrap::name: " << dt.ClapTrap::getName() << std::endl;
    std::cout << "DiamondTrap hit points: " << dt.getHitsPts() << std::endl;
    std::cout << "DiamondTrap energy points: " << dt.getEnergyPts() << std::endl;
    std::cout << "DiamondTrap attack damage: " << dt.getAttackDamage() << std::endl;

    std::cout << "\n--- Testing Copy Constructor and Assignment ---" << std::endl;
    DiamondTrap dtCopy(dt); // Copy constructor
    dtCopy.whoAmI();

    DiamondTrap dtAssigned = dt; // Assignment operator
    dtAssigned.whoAmI();

    std::cout << "\n--- Final stats and clean up ---" << std::endl;
    return 0;
}