#ifndef ITER_HPP
# define ITER_HPP

# include <functional>

template <typename T1, typename T2, typename T3>
void iter(T1 &addr, const T2 value, T3 func) {
	for (int x = 0; x < value; x++)
		func(addr[x]);
}

#endif