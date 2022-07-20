#include "Tokenizator.h"
#include <stdexcept>

void Tokenizator::init()
{
  current_token_type = static_cast<int>(TEXT);
}

PrepToken Tokenizator::Tokenization (char c)
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
        current_token_type = OPENING_BLOCK_TAG_NAME | CLOSING_BLOCK_TAG_NAME | EMPTY_TAG_NAME | COMMENT | MACRO_TAG;
        token_seq.push_back(current_token_type);
      }else{
        buffer.pushChar(c);
        if(buffer.isFully())
        {
          return (token_seq.back(),buffer.getBuff())
        }
        current_token_type = TEXT;
      }

      if(current_token_type != TEXT)
      {
        current_token_type = token_seq.back()
      }

      break;
    }
    case OPENING_BLOCK_TAG_NAME | CLOSING_BLOCK_TAG_NAME | EMPTY_TAG_NAME | COMMENT | MACRO_TAG:
    {
      if (c == ' ') 
      {
        current_token_type = OPENING_BLOCK_TAG_NAME;
        token_seq.push_back(current_token_type);
      }
      if (c == '/')
      {
        current_token_type = CLOSING_BLOCK_TAG_NAME;
        token_seq.push_back(current_token_type);
      } 
      if (c == '!') current_token_type = EMPTY_TAG_NAME | COMMENT;
      if (c == '?')
      {
        current_token_type = MACRO_TAG;
        token_seq.push_back(current_token_type);
      } 
    }
    case OPENING_BLOCK_TAG_NAME:
    {
      if (c == ' ')
      {
        current_token_type = OPENING_BLOCK_TAG_NAME;
        token_seq.push_back(current_token_type);
      }else if (c == '>'){
        return;
      }else{
        current_token_type = TEXT | ATTRIBUTE_NAME; 
      }
    }
    case TEXT | ATTRIBUTE_NAME:
    {
      if()
    }
    case CLOSING_BLOCK_TAG_NAME:
    {
      current_token_type = TEXT;
    }
    case EMPTY_TAG_NAME | COMMENT:
    {
      if (c == '-') 
      {
        current_token_type = COMMENT;
        token_seq.push_back(current_token_type);
      }else{
        current_token_type = EMPTY_TAG_NAME;
        token_seq.push_back(current_token_type);
      } 
    }
    case COMMENT:
    {
      if (c == '-') 
      {
        current_token_type = TEXT;
      }else{
        error_message = "Expected '-'!"
        throw std::runtime_error(error_message);
      }
    }
    case EMPTY_TAG_NAME:
    {
      current_token_type = TEXT;
    }
    case MACRO_TAG:
    {
      current_token_type = TEXT;
    }
  }
}