/*
A simple implementation of PageRank.
  * pagerank is useful because we have all these relations 
  between pages, and it would be nice to solve for all these 
  reputation contributions exactly, but finding eigenvalues 
  for big matrices is hard.
*/

#include <iostream>
#include <vector>
#include "randutils.hpp"
using namespace std;

randutils::mt19937_rng rng;

class Page{
private:
  int visits = 0;
  vector<Page*> links;
public:
  Page(){}
  int resetVisits(){visits = 0;}
  int getVisits(){return visits;}
  void visit(){visits++;}
  void linkTo(Page& p){
    links.push_back(&p);
  }
  Page* getRandomPage(){
    return links[rng.uniform(0, links.size()-1)];
  }
};

void pageRank(vector<Page> www){
  const int iterations = 10000;
  const double delta = 1.0;
  Page* currentPage = &www[rng.uniform(0, www.size()-1)];
  
  for(int i = 0; i < iterations; i++){
    currentPage->visit();
    //cout << currentPage->getVisits() << " ";
    if(rng.uniform(0.0, 1.0) < delta)
      currentPage = currentPage->getRandomPage();
    else
      currentPage = &www[rng.uniform(0, www.size()-1)];
  }
}

int main(){
  vector<Page> www(3);
  www[0].linkTo(www[1]);
  www[0].linkTo(www[2]);
  www[1].linkTo(www[2]);
  www[2].linkTo(www[0]);
  
  pageRank(www);
  
  for(int i = 0; i < www.size(); i++)
    cout << i << ": " << www[i].getVisits() << endl;
}
