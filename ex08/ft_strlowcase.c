/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:41:58 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/15 11:12:12 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if ('A' <= str[index] && str[index] <= 'Z')
			str[index] = str[index] + 32;
		index++;
	}
	return (str);
}

// int	main(void)
// {
// 	char test1[] = "asdkjadfiuhdsaf6832irfu9yschuwf7893y2rf97uhvuiwhf";
// 	char test2[] = "";
// 	char test3[] = "58545459652545656158565";
// 	char test4[] = "arnauddfkjsdjvbfdshujfandidgroussard";
// 	char test5[] = "EDRGEWQSDGKLKJNHBBVCDWEDFDFGHG";
// 	char test6[] = "ArnauDDDDDDDDDddddDDd";
// 	printf("%s\n", ft_strlowcase(test1));
// 	printf("%s\n", ft_strlowcase(test2));
// 	printf("%s\n", ft_strlowcase(test3));
// 	printf("%s\n", ft_strlowcase(test4));
// 	printf("%s\n", ft_strlowcase(test5));
// 	printf("test6 : %s\n", test6);
// 	ft_strlowcase(test6);
// 	printf("test6 : apres : %s\n", test6);
// 	printf("ft(test6) : %s\n", ft_strlowcase(test6));
// 	return (0);
// }
// int	main(int argc, char **argv)
// {
// 	printf("%s", ft_strlowcase(argv[argc - 1]));
// }