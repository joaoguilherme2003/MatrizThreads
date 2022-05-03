# MatrizThreads
Este código realiza a soma dos valores de uma matriz quadrada, linha a linha, sendo uma thread por soma de linha;

O usuário deve inserir o tamanho do lado da matriz e depois inseri-la;

Para manipular as threads foi usado a biblioteca <pthread.h>;

pthread_t = tipo usado para definir o array de threads;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER = usado para definir o mutex como forma de impedir o embaralhamento de threads;

pthread_create =  usado para cirar as threads e designar sua função;

pthread_join = usado para encerrar asa threads;

## makefile

Make = Cria o aplicativo binario do codigo.

Make run = Executa o aplicativo.

Make clean = Apaga o aplicativo binario.

#Compile
```c
$ make
```
#Run
```c
$ make run
```
#Clean
```c
$ make clean
```
