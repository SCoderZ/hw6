#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
#include <set>


struct IntHash2 {
    // size_t size;
    IntHash2() {}
    HASH_INDEX_T operator()(const int& k) const
    {
        return k;
    }
};
using namespace std;
int main()
{
  /* DoubleHashProber<std::string, MyStringHash > dh;
  HashTable<
  std::string, 
  int, 
  DoubleHashProber<std::string, MyStringHash >, 
  std::hash<std::string>, 
  std::equal_to<std::string> > ht(0.7, dh); */


  // This is just arbitrary code. Change it to test whatever you like about your 
  // hash table implementation.
  /* for(size_t i = 0; i < 10; i++){
    std::stringstream ss;
    ss << "hi" << i;
    ht.reportAll(cout);
    ht.insert({ss.str(), i});
  }
  if( ht.find("hi1") != nullptr ){
    cout << "Found hi1" << endl;
    ht["hi1"] += 1;
    cout << "Incremented hi1's value to: " << ht["hi1"] << endl;
  }
  if( ht.find("doesnotexist") == nullptr ){
    cout << "Did not find: doesnotexist" << endl;
  }
  cout << "HT size: " << ht.size() << endl;
  ht.remove("hi7");
  ht.remove("hi9");
  cout << "HT size: " << ht.size() << endl;
  if( ht.find("hi9") != nullptr ){
    cout << "Found hi9" << endl;
  }
  else {
    cout << "Did not find hi9" << endl;
  }
  ht.insert({"hi7",17});
  cout << "size: " << ht.size() << endl;
  return 0; */
//Reach the default alpha factor of .4 (5 items /11 items = .45) to force a resize
/* pair<string, int> pair1("one", 1);
    pair<string, int> pair2("two", 2);
    pair<string, int> pair3("three", 3);
    pair<string, int> nonExistantPair("cat", 25);
    HashTable<string, int, DoubleHashProber<string, std::hash<string>>, hash<string>, equal_to<string> > ht;
    set<pair<string, int>> items;
    //Insert Items
    ht.insert(pair1);
    ht.insert(pair2);
    ht.insert(pair3);
    items.insert(pair1);
    items.insert(pair2);
    items.insert(pair3);
    // EXPECT_TRUE(verifyItems(ht, items));
  ht.reportAll(cout);
  cout << endl;
    //Try removing non-existant items
  cout << ht.size() << endl;
    ht.remove("cat");
  ht.reportAll(cout);
  cout << endl;
  cout << ht.size() << endl; */
/* HashTable<string, int, LinearProber<string>, hash<string>, equal_to<string> > ht;
    set<pair<string, int>> items;
    //Insert (one, 1)
    pair<string, int> pair1("one", 1);
    ht.insert(pair1);
    items.insert(pair1);
  ht.reportAll(cout);
  cout << endl;
  cout << ht.size() << endl;
    // EXPECT_TRUE(verifyItems(ht, items));
    //Insert (two, 2)
    pair<string, int> pair2("two", 2);
    ht.insert(pair2);
    items.insert(pair2);
  ht.reportAll(cout);
  cout << endl;
  cout << ht.size() << endl;
    // EXPECT_TRUE(verifyItems(ht, items));
    //Insert (three, 3)
    pair<string, int> pair3("three", 3);
    ht.insert(pair3);
    items.insert(pair3);
    // EXPECT_TRUE(verifyItems(ht, items));
  ht.reportAll(cout);
  cout << endl;
  cout << ht.size() << endl; */
double loadfactor = 0.6;
    const vector<int> sizemap =
    {
        11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421
    };
    HashTable<int, int, LinearProber<int>, IntHash2, equal_to<int>> ht(loadfactor, LinearProber<int>(), IntHash2());
    set<pair<int, int>> items;
    for(size_t i = 0;i<sizemap.size()-1;i++){
    cout << "#######" << endl;
        int min = (int)floor(sizemap[i]*loadfactor);
        for(int j = 0; j<=min/2;j++){
            pair<int,int> pair(j,j);
            //insert then delete
            ht.insert(pair);
            ht.remove(j);
            // EXPECT_TRUE(ht.find(j) == nullptr);
        }
  ht.reportAll(cout);
  cout << "Before" << ht.size() << endl;
        // EXPECT_EQ(ht.size(),0);
        //reinsert the same pair, loc should change
    cout << "n:" << (min-(min/2)) << endl;
        for(int j = 0; j<(min-(min/2));j++){
            pair<int,int> pair(j,j);
            //insert again
            ht.insert(pair);
            items.insert(pair);
            // EXPECT_EQ(ht.probe(j),(min/2)+1+j);
        }
  ht.reportAll(cout);
  cout << ht.size() << endl;
  cout << endl;
        // EXPECT_EQ(ht.table_.size(),sizemap[i]);
        // EXPECT_EQ(ht.size(),items.size());
//add another should resize/rehash
        pair<int,int> pair((min/2)+1,(min/2)+1);
        ht.insert(pair);
        items.insert(pair);
        // EXPECT_EQ(ht.table_.size(),sizemap[i+1]);
        // EXPECT_EQ(ht.size(),items.size());
        //should be put into the correct spot, now that
        //the "deleted" items are actually "deleted" when resizing
        for(int j = 0; j<=(min/2+1);j++){
            // EXPECT_EQ(ht.probe(j),j);
        }
    }
    // EXPECT_TRUE(verifyItems(ht, items));
}
