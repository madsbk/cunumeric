/* Copyright 2021 NVIDIA Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include "numpy.h"
#include "binary/binary_op_util.h"

namespace legate {
namespace numpy {

struct BinaryOpArgs {
  const Array& in1;
  const Array& in2;
  const Array& out;
  BinaryOpCode op_code;
  std::vector<UntypedScalar> args;
};

class BinaryOpTask : public NumPyTask<BinaryOpTask> {
 public:
  static const int TASK_ID = NUMPY_BINARY_OP;

 public:
  static void cpu_variant(TaskContext& context);
#ifdef LEGATE_USE_OPENMP
  static void omp_variant(TaskContext& context);
#endif
#ifdef LEGATE_USE_CUDA
  static void gpu_variant(TaskContext& context);
#endif
};

}  // namespace numpy
}  // namespace legate
