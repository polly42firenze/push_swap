
#include "../push_swap.h"

void	set_index(t_stack_node *node)
{
	int	i;
	int	len;

	i = 0;
	len = ft_dllstsize(node);
	while (node)
	{
		node->index = i;
		if (node->index <= len / 2)
			node->mid= true;
		else
			node->mid= false;
		i++;
		node = node->next;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	long	diff;
	t_stack_node	*b_cpy;

	while (a)
	{
		diff =LONG_MAX;
		b_cpy = b;
		while (b_cpy)
		{
			if (b_cpy->value < a->value)
			{
				if (a->value - b_cpy->value < diff)
				{
					diff = a->value - b_cpy->value;
					a->target = b_cpy;
				}
			}
			b_cpy = b_cpy->next;
		}
		if (diff == LONG_MAX)
			a->target = max_node(b);
		a = a->next;
	}
}

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*a_cpy;
	t_stack_node	*target;
	long	nbr;

	while (b)
	{
		nbr = LONG_MAX;
		a_cpy = a;
		while (a_cpy)
		{
			if (a_cpy->value > b->value && a_cpy->value < nbr)
			{
				nbr = a_cpy->value;
				target = a_cpy;
			}
			a_cpy = a_cpy->next;
		}
		if (nbr == LONG_MAX)
			b->target = min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int		a_len;
	int		b_len;
	int		cheap;
	t_stack_node	*cheap_node;

	a_len = ft_dllstsize(a);
	b_len = ft_dllstsize(b);
	cheap = INT_MAX;
	while (a)
	{
		a->cost = a->index;
		if (!(a->mid))
			a->cost = a_len - (a->index);
		if (a->target->mid)
			a->cost += a->target->index;
		else
			a->cost += b_len - (a->target->index);
		if (a->cost < cheap)
		{
			cheap = a->cost;
			cheap_node = a;
		}
		a = a->next;
	}
	cheap_node->cheap = true;
}

void	sort_init(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_target_b(a, b);
	set_cost(a, b);
}
