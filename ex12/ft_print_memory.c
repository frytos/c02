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
void	print_addr(void *addr, unsigned int offset_addr, unsigned int size);
void	print_content_hex(char *addr, unsigned int offset_addr, unsigned int size);
void	print_content_char(char *addr, unsigned int offset_addr, unsigned int size);

void    *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int offset_addr;
    
	offset_addr = 0;
	while (offset_addr < size)
	{
		print_addr(addr, offset_addr, size);
		print_content_hex((char*)addr, offset_addr, size);
		print_content_char((char*)addr, offset_addr, size);
		offset_addr += 16;
	}
    return(addr);
}

void	print_addr(void *addr, unsigned int offset_addr, unsigned int size)
{
	unsigned long	addr_value;
	char			hex_addr[16 + 1];
	char			*hex_base;
	int				index;

	addr_value = (unsigned long)&addr[offset_addr];
	hex_addr[16] = 0;
	hex_base = "0123456789abcdef";
	index = 0;
	while (addr_value / 16 > 0)
	{
		hex_addr[15 - index] = hex_base[addr_value % 16];
		addr_value = addr_value / 16;
		index++;
	}
	hex_addr[15 - index] = hex_base[addr_value % 16];
	index++;
	while (index < 16)
	{
		hex_addr[15 - index] = '0';
		index++;
	}
	ft_putstr(hex_addr);
	ft_putstr(": ");
}


void	print_content_hex(char *addr, unsigned int offset_addr, unsigned int size)
{
	char			*hex_base;
	unsigned int	index;
	
	hex_base = "0123456789abcdef  ";
	index = 0;
	while ((index < 16 && offset_addr + index < size) && addr[offset_addr + index] != 0)
	{
		write(1, &hex_base[*(addr + offset_addr + index) / 16], 1);
		write(1, &hex_base[*(addr + offset_addr + index) % 16], 1);
		if (index % 2 == 1)
			write(1, " ", 1);
		index++;
	}
	while (index < 16)
	{
		write(1, hex_base + 16, 2);
		if (index % 2 == 1)
			write(1, hex_base + 16, 1);
		index++;
	}
}

void	print_content_char(char *addr, unsigned int offset_addr, unsigned int size)
{
	unsigned int	index;
	
	index = 0;
	while ((index < 16 && offset_addr + index < size) && addr[offset_addr + index] != 0)
	{
		if (*(addr + offset_addr + index) < 32 || 126 < *(addr + offset_addr + index))
			write(1, ".", 1);
		else
			write(1, addr + offset_addr + index, 1);
		index++;
	}
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		write(1, &str[index], 1);
		index++;
	}
}

int	main(void)
{
	char	myString[] = "Hello\nArnaud\t\t\t\nkikou, tranquillou bilou, y'a pas le feu au lac non plus,\n calme tes betes l'amigros\n";
	ft_print_memory(myString, 112);

	// write(1, "\n\n", 2);
    // int a = 42;
    // int *ptr_to_a = &a;
    // ft_print_memory(ptr_to_a, 2);
}

