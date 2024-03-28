#include <iostream>
#include "Bitmap.h"
#include "MandelBrot.h"
using namespace std;
using namespace caveofprogramming;

int main() {

    int const WIDTH=800;
    int const HEIGHT=600;
	Bitmap bitmap(WIDTH, HEIGHT);
	bitmap.setPixel(WIDTH/2,HEIGHT/2, 255, 255, 255);

    double min =999999;
    double max=-999999;

	for(int y=0;y<HEIGHT;y++)
	{
        for(int x=0;x<WIDTH;x++)
        {
            double xFractal=(x-WIDTH/2) * 2.0/WIDTH;
            double yFractal=(y-HEIGHT/2)* 2.0/HEIGHT;
            int iterations =MandelBrot::getIterations(xFractal,yFractal);

            uint8_t red = (uint8_t)(256 * (double)iterations/MandelBrot::MAX_ITERATIONS);
            bitmap.setPixel(x,y,red,0,0);
            if(red<min) min=red;
            if(red>max) max=red;

        }
	}

	cout<<min<<", "<<max<<endl;

    bitmap.write("test.bmp");
	cout << "finished!!" << endl; // prints !!!Hello World!!!
	return 0;
}
