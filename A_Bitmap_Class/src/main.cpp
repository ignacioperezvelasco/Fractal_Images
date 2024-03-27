#include <iostream>

#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main() {

	Bitmap bitmap(800, 600);
    bitmap.write("test.bmp");
	cout << "finished!!" << endl; // prints !!!Hello World!!!
	return 0;
}
