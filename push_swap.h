/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:06:41 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 21:50:15 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	size_t			index;
	struct s_stack	*next;
}	t_stack;


char	**process_input(int ac, char **av);
t_stack	*init_stack(int ac, char **av);
void	sort_stack(t_stack **stack_a);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	ft_error(void);
int		ft_printf(const char *str, ...);
int		ft_isdigit(int c);
int		ft_issign(int c);
char	**ft_split(const char *s, char c);
char	*ft_get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_arrfree(char **arr, bool error);
size_t	ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int n);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
void	ft_lstfree(t_stack **lst, bool error);
int		ft_lstmax(t_stack *lst);
int		ft_lstmin(t_stack *lst);

int		calculate_rotation_ba(t_stack *a, t_stack *b);
int		calculate_rotation_ab(t_stack *a, t_stack *b);
int		calculate_rarb_a(t_stack *a, t_stack *b, int c);
int		calculate_rarrb_a(t_stack *a, t_stack *b, int c);
int		calculate_rrarb_a(t_stack *a, t_stack *b, int c);
int		calculate_rrarrb_a(t_stack *a, t_stack *b, int c);
int		calculate_rarb_b(t_stack *a, t_stack *b, int c);
int		calculate_rarrb_b(t_stack *a, t_stack *b, int c);
int		calculate_rrarb_b(t_stack *a, t_stack *b, int c);
int		calculate_rrarrb_b(t_stack *a, t_stack *b, int c);
int		use_rarb(t_stack **a, t_stack **b, int c, char s);
int		use_rarrb(t_stack **a, t_stack **b, int c, char s);
int		use_rrarb(t_stack **a, t_stack **b, int c, char s);
int		use_rrarrb(t_stack **a, t_stack **b, int c, char s);
bool	is_sorted(t_stack *stack);
size_t	find_index(t_stack *a, int number);
size_t	get_index_b(t_stack *stack_b, int number_push);
size_t	get_index_a(t_stack *stack_a, int number_push);

#endif