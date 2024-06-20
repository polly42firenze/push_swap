
#include "../push_swap.h"

t_stack_node	*ft_dllstnew(int content)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node) * 1);
	if (!new)
		return (NULL);
	new -> value = content;
	new -> prev = NULL;
	new -> next = NULL;
	new -> target = NULL;
	new -> mid = false;
	new -> cheap = false;
	return (new);
}

t_stack_node	*ft_dllstlast(t_stack_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst -> next == NULL)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_dllstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_dllstlast(*lst);
		last -> next = new;
		last -> next -> prev = last;
	}
}

int	ft_dllstsize(t_stack_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_list_sorted(t_stack_node *a)
{
	t_stack_node	*min;
	t_stack_node	*tmp;

	if (!a)
		return (0);
	min = min_node(a);
	tmp = min;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->value > a->value && min != a)
		return (0);
	tmp = a;
	while (tmp->next != min && min != a)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
