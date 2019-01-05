#ifndef __ACSP_FOR_FSRS_INSTANCE_HPP__
#define __ACSP_FOR_FSRS_INSTANCE_HPP__

#include "Fsrs.hpp"
#include "languages/Bair/ConstraintsSys.hpp"

namespace simple_fsrs{
namespace ACSP_FOR_FSRS{

    class Fsrs_CS : public libstark::ConstraintSys{
    public:
        Fsrs_CS();
    
    // the amount of inputs each polynomial expects
    size_t numVars() const{ return 2 * Fsrs::NUMREGS; }
    size_t numMappings() const{ return polys_.size(); }

    Fsrs_CS* clone() const;

    // the constraint polynomials
    const polySet_t& constraints() const{ return polys_; }
    std::vector<FieldElement> eval(const std::vector<FieldElement>& assignment) const;

    private:
        polySet_t polys_;

    };

} // namespace ACSP_FOR_FSRS
} // namespace simple_fsrs



#endif // __ACSP_FOR_FSRS_INSTANCE_HPP__