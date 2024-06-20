
#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	args = check_arg_num(ac, av);
	if (!args)
		return (0);
	a = stack_init(args, a);
	if (!a)
		return (ft_free_mat(args), 1);
	if (!ft_list_sorted(a))
	{
		if (ft_dllstsize(a) == 2)
			s(&a, 'a', true);
		else if (ft_dllstsize(a) == 3)
			sort_three(&a, 'a');
		else
			sort(&a, &b);
	}
	min_up(&a);
	free_list(&a);
	ft_free_mat(args);
	return (0);
}
