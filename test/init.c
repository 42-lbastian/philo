#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct	s_list
{
	char *name;
	int age;
	int	id;
	pthread_t *tid_sec;
	pthread_mutex_t mutex_age;
	pthread_mutex_t mutex_id;
}				t_list;

void  *print_hello1(void *list)
{
	pthread_mutex_lock(&(((t_list *)list)->mutex_age));
	printf("First %d\n", ((t_list *)list)->age);
	((t_list *)list)->age++;
	pthread_mutex_unlock(&(((t_list *)list)->mutex_age));
	sleep(10);
	return (NULL);
}

void  *print_hello(void *list)
{
	int i;

	i = 0;
	printf("Actual %d\n", ((t_list *)list)->age);
	((t_list *)list)->age++;
	while (i < 3)
	{
		if (((t_list *)list)->tid_sec[i] != pthread_self())
			pthread_cancel(((t_list *)list)->tid_sec[i]);
		i++;
	}
	pthread_exit(NULL);
	sleep(3);
	return (NULL);
}

void	*ft_one_two(void *list)
{
	int id;
	pthread_mutex_lock(&((t_list *)list)->mutex_id);
	id = ((t_list *)list)->id;
	if (id % 2 == 0)
	{
		printf("Ok %d\n", id);
	}
	else
	{
		printf("Not Ok %d\n", id);
	}
	((t_list *)list)->id++;
	pthread_mutex_unlock(&((t_list *)list)->mutex_id);
	sleep(4);
	pthread_mutex_lock(&((t_list *)list)->mutex_id);
	if (id % 2 == 0)
	{
		printf("Ok2 %d\n", id);
	}
	else
	{
		printf("Not Ok2 %d\n", id);
	}
	pthread_mutex_unlock(&((t_list *)list)->mutex_id);	
	return (NULL);
}

void	*ft_infinite(void *list)
{
	int i;

	i = 0;
	while (1)
	{
		printf("NB %d\n", i);
		i++;
		sleep(2);
	}
}

void	*ft_infinite2(void *list)
{
	sleep(5);
	printf("ENNNND\n");
	return (NULL);
}

void *main_thread(void *list)
{
	int th;
	
	((t_list *)list)->id = 0;
	th = pthread_create(&(((t_list *)list)->tid_sec[0]), NULL, ft_infinite, list);
	th = pthread_create(&(((t_list *)list)->tid_sec[1]), NULL, ft_infinite, list);
	th = pthread_create(&(((t_list *)list)->tid_sec[2]), NULL, ft_infinite2, list);
	pthread_join(((t_list *)list)->tid_sec[2], NULL);
	pthread_detach(((t_list *)list)->tid_sec[1]);
	pthread_join(((t_list *)list)->tid_sec[1], NULL);
	return (NULL);
}

int main(int argc, char **argv)
{
	int th;
	pthread_t tid_main;
	t_list *list;

	list = malloc(sizeof(t_list));
	list->tid_sec = malloc(sizeof(pthread_t) * 3);
	list->name = argv[1];
	list->age = atoi(argv[2]);
	pthread_mutex_init(&(list->mutex_age), NULL);
	pthread_mutex_init(&(list->mutex_id), NULL);
	th = pthread_create(&tid_main, NULL, main_thread, (void *)list);
	pthread_join(tid_main, NULL);
	return (0);
}
