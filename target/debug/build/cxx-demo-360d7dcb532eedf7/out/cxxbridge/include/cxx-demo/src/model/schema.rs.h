#pragma once
#include "cxx-demo/src/model/datatypes.rs.h"
#include <cstdint>
#include <type_traits>

namespace model {
  namespace schema {
    struct SchemaV2;
  }
}

namespace model {
namespace schema {
#ifndef CXXBRIDGE1_STRUCT_model$schema$SchemaV2
#define CXXBRIDGE1_STRUCT_model$schema$SchemaV2
struct SchemaV2 final {
  ::std::int32_t schema_id;
  ::model::datatypes::StructType fields;

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_model$schema$SchemaV2
} // namespace schema
} // namespace model
