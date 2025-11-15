#include "Cat.hpp"

Cat::Cat() 
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    type = other.type;
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        delete brain;
        Animal::operator=(other);
        type = other.type;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
    brain->setIdea(i,idea);
}

std::string Cat::getIdea(int i)
{
    return brain->getIdea(i);
}
