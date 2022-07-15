#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

enum Token = {
  END = 1<<0, TEXT = 1<<1, OPENING_BLOCK_TAG_NAME = 1<<2,
  CLOSING_BLOCK_TAG_NAME = 1<<3, EMPTY_TAG_NAME = 1<<4,
  COMMENT = 1<<5, MACRO_TAG = 1<<6, ATTRIBUTE_NAME = 1<<7,
  UNQUOTED_ATTRIBUTE_VALUE = 1<<7, SINGLE_QUOTED_ATTRIBUTE_VALUE = 1<<8,
  DOUBLE_QUOTED_ATTRIBUTE_VALUE = 1<<9
}

struct PrepToken
{
  Token lhs;
  std::string rhs;
};

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
  }

  void getChar(char c)
  {
    if (c == ' ' || c == '?' || c == '-') 
    {
      isEnd = true;
      //нужно написать функцию либо выделения новой памяти, либо очистки старой
      return;
    }else {
      *(buffer + bufCounter) = c;
      bufCounter++;
    }
  }

  bool isFully()
  {
    return isEnd;
  }

  std::string getBuff()
  {
    
  }

private:
  bool isEnd;
  uint8_t bufCounter;
  char* buffer;
};

class Tokenizator
{
public:

  void init()
  {
    current_token_type = static_cast<int>(TEXT);
  }

  prepToken Tokenization (char c)
  {
    switch (current_token_type)
    {
      case TEXT:
      {
        if (c == '>')
        {
          error_message = "unexpected ending!";
          throw std::runtime_error(error_message);
        }else if (c == '<'){
          current_token_type = OPENING_BLOCK_TAG_NAME | CLOSING_BLOCK_TAG_NAME | EMPTY_TAG_NAME | COMMENT | MACRO_TEG;
        }else{
          buffer.getChar(c)
          if(buffer.isFully()){

          }
          current_token_type = TEXT;
        }

      

        break;
      }
      case OPENING_BLOCK_TAG_NAME | CLOSING_BLOCK_TAG_NAME | EMPTY_TAG_NAME | COMMENT | MACRO_TEG:
      {
        if (c == ' ') current_token_type = OPENING_BLOCK_TAG_NAME;
        if (c == '/') current_token_type = CLOSING_BLOCK_TAG_NAME;
        if (c == '!') current_token_type = EMPTY_TAG_NAME | COMMENT;
        if (c == '?') current_token_type = MACRO_TEG;
      }
      case EMPTY_TAG_NAME | COMMENT:
      {
        if (c == '-') current_token_type = COMMENT;
        else current_token_type = EMPTY_TAG_NAME;
      }
      case COMMENT:
      {
        if (c == '-') 
        {
          current_token_type = TEXT;
          buffer.add(COMMENT);
        }
      }
    }
  }

private:
  Buffer buffer;
  std::string error_message;
  size_t current_token_type;
  std::string buffer;
};

class Lexer
{ 
public:

  void init()
  {
    MakeToken.init();
    line = 1;
    pos = 1;
    ready_to_tokenization = true;
  }

  void Disassemble(ifstream& file)
  {
    if(ready_to_tokenization == false) { std::cout << "make initalization of lexer first!";return;}

    try
    {
      while ((c = file.get()) != EOF)
        {
          if (c != '\n')
          {
            pos++;
            readyToken = MakeToken.Tokenization(c);
            if(readyToken.lhs == END)
            {
              ready_to_send_Tokens.push_back(readyToken);
            }
          }else{
            pos = 1;
            line++;
          }
        }
    }catch(std::exception& e){

    }

  }

private:

  Tokenizator MakeToken;
  PrepToken readyToken;
  std::vector<PrepToken> ready_to_send_Tokens;
  bool ready_to_tokenization = false;
  unsigned long line;
  unsigned long pos;
  char c;
};

class SynatAnalyzator{

};

