#include "iostream"
#define MAXN 100

using namespace std;



void merge(int a[], int b[], int done, int rightEnd, int leftEnd){
  int  rightPoint, leftPoint, tempArrayPoint;
  rightPoint = done;
  leftPoint =  rightEnd + 1;
  tempArrayPoint = done;
  while(rightPoint <= rightEnd && leftPoint <= leftEnd){
    if (a[rightPoint] < a[leftPoint])
    {
      b[tempArrayPoint++] = a[rightPoint++];
    }
    else{
      b[tempArrayPoint++] = a[leftPoint++];
    }
  }
  while(rightPoint <= rightEnd){
    b[tempArrayPoint++] = a[rightPoint++];
  }
  while(leftPoint <= leftEnd){
    b[tempArrayPoint++] = a[leftPoint++];
  }
} 

void mpass(int a[], int b[], int n, int teamLong){
  int done, tempPoint;
  done = 0;
  while(done + 2 * teamLong < n){
    merge(a, b, done, done + teamLong - 1, done + 2 * teamLong - 1);
    done += 2 * teamLong;
  }
  if (done + teamLong < n)
  {
    merge(a, b, done, done + teamLong -1, n - 1);
  }
  else{
    for(tempPoint = done; tempPoint<n; tempPoint++){
      b[tempPoint] = a[tempPoint];
    }
  }
}

void mergeSort(int a[], int n){
  int b[MAXN];
  int teamLong = 1;
  while(teamLong < n){
    mpass(a, b, n, teamLong);
    teamLong *= 2;
    mpass(b, a, n, teamLong);
    teamLong *= 2;
  }
}


int main (){
  int a[9] = {2, 1, 5, 4, 7, 8, 6, 9, 3};
  mergeSort(a, 9);
  for (int i = 0; i < 9; ++i)
  { 
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 1;
}