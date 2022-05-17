
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
int SearchMaxEven(int** a, const int n, const int k, int& maxEven);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int n;
	int k;
	int S = 0;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	CreateRows(a, k, n, Low, High, 0);
	Print(a, k, n, 0, 0);

	int maxEven;
	S = (SearchMaxEven(a, k, n, maxEven));
	cout << "S = " << S << endl;
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);

}
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);

}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;

}

int SearchMaxEven(int** a, const int k, const int n, int& maxEven)
{
	int S = 0;
	for (int i = 0; i < k; i++)
	{
		maxEven = a[i][0];
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > maxEven)
			{
				maxEven = a[i][j];
			}
		}
		S += maxEven;
	}
	return S;
}
