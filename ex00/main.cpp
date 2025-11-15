#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
    const Animal* meta = new Animal();
    const WrongAnimal j =WrongCat();
    const Animal* i = new Cat();
    const WrongAnimal* wrongMeta = new WrongCat();

    std::cout << j.getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j.makeSound();
    meta->makeSound();    
    wrongMeta->makeSound(); // will output the wrong cat sound!

    delete meta;
    delete i;
    delete wrongMeta;

    Animal* animals[4] = {
        new Dog(),
        new Cat(),
        new Dog(),
        new Dog()
    };
    
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound(); 
    
    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}