
#include "../push_swap.h"

char	**check_arg_num(int ac, char **av)
{
	char	**av_cpy;

	if (ac < 2)
		return (NULL);
	else if (ac == 2 && !av[1][0])
		return (ft_putstr_fd("Error\n", 2), exit(1), NULL);
	else if (ac == 2)
	{
		if (av[1][0] == ' ' || av[1][ft_strlen(av[1]) - 1] == ' '
			|| ft_strnstr(av[1], "  ", ft_strlen(av[1])))
			return (ft_putstr_fd("Error\n", 2), exit(1), NULL);
		av_cpy = ft_av_split(av[1], ' ');
	}
	else
		av_cpy = ft_mat_dup(av);
	if (!av_cpy)
		return (ft_putstr_fd("Error\n", 2), exit(1), NULL);
	return (av_cpy);
}

int	ft_list_check(int num, t_stack_node *a)
{
	while (a)
	{
		if (num == a->value)
			return (1);
		a = a->next;
	}
	return (0);
}
t_stack_node	*stack_init(char **args, t_stack_node *a)
{
	t_stack_node	*new;
	long	num;
	int		i;

	i = 0;
	while (args[++i])
	{
		if (!ft_is_number(args[i]))
			return (ft_putstr_fd("Error\n", 2), free_list(&a));
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_putstr_fd("Error\n", 2), free_list(&a));
		if (ft_list_check(num, a))
			return (ft_putstr_fd("Error\n", 2), free_list(&a));
		new = ft_dllstnew(num);
		if (!new)
			return (ft_putstr_fd("Error\n", 2), free_list(&a));
		ft_dllstadd_back(&a, new);
	}
	return (a);
}
