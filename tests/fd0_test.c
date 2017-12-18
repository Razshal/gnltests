/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd0_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:13:35 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/18 12:09:02 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnltests.h"

void	fd0_test(void)
{
	char	*str;
	int		res = 5;

	while (res > 0)
	{
		res = get_next_line(0, &str);
		printf("Return : %d\n", res);
		printf("Line:\n%s\n", str);
	}
}
