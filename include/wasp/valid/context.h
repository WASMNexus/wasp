//
// Copyright 2019 WebAssembly Community Group participants
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef WASP_VALID_CONTEXT_H_
#define WASP_VALID_CONTEXT_H_

#include <set>
#include <vector>

#include "wasp/base/errors.h"
#include "wasp/base/features.h"
#include "wasp/base/span.h"
#include "wasp/base/string_view.h"
#include "wasp/base/types.h"
#include "wasp/binary/types.h"
#include "wasp/valid/types.h"

namespace wasp {
namespace valid {

enum class LabelType {
  Function,
  Block,
  Loop,
  If,
  Else,
  Try,
  Catch,
};

using ValueTypeSpan = span<const ValueType>;

struct Label {
  Label(LabelType,
        StackTypeSpan param_types,
        StackTypeSpan result_types,
        Index type_stack_limit);

  const StackTypeList& br_types() const {
    return label_type == LabelType::Loop ? param_types : result_types;
  }

  LabelType label_type;
  StackTypeList param_types;
  StackTypeList result_types;
  Index type_stack_limit;
  bool unreachable;
};

struct Context {
  Context(Errors&);
  Context(const Features&, Errors&);
  Context(const Context&, Errors&);

  void Reset();

  Index GetLocalCount() const;
  optional<ValueType> GetLocalType(Index) const;
  bool AppendLocals(Index count, ValueType);
  bool AppendLocals(const ValueTypeList&);

  Features features;
  Errors* errors;

  std::vector<binary::TypeEntry> types;
  std::vector<binary::Function> functions;
  std::vector<TableType> tables;
  std::vector<MemoryType> memories;
  std::vector<GlobalType> globals;
  std::vector<binary::EventType> events;
  std::vector<ReferenceType> element_segments;
  Index imported_function_count = 0;
  Index imported_global_count = 0;
  optional<Index> declared_data_count;
  Index code_count = 0;
  std::vector<Index> locals_partial_sum;
  ValueTypeList locals;
  StackTypeList type_stack;
  std::vector<Label> label_stack;
  std::set<string_view> export_names;
  std::set<Index> declared_functions;
};

}  // namespace valid
}  // namespace wasp

#endif  // WASP_VALID_CONTEXT_H_
