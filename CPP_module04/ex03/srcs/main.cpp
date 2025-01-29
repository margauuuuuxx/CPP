#include "../includes/Cure.class.hpp"
#include "../includes/Ice.class.hpp"
#include "../includes/MateriaSource.class.hpp"
#include "../includes/Character.class.hpp"

int main ()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* Marg = new Character("Marg");
    ICharacter* Corrector = new Character("the corrector correcting this");
    
    AMateria* a = src->createMateria("ice");
    Marg->equip(a);
    AMateria* b = src->createMateria("cure");
    Corrector->equip(b);

    Marg->use(0, *Corrector);
    Corrector->use(0, *Marg);

    delete (src);
    delete (Marg);
    delete (Corrector);
    delete (a);
    delete (b);

    return 0;
}