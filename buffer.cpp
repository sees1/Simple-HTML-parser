#include "buffer.h"

void Buffer::pushChar(char c)
{
  if (c == ' ' || c == '?' || c == '-') 
  {
    isEnd = true;
    delete [] buffer;
    buffer = new char [256];
    return;
  }else {
    *(buffer + bufCounter) = c;
    bufCounter++;
  }
}

bool Buffer::isFully()
{
  return isEnd;
}

std::string Buffer::getBuff()
{
  String_buff.assign(const_cast<const char*>(buffer),bufCounter);
  return String_buff;
}
