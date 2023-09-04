/* This program estimates the area under a given curve
   using trapezoids with equal bases
*/
#include <iostream>
#include <cmath>
using namespace std;

double integrate(double a, double b, int numOfTrapezoids);
double f(double x);

int main()
{
	int numOfTrapezoids;
	double a, b, area;

	cout << "Enter the interval endpoints, a & b: ";
	cin >> a >> b;
	cout << "Enter the number of trapezoids: ";
	cin >> numOfTrapezoids;

	// Estimate the area under the curve y = f(x) = 4 * e^-x 
	area = integrate(a, b, numOfTrapezoids);

	cout << "Using " << numOfTrapezoids << " trapezoids, the estimated area is " << area << "\n";

	return 0;
}

double integrate(double a, double b, int numOfTrapezoids)
{
	double sum(0), x, base, area, k;
	base = (b - a) / numOfTrapezoids;
	
	for (k = 2; k <= numOfTrapezoids; k++)
	{
		x = a + base * (k - 1);
		sum = sum + f(x);
	}

	area = 0.5 * base * (f(a) + 2 * sum + f(b));
	return area;
}

double f(double x)
{
	return 4 * exp(-x);
}
