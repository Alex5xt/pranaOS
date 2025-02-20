/*
 * Copyright (c) 2021, krishpranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

// includes
#include <libabi/Keyboard.h>
#include <libutils/Lock.h>
#include <libutils/RingBuffer.h>

#include "ps2/LegacyDevice.h"

#define PS2KBD_ESCAPE 0xE0

struct LegacyKeyboard : public LegacyDevice
{
private:
    Lock _events_lock{"legacy-keyboard-event"};
    RingBuffer<char> _events{sizeof(KeyboardPacket) * 1024};
    bool _escaped = false;
    KeyMap *_keymap = nullptr;
    KeyMotion _keystate[__KEY_COUNT] = {};

    Key scancode_to_key(int scancode);

    Text::Rune key_to_rune(Key key);

    KeyModifier modifiers();

    void handle_key(Key key, KeyMotion motion);

public:
    LegacyKeyboard(DeviceAddress address);

    void handle_interrupt() override;

    bool can_read() override;

    ResultOr<size_t> read(size64_t offset, void *buffer, size_t size) override;

    JResult call(IOCall request, void *args) override;
};