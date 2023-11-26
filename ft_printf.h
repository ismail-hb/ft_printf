/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:13:31 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/24 02:17:05 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

void	ft_nbr(unsigned int nb, int *j);
void	ft_puthexalower(unsigned int nb, int *j);
void	ft_puthexaupper(unsigned int nb, int *j);
void	whichisit(const char form, va_list args, int *j);
void	ft_putchar(char c, int *j);
void	ft_putstr(char *str, int *j);
void	putnbr_base(unsigned long int nbr, char *base, int *j);
void	ft_putaddress(void *nb, int *j);
void	ft_putnbr(int nb, int *j);
int		ft_printf(const char *form, ...);

#endif
