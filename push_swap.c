int	ft_push_swap(int *tab)
{
	if (!tab)
		return(ft_printf("Erreur mémoire"), -1);
	stacka = ft_tabtostack(tab);
	if(!stacka)
		return(ft_printf("Erreur mémoire"), -1);
	
}