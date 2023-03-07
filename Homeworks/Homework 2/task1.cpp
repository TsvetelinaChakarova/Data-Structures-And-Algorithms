#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector <int> &array, int left, int middle, int right) {

   int leftArraySize = middle - left + 1;
   int rightArraySize = right - middle;
   int leftArr[leftArraySize], rightArr[rightArraySize];
  
   for (int i = 0; i < leftArraySize; i++) {
      leftArr[i] = array[left+i];
   }
   
   for(int j = 0; j < rightArraySize; j++) {
      rightArr[j] = array[middle+1+j];
   }
   
   int i = 0, j = 0, k = left;
  
   while(i < leftArraySize && j < rightArraySize) {
      if (leftArr[i] <= rightArr[j]) {
         array[k] = leftArr[i];
         i++;
      }
      
      else {
         array[k] = rightArr[j];
         j++;
      }
      
      k++;
   }
   
   while(i < leftArraySize) {       
      array[k] = leftArr[i];
      i++; k++;
   }
   
   while(j < rightArraySize) {     
      array[k] = rightArr[j];
      j++; k++;
   }
}

void mergeSort(vector <int> &array, int left, int right) {
   int middle;
   if (left < right) {
      int middle = left + (right - left) / 2;
      mergeSort(array, left, middle);
      mergeSort(array, middle+1, right);
      merge(array, left, middle, right);
   }
}

int main() {
  
   int numberOfPresents, currentPrice;
   vector <int> pricesOfPresents;
   unsigned int numberOfEmployees;
   long long finalPrice = 0;
   
   cin>>numberOfPresents;
   
   for (int i = 0; i < numberOfPresents; i++) {
       cin >> currentPrice;
       pricesOfPresents.push_back(currentPrice);
   }
   
   cin >> numberOfEmployees;
  
   mergeSort(pricesOfPresents, 0, pricesOfPresents.size() -1); 
  
   for (int i = 0; i < numberOfEmployees; i++) {
       finalPrice += pricesOfPresents[i];
   }
   
   cout << finalPrice << endl;
   
    return 0;
}
