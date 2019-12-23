//Group Number: 12
//Group Members:
//Muhammad Sumair Saif 3275-FBAS/BSSE/F16
//Faheem Safdar        3269-FBAS/BSSE/F16
//Section: A
//Topic: Rectangular Rule
//Course: Numerical Computing
//Instructor: Sir Muhammad Rehan
//Date: 23/12/2019

//---------------------------------------------------

//Libraries used for assistance in this program
#include<iostream>
#include<iomanip>
#include<cmath>
#define SIZE 100

using namespace std;

//Declarations of all funcions in this program
double numericalCalculator(int, int, int, double, double, double[], double[]);
double exactCalculator(int, int, int);
double errorCalculator(double, double);
void displayFunc(double[], double[], double, double, double, int);

int main()
{
	int n = 0;        //Number of Iterations
	int a = 0;        //Lower Limit
	int b = 0;        //Upper Limit
	int power = 0;    //Power of variable
	double h = 0;

	double numericalAnswer;
	double exactAnswer;
	double error;
	double yValuesAdded = 0.0;

	//Taking Input for Various Parameters
	cout << "The Expression : x" << endl;
	cout << "Enter Lower Limit: "; cin >> a;
	cout << "Enter Upper Limit: "; cin >> b;
	cout << "Enter Power: "; cin >> power;
	cout << "Enter Number of Iterations: "; cin >> n; cout << endl;

	double valsOfx[SIZE]; //Array for storing values of x0, x1, x2 upto xn
	double valsOfy[SIZE]; //Array for storing values of y0, y1, y2 upto yn

	numericalAnswer = numericalCalculator(a, b, n, h, yValuesAdded, valsOfx, valsOfy);

	exactAnswer = exactCalculator(a, b, power);

	error = errorCalculator(numericalAnswer, exactAnswer);

	displayFunc(valsOfx, valsOfy, numericalAnswer, exactAnswer, error, n);
}

//This function calculates numerical answer for given expression
double numericalCalculator(int a, int b, int n, double h, double yValuesTotal, double valsOfx[], double valsOfy[])
{
	h = (b - a) / static_cast<float>(n);

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

	return (pow(b, power) / (float)power) - (pow(a, power) / (float)power);
}

//This function calculates difference between numerical and exact answers for given expression
double errorCalculator(double numerical, double exact)
{
	return fabs(numerical - exact);
}

//This function's sole purpose is to display various values and artifacts 
void displayFunc(double valsOfx[], double valsOfy[], double numericalAnswer, double exactAnswer, double error, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		cout << "x" << i << " = "<< setprecision(6) << valsOfx[i] << "      " << "y" << i << " = " << setprecision(6) << valsOfy[i] << endl;
	}

	cout << endl;

	cout << "Numerical Answer = " << setprecision(6) << numericalAnswer << endl;
	cout << "Exact Answer = " << exactAnswer << endl;
	cout << "Error = " << error << endl << endl;
}