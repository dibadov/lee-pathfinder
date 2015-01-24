#include "utils.h"

using namespace std;

int* LoadMap(const char *filename, int &x, int &y)
{
	FILE *pFile = fopen(filename, "r");
	int x_size, y_size;
	fscanf_s(pFile, "Horizontal: %d\n", &x_size);
	fscanf_s(pFile, "Vertical: %d\n", &y_size);

	int *result = new int[x_size*y_size];

	char temp;

	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			fscanf_s(pFile, "%c", &temp);
			temp -= 48;
			result[i*y_size + j] = temp;
		}
		fscanf_s(pFile, "\n");
	}
	fclose(pFile);
//	cout << "Map loaded(" << x_size << "," << y_size << ")" << endl;

	x = x_size;
	y = y_size;
	return result;
}

void PrintMap(int *map, int x_size, int y_size)
{
	for (int y = 0; y < y_size; y++)
	{
		for (int x = 0; x < x_size; x++)
		{
			cout <<setw(3)<< map[y*y_size + x]<<" ";
		}
		cout << endl;
	}
}
