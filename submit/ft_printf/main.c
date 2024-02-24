/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:26:36 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/19 17:46:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

/** Libft **/
char	*ft_strjoin(const char *s1, const char *s2);

/** this **/
char	*ft_replace_chr(char *str, char target, char c);
void	test(int (*p)(const char *f, ...), char *f_name);
int		tf_cpdiux_ux(int (*p)(const char *f, ...), char *tmp_f, char *f_name);
int		tf_string(int (*p)(const char *f, ...), char *tmp_f, char *f_name);

static const char	*g_template[] = {
	"%@",
	"%@",
	"%#@",
	"%-@",
	"%-1@",
	"%-5@",
	"%+@",
	"% @",
	"%0@",
	"%.0@",
	"%.1@",
	"%.5@",
	"%1@",
	"%5@",
	"%@ ",
	"%@ ",
	"%#@ ",
	"%-@ ",
	"%-1@ ",
	"%-5@ ",
	"%+@ ",
	"% @ ",
	"%0@ ",
	"%.0@ ",
	"%.1@ ",
	"%.5@ ",
	"%1@ ",
	"%5@ ",
	" %@",
	" %@",
	" %#@",
	" %-@",
	" %-1@",
	" %-5@",
	" %+@",
	" % @",
	" %0@",
	" %.0@",
	" %.1@",
	" %.5@",
	" %1@",
	" %5@",
	" %@ ",
	" %@ ",
	" %#@ ",
	" %-@ ",
	" %-1@ ",
	" %-5@ ",
	" %+@ ",
	" % @ ",
	" %0@ ",
	" %.0@ ",
	" %.1@ ",
	" %.5@ ",
	" %1@ ",
	" %5@ ",
};
static const int	g_template_len = sizeof(g_template) / sizeof(g_template[0]);
static const long	g_nv[] = {
	0,
	-1,
	1,
	INT_MAX,
	INT_MIN,
	UINT_MAX,
	UINT_MAX,
	LONG_MAX,
	LONG_MIN,
};
static const int	g_nv_len = sizeof(g_nv) / sizeof(g_nv[0]);
static const char	*g_sv[] = {
	NULL,
	"",
	"a",
	" a",
	"a ",
	" a ",
	"ab",
	" ab",
	"ab ",
	" ab ",
};
static const int	g_sv_len = sizeof(g_sv) / sizeof(g_sv[0]);

/**
 * compile-command: make && main.c libftprintf.a
 * use setvbuf because printf is default buffering butft_printf is not
 * buffering.
 */
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		puts("need one args: printf | ft_printf");
		return (-1);
	}
	if (setvbuf(stdout, NULL, _IONBF, 0) != 0)
		return (-1);
	if (strncmp(argv[1], "printf", 3) == 0)
		test(printf, "print");
	else if (strncmp(argv[1], "ft_printf", 3) == 0)
		test(ft_printf, "print");
	return (0);
}

void	test(int (*p)(const char *f, ...), char *f_name)
{
	char		*format;
	int			index;

	index = 0;
	while (index < g_template_len)
	{
		format = strdup(g_template[index]);
		tf_cpdiux_ux(p, format, f_name);
		tf_string(p, format, f_name);
		index++;
	}
	printf("%s,%s,%%", f_name, "%%");
	printf(",%d\n", p("%%"));
	printf("%s,%s,%%", f_name, " %%");
	printf(",%d\n", p(" %%"));
	printf("%s,%s,%%", f_name, "%% ");
	printf(",%d\n", p("%% "));
	printf("%s,%s,%%", f_name, " %% ");
	printf(",%d\n", p(" %% "));
}

int	tf_cpdiux_ux(int (*p)(const char *f, ...), char *tmp_f, char *f_name)
{
	const char	cses[] = "cpdiuxX";
	const int	cses_len = sizeof(cses) / sizeof(cses[0]) - 1;
	int			index;
	int			cs_index;
	char		*format;

	cs_index = 0;
	while (cs_index < cses_len)
	{
		index = 0;
		format = strdup(tmp_f);
		if (format == NULL)
			return (-1);
		ft_replace_chr(format, '@', cses[cs_index]);
		while (index < g_nv_len)
		{
			printf("%s,%s,%ld,", f_name, format, g_nv[index]);
			printf(",%d\n", p(format, g_nv[index]));
			index++;
		}
		free(format);
		cs_index++;
	}
	return (0);
}

int	tf_string(int (*p)(const char *f, ...), char *tmp_f, char *f_name)
{
	int			index;
	char		*format;

	format = strdup(tmp_f);
	if (format == NULL)
		return (-1);
	ft_replace_chr(format, '@', 's');
	index = 0;
	while (index < g_sv_len)
	{
		printf("%s,%s,%s,", f_name, format, g_sv[index]);
		printf(",%d\n", p(format, g_sv[index]));
		index++;
	}
	return (0);
}

char	*ft_replace_chr(char *str, char target, char c)
{
	while (*str != '\0')
	{
		if (*str == target)
			*str = c;
		str++;
	}
	return (str);
}
