/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:46:58 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/14 05:23:19 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (src[index] != 0 && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = 0;
		index++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char s1[20] = "Corona";
// 	char d1[20] = "Amsterdam";
// 	char f1[20] = "Amsterdam";
// 	printf("ft_strncpy(d1, s1, 6) : %s\n", ft_strncpy(d1, s1, 7));
// 	printf("   strncpy(f1, s1, 6) : %s\n", strncpy(f1, s1, 7));
// 	char s2[] = "groussarda";
// 	char d2[] = "ARNAUD";
// 	char f2[] = "ARNAUD";
// 	printf("s2 : %s\n", s2);
// 	printf("d2 : %s\n", d2);
// 	printf("ft_strncpy(d2, s2, 3) : %s\n", ft_strncpy(d2, s2, 3));
// 	printf("   strncpy(f2, s2, 3) : %s\n", strncpy(f2, s2, 3));
// 	char *str = "bonjour a tous";
// 	char str2[20];
// 	char str3[20];
// 	printf("str2 :      %s\n",&str2[6]);
// 	ft_strncpy(str2,str,6);
// 	printf("str2 :%s\n",str2);
// 	printf("str3 :      %s\n",&str3[6]);
// 	strncpy(str3,str,6);
// 	printf("str3 :%s\n",str3);
// 	char s3[] = "HEY";
// 	char d3[] = "holaaaaaaaaa";
// 	char f3[] = "holaaaaaaaaa";
// 	printf("s3 : %s\n", s3);
// 	printf("d3 : %s\n", d3);
// 	printf("after d3 : %s\n", &d3[6]);
// 	printf("ft_strncpy(d3, s3, 6) : %s\n", ft_strncpy(d3, s3, 8));
// 	printf("s3 : %s\n", s3);
// 	printf("f3 : %s\n", f3);
// 	printf("after f3 : %s\n", &f3[6]);
// 	printf("   strncpy(f3, s3, 6) : %s\n", strncpy(f3, s3, 8));
// }