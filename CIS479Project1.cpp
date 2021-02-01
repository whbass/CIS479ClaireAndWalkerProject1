//Claire Hofmann & Walker Bass CIS-479 Project 1
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

void printPuzzle(vector<vector<int>>, int, int);

int currentLevel = 0;
int expansionOrder = 1;

struct Node
{
	vector<vector<int>> puzzle;
	int fn;
	int level;
	int currentPathCost;

	bool operator<(const Node &o) const
	{		
		return fn < o.fn || (fn == o.fn && level > o.level);
	}
};

priority_queue <Node> q;

//Gets Windy Manhattan Distance of a 3x3 2d puzzle array. Y is up and down, x is side to side. Use negs & abs values after getting value to determine amount due to wind
//int heuristicFunction(int p[][3])
int heuristicFunction(vector<vector<int>> p)
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

void priorityQueue(Node startingNode)
{
	Node currentNode = startingNode;
	vector<vector<int>> p;
	int num, x, y, pTemp, pathCost, fn1 = 2147483000, fn2 = 2147483000, fn3 = 2147483000, fn4 = 2147483000, hTemp, h = 2147483000;
	vector<vector<int>> p1, p2, p3, p4;
	Node n1,n2,n3,n4;

	h = heuristicFunction(currentNode.puzzle);
	
	while(h != 0)
	{
		p = currentNode.puzzle;
		pathCost = currentNode.currentPathCost;
		fn1 = 2147483000;
		fn2 = 2147483000; 
		fn3 = 2147483000; 
		fn4 = 2147483000;
		h = 2147483000;
		pTemp = pathCost;
		p1.clear(); p2.clear(); p3.clear(); p4.clear();
		n1 = {}; n2 = {}, n3 = {}, n4 = {};
		
		//determines where empty tile is
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
			pTemp += 1;
			fn1 = h + pTemp;
			p1 = p;
			
			p[y+1][x] = p[y][x];
			p[y][x] = 0;

			pTemp = pathCost;
		}
		
		if((x+1) < 3)
		{
			p[y][x] = p[y][x+1];
			p[y][x+1] = 0;
			
			h = heuristicFunction(p);
			pTemp += 2;
			fn2 = h + pTemp;
			p2 = p;
			
			p[y][x+1] = p[y][x];
			p[y][x] = 0;

			pTemp = pathCost;
		}
		
		if((x-1) >= 0)
		{
			p[y][x] = p[y][x-1];
			p[y][x-1] = 0;
			
			h = heuristicFunction(p);
			pTemp += 2;
			fn3 = h + pTemp;
			p3 = p;
		
			p[y][x-1] = p[y][x];
			p[y][x] = 0;

			pTemp = pathCost;
		}
		
		if((y-1) >= 0)
		{
			p[y][x] = p[y-1][x];
			p[y-1][x] = 0;
			
			h = heuristicFunction(p);
			pTemp +=3;
			fn4 = h + pTemp;
			p4 = p;
			
			p[y-1][x] = p[y][x];
			p[y][x] = 0;

			pTemp = pathCost;
		}
				
		n1 = {p1, -fn1, currentNode.level+1, currentNode.currentPathCost+1};
		n2 = {p2, -fn2, currentNode.level+1, currentNode.currentPathCost+2};
		n3 = {p3, -fn3, currentNode.level+1, currentNode.currentPathCost+2};
		n4 = {p4, -fn4, currentNode.level+1, currentNode.currentPathCost+3};
		q.pop();
		q.push(n1);
		q.push(n2);
		q.push(n3);
		q.push(n4);
		
		currentNode = q.top();
		h = heuristicFunction(p);
		
		printPuzzle(p, pathCost, h);
		expansionOrder++;
	}
}

void printPuzzle(vector<vector<int>> p, int pathCost, int h)
{
	cout << "----------";
	for (int i = 0; i < 3; i++)
	{
		cout << endl;
		for (int j = 0; j < 3; j++)
		{
			if(p[i][j] == 0)
				cout << "- ";
			else
				cout << p[i][j] << " ";
		}
	}
		cout << endl;
		cout << pathCost << "  " << h << "\n #" << expansionOrder << endl;
}

int main()
{
	vector<vector<int>> startingPuzzle {{2, 8, 3}, {6, 7, 4}, {1, 5, 0}};
	Node startingNode = {startingPuzzle, 0, 0, 0};

	q.push(startingNode);

	priorityQueue(startingNode);

	return 0;
}
