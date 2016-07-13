#include <unistd.h>

int		main()
{
	char*	args[] = {"/bin/sh", NULL};

	execve(args[0], args, NULL);
	return (0);
}
