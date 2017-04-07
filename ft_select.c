/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:26:44 by qle-guen          #+#    #+#             */
/*   Updated: 2017/04/07 12:10:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char
	**print_ents
	(t_seldata *sd
	, char **argv)
{
	size_t	len;
	size_t	max;

	max = 0;
	while (*argv)
	{
		if (sd->y == sd->li)
		{
			sd->y = 0;
			sd->x += max + 1;
			max = 0;
		}
		len = ft_strlen(*argv);
		if (len > max)
			max = len;
		term_abs_goto(sd->x, sd->y);
		write(1, *argv, len);
		argv++;
		sd->y++;
	}
	return (argv);
}

static int
	loop
	(t_seldata *sd
	, char **argv)
{
	char		inp[3];
	ssize_t		br;

	term_clear();
	print_ents(sd, argv);
	if ((br = read(0, inp, 1)) < 0)
		return (FMTERR("read error %d", 1, br));
	return (loop(sd, argv));
}

int
	main
	(int argc
	, char **argv)
{
	char			*term_type;
	struct termios	tios;
	t_seldata		sd;

	if (argc == 1)
		return (0);
	if ((term_type = getenv("TERM")) == NULL)
		return (FMTERR("ft_select: cannot get terminal type", 1, 0));
	if (tgetent(NULL, term_type) != 1)
		return (FMTERR("ft_select: cannot get term entry", 1, 0));
	if (tcgetattr(0, &tios) == -1)
		return (FMTERR("ft_select: cannot get term info", 1, 0));
	tios.c_lflag &= ~ICANON;
	if (tcsetattr(0, TCSADRAIN, &tios) == -1)
		return (FMTERR("ft_select: cannot set term info", 1, 0));
	signal(SIGINT, &sel_exit);
	ft_bzero(&sd, sizeof(sd));
	seldata_upd(&sd);
	return (loop(&sd, argv));
}
