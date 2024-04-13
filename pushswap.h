#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_list;

int	ft_printf(const char *str, ...);
int	ft_isdigit(int c);

#endif