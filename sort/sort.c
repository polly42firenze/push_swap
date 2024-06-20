
#include "../push_swap.h"

static void	r_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rb(a, b, true);
	set_index(*a);
	set_index(*b);
}

static void	rr_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrb(a, b, true);
	set_index(*a);
	set_index(*b);
}

static void	sort_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheap(*a);
	if (cheapest->mid && cheapest->target->mid)
		r_both(a, b, cheapest);
	else if (!(cheapest->mid) && !(cheapest->target->mid))
		rr_both(a, b, cheapest);
	push_init(a, cheapest, 'a');
	push_init(b, cheapest->target, 'b');
	p(b, a, 'b');
}

static void	sort_b(t_stack_node **a, t_stack_node **b)
{
	push_init(a, (*b)->target, 'a');
	p(a, b, 'a');
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = ft_dllstsize(*a);
	if (a_len-- > 3 && !ft_list_sorted(*a))
		p(b, a, 'b');
	while (a_len-- > 3 && !ft_list_sorted(*a))
	{
		sort_init(*a, *b);
		sort_a(a, b);
	}
	sort_three(a, 'a');
	while (*b)
	{
		sort_init(*a, *b);
		sort_b(a, b);
	}
	set_index(*a);
	min_up(a);
}
