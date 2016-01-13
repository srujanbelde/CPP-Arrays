/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, count = 0;
	int day = ((date[0] - '0') * 10) + (date[1] - '0');
	int month = ((date[3] - '0') * 10) + (date[4] - '0');
	int year = ((date[6] - '0') * 1000) + ((date[7] - '0')*100) + ((date[8] - '0') * 10) + (date[9] - '0');
	for (i = 0; i < len; i++)
	{
		int day1 = ((Arr[i].date[0] - '0') * 10) + (Arr[i].date[1] - '0');
		int month1 = ((Arr[i].date[3] - '0') * 10) + (Arr[i].date[4] - '0');
		int year1 = ((Arr[i].date[6] - '0') * 1000) + ((Arr[i].date[7] - '0') * 100) + ((Arr[i].date[8] - '0') * 10) + (Arr[i].date[9] - '0');
		if (year <= year1)
		{
			if (year < year1)
				count++;
			else
			{
				if (month <= month1)
				{
					if (month < month1)
						count++;
					else
					{
						if (day < day1)
							count++;
					}
				}
			}
		}
	}
	return count;
}
