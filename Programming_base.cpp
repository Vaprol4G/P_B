#include <iostream>
using namespace std;
#include <string>
#include <fstream>


void Print(int arr[10][10])
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int a[10][10];

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				a[i][j] = 0;
			}

		}
	
	fstream fl;
	fl.open("test.txt");
	if (!fl.is_open())
	{
		cout << "File not found" << endl;
	}
	else
	{
		int i = 0;
		int j = 0;
		while (!fl.eof())
		{	
			fl >> a[i][j];
			j++;
			if (j==10)
			{
				j = 0;
				i++;
			}
		}
	}
	fl.close();

	Print(a);

	//сортировка строк
	int min;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			min = a[i][j];
			for (int z = j; z < 10; z++)
			{			
				if (a[i][z] < min)
				{
					swap(a[i][j], a[i][z]);
					min = a[i][j];
				}	
			}
		}
	}

	Print(a);

	// сортировка столбцов
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			min = a[i][j];
			for (int p = i; p < 10; p++)
			{
				if (a[p][j] < min)
				{
					min = a[p][j];
					for (int z = j; z < 10; z++)
					{
						swap(a[p][z], a[i][z]);
					}
				}
			}
		}
	}
	Print(a);

	//Полная сортировка в обратном порядке

	int ca = 1;
	swap(a[9][9],a[0][0]);
	while (ca > 0)
	{
		ca = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (((i < 9) || (j < 9)) && (a[i][j] < a[i + 1][0]))
				{
					swap(a[i][j], a[i + 1][0]);
					ca++;
				}
				else
				{
					if ((a[i][j] < a[i][j + 1]) && ((i < 9) || (j < 9)))
					{
						swap(a[i][j], a[i][j + 1]);
						ca++;
					}
				}

			}

		}
	}	
	
	Print(a);
}