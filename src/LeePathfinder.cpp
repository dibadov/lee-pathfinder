#include "LeePathfinder.h"

LeePathfinder::LeePathfinder(int *field, int size_x, int size_y)
{
	this->field = field;
	this->size_x = size_x;
	this->size_y = size_y;

	indexes = new int[size_x*size_y];
	for (int i = 0; i < size_y; i++)
		for (int j = 0; j < size_x; j++)
			indexes[size_y*i + j] = -2;

	for (int i = 0; i < size_y; i++)
		for (int j = 0; j < size_x; j++)
		{
			if (field[size_y*i + j] == 2)
			{
				start.first = j;
				start.second = i;
			}
			if (field[size_y*i + j] == 3)
			{
				end.first = j;
				end.second = i;
			}
		}
}

void LeePathfinder::Backtrace()
{
	int x = end.first;
	int y = end.second;

	int tempX;
	int tempY;

	int temp = 100;

	while (x != start.first || y != start.second)
	{
		if (x < size_x - 1)
		{
			if (indexes[size_y*y + x + 1] >= 0)
				if (temp > indexes[size_y*y + x + 1])
				{
					temp = indexes[size_y*y + x + 1];
					tempX = x + 1;
					tempY = y;
				}
			
		}
		if (x > 0)
		{
			if (indexes[size_y*y + x - 1] >= 0)
			if (temp > indexes[size_y*y + x - 1])
			{
				temp = indexes[size_y*y + x - 1];
				tempX = x - 1;
				tempY = y;
			}

		}
		if (y < size_y - 1)
		{
			if (indexes[size_y*(y+1) + x] >= 0)
			if (temp > indexes[size_y*(y + 1) + x])
			{
				temp = indexes[size_y*(y + 1) + x];
				tempX = x;
				tempY = y+1;
			}

		}
		if (y > 0)
		{
			if (indexes[size_y*(y - 1) + x] >= 0)
			if (temp > indexes[size_y*(y - 1) + x])
			{
				temp = indexes[size_y*(y - 1) + x];
				tempX = x;
				tempY = y - 1;
			}

		}
		x = tempX;
		y = tempY;

		
		path.push_back(Coord(x,y));
	}
}

bool LeePathfinder::MarkPoint(int i, int j, int n)
{
	if (indexes[i*size_y + j] == -2)
	{
		if (field[i*size_y + j] ==1)
			indexes[i*size_y + j] = -1;
		else
		{
			indexes[i*size_y + j] = n + 1;
			return true;
		}
	}
	return false;
}


CoordVector* LeePathfinder::CalculatePath()
{
	indexes[size_y*start.second + start.first] = 0;
	int i, j;
	CoordVector marked;
	marked.push_back(start);

	int s, e;
	s = 0;
	int n = 0;
	bool stop = false;
	bool end_reached = false;

	while (!stop && !end_reached)
	{
		stop = true;
		e = marked.size();		
		for (int k = s; k<e; k++)
		{
			j = marked[k].first;
			i = marked[k].second;

			if (indexes[i*size_y + j] != n)
					continue;

			if (i == end.second && j == end.first)
				end_reached = true;

			if (j < size_x - 1)
				if (MarkPoint(i, j+1, n))
				{
					marked.push_back(Coord(j+1,i));
					stop = false;
				}

			if (j > 0)
				if (MarkPoint(i, j-1, n))
				{
					marked.push_back(Coord(j-1,i));
					stop = false;
				}

			if (i < size_y - 1)
				if (MarkPoint(i+1, j, n))
				{
					marked.push_back(Coord(j,i+1));
					stop = false;
				}

			if (i >0)
				if (MarkPoint(i-1, j, n))
				{
					marked.push_back(Coord(j,i-1));
					stop = false;
				}		
		}
		s = e;
		n++;
	}

	if (end_reached)
		Backtrace();

	return &path;
}


LeePathfinder::~LeePathfinder()
{
	delete[] indexes;
}
