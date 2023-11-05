/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozbakir <yozbakir@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:35:43 by yozbakir          #+#    #+#             */
/*   Updated: 2023/10/29 20:37:11 by yozbakir          ###   ########.tr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *, ...);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_unsign_nbr(int n);
int ft_print_to_hex(unsigned int n, char c);
int ft_hex_to_ptr(unsigned long int n, int is_first);
#endif