/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:25:25 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 14:30:44 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_part
{
	char			*str;
	char			type[3];
	char			*data;
	int				datalen;
	char			zero;
	char			plus;
	int				minus;
	int				sharp;
	char			space;
	int				width;
	int				preci;
	long long int	hex;
	struct s_part	*next;
}				t_part;
t_part			*create_list(char *format);
t_part			*apply_flags(t_part *begin);
char			*ft_itoa_base_ll(long long value, int base, int isuns);
char			*ft_itoa_base(int value, int base, int isuns);
char			*save_float(double d, int precision);
char			*save_ldouble(long double d, int precision);
char			*float_manager(t_part *new, va_list ar);
char			*hex_manager(t_part *new, va_list ar);
char			*number_manager(t_part *new, va_list ar);
char			*ft_itoa_u(unsigned int n);
char			*ft_itoa_l(long int n);
char			*ft_itoa_ll(long long int n);
char			*ft_itoa_ul(unsigned long int n);
char			*ft_itoa_ull(unsigned long long int n);
int				ft_intlen_ll(long long int num);
int				is_fspecif(char c);
void			get_data(t_part *new, va_list ar);
void			initialize_pf(t_part *new);
void			error_manager(char *str);
void			free_list(t_part **list);
void			get_valid_flags(t_part *list);
int				ft_printf(const char *format, ...);
int				is_valid_format(char *str, int len);
int				is_hex(char c);
int				apply_preci(t_part *list);

#endif
