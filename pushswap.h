#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>

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

int		validate_input(char **av);

#endif