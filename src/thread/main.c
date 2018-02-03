#include "../../head.h"

static void	init_demo(t_contrast *main_x)
{
	main_x->lenght = 5;
	main_x->height = 5;
	main_x->mapping_pixel = (int*)malloc(sizeof(int) * (5 * 5) + 1);
	main_x->size_map = 5 * 5;
	main_x->max_grey_lvl = 5;
	int x = 0;
	int y = 0;
	int i = 0;
	while (y < main_x->lenght)
	{
		x = 0;
		while (x < main_x->height)
		{
			if (x % 2)
				main_x->mapping_pixel[i] = 5;
			else
				main_x->mapping_pixel[i] = 10;
			i++;
			x++;
		}
		y++;
	}
}

void	*thread_change(void *parameter)
{
	int 		i;
	t_contrast	*x;

	x = (t_contrast*)parameter;
	i = 0
	while (i < x->size_map)
	{
		algo_contrast(x, i);
		i++;
	}
	return (0);
}

int 	thread_change_mapping(t_contrast *main_x)
{
	pthread_t	thread_handle[FT_CPU];
	int 		res;
	int 		i;

	i = 0;
	while (i < FT_CPU)
	{
		res = pthread_create(&thread_handle[i], 0, thread_change, (void*)main_x);
		if (res != 0)
		{
			printf("ERROR %d\n", res);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < FT_CPU)
	{
		main_x->count = i;
		pthread_join(thread_handle[i], 0);
		i++;
	}
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
	init_demo(main_x);
	if ((thread_change_mapping(main_x)) == -1)
		return (-1);
	// return (1);
	// save_file(main_x);
}
