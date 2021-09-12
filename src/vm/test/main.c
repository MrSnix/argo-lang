#include <munit.h>
#include "core/test-engine.h"
#include "core/test-decoder.h"

MunitTest tests[] = {
    {"/vm__create", vm__create_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/vm__run", vm__run_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/vm__free", vm__free_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/vm__op_create", vm__op_create_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/vm__op_free", vm__op_free_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite suite = {
    "/argo-vm",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE};

int main(int argc, char *const *argv)
{
  return munit_suite_main(&suite, (void *)"argo-vm", argc, argv);
}
