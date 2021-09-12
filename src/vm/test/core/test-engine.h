#ifndef ARGO_VM__TEST_ENGINE_H
#define ARGO_VM__TEST_ENGINE_H

#define MUNIT_ENABLE_ASSERT_ALIASES

#include <munit.h>

MunitResult vm__create_test();
MunitResult vm__run_test();
MunitResult vm__free_test();

#endif
