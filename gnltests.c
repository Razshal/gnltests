/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:46:10 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/17 19:20:28 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnltests.h"

int main(void)
{
	NAME("GNLTESTS");
	basic_test();
	buffer_test();
	printf("Now you can type your tests trough the stardard input\n");
	fd0_test();
}
