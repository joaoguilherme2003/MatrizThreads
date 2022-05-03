#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *somar_linhas (void *arg);

int soma_total = 0;
int tamanho_matriz = 0;
int comeco = 0;
int fim = 0;
int *numeros;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
	scanf("%d ", &tamanho_matriz);
	
	int i = tamanho_matriz, j = tamanho_matriz;
	int matriz[tamanho_matriz][tamanho_matriz];
    	pthread_t threads[tamanho_matriz];

	numeros = malloc(sizeof (int)*(i*j));

    	int p = 0;

	for (int i = 0; i < tamanho_matriz; i++){
		for (int j = 0; j < tamanho_matriz; j++) {
			scanf("%d", &matriz[i][j]);
			numeros[p] = matriz[i][j];
			p++;
		}
	}

    	fim = tamanho_matriz;

	for (int i = 0; i < tamanho_matriz; i++) 
		pthread_create(&(threads[i]), NULL, somar_linhas, NULL);	
	
	for (int i = 0; i < tamanho_matriz; i++) 
		pthread_join(threads[i], NULL);
	
	printf("%d", soma_total);
	return 0;
}

void *somar_linhas(void *arg)
{
	pthread_mutex_lock(&mutex);
	
	for (int i = comeco; i < fim; i++) {
		soma_total += numeros[i];
	}
	comeco += tamanho_matriz;
	fim += tamanho_matriz;
	
	pthread_mutex_unlock(&mutex);
	return arg;
}
