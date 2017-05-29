/*
 * See the dyninst/COPYRIGHT file for copyright information.
 * 
 * We provide the Paradyn Tools (below described as "Paradyn")
 * on an AS IS basis, and do not warrant its validity or performance.
 * We reserve the right to update, modify, or discontinue this
 * software at any time.  We shall have no obligation to supply such
 * updates or modifications or any other form of support to you.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define INSIDE_INSTRUCTION_API

#include "common/src/Types.h"
#include "InstructionDecoder-ptx.h"
#include "Expression.h"
#include "Register.h"
#include "Dereference.h"
#include "Immediate.h" 
#include "BinaryFunction.h"
#include "common/src/singleton_object_pool.h"

namespace Dyninst {
namespace InstructionAPI {

    INSTRUCTION_EXPORT
    InstructionDecoder_ptx::InstructionDecoder_ptx(Architecture a) :
        InstructionDecoderImpl(a)
    {
    }

    INSTRUCTION_EXPORT
    InstructionDecoder_ptx::~InstructionDecoder_ptx()
    {
    }

    INSTRUCTION_EXPORT Instruction::Ptr
    InstructionDecoder_ptx::decode(InstructionDecoder::buffer& b)
    {
        const char* tail = strchr(reinterpret_cast<const char*>(b.start), '\n');
        if (tail)
            b.start = reinterpret_cast<const unsigned char*>(tail) + 1;
        else
            b.start = b.end;

        return InstructionDecoderImpl::decode(b);
    }

    void
    InstructionDecoder_ptx::doDelayedDecode(const Instruction* insn_to_complete)
    {
        InstructionDecoder::buffer b(insn_to_complete->ptr(),
                                     insn_to_complete->size());
        decodeOperands(insn_to_complete);
    }    

    void
    InstructionDecoder_ptx::setMode(bool is64)
    {
    }

    bool
    InstructionDecoder_ptx::decodeOperands(const Instruction* insn_to_complete)
    {
        return true;
    }

    void
    InstructionDecoder_ptx::decodeOpcode(InstructionDecoder::buffer& b)
    {
    }

    Result_Type
    InstructionDecoder_ptx::makeSizeType(unsigned int opType)
    {
        return s64;
    }

};
};

