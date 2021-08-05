#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdarg.h"

typedef struct s_struct
{
	char	format;

	int		minus;
	int		zero;

	int		width;
	int		precision;
	int		length;
}				t_struct;

typedef struct s_istruct
{
	int	i;
	int	j;
	int	k;
}				t_istruct;

typedef struct s_rewstruct
{
	int		j;
	int		len;
	int		end;
}				t_rewstruct;

int		ft_printf(const char *format, ...);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
int		ft_strchr (const char *str, int ch);
int		ft_width(va_list ag, t_istruct size, const char *format, t_struct *new);
int		ft_length(va_list ag, t_istruct size, \
					const char *format, t_struct *new);
int		ft_get_length_width(va_list ag, const char *format, \
								t_struct *setting, t_istruct size);
int		ft_get_setting_format(va_list ag, const char *format, \
								int i, t_struct *send_setting);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_write_space(char c, int i, int side);
char	*ft_write_char(char c);
char	*ft_rewrite_format(const char *format, const char *str, \
							int i, t_struct setting);
char	*ft_ifchar(va_list ag, const char *format, t_struct setting, int *j);
char	*ft_write_str_space(char *str, int len);
char	*ft_write_str_space_minus(char *str, int len);
char	*ft_write_str_precision(char *str, int precision);
char	*ft_strdup_malloc(char *str);
char	*ft_ifstring(va_list ag, const char *format, t_struct setting, int *j);
char	*ft_write_zero(char c, int i);
char	*ft_rewrite_format_percent(const char *format, const char *str, \
									int i, t_struct setting);
char	*ft_ifpercent(const char *format, t_struct setting, int i);
char	*ft_printf_itoa(int n);
char	*ft_write_str_zero(char *str, int precision);
char	*ft_ifinteger(va_list ag, const char *format, t_struct setting, int i);
char	*ft_printf_itoa_un(unsigned int n);
char	*ft_ifuninteger(va_list ag, const char *format, \
							t_struct setting, int i);
char	*ft_ten_to_sixteen(t_struct setting, unsigned int num);
char	*ft_ifhex(va_list ag, const char *format, t_struct setting, int i);
char	*ft_plus_index(char *str);
char	*ft_ifpointer(va_list ag, const char *format, t_struct setting, int i);
char	*ft_write_empty_line(char *str, int len, int width);
void	ft_sexteen_fill_up(char sexteen[16]);
void	ft_sexteen_fill_low(char sexteen[16]);
char	*ft_rewrite_format_nul(const char *format, const char *str, \
								int i, t_struct setting);
int		ft_putstr_final(char *str, int j, va_list ag);
int		ft_strlen_nul(const char *str);
int		ft_strlen_str(const char *str, int i);
int		ft_width2(va_list ag, t_struct *new);
int		ft_get_setting_format2(const char *format, \
							t_struct *setting, t_istruct *size);
char	*ft_ifhex2(char *string, t_struct setting);
char	*ft_ifstring2(char *string, t_struct setting);

#endif