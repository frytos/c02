/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:23:21 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/14 07:29:53 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_printable(char *str);

int ft_str_is_printable(char *str)
{
	int	index;

	if (str[0] == 0)
	{
		return (1);
	}
	index = 0;
	while (str[index] != 0)
	{
		if (str[index] >= 32 && str[index] <= 126)
		{
			index++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

int	main(void)
{
	char test1[] = "asdkjadfiuhdsaf6832irfu9yschuwf7893y2rf97uhvuiwhf";
	char test2[] = "";
	char test3[] = "58545459652545656158565";
	char test4[] = "arnauddfkjsdjvbfsbgnvjkbnughsbdfvncxgvbdshujfandidgroussard";
	char test5[] = "EDRGEWQSDGKLKJNHBBVCDWEDFDFGHG";
	char test6[] = "Arnaud";
	char test7[] = " ";
	char test8[] = "\n";
	char test9[] = "\t";
	char test10[] = "\\";

	printf("%d\n", ft_str_is_printable(test1));
	printf("%d\n", ft_str_is_printable(test2));
	printf("%d\n", ft_str_is_printable(test3));
	printf("%d\n", ft_str_is_printable(test4));
	printf("%d\n", ft_str_is_printable(test5));
	printf("%d\n", ft_str_is_printable(test6));
	printf("%d\n", ft_str_is_printable(test7));
	printf("%d\n", ft_str_is_printable(test8));
	printf("%d\n", ft_str_is_printable(test9));
	printf("%d\n", ft_str_is_printable(test10));
	return (0);
}
