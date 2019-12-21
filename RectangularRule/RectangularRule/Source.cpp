//Libraries used for assistance in this program
#include<iostream>
#include<iomanip>

using namespace std;

//Declarations of all funcions in this program
double numericalCalculator(int, int, int, double, double, double[], double[]);
double exactCalculator(int, int, int);
double errorCalculator(double, double);
void displayFunc(double[], double[], double, double, double);

int main()
{
	int n = 5;     //Number of Iterations
	int a = 0;     //Lower Limit
	int b = 1;     //Upper Limit
	int power = 5; //Power of variable
	double h = 0;

	double valsOfx[5]; //Array for storing values of x0, x1, x2, x3, x4
	double valsOfy[5]; //Array for storing values of y0, y1, y2, y3, y4

	double numericalAnswer;
	double exactAnswer;
	double error;
	double yValuesAdded = 0.0;

	cout << "The Equation to be Numerically Integrated : x^5" << endl;
	cout << "Lower Limit: " << a << endl;
	cout << "Upper Limit: " << b << endl;
	cout << "Number of Iterations: " << n << endl << endl;

	numericalAnswer = numericalCalculator(a, b, n, h, yValuesAdded, valsOfx, valsOfy);

	exactAnswer = exactCalculator(a, b, power);

	error = errorCalculator(numericalAnswer, exactAnswer);

	displayFunc(valsOfx, valsOfy, numericalAnswer, exactAnswer, error);
}

//This function calculates numerical answer for given expression
double numericalCalculator(int a, int b, int n, double h, double yValuesTotal, double valsOfx[], double valsOfy[])
{
	h = (b - a) / 5.0;

	for (int i = 0; i <= n - 1; i++)
	{
		valsOfx[i] = a + i * h;
		valsOfy[i] = valsOfx[i] * valsOfx[i] * valsOfx[i] * valsOfx[i] * valsOfx[i];

		yValuesTotal += valsOfy[i];
	}

	return h * (yValuesTotal);
}

//This function calculates exact answer for given expression
double exactCalculator(int a, int b, int power)
{
	power += 1;

	return ((b ^ power) / 6.0) - ((a ^ power) / 6.0);
}

//This function calculates difference between numerical and exact answers for given expression
double errorCalculator(double numerical, double exact)
{
	return fabs(numerical - exact);
}

//This function's sole purpose is to display various values and artifacts 
void displayFunc(double valsOfx[], double valsOfy[], double numericalAnswer, double exactAnswer, double error)
{
	cout << "x0 = " << setprecision(4) << valsOfx[0] << "      " << "y0 = " << setprecision(4) << valsOfy[0] << endl;
	cout << "x1 = " << setprecision(4) << valsOfx[1] << "    " << "y1 = " << setprecision(4) << valsOfy[1] << endl;
	cout << "x2 = " << setprecision(4) << valsOfx[2] << "    " << "y2 = " << setprecision(4) << valsOfy[2] << endl;
	cout << "x3 = " << setprecision(4) << valsOfx[3] << "    " << "y3 = " << setprecision(4) << valsOfy[3] << endl;
	cout << "x4 = " << setprecision(4) << valsOfx[4] << "    " << "y4 = " << setprecision(4) << valsOfy[4] << endl;

	cout << endl;

	cout << "Numerical Answer = " << setprecision(4) << numericalAnswer << endl;
	cout << "Exact Answer = " << exactAnswer << endl;
	cout << "Error = " << error << endl << endl;
}