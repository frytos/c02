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
int	ft_strlen(char *str);

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	if ((unsigned int)ft_strlen(src) < n)
	{
		index = 0;
		while (src[index] != 0)
		{
			dest[index] = src[index];
			index++;
		}
		while (index < n)
		{
			dest[index] = 0;
			index++;
		}
	}
	else
	{
		index = 0;
		while (index < n)
		{
			dest[index] = src[index];
			index++;
		}
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		len++;
	}
	return (len);
}


int	main(void)
{
	char source1[] = "arnaud";
	char dest1[] = "GROUSSARDA";
	printf("%s\n", source1);
	printf("%s\n", dest1);
	printf("%s\n", ft_strncpy(dest1, source1, 8));

	char source2[] = "groussarda";
	char dest2[] = "ARNAUD";
	printf("%s\n", source2);
	printf("%s\n", dest2);
	printf("%s\n", ft_strncpy(dest2, source2, 3));
}
