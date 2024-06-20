
#include "../push_swap.h"

t_stack_node	*max_node(t_stack_node *node)
{
	t_stack_node	*max;

	if (!node)
		return (NULL);
	max = node;
	node = node->next;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}

t_stack_node	*min_node(t_stack_node *node)
{
	t_stack_node	*min;

	if (!node)
		return (NULL);
	min = node;
	node = node->next;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

void	push_init(t_stack_node **node, t_stack_node *top, char stack)
{
	while (*node != top)
	{
		if (top->mid)
			r(node, stack, true);
		else
			rr(node, stack, true);
	}
}

t_stack_node	*get_cheap(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheap)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	*free_list(t_stack_node **node)
{
	t_stack_node	*tmp;
	t_stack_node	*node_cpy;

	if (!node)
		return (NULL);
	node_cpy = *node;
	while (node_cpy)
	{
		tmp = node_cpy->next;
		free(node_cpy);
		node_cpy = tmp;
	}
	*node = NULL;
	return (NULL);
}
