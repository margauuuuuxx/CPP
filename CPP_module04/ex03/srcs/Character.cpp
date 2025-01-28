#include "../includes/Character.class.hpp"

Character::Character() : Character("Default name") {}

Character::Character(std::string name)
{
    name = name;
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
}

Character::Character(const Character &other) { *this = other; }

Character&  Character::operator = (const Character &other)
{
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++)
            this->inventory[i] = other.inventory[i];
    }
    return (*this);
}

std::string const & Character::getName() const { return (this->name); }

void    Character::equip(AMateria *m)
{
    if (m == nullptr)
    {
        std::cout << "Cannot equip an AMateria that doesn't exist" << std::endl;
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == nullptr)
        {
            inventory[i] = m;
            std::cout << "Equipment AMateria added in index: " << i << std::endl;
            return;
        }
    }

    std::cout << "Inventory is already full" << std::endl;
}

void    Character::unequip(int idx)
{
    if (idx >= 4 || idx < 0)
    {
        std::cout << "Please submit a valid index: [0;3]" << std::endl;
        return;
    }

    if (inventory[idx] == nullptr)
    {
        std::cout << "Already nothing in the inventory at the provided index" << std::endl;
        return;
    }

    inventory[idx] = nullptr;
    std::cout << "Equipment AMateria successfully unequipped at slot: " << idx << std::endl;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Please submit a valid index: [0;3]" << std::endl;
        return;
    }

    if (inventory[idx] == nullptr)
    {
        std::cout << "No AMateria set in the inventory at the provided index" << std::endl;
        return;
    }

    inventory[idx]->use(target);
}

Character::~Character () {}