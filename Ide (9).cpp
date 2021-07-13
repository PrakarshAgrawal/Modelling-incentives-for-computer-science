#include <bits/stdc++.h>
using namespace std;


#define N 4

bool preference(int prefmen[N][N], int prefwomen[N][N], int w, int m, int m1)
{
	for (int i = 0; i < N; i++)
	{
		
		if (prefwomen[w][i] == m1)
			return true;

	}
	return false;
}

void stableMarriage(int prefmen[N][N],int prefwomen[N][N],string men[N], string women[N])
{

	int matching[N];


	bool mFree[N];

	// Initialize all men and women as free
	memset(matching, -1, sizeof(matching));
	memset(mFree, false, sizeof(mFree));
	int freeCount = N;


	while (freeCount > 0)
	{
		
		int m;
		for (m = 0; m < N; m++)
			if (mFree[m] == false)
				break;

	
		for (int i = 0; i < N && mFree[m] == false; i++)
		{
			int w = prefmen[m][i];

		
			if (matching[w] == -1)
			{
				matching[w] = m;
				mFree[m] = true;
				freeCount--;
			}

			else 
			{
				
				int m1 = matching[w];

				
				if (preference(prefmen,prefwomen, w, m, m1) == false)
				{
					matching[w] = m;
					mFree[m] = true;
					mFree[m1] = false;
				}
			} 
		} 
	} 


	cout << "  \tWoman   Man" << endl;
	for (int i = 0; i < N; i++)
	cout << " " << women[i] << "\t" << men[matching[i]] << endl;
}

/*
4 women and men are being matched with each other on the basis of their preferences
Numbers are assigned according to their index in string array*/
int main()
{
    string women[] = {"Ginny","Emma","Olivia","Luna"};
    string men[] = {"Noah","George","Jacob","Edward"};
	int prefmen[N][N] = { {3, 1, 2, 0},
		{1, 0, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
	};
	int prefwomen[N][N] = 
	{
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
	};
	stableMarriage(prefmen,prefwomen,men,women);

	return 0;
}
