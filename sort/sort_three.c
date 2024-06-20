
#include "../push_swap.h"

void	sort_three(t_stack_node **node, char stack)
{
	t_stack_node	*biggest;

	biggest = max_node(*node);
	if (biggest == *node)
		r(node, stack, true);
	else if ((*node)->next == biggest)
		rr(node, stack, true);
	if ((*node)->value > (*node)->next->value)
		s(node, stack, true);
}
