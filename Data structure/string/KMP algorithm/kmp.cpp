#include <cstring>
#include <iostream>

void get_next(const char *p, int next[])
{
	int k = -1;
	int j = 0;
	next[0] = -1;
	int length = strlen(p);
	while (j < length)
	{
		if (k == -1 || p[k] == p[j])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

void get_next_optimized(const char *p, int next[])
{
	int k = -1;
	int j = 0;
	next[0] = -1;
	int length = strlen(p);
	while (j < length)
	{
		if (k == -1 || p[k] == p[j])
		{
			++k;
			++j;
			if (p[k] != p[j])
			{
				next[j] = k;
			}
			else
			{
				next[j] = next[k];
			}
		}
		else
		{
			k = next[k];
		}
	}
}

int find_substr(const char *S, const char *T)
{
	int i = -1;
	int j = -1;
	int S_length = strlen(S);
	int T_length = strlen(T);
	int next[T_length];
	get_next_optimized(T, next);
	while (i < S_length && j < T_length)
	{
		if (j == -1 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == T_length)
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}

int main(int argc, char const *argv[])
{
	const char *s1 = "abacababc";
	const char *s2 = "abab";
	std::cout << find_substr(s1, s2);
	
	return 0;
}

