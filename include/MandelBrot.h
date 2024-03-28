#ifndef MANDELBROT_H
#define MANDELBROT_H
#include <complex>
namespace caveofprogramming {

class MandelBrot
{
    public:
        static const int MAX_ITERATIONS=1000;
    public:
        MandelBrot();
        virtual ~MandelBrot();
        static int getIterations(double x, double y);

    protected:

    private:
};

#endif // MANDELBROT_H
}
