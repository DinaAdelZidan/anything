#include<iostream>

using namespace std;

void Display(int, int *, int);
int *Merge(int *&, int&, int *&, int&, int&);

int main()
{
	int n, m, sizeZ;

	cout << "Enter the size of your first array: " << endl;
	cin >> n;
	cout << "Enter the size of your second array: " << endl;
	cin >> m;

	int *X = new int[n];
	int *Y = new int[m];
	cout << "First Array: " << endl;
	for (int i = 0; i<n; i++)
		cin >> X[i];
	cout << "Second Array: " << endl;
	for (int i = 0; i<m; i++)
		cin >> Y[i];

	Display(1, X, n);
	Display(2, Y, m);
	int *Z = Merge(X, n, Y, m, sizeZ);
	cout << "**After Merge**" << endl;
	Display(1, X, n);
	Display(2, Y, m);
	Display(3, Z, sizeZ);

	delete[]Z;
	sizeZ = 0;

	system("pause");
	return 0;
}


void Display(int position, int *Array, int size)
{
	cout << endl << "Array(" << position << ")" << endl;
	cout << "Size: " << size << endl << "[  ";
	for (int i = 0; i<size; i++)
		cout << Array[i] << "  ";
	cout << "]" << endl << endl;
}



int *Merge(int *&A, int& sizeA, int *&B, int& sizeB, int& sizeC)
{
	sizeC = sizeA + sizeB;
	int *C = new int[sizeC];

	for (int i = 0; i<sizeA; i++)
		C[i] = A[i];
	for (int i = sizeA; i<sizeC; i++)
		C[i] = B[i - sizeA];

	delete[]A;
	delete[]B;
	A = NULL;
	B = NULL;
	sizeA = 0;
	sizeB = 0;
	return C;
}