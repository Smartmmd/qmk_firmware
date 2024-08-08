/* Copyright 2022 Jacky
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "quantum.h"


void keyboard_pre_init_kb(void) {

    AFIO->MAPR = (AFIO->MAPR & ~AFIO_MAPR_SWJ_CFG_Msk);
    AFIO->MAPR|= AFIO_MAPR_SWJ_CFG_DISABLE;
    gpio_set_pin_output(A8);
    gpio_write_pin_high(A8);
    
    gpio_set_pin_output(A14);
    gpio_write_pin_high(A14);
    keyboard_pre_init_user();
}


bool process_record_kb(uint16_t keycode, keyrecord_t *record)
{
    if (secure_is_locked())
    {
        if ((keycode==QK_SECURE_TOGGLE) || (keycode==MO(1)))
        {
            return true;
        }
        return false;
    }
    secure_activity_event();
       
    return true;
}


