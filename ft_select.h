/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:28:26 by qle-guen          #+#    #+#             */
/*   Updated: 2017/04/06 15:15:47 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libfmt/libfmt.h"

# include <curses.h>
# include <signal.h>
# include <term.h>
# include <stdlib.h>
# include <unistd.h>

// TODO remove
# include <assert.h>
# include <stdio.h>

typedef struct	s_seldata
{
	int			x;
	int			y;
	int			co;
	int			li;
}				t_seldata;

int
	putchar
	(int c);
int
	term_abs_goto
	(int x
	, int y);
int
	term_clear
	(void);
void
	sel_exit
	(int sig);
void
	seldata_upd
	(t_seldata *d);

#endif
