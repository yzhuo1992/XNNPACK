// Auto-generated file. Do not edit!
//   Template: src/f32-spmm/wasmsimd.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include <xnnpack/spmm.h>


void xnn_f32_spmm_minmax_ukernel_4x1__wasmsimd_arm_x4(
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
  const v128_t vmin = wasm_v32x4_load_splat(&params->scalar.min);
  const v128_t vmax = wasm_v32x4_load_splat(&params->scalar.max);
  const v128_t vzero = wasm_f32x4_splat(0.0f);
  size_t n = batch_size;
  while XNN_LIKELY(n >= 4) {
    const float*restrict w = weights;
    const int32_t* dmap = widx_dmap;
    const uint32_t* nnzmap = nidx_nnzmap;
    size_t c = output_channels;
    do {
      uint32_t nnz = *nnzmap++;
      v128_t vacc0123x0 = wasm_v32x4_load_splat(w);
      w += 1;
      v128_t vacc0123x1 = vzero;
      v128_t vacc0123x2 = vzero;
      v128_t vacc0123x3 = vzero;
      for (; nnz >= 4; nnz -= 4) {
        const intptr_t diff0 = dmap[0];
        const intptr_t diff1 = dmap[1];
        const intptr_t diff2 = dmap[2];
        const intptr_t diff3 = dmap[3];
        dmap += 4;
        const v128_t vi0123x0 = wasm_v128_load(input);
        input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff0);
        const v128_t vw0 = wasm_v32x4_load_splat(w);
        w += 1;
        vacc0123x0 = wasm_f32x4_add(vacc0123x0, wasm_f32x4_mul(vi0123x0, vw0));
        const v128_t vi0123x1 = wasm_v128_load(input);
        input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff1);
        const v128_t vw1 = wasm_v32x4_load_splat(w);
        w += 1;
        vacc0123x1 = wasm_f32x4_add(vacc0123x1, wasm_f32x4_mul(vi0123x1, vw1));
        const v128_t vi0123x2 = wasm_v128_load(input);
        input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff2);
        const v128_t vw2 = wasm_v32x4_load_splat(w);
        w += 1;
        vacc0123x2 = wasm_f32x4_add(vacc0123x2, wasm_f32x4_mul(vi0123x2, vw2));
        const v128_t vi0123x3 = wasm_v128_load(input);
        input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff3);
        const v128_t vw3 = wasm_v32x4_load_splat(w);
        w += 1;
        vacc0123x3 = wasm_f32x4_add(vacc0123x3, wasm_f32x4_mul(vi0123x3, vw3));
      }
      v128_t vacc0123 = vacc0123x0;
      vacc0123 = wasm_f32x4_add(vacc0123, vacc0123x1);
      vacc0123 = wasm_f32x4_add(vacc0123, vacc0123x2);
      vacc0123 = wasm_f32x4_add(vacc0123, vacc0123x3);
      if XNN_LIKELY(nnz != 0) {
        do {
          const intptr_t diff = *dmap++;
          const v128_t vi0123 = wasm_v128_load(input);
          input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff);
          const v128_t vw = wasm_v32x4_load_splat(w); w += 1;
          vacc0123 = wasm_f32x4_add(vacc0123, wasm_f32x4_mul(vi0123, vw));
        } while (--nnz != 0);
      }
      v128_t vout0123 = wasm_f32x4_min(vacc0123, vmax);
      vout0123 = wasm_f32x4_max(vout0123, vmin);
      wasm_v128_store(output, vout0123);
      output = (float*restrict) ((uintptr_t) output + output_stride);
    } while (--c != 0);
    output -= batch_size * output_channels;
    output += 4;
    input += 4;
    n -= 4;
  }
  if XNN_UNLIKELY(n != 0) {
    if (n & 2) {
      const float*restrict w = weights;
      const int32_t* dmap = widx_dmap;
      const uint32_t* nnzmap = nidx_nnzmap;
      size_t c = output_channels;
      do {
        uint32_t nnz = *nnzmap++;
        v128_t vacc01 = wasm_v32x4_load_splat(w); w += 1;
        if XNN_LIKELY(nnz != 0) {
          do {
            const intptr_t diff = *dmap++;
            const v128_t vi01 = wasm_v64x2_load_splat(input);
            input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff);
            const v128_t vw = wasm_v32x4_load_splat(w); w += 1;
            vacc01 = wasm_f32x4_add(vacc01, wasm_f32x4_mul(vi01, vw));
          } while (--nnz != 0);
        }
        v128_t vout01 = wasm_f32x4_min(vacc01, vmax);
        vout01 = wasm_f32x4_max(vout01, vmin);
        *((double*) output) = wasm_f64x2_extract_lane(vout01, 0);

        output = (float*restrict) ((uintptr_t) output + output_stride);
      } while (--c != 0);
      output -= batch_size * output_channels;
      output += 2;
      input += 2;
    }
    if (n & 1) {
      const float*restrict w = weights;
      const int32_t* dmap = widx_dmap;
      const uint32_t* nnzmap = nidx_nnzmap;
      size_t c = output_channels;
      do {
        uint32_t nnz = *nnzmap++;
        v128_t vacc0 = wasm_v32x4_load_splat(w); w += 1;
        if XNN_LIKELY(nnz != 0) {
          do {
            const intptr_t diff = *dmap++;
            const v128_t vi0 = wasm_v32x4_load_splat(input);
            input = (const float*restrict) ((uintptr_t) input + (uintptr_t) diff);
            const v128_t vw = wasm_v32x4_load_splat(w); w += 1;
            vacc0 = wasm_f32x4_add(vacc0, wasm_f32x4_mul(vi0, vw));
          } while (--nnz != 0);
        }
        v128_t vout0 = wasm_f32x4_min(vacc0, vmax);
        vout0 = wasm_f32x4_max(vout0, vmin);
        *output = wasm_f32x4_extract_lane(vout0, 0);

        output = (float*restrict) ((uintptr_t) output + output_stride);
      } while (--c != 0);
      output -= batch_size * output_channels;
      output += 1;
      input += 1;
    }
  }
}
