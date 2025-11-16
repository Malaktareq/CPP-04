#include "MateriaSource.hpp"  

MateriaSource::MateriaSource()
{
    for (int i = 0 ; i < 4 ; i++)
        materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{

}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (other.materias[i] != NULL)
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0 ; i < 4 ; i++)
        {
            if (other.materias[i] != NULL)
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return *this;
}
void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
    {
        std::cout << "Cannot learn a null materia." << std::endl;
        return;
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        if (materias[i] == NULL)
        {
            materias[i] = m->clone();
            return;
        }
    }
    std::cout << "No empty slot available to learn materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (materias[i] != NULL && materias[i]->getType() == type)
        {
            return materias[i]->clone();
        }
    }
    std::cout << "Materia of type " << type << " not found." << std::endl;
    return 0;
}