#pragma once
#include "buffer.h"
#include <vector>

enum Token {
  END = 1<<0, TEXT = 1<<1, OPENING_BLOCK_TAG_NAME = 1<<2,
  CLOSING_BLOCK_TAG_NAME = 1<<3, EMPTY_TAG_NAME = 1<<4,
  COMMENT = 1<<5, MACRO_TAG = 1<<6, ATTRIBUTE_NAME = 1<<7,
  UNQUOTED_ATTRIBUTE_VALUE = 1<<7, SINGLE_QUOTED_ATTRIBUTE_VALUE = 1<<8,
  DOUBLE_QUOTED_ATTRIBUTE_VALUE = 1<<9
};

struct PrepToken
{
  Token lhs;
  std::string rhs;
};

class Tokenizator
{
public:

  void init();

  PrepToken Tokenization (char c);

private:
  Buffer buffer;
  std::vector <Token> token_seq;
  std::string error_message;
  Token current_token_type;
};