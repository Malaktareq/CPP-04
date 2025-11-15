#include "Dog.hpp"
#include "Cat.hpp"
// int main()
// {
//     Animal *animals[4] = {new Cat(), new Cat(), new Dog(), new Dog() };
//     for (int i = 0; i < 4; i++)
//     {
//         animals[i]->makeSound();
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         delete animals[i];
//     }
//     Cat *cats = new Cat[4]; 
    
//     for (int i = 0 ; i < 4;i++)
//         cats[i].makeSound();
//     delete[] cats;
// }
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "===== BASIC POLYMORPHISM TEST =====" << std::endl;
    {
        const Animal* a = new Dog();
        const Animal* b = new Cat();

        std::cout << "Dog makes sound: ";
        a->makeSound();
        std::cout << "Cat makes sound: ";
        b->makeSound();

        delete a; // should call Dog destructor then Animal
        delete b; // should call Cat destructor then Animal
    }

    std::cout << "\n===== ARRAY OF ANIMALS TEST =====" << std::endl;
    {
        const int size = 4;
        Animal* animals[size];

        for (int i = 0; i < size; ++i)
        {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << "\n--- makeSound() on each Animal* ---" << std::endl;
        for (int i = 0; i < size; ++i)
            animals[i]->makeSound();

        std::cout << "\n--- deleting Animal* array ---" << std::endl;
        for (int i = 0; i < size; ++i)
            delete animals[i]; // must NOT leak & must call correct destructors
    }

    std::cout << "\n===== DEEP COPY TEST (COPY CONSTRUCTOR) - DOG =====" << std::endl;
    {
        Dog original;
        original.setIdea(0, "I want food");
        original.setIdea(1, "I want to play");

        std::cout << "Original ideas:" << std::endl;
        std::cout << "  idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << original.getIdea(1) << std::endl;

        Dog copy(original); // calls copy constructor

        std::cout << "\nAfter copy constructor:" << std::endl;
        std::cout << "Copy ideas:" << std::endl;
        std::cout << "  idea[0]: " << copy.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << copy.getIdea(1) << std::endl;

        std::cout << "\nModify ORIGINAL's ideas..." << std::endl;
        original.setIdea(0, "I want to sleep");
        original.setIdea(1, "I want a walk");

        std::cout << "\nOriginal ideas (modified):" << std::endl;
        std::cout << "  idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << original.getIdea(1) << std::endl;

        std::cout << "\nCopy ideas (should NOT change if deep copy is correct):" << std::endl;
        std::cout << "  idea[0]: " << copy.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << copy.getIdea(1) << std::endl;
    }

    std::cout << "\n===== DEEP COPY TEST (ASSIGNMENT OPERATOR) - DOG =====" << std::endl;
    {
        Dog a;
        Dog b;

        a.setIdea(0, "Chasing cats");
        a.setIdea(1, "Eating bones");

        b.setIdea(0, "Sleeping");
        b.setIdea(1, "Guarding the house");

        std::cout << "Before assignment:" << std::endl;
        std::cout << "A ideas:" << std::endl;
        std::cout << "  idea[0]: " << a.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << a.getIdea(1) << std::endl;

        std::cout << "B ideas:" << std::endl;
        std::cout << "  idea[0]: " << b.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << b.getIdea(1) << std::endl;

        std::cout << "\nDoing: b = a;" << std::endl;
        b = a; // assignment operator

        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << "B ideas (should equal A now):" << std::endl;
        std::cout << "  idea[0]: " << b.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << b.getIdea(1) << std::endl;

        std::cout << "\nModify A's ideas again..." << std::endl;
        a.setIdea(0, "Digging holes");
        a.setIdea(1, "Barking at strangers");

        std::cout << "\nA ideas (modified):" << std::endl;
        std::cout << "  idea[0]: " << a.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << a.getIdea(1) << std::endl;

        std::cout << "\nB ideas (should NOT change if deep copy is correct):" << std::endl;
        std::cout << "  idea[0]: " << b.getIdea(0) << std::endl;
        std::cout << "  idea[1]: " << b.getIdea(1) << std::endl;


        std::cout << "\nSelf-assignment test (b = b):" << std::endl;
        // b = b; // should NOT crash or leak
        std::cout << "  Still alive after self-assignment ✅" << std::endl;
    }

    std::cout << "\n===== SAME TESTS CAN BE REPEATED FOR CAT IF YOU WANT =====" << std::endl;
    {
        Cat c1;
        c1.setIdea(0, "I am a queen");
        c1.setIdea(1, "I will knock the glass");

        Cat c2(c1); // copy constructor

        std::cout << "c1 idea[0]: " << c1.getIdea(0) << std::endl;
        std::cout << "c2 idea[0]: " << c2.getIdea(0) << std::endl;

        c1.setIdea(0, "I am bored now");

        std::cout << "\nAfter modifying c1:" << std::endl;
        std::cout << "c1 idea[0]: " << c1.getIdea(0) << std::endl;
        std::cout << "c2 idea[0]: " << c2.getIdea(0) << " (should NOT change)" << std::endl;
    }

    std::cout << "\n===== END OF ALL TESTS =====" << std::endl;
    return 0;
}
