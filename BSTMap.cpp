//
//  BSTMap.cpp
//
//
//  Created by Xialinqiao on 2017-07-01.
//
//

#include "BSTMap.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//intert a node the tree
template<class K,class V>
bool BSTMap<K,V>::insert(const K& key, const V& value){
    if(isEmpty()){
        root=new treeNode(key,value,0,0);
        return true;
    }
    treeNode* p=root, *pre=nullptr;
    while(p!=nullptr){
        pre=p;
        if(p->nodeKey<key)
            p=p->right;
        else
            p=p->left;
        }
    if(pre->nodeKey<key)
        pre->right=new treeNode(key,value,0,0);
    else
        pre->left=new treeNode(key,value,0,0);


    }

//check if the map is empty
template<class K,class V>
bool BSTMap<K,V>::isEmpty()const{
       if(root==nullptr){
        return true;
    }
    else{
        return false;
    }
}
//print the content of the tree
template<class K,class V>
void BSTMap<K,V>::print() const{
    inorder(root);
    //cout<<root->left->nodeKey<<endl;
}
//inorder traversal
template<class K,class V>
void BSTMap<K,V>::inorder(treeNode* p)const{
    if(p!=nullptr){
        inorder(p->left);
        cout<<p->nodeKey<<":  "<<p->keyVal<<endl;
        inorder(p->right);
    }
}
//Search a node in the tree
template<class K,class V>
const V*  BSTMap<K,V>::search(const K& key) const{
    treeNode* p=root;
    while(p!=nullptr){
    if(p->nodeKey==key){
        cout<<"search results: "<<p->nodeKey<<" "<<p->keyVal<<endl;
        return &p->keyVal;
    }
    else if(p->nodeKey>key){
        p=p->left;
    }
    else if (p->nodeKey<key){
        p=p->right;
    }
    }
    if (p==nullptr){
        cout<<"The key word you entered was not found!"<<endl;
    }

}
//Delete a node form a tree
template<class K,class V>
bool BSTMap<K,V>::remove(const K& key){
    treeNode* p=root;
    treeNode* prev=nullptr;
    while(p!=nullptr){
        if(p->nodeKey==key)
           break;
           prev=p;
        if(p->nodeKey<key){
            p=p->right;
        }
        //if(p->nodeKey>key)
        else
        {
            p=p->left;
        }
    }
  //  cout<<"("<<p->nodeKey<<")"<<prev->nodeKey<<endl;
    if (p!=nullptr&&p->nodeKey==key){
      if (p==root)
        deleteByMerging(root);
      else if(prev->left==p)
        deleteByMerging(prev->left);
      else
        deleteByMerging(prev->right);
        return true;
          }
    else if (!isEmpty()){
        cout<<"The node you want to delete was not found"<<endl;
        return false;
    }
    else{
        cout<<"The tree is empty"<<endl;
        return false;
    }
}
//A delete by merging function
template<class K,class V>
void BSTMap<K,V>::deleteByMerging(treeNode*& node){
    treeNode* temp=node;
   if (node!=nullptr){
     if(node->right==nullptr)//no left child
        node=node->left;//go to right

     else if(node->left==nullptr){//no right child
        node=node->right;//go to left
    }
    // else if(node->right==nullptr&&node->left==nullptr){
      //   temp=node;
     //}
     else{
         temp=node->left;//temp points to node's left child;
         while(temp->right!=nullptr)
             temp=temp->right;//find the most right node of the left sub tree
         temp->right=node->right;
         temp=node;
         node=node->left;

     }
      delete temp;
    }

 }


//constructor
template<class K,class V>
BSTMap<K,V>::BSTMap():root(nullptr){
}


int main(){
    BSTMap <string,int > *map1=new BSTMap<string,int>();//create map1 name->phone
    BSTMap <int,string > *map2=new BSTMap<int,string>();//create map2 phone->name
   /*--------------------------Test empty function---------------------------------------------------------------------------*/
    if(map2->isEmpty())
        cout<<"map2 is empty!"<<endl;
    if (map1->isEmpty())
        cout<<"map1 is empty!"<<endl;
    ifstream file("phone.txt",ios::in);
    string name;
    int number;
    if(!file)
        cout<<"cannot open the file"<<endl;
    while(file>>name>>number){
        map1->insert(name,number);
      //  map2->insert(number,name);

    }
    map1->print();
    cout<<endl;
    map1->remove("Bob");//test delete function
  //  cout<<"map1 content after deletion>>"<<endl;
    map1->print();//print the content after deletion to check the functionality of the remove function
    //test map 2
    /*
    map2->print();
    map2->remove(359433);
    cout<<"map2 content after deletion>>"<<endl;
    map2->print();
    */
    return 0;
}
