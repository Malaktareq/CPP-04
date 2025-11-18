#include "Character.hpp"
#include "AMateria.hpp"
Character::Character()
{
    name = "default";
    for (int i = 0 ; i < 4 ; i++)
        inventory[i] = NULL;
}

Character::Character(const std::string& name)
{
    this->name = name;
    for (int i = 0 ; i < 4 ; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& other)
{
    name = other.name;
    for (int i = 0 ; i < 4 ; i++)
    {
        if (other.inventory[i] != NULL)
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0 ; i < 4 ; i++)
        {
            if (other.inventory[i] != NULL)
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
    {
        std::cout << "Cannot equip a null materia." << std::endl;
        return;
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
    std::cout << "No empty slot available to equip materia." << std::endl;
    delete m;
}

void Character::use(int i, ICharacter& target)
{
    if (i < 0 || i >= 4 || inventory[i] == NULL)
    {
        std::cout << "No materia to use." << std::endl;
        return;
    }
    inventory[i]->use(target);
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Index out of bounds." << std::endl;
        return;
    }
    if (inventory[idx] == NULL)
    {
        std::cout << "No materia to unequip at this index." << std::endl;
        return;
    }
    inventory[idx] = NULL;
}
AMateria* Character::getMateria(int index)
{
    return inventory[index] ;
}
Character::~Character()
{
    for (int i =0 ; i < 4;i++)
        delete inventory[i];
}