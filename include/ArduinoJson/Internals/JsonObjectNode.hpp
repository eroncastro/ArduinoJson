// Copyright Benoit Blanchon 2014
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "../JsonPair.hpp"

namespace ArduinoJson {
namespace Internals {

struct JsonObjectNode {
  JsonObjectNode *next;
  JsonPair pair;
};
}
}
