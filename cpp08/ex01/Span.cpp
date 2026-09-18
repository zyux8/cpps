#include "Span.hpp"

Span::Span(unsigned int N) {
	n = N;
}

Span::Span() {
	n = 1;
}

Span::~Span() {

}

Span& Span::operator= (const Span& other) {
	if (this != &other) {
		this->n = other.n;
		this->arr = other.arr;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (arr.size() < n) {
		arr.push_back(num);
		std::cout << "Your number " << num << " has been added to the array." << std::endl;
	}
	else
		std::cout << "The array contains maximum amount of numbers." << std::endl;
}

int Span::shortestSpan() {
	if (arr.size() < 2)
		throw std::runtime_error ("shortestSpan; Array contains too little entries.");
	int span = abs(arr.at(0) - arr.at(1));
	int temp;
	for (std::vector<int>::size_type x = 0; x < arr.size(); x++) {
		for (std::vector<int>::size_type y = 1; y < arr.size(); y++) {
			if (x == y)
				continue;
			temp = arr.at(x) - arr.at(y);
			if (span > temp) {
				span = abs(temp);
			}
		}
	}
	return span;
}

int Span::longestSpan() {
	if (arr.size() < 2)
		throw std::runtime_error ("longestSpan; Array contains too little entries.");
	int min = *std::min_element(arr.begin(), arr.end());
	int max = *std::max_element(arr.begin(), arr.end());

	return max - min;
}