/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:40:38 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/27 20:50:20 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static char	*check_operation(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		ft_error();
	return (ft_get_next_line(0));
}

static void	check_operations(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = check_operation(a, b, line);
		free(tmp);
	}
	if (*b)
		ft_printf("KO\n");
	else if (!is_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	stack_a = init_stack(ac, process_input(ac, av + 1));
	if (!stack_a)
		ft_lstfree(&stack_a, true);
	line = ft_get_next_line(0);
	if (!line && !is_sorted(stack_a))
		ft_printf("KO\n");
	else if (!line && is_sorted(stack_a))
		ft_printf("OK\n");
	else
		check_operations(&stack_a, &stack_b, line);
	ft_lstfree(&stack_b, false);
	ft_lstfree(&stack_a, false);
	return (0);
}
