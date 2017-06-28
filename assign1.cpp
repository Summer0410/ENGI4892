#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include "assign1.h"

int main(){
    ifstream myfile("array.txt");//open the file.
    int data;
    myfile>>data;//read the first number of the array.
    array_struct a[data];//create an array of structure.
//create arrays.
    for(int i=0; i<data;i++){
        int col;
        myfile>>col;
        a[i].arrNum=new int[col];
        for(int j=0; j<col;j++){
            myfile>>(a[i].arrNum)[j];
        }
//assign maximum, minimum and average values to each array.
        a[i].maxNum=calMax(a[i].arrNum,col);
        a[i].minNum=calMin(a[i].arrNum,col);
        a[i].avg=calAvg(a[i].arrNum,col);
        a[i].size=col;
    }
//print the arrays
    for (int m=0; m<data;m++){
        cout<<"The array is shown below: "<<endl;
        for(int n=0; n<a[m].size;n++){
            cout<<a[m].arrNum[n]<<" ";
        }
        cout<<endl;
//print the values
        cout<<"The size of "<< m+1<<" internal array is: "<< a[m].size<<endl;
        cout<<"The maximum value of "<< m+1<<" structure is: "<< a[m].maxNum<<endl;
        cout<<"The minimum value of "<< m+1<<" structure is: "<< a[m].minNum<<endl;
        cout<<"The average value of "<< m+1<<" structure is: "<< a[m].avg<<endl;

    }

}



    int calMax(int* array, int size){
        int maxNum = array[0];
        for(int i=1; i<size;i++){
            if(array[i]>maxNum){
                maxNum = array[i];
            }
        }
        return maxNum;
    }


    int calMin(int* array, int size){
           int minNum = array[0];
        for(int i=1; i<size;i++){
            if(array[i]<minNum){
                minNum = array[i];
            }
        }
        return minNum;
    }

    double calAvg(int* array, int size){
        double sum=0;
        for(int i=0;i<size;i++)
            sum+=array[i];
        return sum/size;

    }
