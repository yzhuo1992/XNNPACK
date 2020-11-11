// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-ibilinear-chw.yaml
//   Generator: tools/generate-ibilinear-chw-test.py


#include <gtest/gtest.h>

#include <xnnpack/common.h>
#include <xnnpack/isa-checks.h>

#include <xnnpack/ibilinear.h>
#include "ibilinear-microkernel-tester.h"


TEST(F32_IBILINEAR_CHW__SCALAR_P1, pixels_eq_1) {
  IBilinearMicrokernelTester()
    .pixels(1)
    .channels(1)
    .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p1);
}

TEST(F32_IBILINEAR_CHW__SCALAR_P1, pixels_gt_1) {
  for (size_t pixels = 2; pixels < 10; pixels++) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p1);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P1, channels_eq_1) {
  for (size_t pixels = 1; pixels <= 5; pixels += 1) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p1);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P1, channels_gt_1) {
  for (size_t channels = 2; channels < 3; channels++) {
    for (size_t pixels = 1; pixels <= 5; pixels += 1) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p1);
    }
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P1, input_offset) {
  for (size_t pixels = 1; pixels < 5; pixels += 1) {
    for (size_t channels = 1; channels <= 5; channels += 1) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .input_offset(7)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p1);
    }
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P1, input_stride) {
  for (size_t pixels = 1; pixels < 5; pixels += 1) {
    for (size_t channels = 1; channels <= 5; channels += 1) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .input_stride(23)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p1);
    }
  }
}


TEST(F32_IBILINEAR_CHW__SCALAR_P2, pixels_eq_2) {
  IBilinearMicrokernelTester()
    .pixels(2)
    .channels(1)
    .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p2);
}

TEST(F32_IBILINEAR_CHW__SCALAR_P2, pixels_div_2) {
  for (size_t pixels = 4; pixels < 20; pixels += 2) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p2);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P2, pixels_lt_2) {
  for (size_t pixels = 1; pixels < 2; pixels++) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p2);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P2, pixels_gt_2) {
  for (size_t pixels = 3; pixels < 4; pixels++) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p2);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P2, channels_eq_1) {
  for (size_t pixels = 1; pixels <= 10; pixels += 1) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p2);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P2, channels_gt_1) {
  for (size_t channels = 2; channels < 3; channels++) {
    for (size_t pixels = 1; pixels <= 10; pixels += 1) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p2);
    }
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P2, input_offset) {
  for (size_t pixels = 1; pixels < 10; pixels += 1) {
    for (size_t channels = 1; channels <= 5; channels += 1) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .input_offset(7)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p2);
    }
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P2, input_stride) {
  for (size_t pixels = 1; pixels < 10; pixels += 1) {
    for (size_t channels = 1; channels <= 5; channels += 1) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .input_stride(43)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p2);
    }
  }
}


TEST(F32_IBILINEAR_CHW__SCALAR_P4, pixels_eq_4) {
  IBilinearMicrokernelTester()
    .pixels(4)
    .channels(1)
    .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p4);
}

TEST(F32_IBILINEAR_CHW__SCALAR_P4, pixels_div_4) {
  for (size_t pixels = 8; pixels < 40; pixels += 4) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p4);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P4, pixels_lt_4) {
  for (size_t pixels = 1; pixels < 4; pixels++) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p4);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P4, pixels_gt_4) {
  for (size_t pixels = 5; pixels < 8; pixels++) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p4);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P4, channels_eq_1) {
  for (size_t pixels = 1; pixels <= 20; pixels += 3) {
    IBilinearMicrokernelTester()
      .pixels(pixels)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p4);
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P4, channels_gt_1) {
  for (size_t channels = 2; channels < 3; channels++) {
    for (size_t pixels = 1; pixels <= 20; pixels += 3) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p4);
    }
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P4, input_offset) {
  for (size_t pixels = 1; pixels < 20; pixels += 3) {
    for (size_t channels = 1; channels <= 5; channels += 1) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .input_offset(7)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p4);
    }
  }
}

