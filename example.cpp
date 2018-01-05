#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <cmath>

#include "config.h"

#ifdef MYSQRT
#include "mysqrt.h"
#endif

int main(int argc, char *argv[]) 
{
	if ( argc > 1 && std::string("--version") == std::string(argv[1])) 
	{
		std::cout << "version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
	}
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

#ifdef MYSQRT
	std::cout << mylib::mysqrt(5.) << " ";
#else 
	std::cout << "test" << " ";
#endif
}

