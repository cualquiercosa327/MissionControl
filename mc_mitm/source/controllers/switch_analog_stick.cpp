/*
 * Copyright (c) 2020-2022 ndeadly
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "switch_analog_stick.hpp"

namespace ams::controller {

    void SwitchAnalogStick::SetData(uint16_t x, uint16_t y) {
        m_xy[0] = x & 0xff;
        m_xy[1] = (x >> 8) | ((y & 0xff) << 4);
        m_xy[2] = (y >> 4) & 0xff;
    }

    void SwitchAnalogStick::SetX(uint16_t x) {
        m_xy[0] = x & 0xff;
        m_xy[1] = (m_xy[1] & 0xf0) | (x >> 8);
    }

    void SwitchAnalogStick::SetY(uint16_t y) {
        m_xy[1] = (m_xy[1] & 0x0f) | ((y & 0xff) << 4);
        m_xy[2] = (y >> 4) & 0xff;
    }

    uint16_t SwitchAnalogStick::GetX(void) {
        return m_xy[0] | ((m_xy[1] & 0xf) << 8);
    }

    uint16_t SwitchAnalogStick::GetY(void) {
        return (m_xy[1] >> 4) | (m_xy[2] << 4);
    }

    void SwitchAnalogStick::InvertX(void) {
        m_xy[0] ^= 0xff;
        m_xy[1] ^= 0x0f;
    }

    void SwitchAnalogStick::InvertY(void) {
        m_xy[1] ^= 0xf0;
        m_xy[2] ^= 0xff;
    }

}
