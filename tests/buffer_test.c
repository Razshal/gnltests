#include "../gnltests.h"
#include <stdio.h>
#include <fcntl.h>

///////////////=================================================
//Thanks to sacrimento for this test idea

void buffer_test(void)
{
	NAME("Buffer test");
	char	*str;
	int		count = 0;
	int		res = 0;
	int fd = open("/dev/random", O_RDONLY);
	while ((res = get_next_line(fd, &str)) == 1 && count < 500)
		count++;
	if (res)
		PRINTFSUCCESS;
	else
	{
		PRINTFFAILURE;
		printf("Votre get_next_line ne manipule pas correctement son buffer\n");
	}
}
