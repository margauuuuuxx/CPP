#include "../includes/HumanA.class.hpp"
#include "../includes/HumanB.class.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim ("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
        Weapon gun = Weapon("AK47");
        gun.setType("AK47 with so much munitions");
        HumanA marg("Marg", gun);
        marg.attack();
    }
    {
        HumanB elise("Elise");
        elise.attack();
    }

    return (0);
}

// expected output: 1st attack with spiked and then 2nd with other for both 