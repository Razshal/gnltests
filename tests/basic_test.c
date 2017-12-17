/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:03:48 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/17 15:25:51 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnltests.h"

char	*line = NULL;

static int	generic_tester(char *expected, int fd)
{
	GNLRETURN(get_next_line(fd, &line));
	if (line && !strcmp(line, expected))
	{
		PRINTFSUCCESS;
		return (1);
	}
	else
	{
		PRINTFFAILURE;
		printf("your line =\n|%s|\ninstead of\n|%s|\n", line, expected);
	}
	return (0);
}

void	basic_test(void)
{
	NAME("basic_test");
	int fd = open("./tests/test1", O_RDONLY);
	generic_tester("teeeeest", fd);
	ft_memdel((void**)&line);
	close(fd);

///////////////=================================================

	fd = open("./tests/test2", O_RDONLY);
	generic_tester("1234fjdskfjdskfjdskjfhds1", fd);
	generic_tester("fdsfjhdskfjhdskfjh dskfjhds2", fd);
	generic_tester("kfjhdskfjhdskjfhdskjfh3", fd);
	generic_tester("dskjfhdskfjhsdk fjhsdkjfhsdkf4", fd);
	generic_tester("jhsdkfjhdskfjhdskfjhdskfjhdskfjhdskfjhds fsdf 5", fd);
	generic_tester(" fjdslfkjdslkfjdslk fjdslfj dslkfjdslfkjsdlfkjsdlkfjdslkfjsdlkjfldskfjoidjfgodigjfodgjfd lgjfdkl gjfdlgj dfigjfdoi jgodfjg ofdijgofdijg6", fd);
	generic_tester(" fsdjflisdjfsdjfidsjfidsjfoisdjfodsijfodsijgidfjgoifdjgopdfkgdf7", fd);
	
	if (!get_next_line(fd, &line))
		PRINTFSUCCESS;
	else
		PRINTFFAILURE;

	ft_memdel((void**)&line);
	close(fd);

///////////////================================================

	fd = open("./tests/gnl7_3.txt", O_RDONLY);
	generic_tester("1234567", fd);
	generic_tester("abcdefg", fd);
	generic_tester("4567890", fd);
	generic_tester("defghijk", fd);
	ft_memdel((void**)&line);
	close(fd);

///////////////=================================================

	fd = open("./tests/gnl7_2.txt", O_RDONLY);
	generic_tester("1234567", fd);
	GNLRETURN(get_next_line(fd, &line));
	ft_memdel((void**)&line);
	close(fd);

///////////////=================================================
}
