/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:17:40 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/14 07:21:28 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	index;

	if (str[0] == 0)
		return (1);
	index = 0;
	while (str[index] != 0)
	{
		if ('A' <= str[index] && str[index] <= 'Z')
			index++;
		else
			return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	char test1[] = "asdkjadfiuhdsaf6832irfu9yschuwf7893y2rf97uhvuiwhf";
// 	char test2[] = "";
// 	char test3[] = "58545459652545656158565";
// 	char test4[] = "arnauddfkjsdjvbfsbcxgvbdshujfandidgroussard";
// 	char test5[] = "EDRGEWQSDGKLKJNHBBVCDWEDFDFGHG"; 
// 	char test6[] = "Arnaud";
// 	printf("%d\n", ft_str_is_uppercase(test1));
// 	printf("%d\n", ft_str_is_uppercase(test2));
// 	printf("%d\n", ft_str_is_uppercase(test3));
// 	printf("%d\n", ft_str_is_uppercase(test4));
// 	printf("%d\n", ft_str_is_uppercase(test5));
// 	printf("%d\n", ft_str_is_uppercase(test6));
// 	return (0);
// }
// int	main(int argc, char **argv)
// {
// 	printf("%d", ft_str_is_uppercase(argv[argc - 1]));
// }