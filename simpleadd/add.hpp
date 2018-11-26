#ifndef __ACSP_FOR_ADD_HPP__
#define __ACSP_FOR_ADD_HPP__

#include "languages/Bair/BairInstance.hpp"
#include "languages/Bair/BairWitness.hpp"

#include <algebraLib/BitExtract.hpp>

#define EXTDIM 64 // TODO: fix number

using namespace Algebra;

namespace simple_add{
    namespace ACSP_FOR_ADD{
        typedef struct{
            long long length;
            std::vector<Algebra::FieldElement> head;
        }AddCommonParams;

        libstark::BairInstance buildBairInstance(const AddCommonParams&);
        // libstark::BairWitness buildBairWitness(const AddCommonParams&)
    }
}

#endif // __ACSP_FOR_ADD_HPP__