#include "../../head.h"

void	*ft_copy(void *data, size_t size)
{
	void	*shit;

	shit = malloc(size);
	memcpy(shit, data, size);
	return (shit);
}

void	*thread_change(void *parameter)
{
	int 		i;
	t_contrast	*x;

	x = (t_contrast*)parameter;
	i = x->array[x->count];
	while (i < x->array[x->count + 1])
	{
		algo_contrast(x, i);
		i++;
	}
	return (0);
}

int 	get_color(t_thread *tmp, int i)
{
	int 	res;
	int 	cores;
	int 	j;

	j = 0;
	res = -1;
	cores = 4;//(int)sysconf(_SC_NPROCESSORS_ONLN);
	while (j < cores)
	{
		if (i < tmp[j].thread->array[tmp[j].thread->count + 1])
			return (tmp[j].thread->mapping_pixel[i]);
		j++;
	}
	return (res);
}

void	thread_save_file(t_thread *tmp)
{
	int		x;
	int		y;
	int		i;
	int		fd;
	int 	color;

	i = 0;
	y = 0;
	fd = open(tmp[i].thread->name_new_file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	save_two(tmp[i].thread, fd);
	while (y < tmp[0].thread->height)
	{
		x = 0;
		while (x < tmp[0].thread->lenght)
		{
			if (x != 0)
				ft_putchar_fd(' ', fd);
			color = get_color(tmp, i);
			ft_putnbr_fd(color, fd);
			x++;
			i++;
		}
		ft_putchar_fd('\n', fd);
		y++;
	}
	close(fd);
}

int 	thread_change_mapping(t_contrast *main_x)
{
	pthread_t	thread_handle[FT_CPU];
	t_thread	*tmp;
	int 		res;
	int 		i;

	i = 0;
	tmp = (t_thread*)malloc(sizeof(t_thread) * (FT_CPU + 1));
	while (i < FT_CPU)
	{
		tmp[i].thread = ft_copy(main_x, sizeof(t_contrast) + 1);
		tmp[i].thread->count = i;
		tmp[i].thread->array = get_borders(main_x);
		res = pthread_create(&thread_handle[i], 0, thread_change, tmp[i].thread);
		if (res != 0)
		{
			printf("ERROR %d\n", res);
			return (-1);
		}
		i++;
	}
	free(main_x);
	i = 0;
	while (i < FT_CPU)
	{
		pthread_join(thread_handle[i], 0);
		i++;
	}
	thread_save_file(tmp);
	return (1);
}

int		main(int argc, char **argv)
{
	t_lst			*list_read;
	t_contrast		*main_x;

	if (input_param(argc, argv) != 1)
		return (-1);
	list_read = ft_read(argv);
	if (list_read->len == 0)
	{
		printf("Error file\n");
		return (0);
	}
	main_x = (t_contrast*)malloc(sizeof(t_contrast));
	init(main_x, argv);
	main_x = valid_filling(main_x, list_read);
	if (main_x->size_map == 0)
	{
		printf("Error file\n");
		return (0);
	}
	if ((thread_change_mapping(main_x)) == -1)
		return (-1);
}
