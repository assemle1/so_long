/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:13:50 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 01:43:44 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

static int	lenn(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	int		t;
	char	*str;

	nb = n;
	len = lenn (nb);
	n = len;
	t = 0;
	str = (char *) malloc (sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
		t = 1;
	}
	while (n-- > t)
	{
		str[n] = nb % 10 + 48;
		nb = nb / 10;
	}
	str[len] = 0;
	return (str);
}
