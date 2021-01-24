//Claire Hofmann & Walker Bass CIS-479 Project 1
#include<iostream>
using namespace std;


//I know we love our if statements but there has to be a better way to do this. We'll see what happens :)
int heuristicFunction(int p[][3])
{
	int num, total;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			num = p[i][j];
			
			//num  is 1
			if(num == 1 && i == 0 && j == 0)
			{
				//nothing, at right spot
			}
			else if(num == 1 && i == 0 && j == 1)
			{
				total += 2;
			}
			else if(num == 1 && i == 0 && j == 2)
			{
				total += 4;
			}
			else if(num == 1 && i == 1 && j == 0)
			{
				total += 1;
			}
			else if(num == 1 && i == 1 && j == 1)
			{
				total += 3;
			}
			else if(num == 1 && i == 1 && j == 2)
			{
				total += 5;
			}
			else if(num == 1 && i == 2 && j == 0)
			{
				total += 2;
			}
			else if(num == 1 && i == 2 && j == 1)
			{
				total += 4;
			}
			else if(num == 1 && i == 2 && j == 2)
			{
				total += 6;
			}
			
			//num is 2
			if(num == 2 && i == 0 && j == 0)
			{
				total += 2;
			}
			else if(num == 2 && i == 0 && j == 1)
			{
				//in right spot
			}
			else if(num == 2 && i == 0 && j == 2)
			{
				total += 2;
			}
			else if(num == 2 && i == 1 && j == 0)
			{
				total += 3;
			}
			else if(num == 2 && i == 1 && j == 1)
			{
				total += 1;
			}
			else if(num == 2 && i == 1 && j == 2)
			{
				total += 3;
			}
			else if(num == 2 && i == 2 && j == 0)
			{
				total += 4;
			}
			else if(num == 2 && i == 2 && j == 1)
			{
				total += 2;
			}
			else if(num == 2 && i == 2 && j == 2)
			{
				total += 4;
			}
			
			//num is 3
			if(num == 3 && i == 0 && j == 0)
			{
				total += 4;
			}
			else if(num == 3 && i == 0 && j == 1)
			{
				total += 2;
			}
			else if(num == 3 && i == 0 && j == 2)
			{
				//in right spot
			}
			else if(num == 3 && i == 1 && j == 0)
			{
				total += 5;
			}
			else if(num == 3 && i == 1 && j == 1)
			{
				total += 3;
			}
			else if(num == 3 && i == 1 && j == 2)
			{
				total += 1;
			}
			else if(num == 3 && i == 2 && j == 0)
			{
				total += 6;
			}
			else if(num == 3 && i == 2 && j == 1)
			{
				total += 4;
			}
			else if(num == 3 && i == 2 && j == 2)
			{
				total += 2;
			}
			
			//num is 4
			if(num == 4 && i == 0 && j == 0)
			{
				total += 7;
			}
			else if(num == 4 && i == 0 && j == 1)
			{
				total += 5;
			}
			else if(num == 4 && i == 0 && j == 2)
			{
				total += 3;
			}
			else if(num == 4 && i == 1 && j == 0)
			{
				total += 4;
			}
			else if(num == 4 && i == 1 && j == 1)
			{
				total += 2;
			}
			else if(num == 4 && i == 1 && j == 2)
			{
				//in right spot
			}
			else if(num == 4 && i == 2 && j == 0)
			{
				total += 5;
			}
			else if(num == 4 && i == 2 && j == 1)
			{
				total += 3;
			}
			else if(num == 4 && i == 2 && j == 2)
			{
				total += 1;
			}
			
			//num is 5
			if(num == 5 && i == 0 && j == 0)
			{
				total += 10;
			}
			else if(num == 5 && i == 0 && j == 1)
			{
				total += 8;
			}
			else if(num == 5 && i == 0 && j == 2)
			{
				total += 6;
			}
			else if(num == 5 && i == 1 && j == 0)
			{
				total += 7;
			}
			else if(num == 5 && i == 1 && j == 1)
			{
				total += 5;
			}
			else if(num == 5 && i == 1 && j == 2)
			{
				total += 3;
			}
			else if(num == 5 && i == 2 && j == 0)
			{
				total += 4;
			}
			else if(num == 5 && i == 2 && j == 1)
			{
				total += 2;
			}
			else if(num == 5 && i == 2 && j == 2)
			{
				//in right spot
			}
			
			//num is 6
			if(num == 6 && i == 0 && j == 0)
			{
				total += 8;
			}
			else if(num == 6 && i == 0 && j == 1)
			{
				total += 6;
			}
			else if(num == 6 && i == 0 && j == 2)
			{
				total += 8;
			}
			else if(num == 6 && i == 1 && j == 0)
			{
				total += 5;
			}
			else if(num == 6 && i == 1 && j == 1)
			{
				total += 3;
			}
			else if(num == 6 && i == 1 && j == 2)
			{
				total += 5;
			}
			else if(num == 6 && i == 2 && j == 0)
			{
				total += 2;
			}
			else if(num == 6 && i == 2 && j == 1)
			{
				//in right spot
			}
			else if(num == 6 && i == 2 && j == 2)
			{
				total += 2;
			}
			
			//num is 7
			if(num == 7 && i == 0 && j == 0)
			{
				total += 6;
			}
			else if(num == 7 && i == 0 && j == 1)
			{
				total += 8;
			}
			else if(num == 7 && i == 0 && j == 2)
			{
				total += 10;
			}
			else if(num == 7 && i == 1 && j == 0)
			{
				total += 3;
			}
			else if(num == 7 && i == 1 && j == 1)
			{
				total += 5;
			}
			else if(num == 7 && i == 1 && j == 2)
			{
				total += 7;
			}
			else if(num == 7 && i == 2 && j == 0)
			{
				//in right spot
			}
			else if(num == 7 && i == 2 && j == 1)
			{
				total += 2;
			}
			else if(num == 7 && i == 2 && j == 2)
			{
				total += 4;
			}
			
			//num is 8
			if(num == 8 && i == 0 && j == 0)
			{
				total += 3;
			}
			else if(num == 8 && i == 0 && j == 1)
			{
				total += 5;
			}
			else if(num == 8 && i == 0 && j == 2)
			{
				total += 7;
			}
			else if(num == 8 && i == 1 && j == 0)
			{
				//in right spot
			}
			else if(num == 8 && i == 1 && j == 1)
			{
				total += 2;
			}
			else if(num == 8 && i == 1 && j == 2)
			{
				total += 4;
			}
			else if(num == 8 && i == 2 && j == 0)
			{
				total += 1;
			}
			else if(num == 8 && i == 2 && j == 1)
			{
				total += 3;
			}
			else if(num == 8 && i == 2 && j == 2)
			{
				total += 5;
			}
		}
	}
	return total;
}

int main()
{
	int puzzle[3][3] = {{2, 8, 3}, {6, 7, 4}, {1, 5, 0}};
	int h;
	
	h = heuristicFunction(puzzle);

	cout << h;

	return 0;
}
