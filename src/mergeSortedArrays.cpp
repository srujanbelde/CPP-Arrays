/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i=0, j=0,c=0;
	struct transaction C[100];
	while(i < ALen&&j < BLen)
	{
		int day1 = ((A[i].date[0] - '0') * 10) + (A[i].date[1] - '0');
		int month1 = ((A[i].date[3] - '0') * 10) + (A[i].date[4] - '0');
		int year1 = ((A[i].date[6] - '0') * 1000) + ((A[i].date[7] - '0') * 100) + ((A[i].date[8] - '0') * 10) + (A[i].date[9] - '0');
		int day2 = ((B[j].date[0] - '0') * 10) + (B[j].date[1] - '0');
		int month2 = ((B[j].date[3] - '0') * 10) + (B[j].date[4] - '0');
		int year2 = ((B[j].date[6] - '0') * 1000) + ((B[j].date[7] - '0') * 100) + ((B[j].date[8] - '0') * 10) + (B[j].date[9] - '0');
		if (year1 <= year2)
		{
			if (year1 < year2)
				C[c++] = A[i++];
			else
			{
				if (month1 <= month2)
				{
					if (month1<month2)
						C[c++] = A[i++];
					else
					{
						if (day1 <= day2)
						{
							if (day1 < day2)
								C[c++] = A[i++];
							else
							{
								C[c++] = A[i++];
								C[c++] = B[j++];
							}
						}
						else
							C[c++] = B[j++];
					}
				}
				else
					C[c++] = B[j++];
			}
		}
		else
			C[c++] = B[j++];
	}
	if (i < ALen)
	{
		for (int k = i; k < ALen; k++)
			C[c++] = A[k];
	}
	if (j < BLen)
	{
		for (int k = j; k < BLen; k++)
			C[c++] = B[k];
	}
	return C;
}