#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <chrono>

#include "Meqdad.hpp"

std::string Meqdad::uuid() {
  namespace buuids = boost::uuids;
  static buuids::random_generator generator;

  buuids::uuid uuid = generator();
  return buuids::to_string(uuid);
}

std::string Meqdad::timestamp() {
  return std::format("{:%FT%T%Z}", std::chrono::system_clock::now());
}
