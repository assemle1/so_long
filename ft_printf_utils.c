/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:07:12 by astalha           #+#    #+#             */
/*   Updated: 2023/01/21 01:07:55 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		put_char('-', len);
		ft_putnbr(n, len);
	}
	else
	{
		if (n < 10)
			put_char(n + 48, len);
		else
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);
		}
	}
}

void	ft_putstr(char *str, int *len)
{
	int	i;
	int	n;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i] != '\0')
		i++;
	n = i;
	i = 0;
	while (i < n)
	{
		put_char(str[i], len);
		i++;
	}
}

void	ft_putadd(unsigned long long n, int *len)
{
	if (n < 10)
		put_char (n + '0', len);
	else if (n < 16)
		put_char (n % 10 + 'a', len);
	else
	{
		ft_putadd (n / 16, len);
		ft_putadd (n % 16, len);
	}
}

void	ft_put_u(unsigned int nb, int *len)
{
	if (nb < 10)
		put_char (nb + 48, len);
	else
	{
		ft_putnbr (nb / 10, len);
		ft_putnbr (nb % 10, len);
	}
}

void	print_hex(unsigned int n, int *len, char uplow)
{
	if (n < 10)
		put_char (n + '0', len);
	else if (n < 16 && uplow == 'l')
		put_char (n % 10 + 'a', len);
	else if (n < 16 && uplow == 'u')
		put_char (n % 10 + 'A', len);
	else
	{
		print_hex (n / 16, len, uplow);
		print_hex (n % 16, len, uplow);
	}
}
