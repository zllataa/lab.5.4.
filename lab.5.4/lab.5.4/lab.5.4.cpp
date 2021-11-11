// Лабораторна робота No 5.4
#include <iostream>
#include <cmath>

using namespace std;

double P0(const int k, const int N)
{
	double p = 1;
	for (int k = N; k <= 19; k++)
		p *= ((1.0*(k - N) / (1.0 * k + N)) + 1);
	return p;
}
double P1(const int k, const int N, const int i)
{
	if (i > 19)
		return 1;
	else
		return (((k - N) / (k + N)) + 1) * P1(k, N, i + 1);
}
double P2(const int k, const int N, const int i)
{
	if (i < 19)
		return 1;
	else
		return (((k - N) / (k + N)) + 1) * P2(k, N, i - 1);
}
double P3(const int k, const int N, const int i, double t)
{
	t = t * (((k - N) / (k + N)) + 1);
	if (i >= 19)
		return t;
	else
		return P3(k, N, i + 1, t);
}
double P4(const int k, const int N, const int i, double t)
{
	t = t * (((k - N) / (k + N)) + 1);
	if (i <= k)
		return t;
	else
		return P4(k, N, i - 1, t);
}



int main()
{
	int k, N;
	cout << "k = "; cin >> k;
	cout << "N = "; cin >> N;
	cout << "(iter) P0 = " << P0(k, N) << endl;
	cout << "(rec up ++) P1 = " << P1(k, N, k) << endl;
	cout << "(rec up --) P2 = " << P2(k, N, N) << endl;
	cout << "(rec down ++) P3 = " << P3(k, N, k, 1) << endl;
	cout << "(rec down --) P4 = " << P4(k, N, N, 1) << endl;
	return 0;
}
