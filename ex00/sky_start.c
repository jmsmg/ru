/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:30:06 by gulee             #+#    #+#             */
/*   Updated: 2021/10/17 14:30:09 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_push(int skysc[4][4], int *input);

void	print_sky(int skysc[4][4]);

void	add_41push(int skysc[4][4], int *input, int loca)
{
	int	build;

	build = 0;
	while ((input[loca]) && loca <= 15)
	{
		if ((input[loca] == 4) && ((loca >= 8 && loca <= 11)))
		{
			while (build < 4)
			{
				skysc[loca % 4][build] = build + 1;
				build++;
			}
		}
		build = 4;
		if ((input[loca] == 4) && ((loca >= 12 && loca <= 15)))
		{
			while (build > 0)
			{
				skysc[loca % 4][4 - build] = build;
				build--;
			}
		}
		loca++;
	}
}

void	add_40push(int skysc[4][4], int *input)
{
	int	loca;
	int	build;

	loca = 0;
	build = 0;
	while ((input[loca]) && loca < 8)
	{
		if ((input[loca] == 4) && ((loca >= 0 && loca <= 3)))
		{
			while (build < 4)
			{
				skysc[build][loca] = build + 1;
				build++;
			}
		}
		build = 5;
		if ((input[loca] == 4) && ((loca >= 4 && loca <= 7)))
		{
			while (--build > 0)
				skysc[4 - build][(loca % 4)] = build;
		}
		loca++;
	}
	add_41push(skysc, input, loca);
}

void	add_1push(int skysc[4][4], int *input)
{
	int	loca;

	loca = 0;
	while (input[loca])
	{
		if ((input[loca] == 1) && ((loca >= 0) && (loca <= 3)))
			skysc[0][loca] = 4;
		if ((input[loca] == 1) && ((loca >= 4) && (loca <= 7)))
			skysc[3][loca - 4] = 4;
		if ((input[loca] == 1) && ((loca >= 8) && (loca <= 11)))
			skysc[loca - 8][0] = 4;
		if ((input[loca] == 1) && ((loca >= 12) && (loca <= 15)))
			skysc[loca - 12][3] = 4;
		loca++;
	}
	add_40push(skysc, input);
}

int	init_sky(int *input)
{
	int	low;
	int	col;
	int	skysc[4][4];

	low = 0;
	col = 0;
	while (low < 4)
	{
		col = 0;
		while (col < 4)
		{
			skysc[low][col] = 0;
			col++;
		}
		low++;
	}
	add_1push(skysc, input);
	if ((check_push(skysc, input)) == 1)
		print_sky(skysc);
	else
		write(1, "\nERR - No Solution\n\n", 20);
	return (0);
}
