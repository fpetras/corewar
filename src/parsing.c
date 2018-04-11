/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:24:11 by fpetras           #+#    #+#             */
/*   Updated: 2018/04/11 15:03:17 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_parsing(t_asm *a)
{
	ft_handle_comments(a->file);
	ft_trim_file(a->file);
	if (ft_get_name(a) == -1 || ft_get_comment(a) == -1)
		return (-1);
	ft_printf("name: %s\n", a->name);
	ft_printf("comment: %s\n", a->comment);
	return (0);
}
