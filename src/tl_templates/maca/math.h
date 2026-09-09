#pragma once

#include "common.h"

// MACA natively provides hexp, hlog, hsqrt, hsin, hcos, and bf16 htanh.
// The SDK has no half htanh or 16-bit pow overloads, so evaluate those through
// float and convert back.
TL_DEVICE half_t htanh(half_t x) { return half_t(tanhf(float(x))); }

TL_DEVICE half_t hpow(half_t x, half_t y) {
  return half_t(powf(float(x), float(y)));
}

TL_DEVICE bfloat16_t hpow(bfloat16_t x, bfloat16_t y) {
  return bfloat16_t(powf(float(x), float(y)));
}
