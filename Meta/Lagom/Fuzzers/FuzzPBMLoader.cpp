// includes
#include <LibGfx/PBMLoader.h>
#include <stddef.h>
#include <stdint.h>

// extern c function
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* datam size_t size)
{
    Gfx::load_pbm_from_memory(data, size);
    return 0;
}