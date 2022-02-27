#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	long long n, x;
	cin >> n >> x;
	long long counter = 0;
	char arr1[10000];
	long long arr2[10000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
		cin >> arr2[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] == '+')
		{
			x += arr2[i];
		}

		else
		{
			if (arr2[i] > x)
			{
				counter++;
			}
			else
			{
				x -= arr2[i];
			}
		}
	}

	cout << x << " " << counter;

	return 0;

}