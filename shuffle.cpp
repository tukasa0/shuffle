#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void InitRand()
{
	srand((unsigned int)time(NULL));
}

void Shuffle(int* array1, int arraysize)
{
	for (int i = arraysize - 1; i > 0; --i)
	{
		int keep = 0;
		int j = rand() % i;

		keep = *(array1 + i);
		*(array1 + i) = *(array1 + j);
		*(array1 + j) = keep;
	}

}

void Show(const int* const array1, const int const arraysize)
{
	for (int i = 0; i < arraysize; ++i)
	{
		cout << *(array1 + i) << " " << flush;
	}
}

int main()
{
	InitRand();

	const int MAX_INDEX = 10;
	int array1[MAX_INDEX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "シャッフルする前 " << flush;
	Show(array1, MAX_INDEX);
	cout << endl;

	Shuffle(array1, MAX_INDEX);
	
	cout << "シャッフルした後 " << flush;
	Show(array1, MAX_INDEX);
	cout << endl;
	
	
}