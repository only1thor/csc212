// Thor Christian Cusick.
#include <iostream>
#include <string>
using namespace std;
#include <vector>

int main(int argc, char* argv[])
{
	std::vector<int> my_vector;
    for(int i=10; i>0;--i){
	my_vector.insert(my_vector.begin(), i);
    }
	return 0;
}
