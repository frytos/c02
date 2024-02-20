/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:24:28 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/15 14:59:40 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len] != 0)
		src_len++;
	index = 0;
	while (src[index] != 0 && index + 1 < size)
	{
		dest[index] = src[index];
		index++;
	}
	if (size > 0)
		dest[index] = 0;
	return (src_len);
}

// int main(int argc, char *argv[])
// {
//     char dest1[40 + argc];
// 	char dest2[40 + argc];
//     unsigned int i = strlcpy(dest1, argv[1], atoi(argv[2]));
//     printf("---strlcpy---\n%s\n%s\nret:%d\n",argv[1],dest1,i);
// 	unsigned int j = ft_strlcpy(dest2, argv[1], atoi(argv[2]));
//     printf("---FT_STRLCPY---\n%s\n%s\nret:%d\n",argv[1],dest2,j);
// 	// https://man.cx/strcpy(3)/fr
// 	// https://c-for-dummies.com/blog/?p=3873
// }
// int main(void)
// {
// 	char dest1[] = "hello";
// 	char dest2[] = "hello";
// 	char src[] = "HII";
// 	int size = 3;
// 	unsigned int i = strlcpy(dest1, src, size);
//     printf("---strlcpy---\n%s\n%s\nret:%d\n",src,dest1,i);
// 	unsigned int j = ft_strlcpy(dest2, src, size);
//     printf("---FT_STRLCPY---\n%s\n%s\nret:%d\n",src,dest2,j);
// }