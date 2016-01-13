/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	if (A == B)
		return A;
	int i, j,c=0;
	struct transaction C[100];
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			int day1 = ((A[i].date[0] - '0') * 10) + (A[i].date[1] - '0');
			int month1 = ((A[i].date[3] - '0') * 10) + (A[i].date[4] - '0');
			int year1 = ((A[i].date[6] - '0') * 1000) + ((A[i].date[7] - '0') * 100) + ((A[i].date[8] - '0') * 10) + (A[i].date[9] - '0');
			int day2 = ((B[i].date[0] - '0') * 10) + (B[i].date[1] - '0');
			int month2 = ((B[i].date[3] - '0') * 10) + (B[i].date[4] - '0');
			int year2 = ((B[i].date[6] - '0') * 1000) + ((B[i].date[7] - '0') * 100) + ((B[i].date[8] - '0') * 10) + (B[i].date[9] - '0');
			if (day1 == day2&&month1 == month2&&year1 == year2)
			{
				C[c] = A[i];
				c++;
			}
		}
	}
	if (c == 0)
		return NULL;
	return C;
}