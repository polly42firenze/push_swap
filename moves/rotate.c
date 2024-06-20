
#include "../push_swap.h"

void	r(t_stack_node **node, char stack, bool print)
{
	t_stack_node	*last;
	t_stack_node	*second;

	if (!*node || !(*node)->next)
		return ;
	last = ft_dllstlast(*node);
	second = (*node)->next;
	last->next = *node;
	(*node)->next = NULL;
	(*node)->prev = last;
	second->prev = NULL;
	*node = second;
	if (print == true)
		ft_printf("r%c\n", stack);
}

void	rb(t_stack_node **a, t_stack_node **b, bool print)
{
	if (print == true)
		ft_printf("rr\n");
	r(a, 'a', false);
	r(b, 'b', false);
}

void	rr(t_stack_node **node, char stack, bool print)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!*node || !(*node)->next)
		return ;
	last = ft_dllstlast(*node);
	second_last = last->prev;
	last->next = *node;
	(*node)->prev = last;
	last->prev = NULL;
	if (second_last)
		second_last->next = NULL;
	*node = last;
	if (print == true)
		ft_printf("rr%c\n", stack);
}

void	rrb(t_stack_node **a, t_stack_node **b, bool print)
{
	if (print == true)
		ft_printf("rrr\n");
	rr(a, 'a', false);
	rr(b, 'b', false);
}

void	min_up(t_stack_node **a)
{
	t_stack_node	*min;

	min = min_node(*a);
	while (*a != min)
	{
		if (min->mid)
			r(a, 'a', true);
		else
			rr(a, 'a', true);
	}
}
