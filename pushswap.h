#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_list;

int		ft_printf(const char *str, ...);
int		ft_isdigit(int c);
int		ft_issign(int c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(void);
t_list	*ft_lstnew(int n);
void	ft_lstadd_back(t_list **stack, t_list *new);
size_t	ft_lstsize(t_list *stack);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	validate_input(char **av, bool is_split);
t_list	*init_stack(char **av, bool is_split);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	small_sort(t_list **stack_a, t_list **stack_b, size_t size);

#endif