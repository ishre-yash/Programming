#include <iostream>
using namespace std;

void fib(int n)
{
	int t1 = 0, t2 = 1, next;

	for (int i = 0; i <= n; i++)
	{
		cout << t1 << endl;
		next = t1 + t2;
		t1 = t2;
		t2 = next;
	}
}

int main(void)
{
	int num;

	cout << "Enter the num to print:";
	cin >> num;

	fib(num);
}
