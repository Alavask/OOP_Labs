#include <stdlib.h>
#include <iostream>
#include <memory>

using namespace std;
void fv() {
	int i = int(123);
	cout << "i = " << i << endl;
}
void fp1() {
	auto i = std::make_shared<int>(123);
	cout << "*i = " << *i << endl;
}
void fp2() {
	auto i = std::make_shared<int>(123);
	cout << "*i = " << *i << endl;
	i = std::make_shared<int>(456);
	cout << "*i = " << *i << endl;
}
int* fr() {
	static int i = int(123);
	int* ip = &i;
	cout << "i = " << i << endl;
	return ip;
}
int main() {
	fv();
	fp1();
	fp2();
	int* ifr = fr();
	cout << "*ifr = " << *ifr << endl;
	return 0;
}