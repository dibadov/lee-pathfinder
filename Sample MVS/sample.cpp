#include "utils.h"
#include "LeePathfinder.h"

using namespace std;

const char* mapfile = "leetest.map";



int main()
{
	int x, y;
	int *m = LoadMap(mapfile, x, y);
	PrintMap(m,x,y);

	LeePathfinder c(m, x, y);
	vector<pair<int, int>> *a = c.CalculatePath();
	cout<<endl;

	PrintMap(c.GetIndexedMap(),x,y);

	for (int i = 0; i < a->size(); i++)
	{
		cout << (*a)[i].first << "  " << (*a)[i].second << endl;
	}
	
	return 0;
}