/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:45:41 by rbalbous          #+#    #+#             */
/*   Updated: 2018/06/12 16:55:48 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include <fcntl.h>

# define USAGE1 "usage:     ./lem-in -[FLAGS] < map_file\n"
# define USAGE2 "       -c, -colors : colors differents paths\n"
# define USAGE3 "       -d, -debug  : show debug info\n"
# define USAGE4 "       -f, -file   : followed by your file (replace the '<')\n"
# define USAGE5 "       -412, -cheat: surprise"
# define READ "error: read"
# define MALLOC "error: malloc"
# define NOT_VALID "error: file not valid"
# define NO_S_E "error: no start or end room"
# define COMMAND "error: one command followed by another"
# define BAD_NAME "error: bad room name"
# define EMPTY "error: empty file"
# define INFO "error: not enough informations in the file"
# define LINK "error: no solution, try -412"
# define NO_ANTS "error: no ants found"

# define GNL_SIZE 1 << 16
# define DEBUG 0x1
# define COLORS 0x2
# define CHEAT 0x4

typedef struct s_lem		t_lem;
typedef struct s_lstname	t_lstname;
typedef struct s_room		t_room;
typedef struct s_file		t_file;
typedef struct s_display	t_display;
typedef union u_color		t_color;

struct			s_display
{
	int			*turns;
	int			*stock;
	int			path;
	int			i_length;
	int			cur;
	int			max;
	int			nb_ants;
	int			id_turn;
};

struct			s_file
{
	char		*data;
	int			cursor;
	int			size;
	int			fd;
};

struct			s_lstname
{
	t_lstname	*next;
	char		*name;
	int			type;
	int			brk;
};

struct			s_room
{
	char		*name;
	int			*links;
	int			nb_links;
	int			al_checked;
	int			way_out;
	int			nb_sol;
	int			dist;
};

struct			s_lem
{
	int			**paths;
	int			*result;
	int			*tmp;
	t_room		*rooms;
	char		*str;
	char		flags;
	int			ants;
	int			antlen;
	int			str_len;
	int			max_len;
	int			str_index;
	int			sol_max;
	int			nb_rooms;
	int			nb_paths;
	int			nb_soluce;
	int			solutions;
	int			*r_length;
};

union			u_color
{
	int			color;
	t_uint8		rgb[4];
};

int				get_color(t_color c1, t_color c2, double k);
void			get_flags(t_lem *c, int ac, char *av[], int *fd);

int				read_file(t_file *file);
int				check_valid(char *line);

int				parsing(int fd, t_lem *c);
void			get_pipes(t_lem *c);
int				get_rooms(t_lstname *first, t_lem *c);

void			display_usage(void);
void			display_error(char *str);
void			display_debug(t_lem *c);

void			check_links(t_lem *c);
int				check_path(t_lem *c, int path, int dist);
void			solver(t_lem *c);
void			reset(t_lem *c, int k);

void			free_lst(t_lstname *first);
int				check_valid_coord(t_lem *c);
int				check_hyphen(t_lem *c);

void			antflow(t_lem *c);

void			display(t_lem *c, int throll);
int				print_colored_text(t_lem *c, char *str, t_display *disp);
int				print_colored_text2(t_lem *c, char *str, t_display *disp);

int				output(t_lem *c);
int				algo(t_lem *c, int path, int *sol);
int				get_path(t_lem *c, int index);
int				get_new_dist(t_lem *c, int path, int dist, int start);
void			copy_to_result(t_lem *c, int **length);

void			*ft_memaccpy_special(t_lem *c, const void *src, int s);

char			*create_lmatador(t_lem *c);
int				fill_lmatador3(t_lem *c, t_display *disp, char *str, int i);
int				fill_lmatador2(t_lem *c, t_display *disp, char *str, int i);
int				fill_lmatador(t_lem *c, t_display *disp, char *str, int i);

#endif
