/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:03:48 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/18 13:58:28 by mfonteni         ###   ########.fr       */
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
	NAME("One line, 8 chars no \\n");
	int fd = open("./tests/test1", O_RDONLY);
	generic_tester("teeeeest", fd);
	ft_memdel((void**)&line);
	close(fd);

///////////////=================================================

	NAME("7 lines, differents line sizes");
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

	NAME("4 lines, no final \\n");
	fd = open("./tests/gnl7_3.txt", O_RDONLY);
	generic_tester("1234567", fd);
	generic_tester("abcdefg", fd);
	generic_tester("4567890", fd);
	generic_tester("defghijk", fd);
	ft_memdel((void**)&line);
	close(fd);

///////////////=================================================

	NAME("2 lines, 7 and 8 chars, no final \\n");
	fd = open("./tests/gnl7_2.txt", O_RDONLY);
	generic_tester("1234567", fd);
	generic_tester("abcdefgh", fd);
	ft_memdel((void**)&line);
	close(fd);

///////////////=================================================
/*
	NAME("One line, 100k chars, final \\n");
	char *bigstr = (char*)malloc(sizeof(char) * 150000);
	fd = open("./tests/test5", O_RDONLY);
	read(fd, bigstr, 150000);
	get_next_line(fd, &line);
	if (!strcmp(line, bigstr))
		PRINTFSUCCESS;
	else
		PRINTFFAILURE;
*/
///////////////=================================================

	NAME("Wrong fd test");
	fd = 42;
	if (get_next_line(fd, &line) == -1)
		PRINTFSUCCESS;
	else
	{
		PRINTFFAILURE;
		printf("Your gnl doesn't handle wrong fd errors\n");
	}
}
