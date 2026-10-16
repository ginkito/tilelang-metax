#pragma once

#include "common.h"

namespace tl {

// Pass operands by value: checking NaN must not re-evaluate the caller's
// expression (which can, for example, be a returning atomic operation).
TL_DEVICE float clamp(float x, float lo, float hi) {
  if (isnan(x))
    return x;
  if (isnan(lo))
    return lo;
  if (isnan(hi))
    return hi;
  return fminf(fmaxf(x, lo), hi);
}

TL_DEVICE double clamp(double x, double lo, double hi) {
  if (isnan(x))
    return x;
  if (isnan(lo))
    return lo;
  if (isnan(hi))
    return hi;
  return fmin(fmax(x, lo), hi);
}

// Narrow formats, including FP8, are exactly representable in float.
// half_t/bfloat16_t here are native SDK types, so they intentionally go through
// this template.
template <typename T> TL_DEVICE T clamp(T x, T lo, T hi) {
  return T(clamp(float(x), float(lo), float(hi)));
}

TL_DEVICE __half2 clamp2(__half2 x, __half2 lo, __half2 hi) {
  return min2_nan(max2_nan(x, lo), hi);
}

TL_DEVICE __maca_bfloat162 clamp2(__maca_bfloat162 x, __maca_bfloat162 lo,
                                  __maca_bfloat162 hi) {
  return min2_nan(max2_nan(x, lo), hi);
}

} // namespace tl
