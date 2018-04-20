/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:38:33 by rnugroho          #+#    #+#             */
/*   Updated: 2018/04/20 15:45:30 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

int			main(int ac, char **av)
{
	t_vm	v;

	ft_bzero(&v, sizeof(t_vm));
	if (ac < 2 || vm_options(av, &v) == -1)
	{
		ft_dprintf(2, "usage: %s [options] champion1.cor ...\n", av[0]);
		return (-1);
	}
	vm_print();
	return (0);
}
