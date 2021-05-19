#include <cstdlib>
#include <iostream>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base
{

};

class B : public Base
{

};


class C : public Base
{

};

Base * generate(void)
{
	int i;
	
	i = rand() % 3;

	if (i == 0)
	{
		std::cout << "Create a A" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "Create a B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Create a C" << std::endl;
		return new C;
	}
}

void	identify_from_pointer(Base * p)
{
		A *a = dynamic_cast<A *>(p);

		if (a != NULL)
		{
			std::cout << "pointer is a A" << std::endl;
			(void)a;
			return;
		}
		
		B *b = dynamic_cast<B *>(p);
		
		if (b != NULL)
		{
			std::cout << "pointer is a B" << std::endl;
			(void)b;
			return;
		}
	
		C *c = dynamic_cast<C *>(p);
		if (c != NULL)
		{
			std::cout << "pointer is a C" << std::endl;
			(void)c;
			return;
		}

	std::cout << "pointer is not A,B or C" << std::endl;
	return;
}

void	identify_from_reference(Base & p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		std::cout << "reference is a A" << std::endl;
		(void)a;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
		//std::cerr << e.what() << '\n';
	}
	
	try
	{
		B & b = dynamic_cast<B &>(p);
		std::cout << "reference is a B" << std::endl;
		(void)b;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
		//std::cerr << e.what() << '\n';
	}

	try
	{
		C & c = dynamic_cast<C &>(p);
		std::cout << "reference is a C" << std::endl;
		(void)c;
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
		//std::cerr << e.what() << '\n';
	}
	std::cout << "reference is not A,B or C" << std::endl;
	return;
}

int		main(void)
{
	srand(time(NULL));
	Base * ptr = generate();

	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	
	return (0);
}