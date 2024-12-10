int	ft_invalidchar(char **argv, int i, int j)
{
	char	c;
	
	c = argv[i][j];
	if (!ft_isdigit(c) && c != ' ' && c != '-')
		return (1);
	if(c == '-')
		if(argv[i][j + 1] == ' ' || (j > 0 && argv[i][j - 1] != ' '))
			return (1)
	return (0);
}

int	ft_parsenbrs(int argc, char **argv)
{
	int	i;
	int	j;
	int	isnb;
	
	i = 1;
	while(i < argc)
	{
		j = 0;
		isnb = 0;
		while(argv[i][j])
		{
			if((isnb == 1 && ft_isdigit(argv[i][j]) 
				&& !ft_isdigit(argv[i][j+1])) || (ft_invalidchar(argv, i, j)))
				return(-1);
			if(ft_isdigit(argv[i][j]) && !ft_isdigit(argv[i][j+1]))
				isnb = 1;
			j++;
		}
		if (isnb == 0)
			return(-1);
		i++;
	}
	return (argc - 1);
}

int	ft_argcheck(int argc, char **argv)
{
	int	result;
	int	i;
	
	i = 0;
	result = 0;
	if(argc == 1)
		return (-1);
	else if(argc == 2)
	{
		while(argv[1][i])
		{
			if((!ft_isdigit(argv[1][i]) && argv[1][i]!= ' ' && argv[1][i]!= '-')
				|| (argv[1][i] == '-' && ((i > 0 && argv[1][i-1] != ' ') 
				|| (!ft_isdigit(argv[1][i+1])))))
				return (-1);
			if(ft_isdigit(argv[1][i]) && !ft_isdigit(argv[1][i+1]))
				result++;
			i++;
		}
	}
	else
		result = ft_parsenbrs(argc, argv);
	return (result);
}

int	*ft_tabatoi(char **strings, int size)
{
	int	i;
	int	*result;
	
	result = malloc(size*sizeof(int));
	if(!result)
		return(NULL);
	i = 0;
	while(strings[i])
	{
		result[i] = ft_atoi(strings[i]);
		i++;
	}
	return(result);
}

int	main(int argc, char **argv)
{
	int		*tab;
	char	**split;
	int		size
	
	size = ft_argcheck(argc, argv);
	if(size <= 0)
		return (ft_printf("Argument invalide"), -1);
	if(argc == 2)
	{
		split = ft_split(argv[1]);
		if(!split)
			return (ft_printf("Erreur mémoire"), -1);
		tab = ft_tabatoi(split, size);
		if(!tab)
		{
			free(split);
			return (ft_printf("Erreur mémoire"), -1);
		}
	}
	else
		tab = ft_tabatoi(argv+1, size);
	return (push_swap(tab));
}