TEST(F32_IBILINEAR_CHW__SCALAR_P4, input_stride) {
  for (size_t pixels = 1; pixels < 20; pixels += 3) {
    for (size_t channels = 1; channels <= 5; channels += 1) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(channels)
        .input_stride(83)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__scalar_p4);
    }
  }
}


#if XNN_ARCH_WASMSIMD
  TEST(F32_IBILINEAR_CHW__WASMSIMD_P4, pixels_eq_4) {
    IBilinearMicrokernelTester()
      .pixels(4)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p4);
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P4, pixels_div_4) {
    for (size_t pixels = 8; pixels < 40; pixels += 4) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(1)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p4);
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P4, pixels_lt_4) {
    for (size_t pixels = 1; pixels < 4; pixels++) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(1)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p4);
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P4, pixels_gt_4) {
    for (size_t pixels = 5; pixels < 8; pixels++) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(1)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p4);
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P4, channels_eq_1) {
    for (size_t pixels = 1; pixels <= 20; pixels += 3) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(1)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p4);
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P4, channels_gt_1) {
    for (size_t channels = 2; channels < 3; channels++) {
      for (size_t pixels = 1; pixels <= 20; pixels += 3) {
        IBilinearMicrokernelTester()
          .pixels(pixels)
          .channels(channels)
          .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p4);
      }
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P4, input_offset) {
    for (size_t pixels = 1; pixels < 20; pixels += 3) {
      for (size_t channels = 1; channels <= 5; channels += 1) {
        IBilinearMicrokernelTester()
          .pixels(pixels)
          .channels(channels)
          .input_offset(7)
          .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p4);
      }
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P4, input_stride) {
    for (size_t pixels = 1; pixels < 20; pixels += 3) {
      for (size_t channels = 1; channels <= 5; channels += 1) {
        IBilinearMicrokernelTester()
          .pixels(pixels)
          .channels(channels)
          .input_stride(83)
          .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p4);
      }
    }
  }
#endif  // XNN_ARCH_WASMSIMD


#if XNN_ARCH_WASMSIMD
  TEST(F32_IBILINEAR_CHW__WASMSIMD_P8, pixels_eq_8) {
    IBilinearMicrokernelTester()
      .pixels(8)
      .channels(1)
      .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p8);
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P8, pixels_div_8) {
    for (size_t pixels = 16; pixels < 80; pixels += 8) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(1)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p8);
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P8, pixels_lt_8) {
    for (size_t pixels = 1; pixels < 8; pixels++) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(1)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p8);
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P8, pixels_gt_8) {
    for (size_t pixels = 9; pixels < 16; pixels++) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(1)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p8);
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P8, channels_eq_1) {
    for (size_t pixels = 1; pixels <= 40; pixels += 7) {
      IBilinearMicrokernelTester()
        .pixels(pixels)
        .channels(1)
        .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p8);
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P8, channels_gt_1) {
    for (size_t channels = 2; channels < 3; channels++) {
      for (size_t pixels = 1; pixels <= 40; pixels += 7) {
        IBilinearMicrokernelTester()
          .pixels(pixels)
          .channels(channels)
          .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p8);
      }
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P8, input_offset) {
    for (size_t pixels = 1; pixels < 40; pixels += 7) {
      for (size_t channels = 1; channels <= 5; channels += 1) {
        IBilinearMicrokernelTester()
          .pixels(pixels)
          .channels(channels)
          .input_offset(7)
          .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p8);
      }
    }
  }

  TEST(F32_IBILINEAR_CHW__WASMSIMD_P8, input_stride) {
    for (size_t pixels = 1; pixels < 40; pixels += 7) {
      for (size_t channels = 1; channels <= 5; channels += 1) {
        IBilinearMicrokernelTester()
          .pixels(pixels)
          .channels(channels)
          .input_stride(163)
          .TestCHW(xnn_f32_ibilinear_chw_ukernel__wasmsimd_p8);
      }
    }
  }
#endif  // XNN_ARCH_WASMSIMD
