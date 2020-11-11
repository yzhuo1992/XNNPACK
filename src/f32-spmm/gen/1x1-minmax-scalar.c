// Auto-generated file. Do not edit!
//   Template: src/f32-spmm/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/math.h>
#include <xnnpack/spmm.h>


void xnn_f32_spmm_minmax_ukernel_1x1__scalar(
    uint32_t batch_size,
    uint32_t output_channels,
    const float*restrict input,
    const float*restrict weights,
    const int32_t*restrict widx_dmap,
    const uint32_t*restrict nidx_nnzmap,
    float*restrict output,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch_size != 0);

  const uintptr_t output_stride = 1 * batch_size * sizeof(float);
  const float vmin = params->scalar.min;
  const float vmax = params->scalar.max;
  size_t n = batch_size;
  while (n >= 1) {
    const float*restrict w = weights;
    const int32_t* dmap = widx_dmap;
    const uint32_t* nnzmap = nidx_nnzmap;
    size_t c = output_channels;
    while (c >= 1) {
      uint32_t nnz = *nnzmap++;
      float vacc0x0 = *w++;
      if XNN_LIKELY(nnz != 0) {
        do {
          const intptr_t diff = *dmap++;
          const float vi0 = input[0];
          input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff);
          const float vw0 = *w++;
          vacc0x0 += vi0 * vw0;
        } while (--nnz != 0);
      }
      float vout0x0 = math_min_f32(vacc0x0, vmax);
      vout0x0 = math_max_f32(vout0x0, vmin);
      output[0 * batch_size + 0] = vout0x0;
      output = (float*restrict) ((uintptr_t) output + output_stride);
      c -= 1;
    }
    if XNN_UNLIKELY(c != 0) {
      do {
        uint32_t nnz = *nnzmap++;
        float vacc0 = *w++;
        if XNN_LIKELY(nnz != 0) {
          do {
            const intptr_t diff = *dmap++;
            const float vi0 = input[0];
            input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff);
            const float vw = *w++;
            vacc0 += vi0 * vw;
          } while (--nnz != 0);
        }
        float vout0 = math_min_f32(vacc0, vmax);
        vout0 = math_max_f32(vout0, vmin);
        output[0] = vout0;
        output += batch_size;
        c -= 1;
      } while (c != 0);
    }
    output -= batch_size * output_channels;
    output += 1;
    input += 1;
    n -= 1;
  }
  if XNN_UNLIKELY(n != 0) {
  }
}
