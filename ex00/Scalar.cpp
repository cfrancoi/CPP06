#include "Scalar.hpp"

#include <iomanip>
#include <cmath>
#include <cctype>
#include <limits.h>


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Scalar::Scalar(std::string const & ref) 
{
	_val = atof(ref.c_str());
}


Scalar::Scalar()
{
}

Scalar::Scalar( const Scalar & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Scalar::~Scalar()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Scalar &				Scalar::operator=( Scalar const & rhs )
{
	_val = rhs._val;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Scalar::print_char() 
{
	char c;

	c = static_cast<char>(_val);

	std::cout << "char: ";

	if (_val > static_cast<char>(CHAR_MAX) || _val < static_cast<char>(CHAR_MIN) || isnanf(_val))
		std::cout << "impossible";
	else if (isprint(c))
		std::cout << c;
	else
		std::cout << "non displayable";
	std::cout << std::endl;
}

void Scalar::print_int() 
{
	int i;

	i = static_cast<int>(_val);

	std::cout << "int: ";

	if (_val > static_cast<double>(INT_MAX) || _val < static_cast<double>(INT_MIN) || isnanf(_val))
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;
}

void Scalar::print_float() 
{
	float i;

	i = static_cast<float>(_val);

	std::cout << "float: ";
	if (isinff(i) == 1)
		std::cout << "+inf";
	else if (isinff(i) == -1)
		std::cout << "-inf";
	else if (isnanf(i))
		std::cout << "nan";
	else
		std::cout  << std::setprecision(7) << i;
	if (i - static_cast<int>(i) == 0)
		std::cout << ".0";
	std::cout << "f";
	std::cout << std::endl;
}

void Scalar::print_double() 
{
	double i = _val;
	std::cout << "double: ";
	if (isinff(i) == 1)
		std::cout << "+inf";
	else if (isinff(i) == -1)
		std::cout << "-inf";
	else if (isnanf(i))
		std::cout << "nan";
	else
		std::cout << std::setprecision(15) << i;
	if (i - static_cast<int>(i) == 0)
		std::cout << ".0";

	std::cout << std::endl;
}

void Scalar::print_all() 
{
	print_char();
	print_int();
	print_float();
	print_double();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
