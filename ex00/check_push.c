/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:29:00 by gulee             #+#    #+#             */
/*   Updated: 2021/10/17 14:29:05 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_sky(int skysc[4][4], int *in_num);

int	add_push(int skysc[4][4], int *low, int *col)
{
	*low = 0;
	*col = 0;
	while (*low < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (skysc[*low][*col] == 0)
				return (1);
			*col += 1;
		}
		*low += 1;
	}
	return (0);
}

int	build_col(int skysc[4][4], int col, int num)
{
	int	low;

	low = 0;
	while (low < 4)
	{
		if (skysc[low][col] == num)
			return (0);
		low++;
	}
	return (1);
}

int	build_low(int skysc[4][4], int low, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (skysc[low][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	build_check(int skysc[4][4], int low, int col, int num)
{
	if (((build_low(skysc, low, num)) && (build_col(skysc, col, num)) \
				&& (skysc[low][col] == 0)))
		return (1);
	return (0);
}

int	check_push(int skysc[4][4], int *input)
{
	int	low;
	int	col;
	int	n;

	n = 1;
	if ((add_push(skysc, &low, &col) == 0) && (check_sky(skysc, input) == 1))
		return (1);
	while (n <= 4)
	{
		if (build_check(skysc, low, col, n))
		{
			skysc[low][col] = n;
			if (check_push(skysc, input) == 1)
				return (1);
			skysc[low][col] = 0;
		}
		n++;
	}
	return (0);
}
