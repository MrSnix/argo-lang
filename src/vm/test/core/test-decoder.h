#ifndef ARGO_VM__TEST_DECODER_H
#define ARGO_VM__TEST_DECODER_H

#define MUNIT_ENABLE_ASSERT_ALIASES

#include <munit.h>
#include <decoder.h>

MunitResult vm__op_create_test();
MunitResult vm__op_free_test();

MunitResult vm__dec_hlt_test();
MunitResult vm__dec_psh_test();
MunitResult vm__dec_pop_test();
MunitResult vm__dec_add_test();
MunitResult vm__dec_sub_test();
MunitResult vm__dec_mul_test();
MunitResult vm__dec_div_test();
MunitResult vm__dec_jmp_test();
MunitResult vm__dec_jme_test();
MunitResult vm__dec_jmn_test();
MunitResult vm__dec_jmg_test();
MunitResult vm__dec_jml_test();
MunitResult vm__dec_nop_test();
MunitResult vm__dec_cmp_test();

#endif
