#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void InitRand()
{
	srand((unsigned int)time(NULL));
}

int InitRand(int &randkeep, int arraysize)
{
	randkeep = rand() % arraysize;
	return randkeep;
}

void InitArray(int* array1, int* array2, int arraysize)
{
	for (int i = 0; i < arraysize; ++i)
	{
		*(array2 + i) = *(array1 + i);
	}
}

void Shuffle(int* array1, int* array2, int arraysize)
{
	for (int i = arraysize - 1; 0 <= i; --i)
	{
		int randkeep = 0;

		while (*(array2 + InitRand(randkeep, arraysize)) == 0) //中身が0だったらarrayを選びなおす
		{

		}

		*(array1 + i) = *(array2 + randkeep); //ランダムに選ばれたrandkeep番目をbの後ろから入れる
		*(array2 + randkeep) = 0;    //選ばれたrandkeep番目に0を入れる
	}
}

void Show(int* array1, int arraysize)
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
	int* array2 = new int[MAX_INDEX];

	if (array2 == NULL)
	{
		*array2 = 0;
		cout << *array2 << endl;

		delete[] array2;
	}

	cout << "シャッフルする前 " << flush;
	Show(array1, MAX_INDEX);
	cout << endl;

	InitArray(array1, array2, MAX_INDEX);
	Shuffle(array1, array2, MAX_INDEX);
	
	cout << "シャッフルした後 " << flush;
	Show(array1, MAX_INDEX);
	cout << endl;
	
	delete[] array2;
}