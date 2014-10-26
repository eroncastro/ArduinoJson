// Copyright Benoit Blanchon 2014
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "../JsonBuffer.hpp"
#include "JsonArrayIterator.hpp"
#include "JsonArrayConstIterator.hpp"

namespace ArduinoJson {
namespace Internals {
class JsonArrayImpl {
 public:
  typedef JsonValueImpl *value_type;
  typedef JsonArrayIterator iterator;
  typedef JsonArrayConstIterator const_iterator;

  JsonArrayImpl(JsonBuffer *buffer) : _buffer(buffer) {}

  value_type *operator[](int index) const;

  value_type *add();

  JsonArrayImpl *createNestedArray();
  JsonObjectImpl *createNestedObject();

  iterator begin() { return iterator(_firstChild); }
  iterator end() { return iterator(0); }

  const_iterator begin() const { return const_iterator(_firstChild); }
  const_iterator end() const { return const_iterator(0); }

 private:
  JsonBuffer *_buffer;
  Internals::JsonArrayNode *_firstChild;
};
}
}
