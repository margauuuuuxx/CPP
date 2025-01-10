#include "../includes/ClapTrap.class.hpp"
#include "../includes/ScavTrap.class.hpp"

int main()
{
    ClapTrap    def;
    ScavTrap    a("A");
    ScavTrap    b(a);
    ScavTrap    c = a;

    std::cout << "Here are the stats of A:" << std::endl;
    std::cout << "\tHit points: " << a.getHitsPts() << "\n\tEnergy points: " << a.getEnergyPts() << "\n\tAttack damage: " << a.getAttackDamage() << std::endl;
    a.attack("the corrector correcting this");
    b.beRepaired(10);
    c.takeDamage(25);
    a.guardGate();
    
    return (0);
}