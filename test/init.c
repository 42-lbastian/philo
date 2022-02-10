#include <pthread.h>
#include <stdio.h>
#include <libc.h>

#define LIST ((t_list *)list)

typedef struct	s_list
{
	char *name;
	int age;
	pthread_t *tid_sec;
	pthread_mutex_t mutex_age;
}				t_list;

void  *print_hello1(void *list)
{
	pthread_mutex_lock(&(LIST->mutex_age));
	printf("First %d\n", LIST->age);
	LIST->age++;
	pthread_mutex_unlock(&(LIST->mutex_age));
	sleep(10);
	return (NULL);
}

void  *print_hello(void *list)
{
	int i;

	i = 0;
	printf("Actual %d\n", LIST->age);
	LIST->age++;
	while (i < 3)
	{
		if (LIST->tid_sec[i] != pthread_self())
			pthread_cancel(LIST->tid_sec[i]);
		i++;
	}
	pthread_exit(NULL);
	sleep(3);
	return (NULL);
}

void *main_thread(void *list)
{
	int th;
	
	th = pthread_create(&(LIST->tid_sec[0]), NULL, print_hello1, list);
	th = pthread_create(&(LIST->tid_sec[1]), NULL, print_hello1, list);
	sleep(2);
	th = pthread_create(&(LIST->tid_sec[2]), NULL, print_hello, list);
	pthread_join(LIST->tid_sec[0], NULL);
	pthread_join(LIST->tid_sec[1], NULL);
	pthread_join(LIST->tid_sec[2], NULL);
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
	th = pthread_create(&tid_main, NULL, main_thread, (void *)list);
	pthread_join(tid_main, NULL);
	return (0);
}
