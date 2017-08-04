#include "EdgeListGraph.hxx"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeListGraph::EdgeListGraph(const VertexCollection& v,const EdgeCollection& e)
//Time complexity: O(1)
{
  myVertices = v;
  myEdges = e;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
VertexCollection EdgeListGraph::vertices() const
//Time complexity:O(n)
{
  return myVertices;   
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Time complexity:O(1)
EdgeCollection EdgeListGraph::edges() const
{
  return myEdges;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Time complexity: O(n)
EdgeCollection EdgeListGraph::incidentEdges(const Vertex& v) const
{ EdgeCollection edges;
  for(int i=0;i<myEdges.size();i++){//traverse through the edge vector
    if( myEdges[i].contains(v))//To check which edges are conected to the vertex.
      edges.push_back(myEdges[i]) ;//Store the edges
  }
  return edges;//return the edges
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Time complexity:O(n)
bool EdgeListGraph::areAdjacent(const Vertex& v, const Vertex& w) const
{
  for(int i=0;i<myEdges.size();i++){                      //Traverse though the edge vector to see which edges are connected to the two vectors
    if(myEdges[i].contains(v)&&myEdges[i].contains(w))  
      return true;                                       //if found, return true
    else
      return false;                                      //return false if not found
  }
}

 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Time complexicty:O(1)
bool EdgeListGraph::insertVertex(const Vertex& v)
{
  myVertices.push_back(v);                                 //Add the vertex to the vertices vector
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Time complexity:O(n)
bool EdgeListGraph::removeVertex(const Vertex& v)
{ EdgeCollection edge;                            //Initialize a local variable of EdgeCollection type
  VertexCollection vertex;                        //Initialize a local variable of VertexCollectiob type
  for(int i=0;i<myEdges.size();i++){              //Traverse through the edge vector 
    if(!myEdges[i].contains(v)){                  //If the current edge is not connected to the vertex
      edge.push_back(myEdges[i]);                 //Store it in a vector. in other words,edges connected to the vector to be deleted are not contained
    }
  }
      myEdges = edge;                            //myEdges only contains edges that are not connected to the given vertex

    for(int i=0;i<myVertices.size();i++){
      if(myVertices[i]==v){
	myVertices.erase(myVertices.begin()+i);  //Finally delete the vertex
        return true;                             //return true
      }
    }
    return false;                                //else return false
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Time complexity: O(n)
bool EdgeListGraph::insertEdge(const Edge& e){
  bool foundEdge = false;                     //These first afew lines check is the edge already exists in the list
  for(int i = 0;i<myEdges.size();i++){
    if( myEdges[i] == e)
      foundEdge= true;
  }
  if(foundEdge==true)   //If it does, return false, insertion not completed
    return false;
  //If the edge does not exist in the list, so we need to insert the edge
  else{                 
    bool found1=false;   //initialize two bool type variables to check if the two vertices connected to the edge exist in the list
    bool found2=false;
    VertexCollection vertex = e.endVertices();//Store the two vertices connected to the edge in a new vector
    int i=0;
    while(i<myVertices.size()){
      if (myVertices[i]==vertex[0])
	found1=true;                     //if found, found1 becomes true
      if (myVertices[i]==vertex[1])
	found2=true;                    //if found, found2 becomes true
      i++;                              //update the counter
       }
    if(!found1&&!found2){               //if both vertices are not found in the list
      myVertices.push_back(vertex[0]);   //insert both vertices
      myVertices.push_back(vertex[1]);
      myEdges.push_back(e);             //Insert the edge
  }
    else if(found1&&!found2){           //If only the second one is not in the list, insert it to the list
      myVertices.push_back(vertex[1]);
      myEdges.push_back(e);             //insert the edge
  }
    else if(!found1&&found2){           //If only the first one is not in the list, insert it to the list
      myVertices.push_back(vertex[0]);
      myEdges.push_back(e);             // insert the edge
    }
    else{
      myEdges.push_back(e);             //if both alreay exist in the list, only need to insert the edge
  }
   
    return true;                          //Insertion was successful
 }
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeEdge(const Edge& e)
//Time Complexity:O(n)
{
  bool exist = false;                 //to check if the edge exists in the list
  for(int i=0;i<myEdges.size();i++){
    if(myEdges[i]==e)
      exist=true;
  }
  if(exist){                           // if exist, delete the edge
      for(int i=0;i<myEdges.size();i++){
     if(myEdges[i]==e)
       myEdges.erase(myEdges.begin()+i);
   }
      return true;                     //retrun true if deletion was successful 
  }
  return false;                        //return true if deletion was not successful
}
