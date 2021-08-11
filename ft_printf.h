#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int ft_printf(const char *format, ...);

//input
int ft_chr(va_list input);
int	ft_str(va_list input);
int	ft_ptr(va_list args);
int ft_int_dec(va_list input);
int ft_u_int(va_list input);
int	ft_hex(char converter, va_list args);
int ft_percent();
int tag_invalid(char converter);

//printing
int		put_str(char *str);
void	ft_putchar(char c);
char 	*ft_int_to_hex(int n);

//converters
int	printf_handler(char **string, va_list input);
int	conv_invalid(char conv);

#endif