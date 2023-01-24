/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:44:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/08 16:24:46 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf_fd.h"
#include <limits.h>

static int	putstr(char *str, char c, int is_char, t_info *info)
{
	int	len;

	len = 0;
	if (is_char)
		return (write(info->fd, &c, 1));
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	return (write(info->fd, str, len));
}

static int	putnbr_b(t_lu n, char *str, int numdig, t_info *info)
{
	if (n > (t_lu) info->base - 1)
		numdig += putnbr_b(n / info->base, str, numdig, info);
	putstr(NULL, str[n % info->base], CHAR, info);
	return (++numdig);
}

static int	treat_int(int n, char *str, int numdig, t_info *info)
{
	int		nb;
	long	signal;

	nb = n;
	signal = 1;
	if (nb < 0)
		putstr(0, '-', CHAR, info);
	signal = ((nb > 0) - (nb < 0));
	return ((n < 0) + putnbr_b(nb * signal, str, numdig, info));
}

static int	format(const char *str, t_info *info, va_list *args)
{
	if (str[info->i] == 'c')
		return (putstr(0, va_arg(*args, int), CHAR, info));
	if (str[info->i] == 's')
		return (putstr(va_arg(*args, char *), 0, STR, info));
	if (str[info->i] == 'd' || str[info ->i] == 'i')
	{
		info->base = 10;
		return (treat_int(va_arg(*args, int), DEC, 0, info));
	}
	if (str[info->i] == 'u')
	{
		info->base = 10;
		return (putnbr_b((t_lu)va_arg(*args, t_ui), DEC, 0, info));
	}
	if (str[info->i] == 'x')
		return (putnbr_b((t_lu)va_arg(*args, t_ui), HEXLO, 0, info));
	if (str[info->i] == 'X')
		return (putnbr_b((t_lu)va_arg(*args, t_ui), HEXUP, 0, info));
	if (str[info->i] == '%')
		return (putstr(0, '%', CHAR, info));
	if (str[info->i] == 'p')
		return (putstr("0x", 0, CHAR, info) + putnbr_b(va_arg(*args, t_lu),
				HEXLO, 16, 0));
	return (0);
}

int	printf_fd(int fd, const char *str, ...)
{
	va_list		args;
	t_info		info;

	va_start(args, str);
	info.i = 0;
	info.counter = 0;
	info.base = 16;
	info.fd = fd;
	while (str[info.i])
	{
		if (str[info.i] == '%')
		{
			info.i++;
			info.counter += format(str, &info, &args);
		}
		else
			info.counter += putstr(0, str[info.i], CHAR, &info);
		info.i++;
	}
	va_end(args);
	return (info.counter);
}
