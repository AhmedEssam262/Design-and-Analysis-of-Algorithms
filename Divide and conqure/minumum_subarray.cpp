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

//Time complexity : O(n)
//Divide and conqure
/*
we emplemebt this code with three functions 
1- Function for max value
2- Function to get the sub-array with mid 
3- Recursive function to get all functions
*/
int max(int a, int b)
{return (a > b) ? a : b;}

int MaxCrossingSum(int arr[], int low, int mid, int high)
{
	int sum = 0;
	int leftpartsum = -1;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + arr[i];
		if (sum > leftpartsum)
			leftpartsum = sum;
	}
	sum = 0;
	int rightpartsum = -1;
	for (int i = mid + 1; i <= high; i++)
	{
		sum = sum + arr[i];
		if (sum > rightpartsum)
			rightpartsum = sum;
	}
	return leftpartsum + rightpartsum;
}

int MaxSubArraySum(int arr[], int low, int high)
{
	int mid;
	if (low == high)
		return arr[low];
	mid = (low + high) / 2;
	return max(max(MaxSubArraySum(arr, low, mid), MaxSubArraySum(arr, mid + 1, high)), MaxCrossingSum(arr, low, mid, high));
}

int main()
{
	int arr[16] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	cout << minumum_subarray(arr,16) << endl;
	//output = 43
}
