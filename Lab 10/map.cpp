// Thor Christian Cusick.
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
	map<string, string> spanish;
	spanish["Computer"] = "Computadora";
	spanish["science"] = "ciencia";
	spanish["is"] = "es";
	spanish["awesome"] = "impresionante";
	cout << spanish["Computer"] << " " << spanish["science"] << " " << spanish["is"] << " " << spanish["awesome"] << " " << endl;
}
