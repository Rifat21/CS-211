// Continued Fractions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class Rat {
private:
	int n;
	int d;

public:
	// constructors
	// default constructor
	Rat() {
		n = 0;
		d = 1;
	}

	// 2 parameter constructor
	Rat(int i, int j) {
		n = i;
		d = j;
	}

	// conversion constructor
	Rat(int i) {
		n = i;
		d = 1;
	}

	//accessor functions (usually called get() and set(...) )
	int getN() { return n; }
	int getD() { return d; }

	void setN(int i) { n = i; }
	void setD(int i) { d = i; }

	//arithmetic operators
	Rat operator+(Rat r) {
		Rat t;
		t.n = n*r.d + d*r.n;
		t.d = d*r.d;
		return t;
	}

	Rat operator-(Rat r) {
		Rat t;
		t.n = n*r.d - d*r.n;
		t.d = d*r.d;
		return t;
	}

	Rat operator*(Rat r) {
		Rat t;
		t.n = n*r.n;
		t.d = d*r.d;
		return t;
	}

	Rat operator/(Rat r) {
		Rat t;
		t.n = n*r.d;
		t.d = d*r.n;
		return t;
	}
	// Write the other 3 operators (operator-, operator*, operator/).

	// Write a function to reduce the Rat to lowest terms, and then you can call this function from other functions.
	// Also make sure that the denominator is positive.  Rats should be printed in reduced form.
	Rat reduce(Rat r) {
		setN(r.n / gcd(r.n, r.d));
		setD(r.d / gcd(r.n, r.d));
		if (r.d < 1) {
			setD(r.d*-1);
			setN(r.n*-1);
		}
		return r;
	}
	// Calculate the GCD (Euclid's algorithm)
	int gcd(int n, int d) {
		return d == 0 ? n : gcd(d, n%d);
	}

	// 2 overloaded i/o operators
	friend ostream& operator<<(ostream& os, Rat r);
	friend istream& operator >> (istream& is, Rat& r);
}; //end Rat

   // operator<<() is NOT a member function but since it was declared a friend of Rat
   // it has access to its private parts.
ostream& operator<<(ostream& os, Rat r) {
	if (r.n > r.d) {
		if (r.n%r.d == 0) {
			os << r.n / r.d << endl;
		}
		else {
			Rat t(r.n%r.d, r.d);
			t.reduce(t);
			os << r.n / r.d << " " << t.n << "/" << t.d << endl;
		}
	}
	else if (r.n == 0) {
		os << 0 << endl;
	}
	else if (r.n == r.d) {
		os << 1 << endl;
	}
	else {
		r.reduce(r);
		os << r.n << "/" << r.d << endl;
	}
	// Rewrite this function so that improper fractions are printed as mixed numbers.  For example:
	// 3/2 should be printed as 1 1/2
	// 1/2 should be printed as 1/2
	// 2/1 should be printed as 2
	// 0/1 should be printed as 0
	// Negative numbers should be printed the same way, but beginning with a minus sign
	return os;
}

double continued_frac_1(int a[], int i) {
	if (a[i+1] == -1) return a[i];
	return(double)(a[i] + (1 / continued_frac_1(a, i + 1)));
}
Rat continued_frac_3(int a[], int i) {
	Rat j(1);
	if (a[i+1] == -1) return Rat(a[i]);
	return (Rat(a[i]) + (j / (continued_frac_3(a, i + 1))));
}
int* continued_frac_2(int a[], int i) {

	int *v = new int[2];
	
	Rat k(continued_frac_3(a, i));
	v[0] = k.getN();
	v[1] = k.getD();
	return v;
}


int main() {
	int array[] = { 3, 7, 16, -1 };
	cout << "Continued fractions function 1: " <<
		continued_frac_1(array, 0) << endl;

	int *a = continued_frac_2(array, 0);
	cout << "Continued fractions function 2: " <<
		a[0] << '/' << a[1] << endl;
	delete[]a;
	
	cout << "Continued fractions function 3: " <<
		continued_frac_3(array, 0) << endl;

	return 0;
}