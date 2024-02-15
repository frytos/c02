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
		{
			capital_is_set = 0;
		}
		if (!capital_is_set && is_word)
		{
			if (ft_char_is_alpha(&str[index]))
			{
				str[index] = str[index] - 32;
			}
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
	{
		char_is_alpha = 1;
	}
	else
	{
		char_is_alpha = 0;
	}
	return (char_is_alpha);
}

int	ft_char_is_numeric(char *str)
{
	int	char_is_numeric;

	if (*str >= 48 && *str <= 57)
	{
		char_is_numeric = 1;
	}
	else
	{
		char_is_numeric = 0;
	}
	return (char_is_numeric);
}

int	ft_char_is_alphanumeric(char *str)
{
	int	char_is_alphanumeric;

	if (ft_char_is_alpha(str) || ft_char_is_numeric(str))
	{
		char_is_alphanumeric = 1;
	}
	else
	{
		char_is_alphanumeric = 0;
	}
	return (char_is_alphanumeric);
}

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (str[index] >= 65 && str[index] <= 90)
		{
			str[index] = str[index] + 32;
		}
		index++;
	}
	return (str);
}

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }
// 
// void	ft_putstr(char *str)
// {
// 	int	index;
// 
// 	index = 0;
// 	while (str[index] != 0)
// 	{
// 		ft_putchar(str[index]);
// 		index++;
// 	}
// }
// 
// int	main(void)
// {
// 	char	s1[] = "salut, coMMent tu vas ? 42mots quatre-deux; cinq+ET+un";
// 	char	s2[] = "https://cdn.int.42.fr/12TE09/TE42/$@TE/42TE/fr.sub.pdf";
// 	ft_putstr(s1);
// 	ft_putchar(10);
// 	ft_strcapitalize(s1);
// 	ft_putstr(s1);
// 	ft_putchar(10);
// 	ft_putchar(10);
// 	ft_putstr(s2);
// 	ft_putchar(10);
// 	ft_strcapitalize(s2);
// 	ft_putstr(s2);
// }
