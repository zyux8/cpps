#pragma once

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

class Span {
	private:
		unsigned int n;
		std::vector<int> arr;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span& operator= (const Span& other);
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
};