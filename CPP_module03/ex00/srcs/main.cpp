#include "../includes/ClapTrap.class.hpp"

int main()
{
    ClapTrap    def;
    ClapTrap    Marg("Marg");
    ClapTrap    a(Marg);
    ClapTrap    b = a;

    def.attack("Marg");
    Marg.beRepaired(10);
    def.takeDamage(20);
    def.attack("Marg");
    a.takeDamage(5);
    b.beRepaired(7);
    b.attack("Def");

    return (0);
}