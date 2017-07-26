
#include <vector>
using namespace std;
#include "HeapPriorityQueue.hxx"
#include <iostream>
#include <fstream>
template<class K, class V>

void  HeapPriorityQueue<K,V>::enqueue(const K& key, const V& value){
  if (isEmpty()){//If the vector is empty, just simply insert the key and value to the vector
    heap.push_back(PQEntry(key,value));
    size++;}
  else{//else insert the key and the value to the vector and make sure the first element is the largest one by using trickle up function
    heap.push_back(PQEntry(key,value));
    trickleUp(size);
    size++;
  }
    }
template<class K, class V>
 // Removes the best key from the heap and returns associated value
V HeapPriorityQueue<K,V>::dequeue(){
  if(isEmpty())
    return 0;
  else{
    V delItem=heap[0].value;//A variable temrorarily hold the deleted element from the vector
    heap[0]=PQEntry(heap[heap.size()-1].key,heap[heap.size()-1].value);//assign the last element to the first element
    heap.pop_back();//detete the last element
    trickleDown(0);
    size--;
    return delItem;//return the deleted value
  }
}

// Test for empty
template<class K, class V>
bool HeapPriorityQueue<K,V>::isEmpty() const{
  return heap.size()==0;//The vector is empty when the size of the vector is 0.
    };

 // When contents of queue (key/value pairs) using level-order traversal
template<class K, class V>
void HeapPriorityQueue<K,V>:: print() const{
  cout<<"content:"<<endl;
  int x=heap.size();
  for(int i=0;i<x;i++){
    cout<<heap[i].key<<" "<<heap[i].value<<endl;
  }
};

int main(){
  //Create a vector named heap 1
  HeapPriorityQueue <int,string> heap1;
  cout<<"------------------------------------------------------Test the isEmpty function when the vector is empty------------------------------------------------------"<<endl;
   if(heap1.isEmpty()){
    cout<<"The heap is empty"<<endl;
  }
   ifstream file("tickets.txt",ios::in);
    string name;
    int number;
    if(!file)
        cout<<"cannot open the file"<<endl;
    cout<<"----------------------------------------------------Reading from the file and insert each element to the vector-------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------Then print the content of the vector after each insertion-------------------------------------------------"<<endl;
    while(file>>number>>name){
        heap1.enqueue(number,name);
	heap1.print();
    }
   cout<<"------------------------------------------------------Test the isEmpty function after insertion------------------------------------------------------"<<endl;  
  if(!heap1.isEmpty()){
    cout<<"The heap is  not empty"<<endl;
  }
 cout<<"--------------------------Dequeue the vector one by one and print the content of the vector after each deletion---------------------------------------------"<<endl;  
  heap1.dequeue();
  heap1.print();
  heap1.dequeue();
  heap1.print();
  heap1.dequeue();
  heap1.print();
  heap1.dequeue();
  heap1.print();
  heap1.dequeue();
  heap1.print();
}
  
