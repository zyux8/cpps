#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Stack top: " <<  mstack.top() << std::endl << std::endl;
	
	mstack.pop();
	
	std::cout << "Stack size: " << mstack.size() << std::endl << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// [...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "current entry: " << *it << std::endl;
	++it;
	std::cout << "next entry: " << *it << std::endl;
	--it;
	std::cout << "previous entry: " << *it << std::endl << std::endl;
	
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	
	return (0);
}