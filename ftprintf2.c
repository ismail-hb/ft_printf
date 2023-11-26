/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:10:44 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/24 02:13:10 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *j)
{
	write(1, &c, 1);
	(*j)++;
}

void	ft_putstr(char *str, int *j)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", j);
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*j)++;
	}
}

void	putnbr_base(unsigned long int nbr, char *base, int *j)
{
	unsigned long int	base_len;
	int					i;

	base_len = 0;
	i = -1;
	while (base[++i])
		base_len++;
	if (nbr >= 0 && nbr < base_len)
	{
		write(1, &base[nbr], 1);
		(*j)++;
	}
	if (nbr >= base_len)
	{
		putnbr_base(nbr / base_len, base, j);
		putnbr_base(nbr % base_len, base, j);
	}
}

void	ft_putaddress(void *nb, int *j)
{
	if (nb == 0)
	{
		ft_putstr("(nil)", j);
		return ;
	}
	write(1, "0x", 2);
	*j += 2;
	putnbr_base((unsigned long int) nb, "0123456789abcdef", j);
}

void	ft_putnbr(int nb, int *j)
{
	if (nb == INT_MIN)
	{
		ft_putstr("-2", j);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-', j);
		nb = -nb;
	}
	putnbr_base((int) nb, "0123456789", j);
}
