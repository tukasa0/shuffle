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

int main()
{
	InitRand();

	const int MAX_INDEX = 10;
	int b[MAX_INDEX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* array = new int[MAX_INDEX];

	if (array == NULL)
	{
		*array = 0;
		cout << *array << endl;

		delete[] array;
	}

	for (int i = 0; i < 10; ++i)
	{
		array[i] = b[i];
	}

	for (int i = 9; 0 <= i; --i)
	{
		int randkeep = 0;

		while (array[InitRand(randkeep, MAX_INDEX)] == 0) //中身が0だったらarrayを選びなおす
		{
			
		}

		b[i] = array[randkeep]; //ランダムに選ばれたrandkeep番目をbの後ろから入れる
		array[randkeep] = 0;    //選ばれたrandkeep番目に0を入れる

		cout << b[i] << endl;   //後ろから表示
	}

	delete[] array;
}