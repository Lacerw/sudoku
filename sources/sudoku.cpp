#include "header.h"

unsigned int g_n;
char** g_m;

char** str_to_squard(char** m, const int n, char* str)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < n; j++, k++)
			m[i][j] = str[k];
		m[i][j] = '\0';
		k++;
	}

	return m;
}

char** brute_force(char** m, const int n)
{
	int i = n_space2(m, n);
	if (i == -2 || g_n > 1)
		return 0;
	if (i == -1)
	{
		//print_squard(m);
		g_n++;
		if(g_n == 1)
			g_m = new_copy(m, n);
	}

	char** m1 = new_copy(m, n);
	char ch = '1';
	while (ch <= '9')
	{
		if (check_sq(m1, i / n, i % n, ch))
		{
			m1[i / n][i % n] = ch;
			brute_force(m1, n);
		}
		ch++;
	}
	free(m1);

	return g_m;
}

int n_space(char** m, const int n)
{
	int i = 0;
	while (i < n * n)
	{
		if (m[i / n][i % n] == '.')
			return i;
		i++;
	}
	return -1;
}

int n_space2(char** m, const int n)
{
	int i = 0, min_result = 10, result = -1;
	while (i < n * n)
	{
		if (m[i / n][i % n] == '.')
		{
			char ch = '1';
			int n_result = 0;

			while (ch <= '9')
			{
				if (check_sq(m, i / n, i % n, ch))
					n_result++;
				ch++;
			}
			if (n_result < min_result)
			{
				min_result = n_result;
				result = i;
			}
		}
		i++;
	}
	if (min_result == 0)
		result = -2;

	return result;
}

char **sudoku(char **m)
{
	int n = 9;

	//print_sudoku(m, n, 0);
	//scan_point(m, n, 0);
	g_n = 0;
	g_m = nullptr;
	g_m = brute_force(m, n);
	//if (g_n != 0)
	//	double_print_sudoku(m, g_m, n);
	//free(m);
	/*if (g_n > 1)
		printf("More one result\n");
	if (g_n == 0)
		printf("No result\n");
	printf("Complete...\n\n");
	if (g_n > 0)*/
		//free(g_m);
return g_m;
}