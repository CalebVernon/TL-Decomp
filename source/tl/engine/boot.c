#include <stdint.h>
#include <stddef.h>

/* stubs so it builds */
__attribute__((noreturn))
static void halt_baddata(void) {
    for (;;) {}
}

/*
 * 0x001000C2
 */
void sub_001000C2(
    uint32_t param_1,
    uint32_t param_2,
    int32_t  param_3,
    int32_t  param_4,
    uint32_t param_5,
    uint16_t *param_6
) {
    uint8_t  bVar1;
    uint32_t r7;   /* unaffiliated register */

    /* store shifted r7 */
    *(uint32_t *)(param_3 + ((uint32_t)param_4 >> 12)) = r7 >> 1;
    *param_6 = (uint16_t)(r7 >> 1);

    *(int32_t *)(param_6 + 0x24) = param_4;

    if (param_4 != 1) {
        halt_baddata();
    }

    bVar1 = *(uint8_t *)(((uintptr_t)param_6 >> 8) + param_3);

    ((uint8_t *)&param_6)[(uintptr_t)param_6] = bVar1;

    *(uint16_t *)((uintptr_t)bVar1 + (uintptr_t)param_6) = 0;
    *(uint16_t *)(bVar1 - 0xDC) = 0;

    *(char *)((uintptr_t)&param_6 >> 0x13) = (char)(uintptr_t)&param_6;

    halt_baddata();
}
