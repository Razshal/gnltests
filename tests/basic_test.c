/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:03:48 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/13 13:34:34 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnltests.h"

void	basic_test(void)
{
	PRINTNAME("basic_test");
	char	*line;
	int fd = open("./tests/test4", O_RDONLY);

	get_next_line(fd, &line);
	printf("line = %s\n", line);
	free(line);

	get_next_line(fd, &line);
	printf("line2 = %s\n", line);
	free(line);
	line = NULL;

	get_next_line(fd, &line);
	printf("line3 = %s\n", line);
	free(line);

	get_next_line(fd, &line);
	printf("line4 = %s\n", line);
	free(line);

	printf("return:%d\n", get_next_line(fd, &line));
	printf("line5 = %s\n", line);
	free(line);

///////////////=================================================
	fd = open("./tests/test5", O_RDONLY);

	get_next_line(fd, &line);
	printf("line = %s\n", line);
	free(line);

	get_next_line(fd, &line);
	printf("line2 = %s\n", line);
	free(line);
}
