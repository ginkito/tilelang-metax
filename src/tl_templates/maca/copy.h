// Copyright (c) 2025 MetaX Integrated Circuits (Shanghai) Co., Ltd. All rights
// reserved.
#pragma once
#include "common.h"
namespace tl {
// Global memory load intrinsics with explicit vector widths
// MACA-compatible implementation using standard pointer casts
// load_global_32: Load 32 bits, return uint32_t
TL_DEVICE uint32_t load_global_32(const void *ptr) {
  return *reinterpret_cast<const uint32_t *>(ptr);
}
// load_global_64: Load 64 bits, return uint2
TL_DEVICE uint2 load_global_64(const void *ptr) {
  return *reinterpret_cast<const uint2 *>(ptr);
}
// load_global_128: Load 128 bits, return uint4
TL_DEVICE uint4 load_global_128(const void *ptr) {
  return *reinterpret_cast<const uint4 *>(ptr);
}
// load_global_256: Load 256 bits, return the pointee vector type. Accepts
template <typename T> TL_DEVICE T load_global_256(const T *ptr) {
  static_assert(sizeof(T) == 32,
                "tl::load_global_256 requires a 32-byte vector type");
  return *ptr;
}
// Predicated (conditional) versions
TL_DEVICE uint32_t load_global_32_conditional(const void *ptr, bool pred) {
  if (pred) {
    return *reinterpret_cast<const uint32_t *>(ptr);
  }
  return 0u;
}
TL_DEVICE uint2 load_global_64_conditional(const void *ptr, bool pred) {
  if (pred) {
    return *reinterpret_cast<const uint2 *>(ptr);
  }
  return make_uint2(0u, 0u);
}
TL_DEVICE uint4 load_global_128_conditional(const void *ptr, bool pred) {
  if (pred) {
    return *reinterpret_cast<const uint4 *>(ptr);
  }
  return make_uint4(0u, 0u, 0u, 0u);
}
template <typename T>
TL_DEVICE T load_global_256_conditional(const T *ptr, bool pred) {
  static_assert(sizeof(T) == 32,
                "tl::load_global_256_conditional requires a 32-byte vector "
                "type");
  if (pred) {
    return *ptr;
  }
  return T{};
}

TL_DEVICE uint32_t load_shared_32(const void *ptr) {
  return *reinterpret_cast<const uint32_t *>(ptr);
}

TL_DEVICE uint2 load_shared_64(const void *ptr) {
  return *reinterpret_cast<const uint2 *>(ptr);
}

TL_DEVICE uint4 load_shared_128(const void *ptr) {
  return *reinterpret_cast<const uint4 *>(ptr);
}

TL_DEVICE void store_shared_32(void *ptr, uint32_t value) {
  *reinterpret_cast<uint32_t *>(ptr) = value;
}

TL_DEVICE void store_shared_64(void *ptr, uint2 value) {
  *reinterpret_cast<uint2 *>(ptr) = value;
}

TL_DEVICE void store_shared_128(void *ptr, uint4 value) {
  *reinterpret_cast<uint4 *>(ptr) = value;
}

// Global memory store intrinsics with explicit vector widths
// store_global_32: Store 32 bits
TL_DEVICE void store_global_32(void *ptr, uint32_t value) {
  *reinterpret_cast<uint32_t *>(ptr) = value;
}
// store_global_64: Store 64 bits
TL_DEVICE void store_global_64(void *ptr, uint2 value) {
  *reinterpret_cast<uint2 *>(ptr) = value;
}
// store_global_128: Store 128 bits
TL_DEVICE void store_global_128(void *ptr, uint4 value) {
  *reinterpret_cast<uint4 *>(ptr) = value;
}
// store_global_256: Store 256 bits
template <typename T> TL_DEVICE void store_global_256(void *ptr, const T &val) {
  static_assert(sizeof(T) == 32,
                "tl::store_global_256 requires a 32-byte vector type");
  *reinterpret_cast<T *>(ptr) = val;
}
// Predicated (conditional) versions
TL_DEVICE void store_global_32_conditional(void *ptr, uint32_t value,
                                           bool pred) {
  if (pred) {
    *reinterpret_cast<uint32_t *>(ptr) = value;
  }
}
TL_DEVICE void store_global_64_conditional(void *ptr, uint2 value, bool pred) {
  if (pred) {
    *reinterpret_cast<uint2 *>(ptr) = value;
  }
}
TL_DEVICE void store_global_128_conditional(void *ptr, uint4 value, bool pred) {
  if (pred) {
    *reinterpret_cast<uint4 *>(ptr) = value;
  }
}
template <typename T>
TL_DEVICE void store_global_256_conditional(void *ptr, const T &val,
                                            bool pred) {
  static_assert(sizeof(T) == 32,
                "tl::store_global_256_conditional requires a 32-byte vector "
                "type");
  if (pred) {
    *reinterpret_cast<T *>(ptr) = val;
  }
}
} // namespace tl
