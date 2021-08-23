#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		converter(char **string, va_list input);
int		ft_c(va_list input);
int		ft_s(va_list input);
int		ft_p(va_list input);
int		ft_d_i(va_list input);
int		ft_u(va_list input);
int		ft_x(int upper, va_list input);
int		ft_percent(void);
char	*get_hex(size_t n);
int		output(char *str);

#endif