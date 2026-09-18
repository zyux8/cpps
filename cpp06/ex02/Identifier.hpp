#pragma once

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Base.hpp"

class Identifier {
	private:
		Identifier();
	public:
		static Base* generate(void);
		static void identify(Base& p);
		static void identify(Base* p);
};
