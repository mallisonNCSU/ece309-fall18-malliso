#include "IntInf.h"
#include <stdio.h>

int main() {
	int testCount = 0;
	IntInf x(1);
	IntInf y(-1);
	IntInf z(0, -5);	
	
	//operator=
	IntInf a;
	a = 2;
	if (a.getNumber() == 2) {
		testCount++;
	}
	a = x;
	if (a.getType() == 1) {
		testCount++;
	}
	
	//operator+
	a = 2;
	a = a + z;
	if (a.getNumber() == -3) {
		testCount++;
	}
	a = 2;
	a = a + x;
	if (a.getType() == 1) {
		testCount++;
	}
	
	//operator-
	a = 2;
	a = a - z;
	if (a.getNumber() == 7) {
		testCount++;
	}
	a = 2;
	a = a - y;
	if (a.getType() == 1) {
		testCount++;
	}
	
	//operator*
	a = 2;
	a = a * z;
	if (a.getNumber() == -10) {
		testCount++;
	}
	a = y * x;
	if (a.getType() == -1) {
		testCount++;
	}
	
	//operator/
	a = 10;
	a = a / z;
	if (a.getNumber() == -2) {
		testCount++;
	}
	a = y / x;
	if (a.getType() == -1) {
		testCount++;
	}
	a = 10;
	a = a / x;
	if ((a.getNumber() == 0) && (a.getType() == 0)) {
		testCount++;
	}
	
	//operator==
	a = -5;
	if(a == z) {
		testCount++;
	}
	a = x;
	if(!(a == x)) {
		testCount++;
	}
	//operator>
	a = 2;
	if(a > z) {
		testCount++;
	}
	if(x > a) {
		testCount++;
	}
	if(x > y) {
		testCount++;
	}
	
	//operator<
	a = -6;
	if(a < z) {
		testCount++;
	}
	if(y < a) {
		testCount++;
	}
	if(y < x) {
		testCount++;
	}
	
	printf("Passed %d/19 tests.\n",testCount);
	if(testCount != 19) {
		return 1;
	} else {
		return 0;
	}
}