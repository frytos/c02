/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:41:58 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/14 23:49:04 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strlowcase(char *str);

char *ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (str[index] >= 65 && str[index] <= 90)
		{
			str[index] = str[index] + 32;
		}
		index++;
	}
	return (str);
}

int	main(void)
{
	char test1[] = "asdkjadfiuhdsaf6832irfu9yschuwf7893y2rf97uhvuiwhf";
	char test2[] = "";
	char test3[] = "58545459652545656158565";
	char test4[] = "arnauddfkjsdjvbfsbgnvjkbnughsbdfvncxgvbdshujfandidgroussard";
	char test5[] = "EDRGEWQSDGKLKJNHBBVCDWEDFDFGHG";
	char test6[] = "Arnaud";

	printf("%s\n", ft_strlowcase(test1));
	printf("%s\n", ft_strlowcase(test2));
	printf("%s\n", ft_strlowcase(test3));
	printf("%s\n", ft_strlowcase(test4));
	printf("%s\n", ft_strlowcase(test5));
	printf("%s\n", ft_strlowcase(test6));
	return (0);
}
