#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double df_dx1(double x1, double x2)
{
	return 2 * x1  + 2 * pow(x2, 2);
}

double df_dx2(double x1, double x2) {
	return 4 * x2 * (x1+ pow(x2, 2));
}

//Градиентный метод с дроблением шага
void GradientCutStep(double x1, double x2, double l, double e) {

	double x[2], y[2], q;
	x[0] = x1;
	x[1] = x2;

	int i = 0;

	cout << "x1 = " << x[0] << " x2 = " << x[1] << endl;
	
	do {
		y[0] = x[0];
		y[1] = x[1];

		x[0] = x[0] - l / 2 * df_dx1(x[0], x[1]);
		x[1] = x[1] - l / 2 * df_dx2(x[1], x[1]);	

		q = (y[0] + y[1]) - (x[0] + x[1]);

		cout			
			<< "q = " << q
			<< "\tx[0] = " << x[0]
			<< "\tx[1] = " << x[1]
			<< "\ty[0] = " << y[0]
			<< "\ty[1] = " << y[1]
			<< "\ti = " << i		
			
			<< endl;

		i++;

	} while (q > e);

	return;
}

int main() {

	double x[] = { 4, 4 };

	double e1 = 0.5;
	double e2 = 0.1;
	double e3 = 0.01;
	double e4 = 0.00001;

	double l = 0.01;
	

	GradientCutStep(x[0], x[1], l, e4);
	cout << "---------------------------------------------------------------" << endl;

}