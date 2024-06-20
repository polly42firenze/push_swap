#include "../push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	segno;
	long	valore;

	segno = 1;
	i = 0;
	valore = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			segno = segno * (-1);
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		valore = valore * 10 + (str[i] - 48);
		i++;
	}
	return (valore * segno);
}
int	ft_is_number(char *s)
{
	int	num;
	int	sign;

	num = 0;
	sign = 0;
	while (s && *s)
	{
		if ((*s < '0' || *s > '9') && *s != '+' && *s != '-')
			return (0);
		else if (*s >= '0' && *s <= '9')
			num++;
		else if (num != 0 && (*s < '0' || *s > '9'))
			return (0);
		else if (*s == '+' || *s == '-')
			sign++;
		s++;
	}
	if (num == 0 || sign > 1)
		return (0);
	return (1);
}
int	ft_mat_len(char **mat)
{
	int	i;

	i = 0;
	while (mat && mat[i])
		i++;
	return (i);
}
void	*ft_free_mat(char **a)
{
	int	i;

	i = -1;
	while (a && a[++i])
		free(a[i]);
	free(a);
	return (NULL);
}
char	**ft_mat_dup(char **mat)
{
	char	**mat_cpy;
	int		i;

	i = 0;
	mat_cpy = ft_calloc(ft_mat_len(mat) + 1, sizeof(char *));
	if (!mat_cpy)
		return (NULL);
	while (mat[i])
	{
		mat_cpy[i] = ft_strdup(mat[i]);
		if (!mat_cpy[i])
			return (ft_free_mat(mat_cpy), NULL);
		i++;
	}
	return (mat_cpy);
}