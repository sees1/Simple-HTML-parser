#include <iomanip>
#include <fstream>
#include "Lexer.h"

void Lexer::init()
{
  MakeToken.init();
  line = 1;
  pos = 1;
  ready_to_tokenization = true;
}

void Lexer::Disassemble(std::ifstream& file)
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

