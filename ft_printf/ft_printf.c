/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozbakir <yozbakir@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:36:38 by yozbakir          #+#    #+#             */
/*   Updated: 2023/10/29 20:36:53 by yozbakir          ###   ########.tr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
//#include <unistd.h>
static int ft_char_check(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
         || c == 'u' || c == 'x' || c == 'X' ||  c == '%')
         return (1);
    else
        return (0);
}

static int ft_format_check(va_list args, char c)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args, int)));
    else if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (c == 'p')
        return (ft_hex_to_ptr(va_arg(args, unsigned long int), 1));
    else if (c == 'd' || c == 'i')
        return (ft_putnbr(va_arg(args, int)));
    else if (c == 'u')
        return (ft_unsign_nbr(va_arg(args, unsigned int)));
    else if (c == 'x' || c == 'X')
        return (ft_print_to_hex(va_arg(args, unsigned int), c));
    else if (c == '%')
        return (ft_putchar('%'));
    return (0);
}

int	ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int len;

    i = 0;
    len = 0;
    //if (write(1,"",0) < 0)
    //    return (-1);
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && ft_char_check(str[i + 1]))
        {
            i++;
            len += ft_format_check(args, str[i]);
        }
        else
            len += ft_putchar(str[i]);
        i++;
    }
    va_end(args);
    return (len);
}