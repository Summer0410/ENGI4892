#ifndef __PRIORITYQUEUE_HXX_
#define __PRIORITYQUEUE_HXX_

#include <vector>
using namespace std;
#include "PriorityQueue.hxx"
#include<iostream>
template<class K, class V>
class HeapPriorityQueue : public PriorityQueue<K,V>
{
  public:
    HeapPriorityQueue()  = default;
    ~HeapPriorityQueue() = default;

    // Adds the key/value pair to the internal heap
    void enqueue(const K& key, const V& value) override;

    // Removes the best key from the heap and returns associated value
    V dequeue() override;

    // Test for empty
    bool isEmpty() const override;

    // Prints contents of queue (key/value pairs) using level-order traversal
    void print() const override;

  private:
    // Auxiliary methods to re-heapify the heap
  void trickleUp(int idx){
    int index=(idx-1)/2;
   if(heap[idx].key>heap[index].key&&idx>=0){
      PQEntry temp=PQEntry(heap[idx].key,heap[idx].value);
      heap[idx]=PQEntry(heap[index].key,heap[index].value);
      heap[index]=PQEntry(temp.key,temp.value);
      trickleUp(index);	 
    }
  }
  void trickleDown(int idx){
   
    int child1=idx*2+1;
    int child2=idx*2+2;
    if(child1<heap.size()-1&&child1<heap.size()-1){
    if(heap[child1].key>heap[child2].key&&heap[idx].key<heap[child1].key){
     PQEntry temp=PQEntry(heap[child1].key,heap[child1].value);
     heap[child1]=PQEntry(heap[idx].key,heap[idx].value);
     heap[idx]=temp;
     cout<<"new root:"<<endl;
     cout<<heap[idx].key<<endl;
      cout<<"new 1:"<<endl;
     cout<<heap[child1].key<<endl;
     //trickleDown(child1);
    }
   else if(heap[child2].key>heap[child1].key&&heap[idx].key<heap[child2].key){
     PQEntry temp=PQEntry(heap[child2].key,heap[child2].value);
     heap[child2]=PQEntry(heap[idx].key,heap[idx].value);
     heap[idx]=temp;
     trickleDown(child2);
    }
    else
      return;
   }
    else
      return;
 
  }

    // The contents of the priority queue (a key/value pair)
    // 'key' is used for priority, 'value' is the relevant data
    struct PQEntry
    {
      K key;
      V value;

      PQEntry(const K& k, const V& v) : key(k), value(v) { }
    };

    // We use a vector so we don't have to worry about running
    // out of space
    std::vector<PQEntry> heap;
   int size=0;
};

#endif
