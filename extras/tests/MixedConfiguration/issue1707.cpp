// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2023, Benoit BLANCHON
// MIT License

#define ARDUINO
#define memcpy_P(dest, src, n) memcpy((dest), (src), (n))

#include "progmem_emulation.hpp"

#include <ArduinoJson.h>

#include <catch.hpp>

TEST_CASE("Issue1707") {
  DynamicJsonDocument doc(128);

  DeserializationError err = deserializeJson(doc, F("{\"hello\":12}"));
  REQUIRE(err == DeserializationError::Ok);
}
