/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:11:28 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/29 18:11:29 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
	}
	else
		return (0);
	return (1);
}
