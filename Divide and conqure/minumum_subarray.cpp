#include<iostream>
#include<math.h>
#include <algorithm>  
using namespace std;

//Time complexity : O(n^2)
int minumum_subarray(int arr[], int size) {
	int sum = 0;
	int max = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			sum += arr[j];
			if (sum > max)
				max = sum;
		}
		sum = 0;
	}
	return max;
}



int main()
{
	int arr[3] = {4,-1,5 };
	cout << su(arr,3) << endl;
}
