
#include <vector>
using namespace std;
#include "HeapPriorityQueue.hxx"
#include <iostream>
template<class K, class V>

void  HeapPriorityQueue<K,V>::enqueue(const K& key, const V& value){
  if (isEmpty()){
    heap.push_back(PQEntry(key,value));
    size++;}
  else{
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
 V delItem=heap[0].value;
  heap[0]=PQEntry(heap[heap.size()-1].key,heap[heap.size()-1].value);
  cout<<heap[0].key<<heap[0].value<<endl;
  heap.pop_back();
  trickleDown(0);
  size--;
  return delItem;
  }
}

    // Test for empty
template<class K, class V>
bool HeapPriorityQueue<K,V>::isEmpty() const{
  return heap.size()==0;
    };

    // Prints contents of queue (key/value pairs) using level-order traversal
template<class K, class V>
void HeapPriorityQueue<K,V>:: print() const{
  cout<<"content:"<<endl;
  for(int i=0;i<heap.size();i++){
    cout<<heap[i].key<<heap[i].value<<endl;
  }

};

int main(){
  HeapPriorityQueue <int,string> heap1;
   if(heap1.isEmpty()){
    cout<<"The heap is empty"<<endl;
  }
  heap1.enqueue(2014,"kat");
  heap1.print();
   heap1.enqueue(2013,"Linda");
     heap1.print();
    heap1.enqueue(2016,"Ryan");
 heap1.print();
    heap1.enqueue(2017,"Anna");
      heap1.print();
      heap1.enqueue(2019,"Summer");
      heap1.print();
  if(!heap1.isEmpty()){
    cout<<"The heap is  not empty"<<endl;
  }
 heap1.dequeue();
 heap1.dequeue();
 heap1.print();
}
  
