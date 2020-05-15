//
// Copyright 2020 WebAssembly Community Group participants
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

#ifndef WASP_TEXT_DESUGAR_H_
#define WASP_TEXT_DESUGAR_H_

#include "wasp/text/types.h"

namespace wasp {
namespace text {

using ModuleItemList = std::vector<At<ModuleItem>>;

struct DesugarContext {
  Index function_count = 0;
  Index table_count = 0;
  Index memory_count = 0;
  Index global_count = 0;
  Index event_count = 0;
  ModuleItemList new_items;
};

void Desugar(DesugarContext&, const At<Function>&) -> At<ModuleItem>;
void Desugar(DesugarContext&, const At<Table>&) -> At<ModuleItem>;
void Desugar(DesugarContext&, const At<Memory>&) -> At<ModuleItem>;
void Desugar(DesugarContext&, const At<Global>&) -> At<ModuleItem>;
void Desugar(DesugarContext&, const At<Event>&) -> At<ModuleItem>;
void Desugar(Module&);

}  // namespace text
}  // namespace wasp

#endif // WASP_TEXT_DESUGAR_H_
