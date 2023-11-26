/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:17:03 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/24 02:13:20 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nbr(unsigned int nb, int *j)
{
	putnbr_base((unsigned int) nb, "0123456789", j);
}

void	ft_puthexalower(unsigned int nb, int *j)
{
	putnbr_base((unsigned int) nb, "0123456789abcdef", j);
}

void	ft_puthexaupper(unsigned int nb, int *j)
{
	putnbr_base((unsigned int) nb, "0123456789ABCDEF", j);
}

void	whichisit(const char form, va_list args, int *j)
{
	if (form == 'c')
		ft_putchar(va_arg(args, int), j);
	if (form == 's')
		ft_putstr(va_arg(args, char *), j);
	if (form == 'p')
		ft_putaddress(va_arg(args, void *), j);
	if (form == 'd' || form == 'i')
		ft_putnbr(va_arg(args, int), j);
	if (form == 'u')
		ft_nbr(va_arg(args, unsigned int), j);
	if (form == 'x')
		ft_puthexalower(va_arg(args, unsigned int), j);
	if (form == 'X')
		ft_puthexaupper(va_arg(args, unsigned int), j);
	if (form == '%')
	{
		write(1, "%", 1);
		(*j)++;
	}
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			i++;
			whichisit(form[i], args, &j);
		}
		else
		{
			write(1, &form[i], 1);
			if (form[i] != '\0')
				j++;
		}
		i++;
	}
	return (j);
}
