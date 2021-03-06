/* Copyright (c) 2015 Convey Computer Corporation
 *
 * This file is part of the OpenHT toolset located at:
 *
 * https://github.com/TonyBrewer/OpenHT
 *
 * Use and distribution licensed under the BSD 3-clause license.
 * See the LICENSE file for the complete license text.
 */

#include "HtcAttributes.h"

//----------------------------------------------------------------------------
// FsmPlaceHolderAttribute
//----------------------------------------------------------------------------


// Return a properly down-casted FsmPlaceHolderAttribute from an expression.
FsmPlaceHolderAttribute *getFsmPlaceHolderAttribute(SgExpression *expr)
{
  AstAttribute *attr = expr->getAttribute("fsm_placeholder");
  // The attribute may be absent, but dynamic_cast returns null for null.
  return dynamic_cast<FsmPlaceHolderAttribute *>(attr);
}


FsmPlaceHolderAttribute::FsmPlaceHolderAttribute(SgLabelStatement *targ)
{
  targetLabel = targ;
}

//----------------------------------------------------------------------------
// ParallelCallAttribute
//----------------------------------------------------------------------------

// Return a properly down-casted ParallelCallAttribute from an expression.
ParallelCallAttribute *getParallelCallAttribute(SgExpression *expr)
{
  AstAttribute *attr = expr->getAttribute("parallel_call");
  // The attribute may be absent, but dynamic_cast returns null for null.
  return dynamic_cast<ParallelCallAttribute *>(attr);
}

ParallelCallAttribute::ParallelCallAttribute(SgLabelStatement *join)
{
  joinCycleLabel = join;
}

//----------------------------------------------------------------------------
// DontProcessAttribute
//----------------------------------------------------------------------------

// Return a properly down-casted DontProcessAttribute from a node.
DontProcessAttribute *getDontProcessAttribute(SgNode *n)
{
  AstAttribute *attr = n->getAttribute("dont_process");
  // The attribute may be absent, but dynamic_cast returns null for null.
  return dynamic_cast<DontProcessAttribute *>(attr);
}


//----------------------------------------------------------------------------
// OmpUplevelAttribute
//----------------------------------------------------------------------------

// Return a properly down-casted OmpUplevelAttribute from a VariableSymbol
OmpUplevelAttribute *getOmpUplevelAttribute(const SgVariableSymbol *sym)
{
  AstAttribute *attr = sym->getAttribute("omp_uplevel");
  return dynamic_cast<OmpUplevelAttribute *>(attr);
}

// Sets the uplevel attribute for the symbol to the given level.
// Modifies the existing attribute's level if it exists.   Otherwise,
// creates a new attribute with the given level.

void setOmpUplevelAttribute(SgVariableSymbol *sym, int level, bool is_parm)
{
    OmpUplevelAttribute *attr = getOmpUplevelAttribute(sym);
    if (attr) {
        attr->setUplevel(level);
        attr->setIsParameter(is_parm);
    } else {
        attr = new OmpUplevelAttribute(level, is_parm);
        sym->addNewAttribute("omp_uplevel", attr);
    }
}


//----------------------------------------------------------------------------
// OmpEnclosingFunctionAttribute
//----------------------------------------------------------------------------

// Return a properly down-casted OmpEnclosingFunctionAttribute for a 
// SgFunctionDeclaration.
OmpEnclosingFunctionAttribute* 
getOmpEnclosingFunctionAttribute(const SgFunctionDeclaration *inner)
{
    AstAttribute *attr = inner->getAttribute("omp_enclosing_function");
    return dynamic_cast<OmpEnclosingFunctionAttribute *>(attr);

}


// Sets the enclosing function for an outlined region function.
// Modifies the existing attribute's level if it exists.   Otherwise,
// creates a new attribute with the given level.

void setOmpEnclosingFunctionAttribute(SgFunctionDeclaration *inner_region,
                                      SgFunctionDeclaration *outer_region)
{
    OmpEnclosingFunctionAttribute *attr = 
        getOmpEnclosingFunctionAttribute(inner_region);
    if (attr) {
        attr->setEnclosingFunction(outer_region);
    } else {
        attr = new OmpEnclosingFunctionAttribute(outer_region);
        inner_region->addNewAttribute("omp_enclosing_function", attr);
    }
}


//----------------------------------------------------------------------------
// DefaultModuleWidthAttribute
//----------------------------------------------------------------------------

// Return a properly down-casted DefaultModuleWidthAttribute from a glob scope.
DefaultModuleWidthAttribute *getDefaultModuleWidthAttribute(SgGlobal *gs)
{
  AstAttribute *attr = gs->getAttribute("default_module_width");
  // The attribute may be absent, but dynamic_cast returns null for null.
  return dynamic_cast<DefaultModuleWidthAttribute *>(attr);
}

DefaultModuleWidthAttribute::DefaultModuleWidthAttribute(int w)
{
  width = w;
}


