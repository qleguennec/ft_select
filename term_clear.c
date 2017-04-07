/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:39:17 by qle-guen          #+#    #+#             */
/*   Updated: 2017/04/05 13:43:09 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int
	term_clear
	(void)
{
	return (tputs(tgetstr("cl", NULL), 0, &putchar));
}
