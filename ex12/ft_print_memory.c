/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 03:25:24 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/18 04:24:27 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    *ft_print_memory(void *addr, unsigned int size);
void	ft_putstr(char *str);
void	ft_putchar(char c);

void    *ft_print_memory(void *addr, unsigned int size)
{
    int offset_addr;
    int lines;
    int index_lines;

    lines = size / 16 + 1;
    index_lines = 0;

    while (index_lines < lines)
    {
        printf("%p: ", addr + 16 * index_lines);
        offset_addr = 0;
        while (offset_addr < 16)
        {
            printf("%x%x ", *((char*)addr + offset_addr),  *((char*)addr + offset_addr + 1));
            offset_addr += 2;
        }
        offset_addr = 0;
        while (offset_addr < 16)
        {
            if (*(char*)addr < 32 && 122 < *(char*)addr)
                ft_putchar('.');
            else
                ft_putchar(*(char*)addr);
            offset_addr ++;
        }
        ft_putchar('\n');
        index_lines++;
    }
    return(addr);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		ft_putchar(str[index]);
		index++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	myString[] = "Hello, j'imprime de la memoire sur l'ordinateur";
	ft_print_memory(&myString, 2);

    int a = 42;
    int *ptr_to_a = &a;
    ft_print_memory(ptr_to_a, 2);
}

