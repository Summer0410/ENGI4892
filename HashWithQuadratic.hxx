#ifndef __HASH_WITH_QUADRATIC_
#define __HASH_WITH_QUADRATIC_

#include "HashTable.hxx"

/**
 * This class uses open-addressing, specifically quadratic probing to
 * resolve collisions.
 */

template<class K, class V>
class HashWithQuadratic : public HashTable<K,V>
{
  public:
    HashWithQuadratic<K,V>(std::function<int(K)> hc)
      : hashcode(hc), size(0) {
      for(int i=0;i<capacity;i++)
	data[i]=nullptr;
    }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
  {  
    int index =hashcode(key)%capacity;//get the index of the key
    if(data[index]==nullptr){//The position is empty we directly insert the element
	size++;
	insert1++;
  	data[index]=new HTEntry(key,value);
      }
      else{
	int i=1;
	while(data[index]!=nullptr){
	  index=index+i*i;//keep checking the next available position
	     insert1++;
	     if(data[index]!=nullptr)
	       index=index-i*i;//Kepp checking the next available position
	     insert1++;
	     i++;
	}
	size++;
       	data[index]= new HTEntry(key,value);//insert the element when find the available position
	  }
      return true;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
  {
      int index =hashcode(key)%capacity;
      if (data[index]==nullptr){//If the place we are checking is empty, return nullptr.
	cout<<"Opps! No such stdeunt!"<<endl;
	return nullptr;
      }
      else if(data[index]->key==key){
	lookup ++;//increase the lookup value
        cout<<data[index]->key<<"  "<<data[index]->value<<endl;//print out the value
	return &data[index]->value;
      }
      else{
	cout<<"right path"<<endl;
		int i=1;
	while(data[index]->key!=key&&index<211&&index>-1){
              index=index+i*i;
	      lookup++;//increase key examined by one
	      if(data[index]->key!=key){
		index=index-i*i;}
	      i++;
	      lookup++;
	}
	if(index<0||index>210){
	  cout<<"Quadratic: no such student!"<<endl;
	  return nullptr;
	}
       else{
        cout<<data[index]->key<<data[index]->value<<endl;//print out the value
        return &data[index]->value;
	}
      } 	
    }

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      float A = size;
      float factor=A/capacity;
      cout<<factor<<endl;
      return factor;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override{
      int examined=insert1+lookup;//Totally examied keys during insertion and search
      cout<<examined<<endl;
      return examined;
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
  void print() const override//travse the hashtable and print the content
  {
      for(int i=0;i<capacity;i++){
	if(data[i]!=nullptr){
	  cout<<data[i]->key<<"  "<<data[i]->value<<endl;
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

    // An array of type 'HTEntry' pointers (nullptr indicates that the
    // position is empty)
    HTEntry* data[capacity];
    int size;
    int lookup=0;//a couner to calculate how many key lookups happened during search
    int insert1=0;
};

#endif
