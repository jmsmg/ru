/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sky.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:29:52 by gulee             #+#    #+#             */
/*   Updated: 2021/10/17 14:29:56 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	colup_check(int skysc[4][4], int col, int num)
{
	int	low;
	int	max;
	int	count;

	low = 0;
	count = 1;
	max = skysc[low][col];
	while (low < 4)
	{
		if (skysc[low][col] > max)
		{
			max = skysc[low][col];
			count++;
		}
		low++;
	}
	if (count == num)
		return (1);
	return (0);
}

int	coldown_check(int skysc[4][4], int col, int num)
{
	int	low;
	int	max;
	int	count;

	low = 3;
	count = 1;
	max = skysc[low][col];
	while (low >= 0)
	{
		if (skysc[low][col] > max)
		{
			max = skysc[low][col];
			count++;
		}
		low--;
	}
	if (count == num)
		return (1);
	return (0);
}

int	lowleft_check(int skysc[4][4], int low, int num)
{
	int	col;
	int	max;
	int	count;

	col = 0;
	count = 1;
	max = skysc[low][col];
	while (col < 4)
	{
		if (skysc[low][col] > max)
		{
			max = skysc[low][col];
			count++;
		}
		col++;
	}
	if (count == num)
		return (1);
	return (0);
}

int	lowright_check(int skysc[4][4], int low, int num)
{
	int	col;
	int	max;
	int	count;

	col = 3;
	count = 1;
	max = skysc[low][col];
	while (col >= 0)
	{
		if (skysc[low][col] > max)
		{
			max = skysc[low][col];
			count++;
		}
		col--;
	}
	if (count == num)
		return (1);
	return (0);
}

int	check_sky(int skysc[4][4], int *in_num)
{
	int	index;

	index = 0;
	while (in_num[index])
	{
		if (index >= 0 && index <= 3)
			if (!colup_check(skysc, index, in_num[index]))
				return (0);
		if (index >= 4 && index <= 7)
			if (!coldown_check(skysc, index - 4, in_num[index]))
				return (0);
		if (index >= 8 && index <= 11)
			if (!lowleft_check(skysc, index - 8, in_num[index]))
				return (0);
		if (index >= 12 && index <= 15)
			if (!lowright_check(skysc, index - 12, in_num[index]))
				return (0);
		index++;
	}
	return (1);
}
