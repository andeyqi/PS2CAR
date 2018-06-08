#ifndef __COMMON_DEF_H__
#define __COMMON_DEF_H__

#include <stdint.h>

#if defined (__GNUC__)
#define SECTION(x)                  __attribute__((section(x)))
#endif

typedef int32_t (*test_func)(void);

#define TEST_FUNCTION_EXPORT(name) \
const test_func __test_fun##name SECTION("testfuntbl") = (test_func)&name

#endif /* __COMMON_DEF_H__ */
