/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:00:50 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/15 17:23:07 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASM_H
# define FT_ASM_H

# include "libft.h"
# include "op.h"

# define SOURCEFILE		1
# define EMPTY			2
# define NEWLINE		3
# define MALLOC			4
# define HEADER			5
# define NAME_LEN		6
# define COMMENT_LEN	8
# define OP				9
# define OP_NAME		10
# define OP_PARAM		11
# define LABEL_MISSING	12

typedef struct	s_op_dict
{
	char		*name;
	int			opcode;
	int			d_size;
}				t_op_dict;

static	t_op_dict g_op_dict[17] = {
	{ .name = "\0", .opcode = 0x00, .d_size = 0 },
	{ .name = "live", .opcode = 0x01, .d_size = 4 },
	{ .name = "ld", .opcode = 0x02, .d_size = 4 },
	{ .name = "st", .opcode = 0x03, .d_size = 0 },
	{ .name = "add", .opcode = 0x04, .d_size = 0 },
	{ .name = "sub", .opcode = 0x05, .d_size = 0 },
	{ .name = "and", .opcode = 0x06, .d_size = 4 },
	{ .name = "or", .opcode = 0x07, .d_size = 4 },
	{ .name = "xor", .opcode = 0x08, .d_size = 4 },
	{ .name = "zjmp", .opcode = 0x09, .d_size = 2 },
	{ .name = "ldi", .opcode = 0x0a, .d_size = 2 },
	{ .name = "sti", .opcode = 0x0b, .d_size = 2 },
	{ .name = "fork", .opcode = 0x0c, .d_size = 2 },
	{ .name = "lld", .opcode = 0x0d, .d_size = 4 },
	{ .name = "lldi", .opcode = 0x0e, .d_size = 2 },
	{ .name = "lfork", .opcode = 0x0f, .d_size = 2 },
	{ .name = "aff", .opcode = 0x10, .d_size = 0 }
};

typedef struct	s_param
{
	char		*str;
	int			type;
	int			size;
	int			value;
}				t_param;

typedef struct	s_op
{
	char		*opname;
	int			opcode;
	int			oc;
	int			size;
	t_param		params[3];
	int			param_c;
	char		*label;
	int			offset;
}				t_op;

typedef struct	s_asm
{
	int			i;
	char		*name;
	char		*comment;
	char		**file;
	char		**labels;
	t_op		ops[1000];
	int			op_c;
	int			size;
}				t_asm;

int				ft_parsing(t_asm *a, header_t *h);
int				ft_get_name(t_asm *a, header_t *h);
int				ft_get_comment(t_asm *a, header_t *h);
int				ft_check_instructions(t_asm *a);
int				ft_get_labels(t_asm *a);
int				ft_is_label(char *line);
int				ft_get_op(t_asm *a);

int				ft_error(int errcode, int status, char *line);
int				ft_file_is_empty(char *file);
int				ft_line_is_empty(t_asm *a);
void			ft_skip_empty_lines(t_asm *a);
void			ft_handle_comments(char **file);
void			ft_trim_file(char **file);
void			ft_print_tab(char **tab);
int				ft_free(char *str, int status);
int				ft_free_tab(char **tab, int status);

int				asm_get_op(t_asm *a);
void			asm_print(t_asm *a);

int				asm_get_paramtype(int opcode, char *param, int *value, int *size);
int				asm_get_indvalue(t_asm *a, char *label);
int				asm_populate_indvalue(t_asm *a);
int				asm_calculate_oc(t_param params[3], int param_c);

int				ft_strcspn(const char *s, const char *charset);
char			*ft_strcdup(const char *s1, const char c);

#endif
