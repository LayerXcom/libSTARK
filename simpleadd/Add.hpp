#ifndef __ACSP_FOR_ADD_HPP__
#define __ACSP_FOR_ADD_HPP__

#include <iostream>
#include <string>

#include "languages/Bair/BairInstance.hpp"
#include "languages/Bair/BairWitness.hpp"

#include <algebraLib/BitExtract.hpp>

#define PRNMSG(str) do { std::cout << str << std::endl; } while( false )
#define DBGMSG(str) do { } while ( false )

#define EXTDIM 64 // TODO: fix number

using namespace Algebra;

using std::cout;
using std::endl;
using std::string;

namespace Add {

    // FieldElement evalCPoly(const std::vector<FieldElement> & vars,
	// 	const std::vector<FieldElement> & RootHash, const FieldElement& gN);

    class evalp {
        public:
            static void setParams(const unsigned int, const int);
            static FieldElement ep(const std::vector<FieldElement>&);
        private:
            static unsigned int a_param;            
    };

    const short NUMREGS = 3;     

    namespace reg {
        typedef enum RegType
        {
            B00 = 0,
            B01,
            B02        
        } RegType;
    }

    typedef std::vector<std::vector<FieldElement>> & witnessType;
    short getDim(long long);
    void genWitnessAddWithPadding(witnessType arr, const unsigned int, const unsigned int);

    // namespace consts {
    //     const FieldElement oneTransformed = mapIntegerToFieldElement(0, 64, 0);
    // }
    
}


namespace simple_add{
    namespace ACSP_FOR_ADD{
        typedef struct{
            long long length;
            std::vector<Algebra::FieldElement> head;
        }AddCommonParams;

        libstark::BairInstance buildBairInstance(const AddCommonParams&, const unsigned int);
        libstark::BairWitness buildBairWitness(const AddCommonParams &, const unsigned int, const unsigned int);
    }
}

#endif // __ACSP_FOR_ADD_HPP__