//fibonacci.cpp
#include <iostream>
using namespace std;
int fibonacci(int n)
{
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
/*
 연습문제 : xref.cpp에서 7-7,7-8
 그리고 한줄에 단어가 두번 이상 나타나면 줄번호를 여러번 출력하지 않고 한번만 출력하세요
*/
int main()
{
	int num;
		cout << "Enter n for a Fibonacci series: ";
	cin >> num;
	cout << "Fibonacci at " << num << " is "
		<< fibonacci(num) << endl;
	return 0;
}