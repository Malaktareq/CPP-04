#include "Brain.hpp"

Brain::Brain()
{
   std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i=0; i < 100; i++)
        ideas[i] = other.ideas[i];
     std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if(this != &other)
    {
        for (int i=0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
      std::cout << "Brain assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
    if ( i  > 99)
        std::cout << "Failed to store the idea" << std::endl;
    else 
        ideas[i] = idea;
}

std::string Brain::getIdea(int i)
{
    if (i > 99 || i < 0)
    {
        std::cout << "invalid idea number" << std::endl;
        return NULL;
    }
    else
        return ideas[i];
}