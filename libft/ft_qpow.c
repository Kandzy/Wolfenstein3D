/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:23:23 by dkliukin          #+#    #+#             */
/*   Updated: 2017/11/06 16:23:25 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long long	ft_qpow(int a, int n)
{
	long long	res;

	res = 1;
	while (n)
	{
		if (n & 1)
		{
			res *= a;
			--n;
		}
		else
		{
			a *= a;
			n >>= 1;
		}
	}
	return (res);
}
