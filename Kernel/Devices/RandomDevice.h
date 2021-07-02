#pragma once
// includes
#include "CharacterDevice.h"

namespace Kernel {

class RandomDevice final : public CharacterDevice {
    AK_MAKE_ETERNAL
public:
    RandomDevice();
    virtual ~RandomDevice() override;

    // ^Device
    virtual mode_t required_mode() const override { return 0666; }
    virtual String device_name() const override { return "random"; }

private:
    // ^CharacterDevice
    virtual KResultOr<size_t> read(FileDescription&, u64, UserOrKernelBuffer&, size_t) override;
    virtual KResultOr<size_t> write(FileDescription&, u64, const UserOrKernelBuffer&, size_t) override;
    virtual bool can_read(const FileDescription&, size_t) const override;
    virtual bool can_write(const FileDescription&, size_t) const override { return true; }
    virtual const char* class_name() const override { return "RandomDevice"; }
};

}
