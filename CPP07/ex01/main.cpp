#include "iter.hpp"

int main(void)
{
	int int_array[] = {1, 2, 3, 4, 5};
	my::iter(int_array, 5, my::print<int>);

	std::cout << "----------------------------------------" << std::endl;

	std::string str_array[] = {"Hello", "World", "C++"};
	my::iter(str_array, 3, my::print<std::string>);

	std::cout << "----------------------------------------" << std::endl;

	char char_array[] = {'a', 'b', 'c', 'd', 'e'};
	my::iter(char_array, 5, my::print<char>);

	std::cout << "----------------------------------------" << std::endl;

	double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	my::iter(double_array, 5, my::print<double>);

	return (0);
}

/*
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  my::iter( tab, 5, print<const int> );
  my::iter( tab2, 5, print<Awesome> );

  return 0;
}
*/
