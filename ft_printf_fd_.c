/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:17:54 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 04:46:02 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static ssize_t	ft_putnbr_base(int fd, ssize_t nbr, char *base)
{
	ssize_t	base_len;
	ssize_t	nbr_len;
	ssize_t	power_index;

	base_len = ft_strlen(base);
	nbr_len = 0;
	power_index = 1;
	if (nbr < 0)
	{
		nbr_len += write(fd, "-", 1);
		nbr *= -1;
	}
	while (nbr >= base_len * power_index)
		power_index *= base_len;
	while (power_index)
	{
		nbr_len += write(fd, &base[nbr / power_index % base_len], 1);
		nbr %= power_index;
		power_index /= base_len;
	}
	return (nbr_len);
}

static void	ft_proc_per(int fd, const char **format, ssize_t *printed,
		va_list *ap)
{
	(*format)++;
	if (**format == 'c')
		*printed += ft_put_char_fd(fd, (char)va_arg(*ap, int));
	else if (**format == 's')
		*printed += ft_put_str_fd(fd, va_arg(*ap, char *));
	else if (**format == 'p')
		*printed += ft_put_ptr_fd(fd, va_arg(*ap, uintptr_t));
	else if (**format == 'd' || **format == 'i')
		*printed += ft_putnbr_base(fd, (ssize_t)va_arg(*ap, int), DEC);
	else if (**format == 'u')
		*printed += ft_putnbr_base(fd, (ssize_t)va_arg(*ap, unsigned int), DEC);
	else if (**format == 'x')
		*printed += ft_putnbr_base(fd, (ssize_t)va_arg(*ap, unsigned int),
				HEX_LOWER);
	else if (**format == 'X')
		*printed += ft_putnbr_base(fd, (ssize_t)va_arg(*ap, unsigned int),
				HEX_UPPER);
	else if (**format == '%')
		*printed += write(fd, "%", 1);
	(*format)++;
}

static void	ft_print_str(int fd, const char **format, ssize_t *printed)
{
	const char	*start;

	start = *format;
	while (**format != '%' && **format)
		(*format)++;
	*printed += write(fd, start, *format - start);
	return ;
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;
	ssize_t	printed;

	printed = 0;
	va_start(ap, format);
	while (*format && printed < INT_MAX)
	{
		if (*format != '%')
			ft_print_str(fd, &format, &printed);
		else
			ft_proc_per(fd, &format, &printed, &ap);
	}
	va_end(ap);
	if (printed >= INT_MAX)
		return (-1);
	return (printed);
}
