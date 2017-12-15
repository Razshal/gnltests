/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:03:48 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/15 18:31:18 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnltests.h"

static int	generic_tester(int condition)
{
	if (condition)
	{
		PRINTFSUCCESS;
		return (1);
	}
	else
		PRINTFFAILURE;
	return (0);
}

void	basic_test(void)
{
	PRINTNAME("basic_test");
	char	*line = NULL;
	char	*line2 = NULL;
	int fd = open("./tests/test1", O_RDONLY);

	get_next_line(fd, &line);

	if (!generic_tester(!strcmp(line, "teeeeest")))
		printf("|%s|\ninstead of\n|teeeeest|\n", line);

	ft_memdel((void**)&line);

///////////////=================================================

	fd = open("./tests/test2", O_RDONLY);
	GNLRETURN(get_next_line(fd, &line));

	if (!generic_tester(!strcmp(line, "1234fjdskfjdskfjdskjfhds1")))
		printf("you are returning\n|%s|\ninstead of\n|teeeeest|\n", line);

	ft_memdel((void**)&line);

///////////////================================================

	fd = open("./tests/gnl7_3", O_RDONLY);
	GNLRETURN(get_next_line(fd, &line));

	if (!generic_tester(line && !strcmp(line, "1234567")))
		printf("you are returning\n|%s|\ninstead of\n|teeeeest|\n", line);

	ft_memdel((void**)&line);

///////////////=================================================

	fd = open("./tests/gnl7_2", O_RDONLY);
	GNLRETURN(get_next_line(fd, &line));

	if (!generic_tester(line && !strcmp(line, "1234567")))
		printf("you are returning\n|%s|\ninstead of\n|teeeeest|\n", line);

	ft_memdel((void**)&line);

///////////////=================================================

	printf("gnl ret %d\nline2 = %s\n", get_next_line(fd, &line), line);
	if (line)free(line);
	line = NULL;

	printf("gnl ret %d\nline3 = %s\n", get_next_line(fd, &line), line);
	if (line)free(line);
	line = NULL;

	printf("gnl ret %d\nline4 = %s\n", get_next_line(fd, &line), line);
	if (line)free(line);
	line = NULL;

	printf("gnl ret %d\nline5 = %s\n", get_next_line(fd, &line), line);
	if (line)free(line);
	line = NULL;
	
	printf("read:%d\n", get_next_line(42, &line));
	if (line)free(line);
	line = NULL;

///////////////=================================================
	PRINTNAME("test2");
	fd = open("./tests/test3", O_RDONLY);

	get_next_line(fd, &line2);
	printf("line = %s\n", line2);
	if (line2)free(line2);
	line2 = NULL;

	get_next_line(fd, &line2);
	printf("line2 = %s\n", line2);
	if (line2)free(line2);
	line2 = NULL;
}
