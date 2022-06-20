// Max-Heap Estrutura de Dados em C

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 1001
#define SHAME 1000

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int colision(int array[]){
    int colisao = 0;

    for(int i = 0; i < MAX; i++) {
        if (array[i] == array[2*(i+1)] || array[i]==array[2*(i+2)])
            colisao+=1;
    }
    return colisao;
}

int main()
{
  int array[100000];
  srand(1);
  int num = 0;
  struct timeval t0;
  struct timeval t1;
  float elapsed;



  gettimeofday(&t0, 0);
    /* ... YOUR CODE HERE ... */
    for(int i = 0; i<100000;i++){
        num=rand()%10000;
        insert(array,num);
    }



    gettimeofday(&t1, 0);

    elapsed = timedifference_msec(t0, t1);

    printf("\n %f time used", elapsed);

//
//  printf("Max-Heap vetor: ");
//  printArray(array, size);
//  printf("Depois de deletar um elemento: ");
//
//  printArray(array, size);
    scanf("%d", num);

  printf("\n Colisoes do Heap %d ", colision(array));
}
