//Claire Hofmann & Walker Bass CIS-479 Project 1
#include<iostream>
#include <cmath>
using namespace std;


//More efficient heuristic function than the ifs. Y is up and down, x is side to side. Use negs & abs values after getting value to determine amount due to wind
int heuristicFunction(int p[][3])
{
	int num, x, y, total;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			num = p[i][j];
			x = 0;
			y = 0;
			
			if(num == 1)
			{
				y = i - 0;
				x = j - 0;
			}
			else if(num == 2)
			{
				y = i - 0;
				x = j - 1;
			}
			else if(num == 3)
			{
				y = i - 0;
				x = j - 2;
			}
			else if(num == 4)
			{
				y = i - 1;
				x = j - 2;
			}
			else if(num == 5)
			{
				y = i - 2;
				x = j - 2;
			}
			else if(num == 6)
			{
				y = i - 2;
				x = j - 1;
			}
			else if(num == 7)
			{
				y = i - 2;
				x = j - 0;
			}
			else if(num == 8)
			{
				y = i - 1;
				x = j - 0;
			}
			
			if(y < 0)
			{
				total += abs(y * 3);
			}
			else if(y > 0)
			{
				total += y;
			}
			
			if(x != 0)
			{
				total += abs(x * 2);
			}
		}
	}
	return total;
}

int main()
{
	int puzzle[3][3] = {{2, 8, 3}, {6, 7, 4}, {1, 5, 0}};
	//int puzzle[3][3] = {{7, 6, 5}, {4, 3, 2}, {1, 4, 1}};
	int h;
	
	h = heuristicFunction(puzzle);

	cout << h;

	return 0;
}
