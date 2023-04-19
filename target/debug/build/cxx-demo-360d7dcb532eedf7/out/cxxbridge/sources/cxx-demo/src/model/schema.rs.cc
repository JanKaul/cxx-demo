#include "cxx-demo/src/model/datatypes.rs.h"
#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_RELOCATABLE
#define CXXBRIDGE1_RELOCATABLE
namespace detail {
template <typename... Ts>
struct make_void {
  using type = void;
};

template <typename... Ts>
using void_t = typename make_void<Ts...>::type;

template <typename Void, template <typename...> class, typename...>
struct detect : std::false_type {};
template <template <typename...> class T, typename... A>
struct detect<void_t<T<A...>>, T, A...> : std::true_type {};

template <template <typename...> class T, typename... A>
using is_detected = detect<void, T, A...>;

template <typename T>
using detect_IsRelocatable = typename T::IsRelocatable;

template <typename T>
struct get_IsRelocatable
    : std::is_same<typename T::IsRelocatable, std::true_type> {};
} // namespace detail

template <typename T>
struct IsRelocatable
    : std::conditional<
          detail::is_detected<detail::detect_IsRelocatable, T>::value,
          detail::get_IsRelocatable<T>,
          std::integral_constant<
              bool, std::is_trivially_move_constructible<T>::value &&
                        std::is_trivially_destructible<T>::value>>::type {};
#endif // CXXBRIDGE1_RELOCATABLE

namespace {
template <typename T>
struct IsRelocatableOrArray : IsRelocatable<T> {};
template <typename T, ::std::size_t N>
struct IsRelocatableOrArray<T[N]> : IsRelocatableOrArray<T> {};
} // namespace
} // namespace cxxbridge1
} // namespace rust

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

static_assert(
    ::rust::IsRelocatableOrArray<::model::datatypes::StructType>::value,
    "type model::datatypes::StructType should be trivially move constructible and trivially destructible in C++ to be used as a field of `SchemaV2` in Rust");
