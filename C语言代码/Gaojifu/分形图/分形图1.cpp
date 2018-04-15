#include<stdio.h>

#include<string.h>

char map[1050][1050];

int r, c, k, i, j;

void dfs(int x, int y, int dis,int t1,int t2)

{

	if (x >= r || y >= c || x < 0 || y < 0)

		return;

	if (t1 == 0 || t2 == 0)

	{

		map[x][y] = 'T';

		return;

	}

	if (dis % 2 == 0)

	{

		for (i = 0; i < t2; i++)

		{

			map[x][y - i] = '.';

			map[x][y + i] = '.';

		}

		dfs(x, y + t2, dis + 1, t1, t2 / 2);

		dfs(x, y - t2, dis + 1, t1, t2 / 2);

	}

	if (dis % 2 == 1)

	{

		for (i = 0; i < t1; i++)

		{

			map[x - i][y] = '.';

			map[x + i][y] = '.';

		}

		dfs(x - t1, y, dis + 1, t1/2, t2);

		dfs(x + t1, y, dis + 1, t1/2, t2);

	}

}

int main()

{

	scanf("%d%d%d", &r, &c, &k);

	if (r == 3)

	{

		printf("...\n");

		printf(".S.\n");

		printf("T..\n");

		return 0;

	}

	dfs(r/2,c/2,0,r/4,c/4);

	map[r / 2][c / 2] = 3;

	int e = 0;

	for (i = 0; i < r; i++)

	{

		for (j = 0; j < c; j++)

		{

			if (map[i][j] == 3)

				printf("S");

			else if (map[i][j] == 'T'&&e == 0)

			{

				printf("T");

				e = 1;

			}

			else if (map[i][j] == 'T'&&e == 1)

				printf(".");

			else if (map[i][j] == '.')

				printf(".");

			else

				printf("*");

		}

		printf("\n");

	}

}

