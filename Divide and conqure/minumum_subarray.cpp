#include<iostream>
#include<math.h>
#include <algorithm>  
using namespace std;

//Time complexity : O(n^2)
//Brute-force solution
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
	int arr[16] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	cout << minumum_subarray(arr,16) << endl;
	//output = 43
}
