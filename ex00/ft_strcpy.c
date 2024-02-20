/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:22:09 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/14 04:40:03 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != 0)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}

// int main(void)
// {
// 	char source1[] = "arnaud";
// 	char dest1[] = "GROUSSARD";
// 	printf("s1 : %s\n", source1);
// 	printf("d1 : %s\n", dest1);
// 	printf("ft_strcpy(dest1, source1) : %s\n", ft_strcpy(dest1, source1));

// 	char source2[] = "groussard";
// 	char dest2[] = "ARNAUD";
// 	printf("s2 : %s\n", source2);
// 	printf("d2 : %s\n", dest2);
// 	printf("ft_strcpy(dest2, source2) : %s\n", ft_strcpy(dest2, source2));

// 	char *str = "bonjour a tous";
//     char str2[15];
//     ft_strcpy(str2,str);
//     printf("str2 :%s",str2);

// 	// char *source2 = "Arnaud";
// 	// char *dest2 = "GROUSSARD";
// 	// printf("%s\n", source2);
// 	// printf("%s\n", dest2);
// 	// printf("%s\n", ft_strcpy(dest2, source2));
// }
