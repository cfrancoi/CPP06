#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>

struct  Data
{	
	char 			pt_a[8];
	int				num;
	char			pt_b[8];
};

char	get_rand_c()
{
	int ret;

	ret = 0;

	while (!isprint(ret))
	{
		int val = rand() % 127;

		ret = static_cast<char>(val);
	}
	return(ret);
}

void	*serialize(void)
{
	Data *ret = new Data;

	srand(time(NULL)); // random seed
	int i;

	i = 0;
	while (i != 8)
	{
		ret->pt_a[i++] = get_rand_c();
	}
	ret->pt_a[7] = 0;
	ret->num = rand();
	i = 0;
	while (i != 8)
	{
		ret->pt_b[i++] = get_rand_c();
	}
	ret->pt_b[7] = 0;

	std::cout << sizeof(Data) << std::endl ;
	std::cout << ret->pt_a << "|" << ret->num << "|" << ret->pt_b << std::endl;
	std::cout << &ret->pt_a << "|" << &ret->num << "|" << &ret->pt_b << std::endl;
	std::cout << ret << "|" << ret + 8 << "|" << ret + 4 << std::endl;
	return (ret);
}

Data * deserialize(void * raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int main()
{
	void *ptr = serialize();

	(void)ptr;

	Data *el = deserialize(ptr);


	std::cout << el->pt_a << "|" << el->num << "|" << el->pt_b << std::endl;
	//std::cout << el << "|" << el + 8 << "|" << el + 4 << std::endl;

	std::cout << sizeof(Data) << std::endl ;
	return 1;
}
