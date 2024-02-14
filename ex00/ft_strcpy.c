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

int main(void)
{
	char source1[] = "arnaud";
	char dest1[] = "GROUSSARD";
	printf("%s\n", source1);
	printf("%s\n", dest1);
	printf("%s\n", ft_strcpy(dest1, source1));

	char source2[] = "groussard";
	char dest2[] = "ARNAUD";
	printf("%s\n", source2);
	printf("%s\n", dest2);
	printf("%s\n", ft_strcpy(dest2, source2));

	//char *source2 = "Arnaud";
	//char *dest2 = "GROUSSARD";
	//printf("%s\n", source2);
	//printf("%s\n", dest2);
	//printf("%s\n", ft_strcpy(dest2, source2));
}
