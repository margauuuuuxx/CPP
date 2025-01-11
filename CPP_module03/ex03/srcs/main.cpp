#include "../includes/DiamondTrap.class.hpp"

int main()
{
    FragTrap    a("A");
    FragTrap    b(a);
    FragTrap    c = a;

    std::cout << "Here are the stats of A:" << std::endl;
    std::cout << "\tHit points: " << a.getHitsPts() << "\n\tEnergy points: " << a.getEnergyPts() << "\n\tAttack damage: " << a.getAttackDamage() << std::endl;
    a.attack("the corrector correcting this");
    b.beRepaired(10);
    c.takeDamage(25);
    a.highFivesGuys();
    
    return (0);
}