#include "Dog.hpp"

Dog::Dog() 
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{    
    type = other.type;
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        delete brain;
        type = other.type;
        Animal::operator=(other);
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << brain << std::endl;
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
    brain->setIdea(i,idea);
}

std::string Dog::getIdea(int i)
{
    return brain->getIdea(i);
}