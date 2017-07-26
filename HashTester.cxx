

#include "HashWithChaining.hxx"
#include "HashWithQuadratic.hxx"
#include <string>
#include<sstream>
#include <fstream>
using namespace std;
int main(int ac, char* av[])
{
  // Key is an integer for student ID
  // Value is a string representing the students' entire name

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 13579
  // FIXME
  std::function<int(int)> concatEven = [](int num){
    int hc = 0;
    int x =1 ;
    for(int i=0;i<5;i++){
      hc=hc+num%10*x;
      num=num/100;
      x=x*10;
    }
    return hc;
  };

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 2468
   std::function<int(int)> concatOdd =[](int num){
    int hc = 0;
    num=num/10;
    int x =1 ;
    for(int i=0;i<4;i++){
      hc=hc+num%10*x;
      num=num/100;
      x=x*10;
    }
    return hc;
   };  // concat even digits, chaining
  HashWithChaining<int,string> h1(concatEven);

  // concat even digits, quadratic probing
  HashWithQuadratic<int,string> h2(concatEven);

  // concat odd digits, chaining
  HashWithChaining<int,string> h3(concatOdd);

  // concat odd digits, quadratic probing
  HashWithQuadratic<int,string> h4(concatOdd);

  // Read data from input file, and do inserts's and find's,
  // and gather statistics ...
 int n=0;
std::ifstream student;
student.open("students.txt");
if (student.is_open()){
  int s_n;
  std::string name;

while(!student.eof()){
student>>s_n;
student>>name;
//Cerate chaining HTs and test insert functions
  h1.insert(s_n,name);
  h3.insert(s_n,name);
//create quadratic HTs and test insert functions
  h2.insert(s_n,name);
  h4.insert(s_n,name);
}
student.close();
}
//Test the print functions

  cout<<endl;
  cout<<"Content of hash table 1  after insertion(Chainning concatEven):"<<endl;
  h1.print();
  cout<<endl;
  cout<<"Content of hash table 3 after insertion(Chaining concatOdd):"<<endl;
  h3.print();
  cout<<endl;
  cout<<"Content of hash table 2  after insertion(Quadratic concatEven ):"<<endl;
  cout<<endl;
  h2.print();
  cout<<endl;
  cout<<"Content of hash table 4 after insertion:(Quadratic concatOdd)"<<endl;
  cout<<endl;
  h4.print();
  //Test the other function
  cout<<"----------------------------------------------------------------test find function of h1--------------------------------------------------"<<endl;
  cout<<"Total of keys examined after insertion in table 1:"<<endl;
  h1.totalKeysExamined();
  cout<<"Table 1 search results:"<<endl;
  cout<<"-----------------------"<<endl;
  h1.find(201573271);
  h1.find(123456789);//Search the item does not exist in the table
  cout<<"-----------------------"<<endl;
  cout<<"Loadfactor of table 1 after find function:"<<endl;
  h1.loadFactor();
  cout<<"Total of keys examined after find function called in table 1:"<<endl;
  h1.totalKeysExamined();
  cout<<"----------------------------------------------------------------test find function of h2--------------------------------------------------"<<endl;
  cout<<"Total of keys examined after insertion in table 2:"<<endl;
  h2.totalKeysExamined();
  cout<<"Table 2 search results:"<<endl;
  cout<<"-----------------------"<<endl;
  h2.find(201573271);
  h2.find(200748269);
  cout<<"-----------------------"<<endl;
  cout<<"Loadfactor of table 2:"<<endl;
  h2.loadFactor();
  cout<<"Total of keys examined in table 2:"<<endl;
  h2.totalKeysExamined();
  cout<<"----------------------------------------------------------------test find function of h3--------------------------------------------------"<<endl;
  cout<<"Total of keys examined after insertion in table 3:"<<endl;
  h3.totalKeysExamined();
  cout<<"Table 3 search results:"<<endl;
  cout<<"-----------------------"<<endl;
  h3.find(201573271);
  h3.find(201459196);
  cout<<"-----------------------"<<endl;
  cout<<"Loadfactor of table 3:"<<endl;
  h3.loadFactor();
  cout<<"Total of keys examined after find function called in table 3:"<<endl;
  h3.totalKeysExamined();
  cout<<"----------------------------------------------------------------test find function of h4--------------------------------------------------"<<endl;
  cout<<"Total of keys examined after insertion in table 4:"<<endl;
  h4.totalKeysExamined();
  cout<<"Table 4 search results:"<<endl;
  cout<<"-----------------------"<<endl;
  h4.find(123456789);//Search the key Doesnot exist in the table!
  h4.find(200860451);
  cout<<"-----------------------"<<endl;
  cout<<"Loadfactor of table 4:"<<endl;
  h4.loadFactor();
  cout<<"Total of keys examined after find funtion called in table 4:"<<endl;
  h4.totalKeysExamined();

}

