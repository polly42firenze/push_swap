
#include "../push_swap.h"

void	s(t_stack_node **node, char stack, bool print)
{
	if (!*node || !(*node)->next)
		return ;
	*node = (*node)->next;
	(*node)->prev->prev = *node;
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	(*node)->next = (*node)->prev;
	(*node)->prev = NULL;
	if (print == true)
		ft_printf("s%c\n", stack);
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	if (print == true)
		ft_printf("ss\n");
	s(a, 'a', false);
	s(b, 'b', false);
}
