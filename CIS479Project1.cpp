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
	int num, x, y, val1, val2, val3, val4;
	int pTemp[3][3];
	
	for (int i = 0; i < 3; i++)
    	for (int j = 0; j < 3; j++)
        	pTemp[i][j] = p[i][j];
	
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
	
	if(x == 0 && y == 0)
	{
		pTemp[0][0] = pTemp[1][0];
		pTemp[1][0] = 0;
		
		val1 = heuristicFunction(pTemp);
		
		pTemp[1][0] = pTemp[0][0];
		pTemp[0][0] = 0;
		
		pTemp[0][0] = pTemp[0][1];
		pTemp[0][1] = 0;
		
		val2 = heuristicFunction(pTemp);
		
		priority_queue <int> q;
	    q.push(-val1);
	    q.push(-val2);
	
		int prio = q.top();
		prio *= -1;
	    cout << val1 << endl;
	    cout << val2 << endl;
	}
	
	if(x == 2 && y == 2)
	{
		pTemp[2][2] = pTemp[1][2];
		pTemp[1][2] = 0;
		
		val1 = heuristicFunction(pTemp);
		
		pTemp[1][2] = pTemp[2][2];
		pTemp[2][2] = 0;
		
		pTemp[2][2] = pTemp[2][1];
		pTemp[2][1] = 0;
		
		val2 = heuristicFunction(pTemp);
		
		priority_queue <int> q;
	    q.push(-val1);
	    q.push(-val2);
	
		int prio = q.top();
		prio *= -1;
	    cout << val1 << endl;
	    cout << val2 << endl;
	}
}

int main()
{
	int puzzle[3][3] = {{2, 8, 3}, {6, 7, 4}, {1, 5, 0}};

	priorityQueue(puzzle);

	return 0;
}
