#include "stringcont.hpp"


void myfunc(){
	StringList<int> bruh;
	bruh.data = int();
	bruh["Yuck"].data = 5;
	bruh["Duck"].data = 7;
	std::cout << bruh["Yuck"].data << std::endl;
	std::cout << bruh["Duck"].data << std::endl;
}

int main(){
	myfunc();
}
