#include "sorter.hpp"

Sorter::Sorter(){;}
Sorter::~Sorter(){;}

//Imprime a lista
void Sorter::printList(int input[], int inputSize){
  std::cout << "{ ";
  for(int i = 0; i < inputSize; i++)
    std::cout << input[i] << " ";
  std::cout << "}";
}

/*Selection Sort
  Complexidade - Melhor: n*n Média: n*n Pior: n*n */
void Sorter::selectionSort(int input[], int inputSize){
  for(int i = 0; i < inputSize - 1; i++){
    int min = i;
    for(int j = i + 1; j < inputSize; j++){
      if(input[j] < input[min])
        min = j;
    }
    if(min != i){
      std::swap(input[i], input[min]);
    }
  }
}

/*Insertion Sort
  Complexidade - Melhor: n Média: n*n Pior: n*n */
void Sorter::insertionSort(int input[], int inputSize){
  int aux, j;
  for(int i = 1; i < inputSize; i++){
    aux = input[i];
    j = i - 1;
    while(j >= 0 && input[j] > aux){
      input[j+1] = input[j];
      j--;
    }
    input[j+1] = aux;
  }
}

void merge(int input[], int start, int mid, int end){
  int a = start;
  int b = mid + 1;
  int k = 0;
  int aux[end - start + 1];

  for(int i = start; i <= end; i++){
    if(a > mid)
      aux[k++] = input[b++];
    else if(b > end)
      aux[k++] = input[a++];
    else if(input[a] < input[b])
      aux[k++] = input[a++];
    else
      aux[k++] = input[b++];
  }

  for(int j = 0; j < k; j++){
    input[start++] = aux[j];
  }
}

/*Merge Sort
  Complexidade - Melhor: n*Log(n) Média: n*Log(n) Pior: n*Log(n) */
void Sorter::mergeSort(int input[], int start, int end){
  if (start < end){
    int mid = (start + end)/2;
    mergeSort(input, start, mid);
    mergeSort(input, mid+1, end);
    merge(input, start, mid, end);
  }
}

int partition(int input[], int start, int end){
  int i = start + 1;
  int pivo = input[start];

  for(int j = start + 1; j <= end; j++){
    if(input[j] < pivo){
      std::swap(input[i], input[j]);
      i++;
    }
  }

  std::swap(input[start], input[i-1]);
  return i-1;
}

/*Quick Sort
  Complexidade - Melhor: n*Log(n) Média: n*Log(n) Pior: n*n */
void Sorter::quickSort(int input[], int start, int end){
  if (start < end){
    int pivo = partition(input, start, end);
    quickSort(input, start, pivo - 1);
    quickSort(input, pivo + 1, end);
  }
}
