// Lab_05_2.cpp
// < Shakh Vlad >
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 32

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

// Обчислює суму ряду; кількість доданків повертає через параметр n
double S(const double x, const double eps, int& n, double s);

// Обчислює наступний доданок ряду з попереднього (рекурентне співвідношення)
double A(const double x, const int n, double a);

int main()
{
	double xp, xk, x, dx, eps, s = 0;
	int n = 0;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << "    |"
		<< setw(10) << "arctg(x)" << "   |"
		<< setw(7) << "S" << "       |"
		<< setw(5) << "n" << "   |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		s = S(x, eps, n, s);

		cout << "|" << setw(7) << setprecision(2) << x << "   |"
			<< setw(10) << setprecision(5) << atan(x) << "   |"
			<< setw(10) << setprecision(5) << s << "   |"
			<< setw(5) << n << "   |"
			<< endl;

		x += dx;
	}
	cout << "-------------------------------------------------" << endl;

	return 0;
}

double S(const double x, const double eps, int& n, double s)
{
	n = 0;
	double a = -1 / x;      // перший доданок (n = 0): (-1)^1 / (1 * x^1)
	s = -PI / 2 + a;        // сума ряду разом із членом -pi/2

	do {
		n++;
		a = A(x, n, a);
		s += a;
	} while (fabs(a) >= eps);

	return s;
}

double A(const double x, const int n, double a)
{
	double R = -(2.0 * n - 1) / ((2.0 * n + 1) * x * x);   // коефіцієнт рекурентності
	a *= R;
	return a;
}