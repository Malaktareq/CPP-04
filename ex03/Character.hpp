#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        AMateria* inventory[4];
        std::string name;
    public:
        Character();
        ~Character();
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int i,ICharacter& target);
        std::string const & getName() const;
        AMateria* getMateria(int index);
};

#endif