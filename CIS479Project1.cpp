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

//Get location of the 0(or -). Find it's coordinates based on y/x. Based on it's y/x, "if" statement to get the correct values that can move to it's spot.
//With new puzzle from moved tile, send to heuristic function to get h distance. Add h distance to path cost(1,2,3 based on wind). Put nums as negative so you can use
//the "top" function which grabs the largest value, to get the lowest value which is what we want. Do this until h is 0, ie puzzle solved.
void priorityQueue(int p[][3])
{
	int num, x, y, pTemp, pathCost, val1 = 2147483000, val2 = 2147483000, val3 = 2147483000, val4 = 2147483000, hTemp, h = 2147483000;
	priority_queue <int> q;
	
	while(h != 0)
	{
		val1 = 2147483000;
		val2 = 2147483000; 
		val3 = 2147483000; 
		val4 = 2147483000;
		h = 2147483000;
		pTemp = pathCost;
		
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
		
		if((y+1) < 3)
		{
			p[y][x] = p[y+1][x];
			p[y+1][x] = 0;
			
			h = heuristicFunction(p);
			pTemp += 3;
			val1 = h + pTemp;
			
			p[y+1][x] = p[y][x];
			p[y][x] = 0;
		}
		
		if((x+1) < 3)
		{
			p[y][x] = p[y][x+1];
			p[y][x+1] = 0;
			
			h = heuristicFunction(p);
			pTemp += 2;
			val2 = h + pTemp;
			
			p[y][x+1] = p[y][x];
			p[y][x] = 0;
		}
		
		if((x-1) >= 0)
		{
			p[y][x] = p[y][x-1];
			p[y][x-1] = 0;
			
			h = heuristicFunction(p);
			pTemp += 2;
			val3 = h + pTemp;
		
			p[y][x-1] = p[y][x];
			p[y][x] = 0;
		}
		
		if((y-1) >= 0)
		{
			p[y][x] = p[y-1][x];
			p[y-1][x] = 0;
			
			h = heuristicFunction(p);
			pTemp +=1;
			val4 = h + pTemp;
			
			p[y-1][x] = p[y][x];
			p[y][x] = 0;
		}
		
	    q.push(-val1);
	    q.push(-val2);
	    q.push(-val3);
	    q.push(-val4);
	
		int prio = q.top();
		prio *= -1;
		q = priority_queue <int>(); 
		
		if(prio == val1)
		{
			p[y][x] = p[y+1][x];
			p[y+1][x] = 0;
			pathCost += 1;
		}
		else if(prio == val2)
		{
			p[y][x] = p[y][x+1];
			p[y][x+1] = 0;
			pathCost += 2;
		}
		else if(prio == val3)
		{
			p[y][x] = p[y][x-1];
			p[y][x-1] = 0;
			pathCost += 2;
		}
		else if(prio == val4)
		{
			p[y][x] = p[y-1][x];
			p[y-1][x] = 0;
			pathCost += 3;
		}
		
		h = heuristicFunction(p);
		
		for (int i = 0; i < 3; i++)
		    	for (int j = 0; j < 3; j++)
		        	cout << p[i][j];
		cout << endl;
		cout << pathCost << endl;
	}
	
	//cout << pathCost;
}

int main()
{
	int puzzle[3][3] = {{2, 8, 3}, {6, 7, 4}, {1, 5, 0}};
	//int puzzle[3][3] = {{2, 8, 3}, {6, 0, 4}, {1, 7, 5}};

	priorityQueue(puzzle);

	return 0;
}
