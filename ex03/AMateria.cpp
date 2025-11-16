#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "default";
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}