#pragma once
#include "Tokenizator.h"
#include <iostream>

class Lexer
{ 
public:

  void init();

  void Disassemble(std::ifstream& file);

private:

  Tokenizator MakeToken;
  PrepToken readyToken;
  std::vector<PrepToken> ready_to_send_Tokens;
  bool ready_to_tokenization = false;
  unsigned long line;
  unsigned long pos;
  char c;
};