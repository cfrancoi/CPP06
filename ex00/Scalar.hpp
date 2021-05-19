#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>

class Scalar
{

	public:

		Scalar(std::string const & ref);
		Scalar( Scalar const & src );
		~Scalar();

		Scalar &		operator=( Scalar const & rhs );

		void			print_char();
		void			print_int();
		void			print_float();
		void			print_double();

		void			print_all();

	private:
		double			_val;
		Scalar();

};

#endif /* ********************************************************** SCALAR_H */