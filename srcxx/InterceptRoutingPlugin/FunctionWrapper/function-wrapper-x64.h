#ifndef FUNCTION_WRAPPER_X64_H_
#define FUNCTION_WRAPPER_X64_H_

#include "hookzz_internal.h"

#include "AssemblyClosureTrampoline.h"
#include "InterceptRouting.h"
#include "Interceptor.h"
#include "intercept_routing_handler.h"

#include "InterceptRouting/x64/X64InterceptRouting.h"

class FunctionWrapperRouting : public X64InterceptRouting {
public:
  FunctionWrapperRouting(HookEntry *entry) : X64InterceptRouting(entry) {
  }

  void *GetTrampolineTarget();

private:
  void BuildPreCallRouting();

  void BuildPostCallRouting();

private:
  void *prologue_dispatch_bridge;

  void *epilogue_dispatch_bridge;
};

#endif