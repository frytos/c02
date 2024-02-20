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

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(char *str);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;
	unsigned int	len_dest;
	unsigned int	len_src;

	index = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	while (index < n)
	{
		if (src[index] == 0)
			break ;
		dest[index] = src[index];
		index++;
	}
	while (index < len_dest && len_src < n)
		dest[index++] = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

// int	main(void)
// {
// 	char s1[] = "arnaud";
// 	char d1[] = "GROUSSARDA";
// 	printf("s1 : %s\n", s1);
// 	printf("d1 : %s\n", d1);
// 	printf("ft_strncpy(d1, s1, 6) : %s\n", ft_strncpy(d1, s1, 7));

// 	char s2[] = "groussarda";
// 	char d2[] = "ARNAUD";
// 	printf("s2 : %s\n", s2);
// 	printf("d2 : %s\n", d2);
// 	printf("ft_strncpy(d2, s2, 3) : %s\n", ft_strncpy(d2, s2, 3));

// 	char *str = "bonjour a tous";
//     char str2[20];
// 	printf("str2 :      %s\n",&str2[6]);
//     ft_strncpy(str2,str,6);
//     printf("str2 :%s\n",str2);

// 	char s3[] = "coucouuuu";
// 	char d3[] = "hello";
// 	printf("s3 : %s\n", s3);
// 	printf("d3 : %s\n", d3);
// 	printf("after d3 : %s\n", &d3[6]);
// 	printf("ft_strncpy(d3, s3, 6) : %s\n", ft_strncpy(d3, s3, 8));
// }
