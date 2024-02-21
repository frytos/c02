/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:02:20 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/17 04:35:57 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int		index;
	char	hex[3 + 1];
	char	*hex_base;

	index = 0;
	hex_base = "0123456789abcdef";
	while (str[index] != 0)
	{
		if (str[index] < 32 || 126 < str[index])
		{
			hex[0] = '\\';
			hex[1] = hex_base[str[index] / 16];
			hex[2] = hex_base[str[index] % 16];
			hex[3] = 0;
			ft_putstr(hex);
		}
		else
			write(1, &str[index], 1);
		index++;
	}
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		ft_putchar(str[index]);
		index++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char str[128];
	for (int i=1; i < 128; i++)
	    str[i-1] = i;
	ft_putstr_non_printable(str);
	ft_putchar('\n');
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	char	s[] = "\nHi!\nGroceries :\n\tChoco\tMilk\n\tCoca\tMate\n\n";
	ft_putstr(s);
	ft_putstr_non_printable(s);
	return (0);
}