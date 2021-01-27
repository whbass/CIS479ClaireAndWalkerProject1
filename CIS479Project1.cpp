//Claire Hofmann & Walker Bass CIS-479 Project 1
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;


//Gets Windy Manhattan Distance of a 3x3 2d puzzle array. Y is up and down, x is side to side. Use negs & abs values after getting value to determine amount due to wind
int heuristicFunction(int p[][3])
{
	int num, x, y, total = 0;
	
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

//Get location of the 0(or -). Find it's coordinates based on x/y. Based on it's x/y, "if" statement to get the correct values that can move to it's spot.
//With new puzzle from moved tile, send to heuristic function to get h distance. Use that value in priority queue. Put nums as negative so you can use
//the "top" function to get the lowest value which is what we want.
void priorityQueue(int p[][3])
{
	int num, x, y, val1 = 2147483647, val2 = 2147483647, val3 = 2147483647, val4 = 2147483647;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			num = p[i][j];
			if(num == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
	}
	
	if((x+1) < 3)
	{
		p[x][y] = p[x+1][y];
		p[x+1][y] = 0;
		
		val1 = heuristicFunction(p);
		
		p[x+1][y] = p[x][y];
		p[x][y] = 0;
	}
	
	if((y+1) < 3)
	{
		p[x][y] = p[x][y+1];
		p[x][y+1] = 0;
		
		val2 = heuristicFunction(p);
		
		p[x][y+1] = p[x][y];
		p[x][y] = 0;
	}
	
	
	if((y-1) >= 0)
	{
		p[x][y] = p[x][y-1];
		p[x][y-1] = 0;
		
		val3 = heuristicFunction(p);
	
		p[x][y-1] = p[x][y];
		p[x][y] = 0;
	}
	
	if((x-1) >= 0)
	{
		p[x][y] = p[x-1][y];
		p[x-1][y] = 0;
		
		val4 = heuristicFunction(p);
		
		p[x-1][y] = p[x][y];
		p[x][y] = 0;
	}
	
	priority_queue <int> q;
    q.push(-val1);
    q.push(-val2);
    q.push(-val3);
    q.push(-val4);

	int prio = q.top();
	prio *= -1;
	
	if(prio == val1)
	{
		p[x][y] = p[x+1][y];
		p[x+1][y] = 0;
	}
	else if(prio == val2)
	{
		p[x][y] = p[x][y+1];
		p[x][y+1] = 0;
	}
	else if(prio == val3)
	{
		p[x][y] = p[x][y-1];
		p[x][y-1] = 0;
	}
	else if(prio == val4)
	{
		p[x][y] = p[x-1][y];
		p[x-1][y] = 0;
	}
	
	for (int i = 0; i < 3; i++)
	    	for (int j = 0; j < 3; j++)
	        	cout << p[i][j];
}

int main()
{
	int puzzle[3][3] = {{2, 8, 3}, {6, 7, 4}, {1, 5, 0}};
	//int puzzle[3][3] = {{0, 8, 6}, {2, 7, 4}, {1, 5, 3}};

	priorityQueue(puzzle);

	return 0;
}
