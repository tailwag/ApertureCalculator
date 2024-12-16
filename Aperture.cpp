#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double format(double n) {
	if (n < 2.8)
		return round(n * 100) / 100;

	if (n < 5.6)
		return round(n * 10) / 10;

	if (n - floor(n) >= 0.9)
		n = round(n);

	if (n < 11) 
		return floor(n * 10) / 10; 

	if (n < 22) 
		return round(n);

	return floor(n);
}

string labels[5] = { "1/4", "1/3", "1/2", "2/3", "3/4" };
double  roots[5] = { 8.0, 6.0, 4.0, 3.0, 2.66666666666 };

int main () {
	double f = 1.0;
	while (f < 64) {
		cout << "Whole," << format(f) << endl;
		for (int i = 0; i < 5; i++) {
			cout << labels[i] << "," << format(f / (1.0 / pow(2.0, 1.0/roots[i]))) << endl;
		}
		f = f / (1 / sqrt(2));
	}
	return 1;
}
