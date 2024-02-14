/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:10:24 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/14 07:13:27 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_lowercase(char *str);

int ft_str_is_lowercase(char *str)
{
	int	index;

	if (str[0] == 0)
	{
		return (1);
	}
	index = 0;
	while (str[index] != 0)
	{
		if (str[index] >=97 && str[index] <= 122)
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

	printf("%d\n", ft_str_is_lowercase(test1));
	printf("%d\n", ft_str_is_lowercase(test2));
	printf("%d\n", ft_str_is_lowercase(test3));
	printf("%d\n", ft_str_is_lowercase(test4));
	return (0);
}
