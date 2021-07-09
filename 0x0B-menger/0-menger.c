#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of sponge
 */
void menger(int level)
{
	char ch;
	int i, j, temp1, temp2, len;

	len = pow(3, level);
	for (i = 0; i < len; i++)
	{

		for (j = 0; j < len; j++)
		{

			ch = '#';
			temp1 = i;
			temp2 = j;

			while (temp1 > 0)
			{

				if (temp1 % 3 == 1 && temp2 % 3 == 1)
				ch = ' ';

				temp1 /= 3;
				temp2 /= 3;
			}
			printf("%c", ch);
		}
		printf("\n");
	}
}
