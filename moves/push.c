
#include "../push_swap.h"

void	p(t_stack_node **dest, t_stack_node **source, char stack)
{
	t_stack_node	*push;

	if (!*source)
		return ;
	push = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	push->prev = NULL;
	if (!*dest)
	{
		*dest = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dest;
		push->next->prev = push;
		*dest = push;
	}
	if (stack != 'c')
		ft_printf("p%c\n", stack);
}
