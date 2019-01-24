#include "hash.h"
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

hashes::hashes()
{
  //init
}

hashes::~hashes()
{
  //deinit
}

void hashes::hashMain()
{
  cout << "Hash Map : " << endl;
  //traversal using iterator (unordered map)
  traversal();

  //insert,delete,find values from hashmap
  insertDeleteFind();

  //insert,delete,find values from dict/ordered hashmap
  dicInsertDeleteFind();

}

void hashes::insertDeleteFind()
{
  //unordered map o(1)
  unordered_map<string,int> umap;

  //both insert methods
  umap["apple"] = 10;
  umap["orange"] = 5;
  umap["duran"] = 13;
  umap["cherry"] = 3;
  umap.insert(make_pair("banana", 7));
  umap.insert(make_pair("kiwi", 4));
  umap.insert(make_pair("grape",18));
  umap.insert(make_pair("cantelope",11));

  //both delete methods
  unordered_map<string,int>::iterator it;
  it = umap.find("orange");
  umap.erase(it);

  umap.erase("cherry");

  //find element (Fast)
  cout << "searching example unordered_map : " << endl;
  string key = "orange";
  if(umap.find(key) == umap.end())
  {
    cout << key << " not in umap" << endl;
  }
  key = "grape";
  if(umap.find(key) != umap.end())
  {
    cout << key << " found in umap" << endl;
  }

}

void hashes::traversal()
{
  //unordered map o(1)
  unordered_map<string,int> umap;
  unordered_map<string,int>::iterator it;

  //both insert methods
  umap["apple"] = 10;
  umap["orange"] = 5;
  umap["duran"] = 13;
  umap["cherry"] = 3;
  umap.insert(make_pair("banana", 7));
  umap.insert(make_pair("kiwi", 4));
  umap.insert(make_pair("grape",18));
  umap.insert(make_pair("cantelope",11));

  //iterating over every key in unordered_map
  cout << "listing entire umap : " << endl;
  for(it = umap.begin(); it != umap.end(); it++)
  {
    cout << "key -> " << it->first << " | value -> " << it->second << endl;
  }


}

void hashes::dicInsertDeleteFind()
{
  //ordered map o(logn)
  map<string,int> omap;
  map<string,int>::iterator it;

  cout << "searching example map (dictionary) : " << endl;
  //both insert methods
  omap["apple"] = 10;
  omap["orange"] = 5;
  omap["duran"] = 13;
  omap["cherry"] = 3;
  omap.insert(make_pair("banana", 7));
  omap.insert(make_pair("kiwi", 4));
  omap.insert(make_pair("grape",18));
  omap.insert(make_pair("cantelope",11));

  //delete methods (iterator,direct)
  it = omap.find("orange");
  omap.erase(it);

  omap.erase("cherry");

  it = omap.find("kiwi");
  omap.erase(it,omap.end());

  string key = "cherry";
  if(omap.find(key) == omap.end())
  {
    cout << key << " not found in omap" << endl;
  }
  key = "grape";
  if(omap.find(key) != omap.end())
  {
    cout << key << " found in omap" << endl;
  }
}
