#pragma once
#include <string>

class Buffer
{
public:

  Buffer():bufCounter(0),isEnd(false)
  {
    buffer = new char [256];
  }

  ~Buffer()
  {
    delete [] buffer;
    buffer = nullptr;
  }

  void pushChar(char c);

  bool isFully();

  std::string getBuff();

private:
  bool isEnd;
  uint8_t bufCounter;
  std::string String_buff;
  char* buffer;
};