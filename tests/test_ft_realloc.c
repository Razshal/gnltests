/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:20:15 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/08 19:14:00 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnltests.h"

char *ft_realloc(char *str, char *str_to_add);

void	test_ft_realloc(void)
{
	char *str_to_add = "petit test";
	char *str = ft_strnew(10);
	
	printf("%s", ft_realloc(str, str_to_add));
}
