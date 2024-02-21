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

#include <stdio.h>
#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	ft_putstr(char *str);
void	print_addr(void *addr, unsigned int offset_addr);
void	print_content_hex(char *addr, unsigned int offset_addr,
			unsigned int size);
void	print_content_char(char *addr, unsigned int offset_addr,
			unsigned int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	offset_addr;

	offset_addr = 0;
	while (offset_addr < size)
	{
		print_addr(addr, offset_addr);
		print_content_hex((char *)addr, offset_addr, size);
		print_content_char((char *)addr, offset_addr, size);
		offset_addr += 16;
	}
	return (addr);
}

void	print_addr(void *addr, unsigned int offset_addr)
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

void	print_content_hex(char *addr, unsigned int offset_addr,
		unsigned int size)
{
	char			*hex_base;
	unsigned int	index;

	hex_base = "0123456789abcdef  ";
	index = 0;
	while (index < 16 && offset_addr + index < size)
	{
		write(1, &hex_base[(unsigned char)*(addr + offset_addr + index) / 16], 1);
		write(1, &hex_base[(unsigned char)*(addr + offset_addr + index) % 16], 1);
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

void	print_content_char(char *addr, unsigned int offset_addr,
		unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (index < 16 && offset_addr + index < size)
	{
		if ((unsigned char)*(addr + offset_addr + index) < 32 || 126 < (unsigned char)*(addr + offset_addr
				+ index))
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
	//char	my_string[160] = "Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print_memory..";

	//printf("%s", my_string);

	//ft_print_memory(my_string, 57);

	// char str[128];
	// for (int i=0; i < 128; i++)
	//     str[i] = i;

	char str[] = "a";

	ft_print_memory(str, 800);
}

// 000000016ae133b8: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin
// 000000016ae133c8: 6368 6573 2e2e 2e63 2e20 6573 7420 666f ches...c. est fo
// 000000016ae133d8: 752e 746f 7574 2e63 6520 7175 206f 6e20 u.tout.ce qu on
// 000000016ae133e8: 7065 7574 2066 6169 7265 2061 7665 632e peut faire avec.
// 000000016ae133f8: 2e2e 7072 696e 745f 6d65 6d6f 7279 2e2e ..print_memory..
// 000000016ae13408: 0000 0000 0000 0000 0000 0000 0000 0000 ................
// 000000016ae13418: 0000 0000 0000 0000 0000 0000 0000 0000 ................
// 000000016ae13428: 0000 0000 0000 0000 0000 0000 0000 0000 ................
// 000000016ae13438: 0000 0000 0000 0000 0000 0000 0000 0000 ................
// 000000016ae13448: 0000 0000 0000 0000 0000 0000 0000 0000 ................
// $> ./ft_print_memory
// 000000010a161f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin
// 000000010a161f50: 6368 6573 090a 0963 0720 6573 7420 666f ches...c. est fo
// 000000010a161f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on
// 000000010a161f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.
// 000000010a161f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..
// 000000010a161f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000 ..lol.lol. .
// $> ./ft_print_memory | cat -te
// 0000000107ff9f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin$
// 0000000107ff9f50: 6368 6573 090a 0963 0720 6573 7420 666f ches...c. est fo$
// 0000000107ff9f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on $
// 0000000107ff9f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.$
// 0000000107ff9f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..$
// 0000000107ff9f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000 ..lol.lol. .$
// $>
// 000000016cec745e: 6100 d076 6c 0100 0000  0d0 23d7 0100 a..v.l......#...
// 000000016cec746e: 0000 0000 0000 0000 0000 0000 0000 0000 ................
// 000000016cec747e: 0000 0000 0000 0000 0000 0000 0000 0000 ................
// 000000016cec748e: 0000 0000 0000 0000 0000 00 00 00 ................
// 000000016cec749e: 00 0000 0000 0000 0000 0000 0000 7  ................
// 000000016cec74ae: 1a d 0100 0000 0000 0000 c074 6c 0100 ...........t.l..
// 000000016cec74be: 0000 0d00 0001 1a00 0000 f7 4700 0000 ............G...
// 000000016cec74ce: 0000 d0d: 3403 0100 0000 00c0 0702 0100 ....4...........

// ccw ex12/ft_print_memory.fix.c | cat -e
// 000000016f8e745e: 6100 9076 8e6f 0100 0000 e090 2383 0100 a..v.o......#...$
// 000000016f8e746e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e747e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e748e: 0000 0000 0000 0000 0000 ffff ffff ffff ................$
// 000000016f8e749e: ffff 0000 0000 0000 0000 0000 0000 03c5 ................$
// 000000016f8e74ae: 4059 0100 0000 0000 0000 8074 8e6f 0100 @Y.........t.o..$
// 000000016f8e74be: 0000 0d00 0001 1a00 0000 9eea 4700 0000 ............G...$
// 000000016f8e74ce: 0000 908d 9200 0100 0000 0080 5100 0100 ............Q...$
// 000000016f8e74de: 0000 0075 8e6f 0100 0000 0080 7600 0100 ...u.o......v...$
// 000000016f8e74ee: 0000 0100 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e74fe: 0000 f842 c5dd 0100 0000 0000 0000 0000 ...B............$
// 000000016f8e750e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e751e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e752e: 0000 1000 0000 0000 0000 0500 0000 0000 ................$
// 000000016f8e753e: 0000 8074 8e6f 0100 0000 3040 5200 0100 ...t.o....0@R...$
// 000000016f8e754e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e755e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e756e: 0000 00c0 8000 0100 0000 0040 0000 0000 ...........@....$
// 000000016f8e757e: 0000 0000 8100 0100 0000 00c0 0500 0000 ................$
// 000000016f8e758e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e759e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e75ae: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e75be: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e75ce: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e75de: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e75ee: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e75fe: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e760e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e761e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e762e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e763e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e764e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e765e: 0000 0075 8e6f 0100 0000 0030 2383 0100 ...u.o.....0#...$
// 000000016f8e766e: 0000 00c0 1703 0000 0000 00c0 1783 0100 ................$
// 000000016f8e767e: 0000 0080 7600 0100 0000 a076 8e6f 0100 ....v......v.o..$
// 000000016f8e768e: 0000 0000 0000 0000 0000 0000 0000 0000 ................$
// 000000016f8e769e: 5485 0080 5100 0100 0000 0100 0000 0000 T...Q...........$
// 000000016f8e76ae: 0000 8078 8e6f 0100 0000 0000 0000 0000 ...x.o..........$
// 000000016f8e76be: 0000 8878 8e6f 0100 0000 aa78 8e6f 0100 ...x.o.....x.o..$
// 000000016f8e76ce: 0000 c178 8e6f 0100 0000 d578 8e6f 0100 ...x.o.....x.o..$
// 000000016f8e76de: 0000 e478 8e6f 0100 0000 0679 8e6f 0100 ...x.o.....y.o..$
// 000000016f8e76ee: 0000 3f79 8e6f 0100 0000 5b79 8e6f 0100 ..?y.o....[y.o..$
// 000000016f8e76fe: 0000 9779 8e6f 0100 0000 b479 8e6f 0100 ...y.o.....y.o..$
// 000000016f8e770e: 0000 c279 8e6f 0100 0000 227a 8e6f 0100 ...y.o...."z.o..$
// 000000016f8e771e: 0000 387a 8e6f 0100 0000 7a7a 8e6f 0100 ..8z.o....zz.o..$
// 000000016f8e772e: 0000 9a7a 8e6f 0100 0000 a57a 8e6f 0100 ...z.o.....z.o..$
// 000000016f8e773e: 0000 c57a 8e6f 0100 0000 e17a 8e6f 0100 ...z.o.....z.o..$
// 000000016f8e774e: 0000 4d7c 8e6f 0100 0000 837c 8e6f 0100 ..M|.o.....|.o..$
// 000000016f8e775e: 0000 ae7c 8e6f 0100 0000 d17c 8e6f 0100 ...|.o.....|.o..$
// 000000016f8e776e: 0000 e47c 8e6f 0100 0000 f27c 8e6f 0100 ...|.o.....|.o..$