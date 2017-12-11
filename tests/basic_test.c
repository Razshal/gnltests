/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:03:48 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/11 19:45:27 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnltests.h"

void	basic_test(void)
{
	PRINTNAME("basic_test");
	char	*line;
	int fd = open("./tests/test4", O_RDONLY);

	printf("1st return :%d\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	free(line);
	get_next_line(fd, &line);
	free(line);
	printf("line2 = %s\n", line);
	get_next_line(fd, &line);
	printf("line3 = %s\n", line);
}
