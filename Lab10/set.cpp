// Thor Christian Cusick.
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
	std::set<string> mySet;
	mySet.insert("Michael");
	mySet.insert("Ryan");
	mySet.insert("Dwight");
	mySet.insert("Jim");
	mySet.insert("Pam");
	mySet.insert("Andy");
	for (std::set<std::string>::const_iterator i = mySet.begin(); i != mySet.end(); i++) {
        std::cout << *i << endl;
	}
	return 0;
}