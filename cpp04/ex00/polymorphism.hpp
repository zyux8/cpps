#ifndef POLYMORPHISM_HPP
# define POLYMORPHISM_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};

class Dog: public Animal {
	public:
		Dog();
		virtual ~Dog();
		void makeSound() const;
};

class Cat:public Animal {
	public:
		Cat();
		virtual ~Cat();
		void makeSound() const;
};

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
};

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
};

#endif