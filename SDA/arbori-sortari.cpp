#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <random>

using namespace std;

#include "../arboreBST.h"
#include "../sortari.h"


// C++ program for building Heap from Array 

#include <iostream> 

using namespace std;

// forma de alocare statica

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// Function to build a Max-Heap from the given array 
void buildHeap(int arr[], int n) {
	// Index of last non-leaf node 
	int startIdx = (n / 2) - 1;

	// Perform reverse level order traversal 
	// from last non-leaf node and heapify 
	// each node 
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, n, i);
	}
}

void printArray(int arr[], int n);

// main function to do heap sort 
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	printArray(arr, n);
	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	int i, size = 1024;// 2 * 65535;
	int* R = new int[size+10];
	//int N[] = { 23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5 };
	//int N[] = { 24, 23, 24, 12, 5, 2, -124, 23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5,23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5,23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5,23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5,23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5,23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5,23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5,23, 24, 12, 5, 2, -1, -2, -5, -3, 0, };
	int *N = new int[size+10];
	int n = size; //  sizeof(N) / sizeof(N[0]);

	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.
						// replace the call to rd() with a
						// constant value to get repeatable
						// results.

	for (i = 0; i < n; i++) {
		N[i] = gen();// % 65535;
		if (i < 20)
			cout << N[i] << ", ";
	}
	cout << endl << "dim = " << n << endl;
	
	/*
	heapSort(N, n);
	cout << "Sorted array is \n";
	printArray(N, n);
	//buildHeap(N, n);
	//printHeap(N, n);
	return 1;
	*/
	/*{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);
		
		for (i = 0; i < n; i++) {
			R[i] = N[i];
		}
		selectdirSort(R, n);
		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("select : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		for (i = 0; i < n; i++) {
			R[i] = N[i];
		}
		insertdirSort(R, n);
		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("insert : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		for (i = 0; i < n; i++) {
			R[i] = N[i];
		}
		inserBinSort(R, n);
		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("insertBin : %.3f seconds.\n", elapsed.count() * 1e-9);
	}*/
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		for (i = 0; i < n; i++) {
			R[i] = N[i];
		}
		quickSort(R, 0, n);

		for (i = 0; i < 24; i++)
			cout << R[i] << ", ";
		cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("quickSort : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		/*for (i = 0; i < n; i++) {
			R[i] = N[i];
		}*/
		quickSort(R, 0, n);

		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("quickSort : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		for (i = 0; i < n; i++) {
			R[i] = N[i];
		}
		mergeSort(R, n);
		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("mergeSort : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		//for (i = 0; i < n; i++) {
		//	R[i] = N[i];
		//}
		mergeSort(R, n);
		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("mergeSort : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		for (i = 0; i < n; i++) {
			R[i] = N[i];
		}
		shellSort(R, n);
		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("shellSort : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	/*
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		for (i = 0; i < n; i++) {
			R[i] = N[i];
		}
		shakeSort(R, n);
		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("shakeSort : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);

		for (i = 0; i < n; i++) {
			R[i] = N[i];
		}
		bubbleSort(R, n);
		//for (i = 0; i < n; i++)
		//	cout << R[i] << ", ";
		//cout << endl;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("bubbleSort : %.3f seconds.\n", elapsed.count() * 1e-9);
	}*/
	{
		auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* h = new NOD<int>(N[0]);
		for (i = 1; i < n; i++) {
			h->push(N[i]);
		}

		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("heap : %.3f seconds.\n", elapsed.count() * 1e-9);
	}
	{	auto begin = std::chrono::high_resolution_clock::now();
		NOD<int>* b = new NOD<int>(N[0]);
		for (i = 1; i < n; i++) {
			b->insert(N[i]);
		}
		//b->inOrdine();
		//cout << endl;

		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("bst : %.3f seconds.\n", elapsed.count() * 1e-9);
	}

	delete[] R;
	delete[] N;
	return 0;
}