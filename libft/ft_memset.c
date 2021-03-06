/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:21:17 by dkliukin          #+#    #+#             */
/*   Updated: 2017/10/25 15:21:23 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *str, int symb, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char*)str)[i] = symb;
		i++;
	}
	return (str);
}
