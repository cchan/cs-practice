/*
A simple implementation of PageRank.
  * pagerank is useful because we have all these relations 
  between pages, and it would be nice to solve for all these 
  reputation contributions exactly, but inverting 1Mx1M matrices
  is hard.
*/

#include <iostream>
#include <vector>
#include <random>
using namespace std;

//singleton rng
std::random_device rd;
std::mt19937_64 gen(rd());

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
    uniform_int_distribution<int> dist(0, links.size()-1);
    return links[dist(gen)]; //precedence: subscript operator > deref operator
  }
};

void pageRank(vector<Page> www){
  uniform_int_distribution<int> distWWW(0, www.size()-1);
  uniform_real_distribution<double> dist01(0.0,1.0);
  
  const int iterations = 10000;
  const double delta = 1.0;
  Page* currentPage = &www[distWWW(gen)];
  
  for(int i = 0; i < iterations; i++){
    currentPage->visit();
    //cout << currentPage->getVisits() << " ";
    if(dist01(gen) < delta)
      currentPage = currentPage->getRandomPage();
    else
      currentPage = &www[distWWW(gen)];
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
