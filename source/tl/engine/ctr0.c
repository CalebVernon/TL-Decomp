#include <stdint.h>
#include <stddef.h>

extern uint32_t MEMORY_START_ZERO; // DAT_00100040
extern uint32_t MEMORY_END_ZERO;   // DAT_00100044
extern uint32_t ROM_LITERAL;       // DAT_001000d4

// 00100024
void ClearMemoryBlock(void) {
    uint32_t *ptr = (uint32_t *)MEMORY_START_ZERO;
    uint32_t *end = (uint32_t *)MEMORY_END_ZERO;

    while (ptr < end) {
        *ptr++ = 0;
    }
}

// 00100058
void WritePointerOffset(uint8_t *ptr, uint16_t value) {
    uint8_t *addr = ptr + 4;
    uint16_t *target = (uint16_t *)(*addr + 4);
    *target = value;
}

// 00100000
void InitializeSystem(void) {
    ClearMemoryBlock();           // 00100024

    uint8_t example_byte_ptr[8] = {0};
    WritePointerOffset(example_byte_ptr, 0x1234); // 00100058

    uint32_t literal = ROM_LITERAL; // 001000d4
    (void)literal;

    // 00100020
    while(1) {}
}
// ram: 0x0019d7a4 - 0x0019d7af
uint32_t MaskLowStatus(uint32_t r10)
{
    return r10 & 0x00008D00;
}
