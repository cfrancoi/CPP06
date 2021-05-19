#include "Scalar.hpp"
#include <string>

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	else
	{
		Scalar el(av[1]);

		el.print_all();
	}
}