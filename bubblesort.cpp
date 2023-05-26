#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;
void bubble(int *a, int n)
{
    int i, j;
    #pragma omp parallel
    for (i = 0; i < n - 1; i++){
         #pragma omp parallel
        for (j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    
    }
}

// void swap(int &a, int &b)
// {
//     int test=a;
//     a=b;
//     b=test;
// }
int main()
{
int *a,n;
cout<<"enter total no of elements=>"<<endl;
cin>>n;
a=new int[n];
cout<<"enter elements=>"<<endl;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
bubble(a,n);
cout<<"sorted array is=>"<<endl;
for(int i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
return 0;
}