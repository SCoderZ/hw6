#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
  HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
  MyStringHash(bool debug = true)
  {
    if(false == debug){
      generateRValues();
    }
  }


  // For k = less-than-or-equal-to-6-letter word
  HASH_INDEX_T sixToDec(const std::string& k) const {
    unsigned long long wi = letterDigitToNumber(k[0]);
    for (unsigned int i = 1; i < k.size(); i++) {
      wi *= 36;
      wi += letterDigitToNumber(k[i]);
    }
    return wi;
  }
  // hash function entry point (i.e. this is h(k))
  HASH_INDEX_T operator()(const std::string& k) const
  {
    // i indicates the index

    int i = 4;
    if (k.size() <= 6) {
      // std::cout << "w[" << i <<"]" << sixToDec(k) << std::endl;
      return rValues[i] * sixToDec(k);
    } else {
      HASH_INDEX_T h = 0;
      int j = k.size() - 6;

      // std::cout << "w[" << i <<"]" << sixToDec(k.substr(j)) << std::endl;
      h += rValues[i] * sixToDec(k.substr(j));

      i--;
      while (j >= 6) {
        const std::string prev = k.substr(j - 6, 6);
        // std::cout << "w[" << i <<"]" << sixToDec(prev) << std::endl;
        h += rValues[i] * sixToDec(prev);
        j -= 6;
        i--;
      }

      if (j < 6 && j != 0) {
        return h + rValues[i] * sixToDec(k.substr(0, j));
      } else { // j == 0
        return h;
      }
    }
  }

  // A likely helper function is to convert a-z,0-9 to an integral value 0-35
  HASH_INDEX_T letterDigitToNumber(char letter) const
  {
    if (65 <= letter && letter <= 90) {
      char lower = tolower(letter);
      return lower - 97;
    } else if (97 <= letter && letter <= 122) {
      return letter - 97;
    } else if (48 <= letter && letter <= 57) {
      return letter - 22;
    }
  }

  // Code to generate the random R values
  void generateRValues()
  {
    // obtain a seed from the system clock:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator (seed);  // mt19937 is a standard random number generator

    // Simply call generator() [it has an operator()] to get another random number
    for(int i{ 0 }; i < 5; ++i)
    {
      rValues[i] = generator();
    }
  }
};

#endif
