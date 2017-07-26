#ifndef __HASH_WITH_CHAINING_
#define __HASH_WITH_CHAINING_

#include <vector>
#include "HashTable.hxx"
using namespace std;
#include <iostream>

/**
 * This class uses separate chaining as described in class, but instead
 * of using linked lists, it uses vectors.
 * The idea and complexity is the same, but you're probably more accustomed
 * to using vectors vs. linked lists.
 */

template<class K, class V>
class HashWithChaining : public HashTable<K,V>
{
  public:
    // c'tor (initializes hashcode lambda function and size)
    HashWithChaining(std::function<int(K)> hc) : hashcode(hc), size(0) { }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {  
      int index =hashcode(key)%10;//I decided to set the size of array as 10 because it's easy to check
      data[index].push_back( HTEntry(key,value));
      insert1++;
      size++;
      return true;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
    {
      int index=hashcode(key)%10;
      if(index<capacity){
	for(int i=0; i<data[index].size();i++){
        if((data[index][i]).key==key){
	   lookup++;
	   cout<<data[index][i].key<<"  "<<data[index][i].value<<endl;
           return &data[index][i].value;
	}
	lookup++;
      }
      cout<<"The result was not found!"<<endl;
      return nullptr;
     }
    }

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      float newSize=size;
      cout<<newSize/10<<endl;//I made the size of the array 10, since I think 211 is too big in this case
      return newSize/10;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override
    {
      int examined=lookup+insert1;
      cout<<examined<<endl;
      return examined;
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {
      for(int i=0;i<10;i++){
	cout<<endl;
	cout<<"table"<<i<<": "<<endl;
	cout<<endl;
	for(int j=0; j<data[i].size();j++){
          cout<<data[i][j].key<<"   "<<data[i][j].value<<endl;
	}
      }
    }

  private:
    static constexpr int capacity = 211;
    std::function<int(K)> hashcode;
    // Contains key/value pairs for the hashtable
    struct HTEntry {
      K key;
      V value;
      HTEntry(const K& k = K(), const V& v = V()) : key(k), value(v) { }
    };

    // A bucket array of vectors (each vector contains type 'HTEntry')
    vector<HTEntry> data[capacity];
    int size;
    int insert1=0;
    int lookup=0;
};

#endif
