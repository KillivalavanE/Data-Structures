#include<bits/stdc++.h>
using namespace std ;
class graph
{
int V;
list<int> *l;
public:
graph(int V)
{
this->V = V;
l = new list<int>[V] ;
}
void add(int i,int j)
{
l[i].push_back(j) ;
l[j].push_back(i) ;
}
void print()
{
for(int i=0;i<V;i++)
{
cout<<"vertex "<<i<<"->";
for(int nbr:l[i])
{
cout<<nbr<<",";
}
cout<<endl;
}
}
};
int main()
{
graph g(5) ;
g.add(0,1) ;
g.add(0,2) ;
g.add(2,3 );
g.add(1,4) ;
g.add(3,4) ;

g.print();
return 0 ;
}