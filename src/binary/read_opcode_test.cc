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

#include "wasp/binary/read/read_opcode.h"

#include "gtest/gtest.h"

#include "src/binary/read_test_utils.h"
#include "src/binary/test_utils.h"

using namespace ::wasp;
using namespace ::wasp::binary;
using namespace ::wasp::binary::test;

TEST(ReaderTest, Opcode) {
  ExpectRead<Opcode>(Opcode::Unreachable, MakeSpanU8("\x00"));
  ExpectRead<Opcode>(Opcode::Nop, MakeSpanU8("\x01"));
  ExpectRead<Opcode>(Opcode::Block, MakeSpanU8("\x02"));
  ExpectRead<Opcode>(Opcode::Loop, MakeSpanU8("\x03"));
  ExpectRead<Opcode>(Opcode::If, MakeSpanU8("\x04"));
  ExpectRead<Opcode>(Opcode::Else, MakeSpanU8("\x05"));
  ExpectRead<Opcode>(Opcode::End, MakeSpanU8("\x0b"));
  ExpectRead<Opcode>(Opcode::Br, MakeSpanU8("\x0c"));
  ExpectRead<Opcode>(Opcode::BrIf, MakeSpanU8("\x0d"));
  ExpectRead<Opcode>(Opcode::BrTable, MakeSpanU8("\x0e"));
  ExpectRead<Opcode>(Opcode::Return, MakeSpanU8("\x0f"));
  ExpectRead<Opcode>(Opcode::Call, MakeSpanU8("\x10"));
  ExpectRead<Opcode>(Opcode::CallIndirect, MakeSpanU8("\x11"));
  ExpectRead<Opcode>(Opcode::Drop, MakeSpanU8("\x1a"));
  ExpectRead<Opcode>(Opcode::Select, MakeSpanU8("\x1b"));
  ExpectRead<Opcode>(Opcode::LocalGet, MakeSpanU8("\x20"));
  ExpectRead<Opcode>(Opcode::LocalSet, MakeSpanU8("\x21"));
  ExpectRead<Opcode>(Opcode::LocalTee, MakeSpanU8("\x22"));
  ExpectRead<Opcode>(Opcode::GlobalGet, MakeSpanU8("\x23"));
  ExpectRead<Opcode>(Opcode::GlobalSet, MakeSpanU8("\x24"));
  ExpectRead<Opcode>(Opcode::I32Load, MakeSpanU8("\x28"));
  ExpectRead<Opcode>(Opcode::I64Load, MakeSpanU8("\x29"));
  ExpectRead<Opcode>(Opcode::F32Load, MakeSpanU8("\x2a"));
  ExpectRead<Opcode>(Opcode::F64Load, MakeSpanU8("\x2b"));
  ExpectRead<Opcode>(Opcode::I32Load8S, MakeSpanU8("\x2c"));
  ExpectRead<Opcode>(Opcode::I32Load8U, MakeSpanU8("\x2d"));
  ExpectRead<Opcode>(Opcode::I32Load16S, MakeSpanU8("\x2e"));
  ExpectRead<Opcode>(Opcode::I32Load16U, MakeSpanU8("\x2f"));
  ExpectRead<Opcode>(Opcode::I64Load8S, MakeSpanU8("\x30"));
  ExpectRead<Opcode>(Opcode::I64Load8U, MakeSpanU8("\x31"));
  ExpectRead<Opcode>(Opcode::I64Load16S, MakeSpanU8("\x32"));
  ExpectRead<Opcode>(Opcode::I64Load16U, MakeSpanU8("\x33"));
  ExpectRead<Opcode>(Opcode::I64Load32S, MakeSpanU8("\x34"));
  ExpectRead<Opcode>(Opcode::I64Load32U, MakeSpanU8("\x35"));
  ExpectRead<Opcode>(Opcode::I32Store, MakeSpanU8("\x36"));
  ExpectRead<Opcode>(Opcode::I64Store, MakeSpanU8("\x37"));
  ExpectRead<Opcode>(Opcode::F32Store, MakeSpanU8("\x38"));
  ExpectRead<Opcode>(Opcode::F64Store, MakeSpanU8("\x39"));
  ExpectRead<Opcode>(Opcode::I32Store8, MakeSpanU8("\x3a"));
  ExpectRead<Opcode>(Opcode::I32Store16, MakeSpanU8("\x3b"));
  ExpectRead<Opcode>(Opcode::I64Store8, MakeSpanU8("\x3c"));
  ExpectRead<Opcode>(Opcode::I64Store16, MakeSpanU8("\x3d"));
  ExpectRead<Opcode>(Opcode::I64Store32, MakeSpanU8("\x3e"));
  ExpectRead<Opcode>(Opcode::MemorySize, MakeSpanU8("\x3f"));
  ExpectRead<Opcode>(Opcode::MemoryGrow, MakeSpanU8("\x40"));
  ExpectRead<Opcode>(Opcode::I32Const, MakeSpanU8("\x41"));
  ExpectRead<Opcode>(Opcode::I64Const, MakeSpanU8("\x42"));
  ExpectRead<Opcode>(Opcode::F32Const, MakeSpanU8("\x43"));
  ExpectRead<Opcode>(Opcode::F64Const, MakeSpanU8("\x44"));
  ExpectRead<Opcode>(Opcode::I32Eqz, MakeSpanU8("\x45"));
  ExpectRead<Opcode>(Opcode::I32Eq, MakeSpanU8("\x46"));
  ExpectRead<Opcode>(Opcode::I32Ne, MakeSpanU8("\x47"));
  ExpectRead<Opcode>(Opcode::I32LtS, MakeSpanU8("\x48"));
  ExpectRead<Opcode>(Opcode::I32LtU, MakeSpanU8("\x49"));
  ExpectRead<Opcode>(Opcode::I32GtS, MakeSpanU8("\x4a"));
  ExpectRead<Opcode>(Opcode::I32GtU, MakeSpanU8("\x4b"));
  ExpectRead<Opcode>(Opcode::I32LeS, MakeSpanU8("\x4c"));
  ExpectRead<Opcode>(Opcode::I32LeU, MakeSpanU8("\x4d"));
  ExpectRead<Opcode>(Opcode::I32GeS, MakeSpanU8("\x4e"));
  ExpectRead<Opcode>(Opcode::I32GeU, MakeSpanU8("\x4f"));
  ExpectRead<Opcode>(Opcode::I64Eqz, MakeSpanU8("\x50"));
  ExpectRead<Opcode>(Opcode::I64Eq, MakeSpanU8("\x51"));
  ExpectRead<Opcode>(Opcode::I64Ne, MakeSpanU8("\x52"));
  ExpectRead<Opcode>(Opcode::I64LtS, MakeSpanU8("\x53"));
  ExpectRead<Opcode>(Opcode::I64LtU, MakeSpanU8("\x54"));
  ExpectRead<Opcode>(Opcode::I64GtS, MakeSpanU8("\x55"));
  ExpectRead<Opcode>(Opcode::I64GtU, MakeSpanU8("\x56"));
  ExpectRead<Opcode>(Opcode::I64LeS, MakeSpanU8("\x57"));
  ExpectRead<Opcode>(Opcode::I64LeU, MakeSpanU8("\x58"));
  ExpectRead<Opcode>(Opcode::I64GeS, MakeSpanU8("\x59"));
  ExpectRead<Opcode>(Opcode::I64GeU, MakeSpanU8("\x5a"));
  ExpectRead<Opcode>(Opcode::F32Eq, MakeSpanU8("\x5b"));
  ExpectRead<Opcode>(Opcode::F32Ne, MakeSpanU8("\x5c"));
  ExpectRead<Opcode>(Opcode::F32Lt, MakeSpanU8("\x5d"));
  ExpectRead<Opcode>(Opcode::F32Gt, MakeSpanU8("\x5e"));
  ExpectRead<Opcode>(Opcode::F32Le, MakeSpanU8("\x5f"));
  ExpectRead<Opcode>(Opcode::F32Ge, MakeSpanU8("\x60"));
  ExpectRead<Opcode>(Opcode::F64Eq, MakeSpanU8("\x61"));
  ExpectRead<Opcode>(Opcode::F64Ne, MakeSpanU8("\x62"));
  ExpectRead<Opcode>(Opcode::F64Lt, MakeSpanU8("\x63"));
  ExpectRead<Opcode>(Opcode::F64Gt, MakeSpanU8("\x64"));
  ExpectRead<Opcode>(Opcode::F64Le, MakeSpanU8("\x65"));
  ExpectRead<Opcode>(Opcode::F64Ge, MakeSpanU8("\x66"));
  ExpectRead<Opcode>(Opcode::I32Clz, MakeSpanU8("\x67"));
  ExpectRead<Opcode>(Opcode::I32Ctz, MakeSpanU8("\x68"));
  ExpectRead<Opcode>(Opcode::I32Popcnt, MakeSpanU8("\x69"));
  ExpectRead<Opcode>(Opcode::I32Add, MakeSpanU8("\x6a"));
  ExpectRead<Opcode>(Opcode::I32Sub, MakeSpanU8("\x6b"));
  ExpectRead<Opcode>(Opcode::I32Mul, MakeSpanU8("\x6c"));
  ExpectRead<Opcode>(Opcode::I32DivS, MakeSpanU8("\x6d"));
  ExpectRead<Opcode>(Opcode::I32DivU, MakeSpanU8("\x6e"));
  ExpectRead<Opcode>(Opcode::I32RemS, MakeSpanU8("\x6f"));
  ExpectRead<Opcode>(Opcode::I32RemU, MakeSpanU8("\x70"));
  ExpectRead<Opcode>(Opcode::I32And, MakeSpanU8("\x71"));
  ExpectRead<Opcode>(Opcode::I32Or, MakeSpanU8("\x72"));
  ExpectRead<Opcode>(Opcode::I32Xor, MakeSpanU8("\x73"));
  ExpectRead<Opcode>(Opcode::I32Shl, MakeSpanU8("\x74"));
  ExpectRead<Opcode>(Opcode::I32ShrS, MakeSpanU8("\x75"));
  ExpectRead<Opcode>(Opcode::I32ShrU, MakeSpanU8("\x76"));
  ExpectRead<Opcode>(Opcode::I32Rotl, MakeSpanU8("\x77"));
  ExpectRead<Opcode>(Opcode::I32Rotr, MakeSpanU8("\x78"));
  ExpectRead<Opcode>(Opcode::I64Clz, MakeSpanU8("\x79"));
  ExpectRead<Opcode>(Opcode::I64Ctz, MakeSpanU8("\x7a"));
  ExpectRead<Opcode>(Opcode::I64Popcnt, MakeSpanU8("\x7b"));
  ExpectRead<Opcode>(Opcode::I64Add, MakeSpanU8("\x7c"));
  ExpectRead<Opcode>(Opcode::I64Sub, MakeSpanU8("\x7d"));
  ExpectRead<Opcode>(Opcode::I64Mul, MakeSpanU8("\x7e"));
  ExpectRead<Opcode>(Opcode::I64DivS, MakeSpanU8("\x7f"));
  ExpectRead<Opcode>(Opcode::I64DivU, MakeSpanU8("\x80"));
  ExpectRead<Opcode>(Opcode::I64RemS, MakeSpanU8("\x81"));
  ExpectRead<Opcode>(Opcode::I64RemU, MakeSpanU8("\x82"));
  ExpectRead<Opcode>(Opcode::I64And, MakeSpanU8("\x83"));
  ExpectRead<Opcode>(Opcode::I64Or, MakeSpanU8("\x84"));
  ExpectRead<Opcode>(Opcode::I64Xor, MakeSpanU8("\x85"));
  ExpectRead<Opcode>(Opcode::I64Shl, MakeSpanU8("\x86"));
  ExpectRead<Opcode>(Opcode::I64ShrS, MakeSpanU8("\x87"));
  ExpectRead<Opcode>(Opcode::I64ShrU, MakeSpanU8("\x88"));
  ExpectRead<Opcode>(Opcode::I64Rotl, MakeSpanU8("\x89"));
  ExpectRead<Opcode>(Opcode::I64Rotr, MakeSpanU8("\x8a"));
  ExpectRead<Opcode>(Opcode::F32Abs, MakeSpanU8("\x8b"));
  ExpectRead<Opcode>(Opcode::F32Neg, MakeSpanU8("\x8c"));
  ExpectRead<Opcode>(Opcode::F32Ceil, MakeSpanU8("\x8d"));
  ExpectRead<Opcode>(Opcode::F32Floor, MakeSpanU8("\x8e"));
  ExpectRead<Opcode>(Opcode::F32Trunc, MakeSpanU8("\x8f"));
  ExpectRead<Opcode>(Opcode::F32Nearest, MakeSpanU8("\x90"));
  ExpectRead<Opcode>(Opcode::F32Sqrt, MakeSpanU8("\x91"));
  ExpectRead<Opcode>(Opcode::F32Add, MakeSpanU8("\x92"));
  ExpectRead<Opcode>(Opcode::F32Sub, MakeSpanU8("\x93"));
  ExpectRead<Opcode>(Opcode::F32Mul, MakeSpanU8("\x94"));
  ExpectRead<Opcode>(Opcode::F32Div, MakeSpanU8("\x95"));
  ExpectRead<Opcode>(Opcode::F32Min, MakeSpanU8("\x96"));
  ExpectRead<Opcode>(Opcode::F32Max, MakeSpanU8("\x97"));
  ExpectRead<Opcode>(Opcode::F32Copysign, MakeSpanU8("\x98"));
  ExpectRead<Opcode>(Opcode::F64Abs, MakeSpanU8("\x99"));
  ExpectRead<Opcode>(Opcode::F64Neg, MakeSpanU8("\x9a"));
  ExpectRead<Opcode>(Opcode::F64Ceil, MakeSpanU8("\x9b"));
  ExpectRead<Opcode>(Opcode::F64Floor, MakeSpanU8("\x9c"));
  ExpectRead<Opcode>(Opcode::F64Trunc, MakeSpanU8("\x9d"));
  ExpectRead<Opcode>(Opcode::F64Nearest, MakeSpanU8("\x9e"));
  ExpectRead<Opcode>(Opcode::F64Sqrt, MakeSpanU8("\x9f"));
  ExpectRead<Opcode>(Opcode::F64Add, MakeSpanU8("\xa0"));
  ExpectRead<Opcode>(Opcode::F64Sub, MakeSpanU8("\xa1"));
  ExpectRead<Opcode>(Opcode::F64Mul, MakeSpanU8("\xa2"));
  ExpectRead<Opcode>(Opcode::F64Div, MakeSpanU8("\xa3"));
  ExpectRead<Opcode>(Opcode::F64Min, MakeSpanU8("\xa4"));
  ExpectRead<Opcode>(Opcode::F64Max, MakeSpanU8("\xa5"));
  ExpectRead<Opcode>(Opcode::F64Copysign, MakeSpanU8("\xa6"));
  ExpectRead<Opcode>(Opcode::I32WrapI64, MakeSpanU8("\xa7"));
  ExpectRead<Opcode>(Opcode::I32TruncF32S, MakeSpanU8("\xa8"));
  ExpectRead<Opcode>(Opcode::I32TruncF32U, MakeSpanU8("\xa9"));
  ExpectRead<Opcode>(Opcode::I32TruncF64S, MakeSpanU8("\xaa"));
  ExpectRead<Opcode>(Opcode::I32TruncF64U, MakeSpanU8("\xab"));
  ExpectRead<Opcode>(Opcode::I64ExtendI32S, MakeSpanU8("\xac"));
  ExpectRead<Opcode>(Opcode::I64ExtendI32U, MakeSpanU8("\xad"));
  ExpectRead<Opcode>(Opcode::I64TruncF32S, MakeSpanU8("\xae"));
  ExpectRead<Opcode>(Opcode::I64TruncF32U, MakeSpanU8("\xaf"));
  ExpectRead<Opcode>(Opcode::I64TruncF64S, MakeSpanU8("\xb0"));
  ExpectRead<Opcode>(Opcode::I64TruncF64U, MakeSpanU8("\xb1"));
  ExpectRead<Opcode>(Opcode::F32ConvertI32S, MakeSpanU8("\xb2"));
  ExpectRead<Opcode>(Opcode::F32ConvertI32U, MakeSpanU8("\xb3"));
  ExpectRead<Opcode>(Opcode::F32ConvertI64S, MakeSpanU8("\xb4"));
  ExpectRead<Opcode>(Opcode::F32ConvertI64U, MakeSpanU8("\xb5"));
  ExpectRead<Opcode>(Opcode::F32DemoteF64, MakeSpanU8("\xb6"));
  ExpectRead<Opcode>(Opcode::F64ConvertI32S, MakeSpanU8("\xb7"));
  ExpectRead<Opcode>(Opcode::F64ConvertI32U, MakeSpanU8("\xb8"));
  ExpectRead<Opcode>(Opcode::F64ConvertI64S, MakeSpanU8("\xb9"));
  ExpectRead<Opcode>(Opcode::F64ConvertI64U, MakeSpanU8("\xba"));
  ExpectRead<Opcode>(Opcode::F64PromoteF32, MakeSpanU8("\xbb"));
  ExpectRead<Opcode>(Opcode::I32ReinterpretF32, MakeSpanU8("\xbc"));
  ExpectRead<Opcode>(Opcode::I64ReinterpretF64, MakeSpanU8("\xbd"));
  ExpectRead<Opcode>(Opcode::F32ReinterpretI32, MakeSpanU8("\xbe"));
  ExpectRead<Opcode>(Opcode::F64ReinterpretI64, MakeSpanU8("\xbf"));
}

TEST(ReaderTest, Opcode_Unknown) {
  ExpectReadFailure<Opcode>({{0, "opcode"}, {1, "Unknown opcode: 6"}},
                            MakeSpanU8("\x06"));
  ExpectReadFailure<Opcode>({{0, "opcode"}, {1, "Unknown opcode: 255"}},
                            MakeSpanU8("\xff"));
}
