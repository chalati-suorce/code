#include <iostream>
using namespace std;

/*
    ~
*/
int main() {
	// 1. 按位取反的定义
	int a = 0b00000000000000000000000000000001;
	int b = 0b11111111111111111111111111111110;
	cout << (~a) << endl;
	cout << b << endl;

	// 0b00000000000000000000000000000000   = 0
	// 0b11111111111111111111111111111111   = -1
	// 0b11111111111111111111111111111110   = -2
	// ...

	int c = 0b0;
	cout << (~c) << endl;

	// 2. 求相反数
	int d = 18;
	cout << (~d + 1) << endl; // 原码、反码、补码、移码

	

	return 0;
}