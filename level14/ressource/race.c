#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <unistd.h>
#include <stdio.h>
#include <i386-linux-gnu/asm/unistd_32.h>

int		main()
{
	pid_t				child;
	long				ptrace_ret;
	struct user_regs_struct		u_regs;
	int				syscall = ~(__NR_write);

	child = fork();
	if (!child)
	{
		ptrace(PTRACE_TRACEME, 0, 0, NULL);
		execve("/tmp/toto", NULL, NULL);
	}
	else
	{
		wait(NULL);
		while ((ptrace_ret = ptrace(PTRACE_SYSCALL, child, 0, 0)) != -1)
		{
			wait(NULL);
			ptrace(PTRACE_GETREGS, child, 0, &u_regs);
			syscall = u_regs.orig_eax;
			if (syscall == __NR_write)
			{
				ptrace(PTRACE_SYSCALL, child, 0, 0);
				wait(NULL);

				ptrace(PTRACE_GETREGS, child, 0, &u_regs);
				printf("syscall[%d] returned : %ld\n", syscall, u_regs.eax);
			}
		}
		ptrace(PTRACE_CONT, child, 0, 0);
		printf("End [%ld]\n", ptrace_ret);
		return (0);
	}
}
