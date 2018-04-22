/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:00:18 by rnugroho          #+#    #+#             */
/*   Updated: 2018/04/22 14:52:25 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

int			vm_error(int errnum, int status)
{
	if (errnum == MALLOC)
		ft_dprintf(2, "Error - Malloc 💥\n");
	if (errnum == INVALID_FILE)
		ft_dprintf(2, "Error - File is not a corewar file\n");
	if (errnum == CHAMP_MAX)
		ft_dprintf(2, "Error - Code is too large (max %d bytes) \n", CHAMP_MAX_SIZE);
	return (status);
}