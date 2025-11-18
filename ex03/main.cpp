
#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    Ice *ice1 = new Ice();
    Ice *ice2 = new Ice();
    Cure *cure1 = new Cure();
    Cure *cure2 = new Cure();
    src->learnMateria(ice1);
    src->learnMateria(ice2);
    src->learnMateria(cure1);
    src->learnMateria(cure2);
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("cure");
    AMateria* unknown = src->createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia type: OK\n";

    me->equip(m1);
    me->equip(m2);

    me->use(0, *bob);  // ice
    me->use(1, *bob);  // cure
    me->use(5, *bob); 

    Character* clone = new Character(*(Character*)me);

    clone->use(0, *bob);
    clone->use(1, *bob);

    delete clone;

    AMateria *tmp = me->getMateria(1);
    me->unequip(1);
    delete tmp;
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
