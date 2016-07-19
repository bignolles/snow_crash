int		main()
{
	void	*ptr1;
	void	*ptr2;
	int		i3;
	void	*ptr4;

	ptr1 = NULL;
	ptr2 = NULL;
	i3 = 1;
	ptr3 = NULL;
	if (ptrace(0, 1, 0, 0) == 0)
	{
		if (getenv("LD_PRELOAD") != NULL)
		{
			fwrite("Injection lib detected... exit\n", 37, 1, stdin);
		}
	}
}
