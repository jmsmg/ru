/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:29:25 by gulee             #+#    #+#             */
/*   Updated: 2021/10/17 15:58:51 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_sky(int skysc[4][4])
{
	int	low;
	int	col;

	low = 0;
	col = 0;
	while (low < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar(skysc[low][col] + '0');
			if (col == 3)
				col++;
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		low++;
	}
}
