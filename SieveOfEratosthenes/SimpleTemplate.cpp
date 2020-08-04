#include <bits/stdc++.h>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i, a, b) for (int i=a; i<=b; i--)
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define fi first 
#define se second 
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define DEBUG



//==========khai bao cac ham su dung=========
void inputArray(int arr[], int);
void ascendingArray(int arr[], int, int);
void descendingArray(int arr[], int, int);
int getInt(int min, int max);
//==========start============
int temp;
int n;
int main() {

	int arr[30];

	inputArray(arr, n);
	ascendingArray(arr, n, temp);
}

int getInt(int min, int max) {
	int value;
	char check; //42a
	do {
		int rc = scanf("%d%c", &value, &check); //tra ve 2 neu gia tri doc thanh cong
		fflush(stdin);
		if (rc != 2 || check != '\n') {
			printf("Invalid value !!! \n");
		}
		else if (value < min || value > max) {
			printf("Value out of range !!!\n");
		}
		else {
			return value;
		}
	} while (1);
}

void inputArray(int* arr[], int* n) {
	int i;
	//input size of array
	printf("Please enter size of array: ");
	scanf("%d", &n);
	// input elements
	for (i = 0; i < *n; i++) {
		printf("\nEnter element[%d]: ", i);
		scanf("%d", &arr[i]);
	}
}

void ascendingArray(int arr[], int n, int temp) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\nThe array sorted in ascending: ");
	for (i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
}
