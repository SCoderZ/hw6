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
pair<string, int> pair1("one", 1);
    pair<string, int> pair2("two", 2);
    pair<string, int> pair3("three", 3);
    HashTable<string, int, DoubleHashProber<string, std::hash<string>>, hash<string>, equal_to<string> > ht;
    set<pair<string, int>> items;
    //Insert Items
    ht.insert(pair1);
    ht.insert(pair2);
    ht.insert(pair3);
    items.insert(pair1);
    items.insert(pair2);
    items.insert(pair3);
  ht.reportAll(cout);
  cout << endl;
  cout << ht.size() << endl;
    // EXPECT_TRUE(verifyItems(ht, items));
    //Remove Items
    ht.remove(pair1.first);
    items.erase(pair1);
  ht.reportAll(cout);
  cout << endl;
  cout << ht.size() << endl;
    // EXPECT_TRUE(verifyItems(ht, items));
    ht.remove(pair3.first);
    items.erase(pair3);
  ht.reportAll(cout);
  cout << endl;
  cout << ht.size() << endl;
    // EXPECT_TRUE(verifyItems(ht, items));
    ht.remove(pair2.first);
    items.erase(pair2);
  ht.reportAll(cout);
  cout << endl;
  cout << ht.size() << endl;
    // EXPECT_TRUE(verifyItems(ht, items));
}
