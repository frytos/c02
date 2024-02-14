/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:31:28 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/14 07:40:57 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strupcase(char *str);

char *ft_strupcase(char *str)
{
	int	index;
	
	index = 0;
	while (str[index] != 0)
	{
		if (str[index] >= 97 && str[index] <= 122)
		{
			str[index] = str[index] - 32;
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

	printf("%s\n", ft_strupcase(test1));
	printf("%s\n", ft_strupcase(test2));
	printf("%s\n", ft_strupcase(test3));
	printf("%s\n", ft_strupcase(test4));
	printf("%s\n", ft_strupcase(test5));
	printf("%s\n", ft_strupcase(test6));
	return (0);
}
