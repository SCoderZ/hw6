#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
#include <set>
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
    HashTable<string, int, DoubleHashProber<string, std::hash<string>>, hash<string>, equal_to<string> > ht;
    set<pair<string, int>> items;
    for(int i = 0; i < 5; i++) {
        pair<string, int> newItem(to_string(i), i);
        ht.insert(newItem);
        items.insert(newItem);
    }
    // EXPECT_EQ(ht.table_.size(), 11);
  cout << "size:" << ht.size() << endl;
  ht.reportAll(cout);
  cout << endl;
    //add another item should resize
    pair<string,int> newItem(to_string(5),5);
    ht.insert(newItem);
    items.insert(newItem);
    // EXPECT_EQ(ht.table_.size(), 23);
  cout << "size:" << ht.size() << endl;
  ht.reportAll(cout);
  cout << endl;
    //check that all the items are still there
    // EXPECT_TRUE(verifyItems(ht, items));
  ht.reportAll(cout);
  cout << endl;

}
