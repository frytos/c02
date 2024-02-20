/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:45:00 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/15 14:23:49 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str);
char	*ft_strlowcase(char *str);
int		ft_char_is_alpha(char *str);
int		ft_char_is_numeric(char *str);
int		ft_char_is_alphanumeric(char *str);

char	*ft_strcapitalize(char *str)
{
	int	index;
	int	capital_is_set;
	int	is_word;

	index = 0;
	capital_is_set = 0;
	ft_strlowcase(str);
	while (str[index] != 0)
	{
		is_word = ft_char_is_alphanumeric(&str[index]);
		if (!is_word)
			capital_is_set = 0;
		if (!capital_is_set && is_word)
		{
			if (ft_char_is_alpha(&str[index]))
				str[index] = str[index] - 32;
			capital_is_set = 1;
		}
		index++;
	}
	return (str);
}

int	ft_char_is_alpha(char *str)
{
	int	char_is_alpha;

	if ((str[0] >= 65 && str[0] <= 90) || (str[0] >= 97 && str[0] <= 122))
		char_is_alpha = 1;
	else
		char_is_alpha = 0;
	return (char_is_alpha);
}

int	ft_char_is_numeric(char *str)
{
	int	char_is_numeric;

	if (*str >= 48 && *str <= 57)
		char_is_numeric = 1;
	else
		char_is_numeric = 0;
	return (char_is_numeric);
}

int	ft_char_is_alphanumeric(char *str)
{
	int	char_is_alphanumeric;

	if (ft_char_is_alpha(str) || ft_char_is_numeric(str))
		char_is_alphanumeric = 1;
	else
		char_is_alphanumeric = 0;
	return (char_is_alphanumeric);
}

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (str[index] >= 65 && str[index] <= 90)
			str[index] = str[index] + 32;
		index++;
	}
	return (str);
}

// int main()
// {
// 	char s1[100] = "salut, COmENT tu vas ? 42mots quare-deux; cinquante+et+un";
// 	char s2[100] = "https://cdn.int.42.fr/12TE09/TE42/$@TE/42TE/fr.sub.pdf";
// 	printf("%s\n",s1);
// 	ft_strcapitalize(s1);
// 	printf("%s\n",s1);
// 	printf("%s\n",s2);
// 	ft_strcapitalize(s2);
// 	printf("%s\n",s2);
// }