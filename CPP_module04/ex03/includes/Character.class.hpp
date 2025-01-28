#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

#include "AMateria.class.hpp"
#include "ICharacter.interface.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];

    public:
        Character();
        Character(std::string name);
        Character(const Character &other);
        Character& operator=(const Character &other);
        ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

};

#endif