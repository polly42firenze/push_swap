
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
	int				value;
	int				index;
	int				cost;
	bool			mid;
	bool			cheap;
}	t_stack_node;

/*MOVES*/

//push
void	p(t_stack_node **dest, t_stack_node **source, char stack);

//rotate
void	r(t_stack_node **node, char stack, bool print); //rotate
void	rb(t_stack_node **a, t_stack_node **b, bool print);//rotate both
void	rr(t_stack_node **node, char stack, bool print);//reverse rotate
void	rrb(t_stack_node **a, t_stack_node **b, bool print);//reverse rotate both
void	min_up(t_stack_node **a);//the smallest number goes up in the stack

//swap
void	s(t_stack_node **node, char stack, bool print);//swap
void	ss(t_stack_node **a, t_stack_node **b, bool print);//swap both

/*SORT*/

//sort_init
void	set_index(t_stack_node *node);//sets the indexes in a stack
void	sort_init(t_stack_node *a, t_stack_node *b);//initializes both stacks

//sort_three
void	sort_three(t_stack_node **node, char stack);

//sort
void	sort(t_stack_node **a, t_stack_node **b);

/*UTILS*/

//dllst_utils
t_stack_node	*ft_dllstnew(int content);
t_stack_node	*ft_dllstlast(t_stack_node *lst);
void	ft_dllstadd_back(t_stack_node **lst, t_stack_node *new);
int		ft_dllstsize(t_stack_node *lst);
int		ft_list_sorted(t_stack_node *a);

//generic_utils
t_stack_node	*min_node(t_stack_node *node);
t_stack_node	*max_node(t_stack_node *node);
t_stack_node	*get_cheap(t_stack_node *node);
void	*free_list(t_stack_node **node);
void	push_init(t_stack_node **node, t_stack_node *top, char stack);//Aprepeares the stack to push a node

//av_split
char	**ft_av_split(char const *s, char c);//it's a split but with the arguments passed to it by the terminal and ' ' as separator

//mod_libft(i don't want to modify my libft)
long	ft_atol(const char *str);
int		ft_is_number(char *s);
int		ft_mat_len(char **mat);
void	*ft_free_mat(char **a);
char	**ft_mat_dup(char **mat);

//init
char	**check_arg_num(int ac, char **av);//it's useful if all the numbers are passed in 1 argument
int		ft_list_check(int num, t_stack_node *a);//checks the doubles
t_stack_node	*stack_init(char **args, t_stack_node *a);//initializes the a stack with the arguments passed to it

#endif