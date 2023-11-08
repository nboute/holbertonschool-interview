#include <stdio.h>

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	unsigned long x, y, dx, dy, empty;
	unsigned long size = 1;

	if (level < 0 || level > 40)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	while (level > 0)
	{
		size *= 3;
		level--;
	}
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			empty = 0;
			dx = x;
			dy = y;
			while (dx > 0 || dy > 0)
			{
				if (dx % 3 == 1 && dy % 3 == 1)
				{
					empty = 1;
					break;
				}
				dx /= 3;
				dy /= 3;
			}
			if (empty)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}

}
