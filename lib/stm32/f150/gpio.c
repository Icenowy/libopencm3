/** @defgroup gpio_file GPIO

@ingroup STM32F1xx

@brief <b>libopencm3 STM32F1xx General Purpose I/O</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

@date 18 August 2012

Each I/O port has 16 individually configurable bits. Many I/O pins share GPIO
functionality with a number of alternate functions and must be configured to
the alternate function mode if these are to be accessed. A feature is available
to remap alternative functions to a limited set of alternative pins in the
event of a clash of requirements.

The data registers associated with each port for input and output are 32 bit
with the upper 16 bits unused. The output buffer must be written as a 32 bit
word, but individual bits may be set or reset separately in atomic operations
to avoid race conditions during interrupts. Bits may also be individually
locked to prevent accidental configuration changes. Once locked the
configuration cannot be changed until after the next reset.

Each port bit can be configured as analog or digital input, the latter can be
floating or pulled up or down. As outputs they can be configured as either
push-pull or open drain, digital I/O or alternate function, and with maximum
output speeds of 2MHz, 10MHz, or 50MHz.

On reset all ports are configured as digital floating input.

@section gpio_api_ex Basic GPIO Handling API.

Example 1: Push-pull digital output actions on ports C2 and C9

@code
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL,  GPIO2 | GPIO9);
	gpio_set(GPIOC, GPIO2 | GPIO9);
	gpio_clear(GPIOC, GPIO2);
	gpio_toggle(GPIOC, GPIO2 | GPIO9);
	gpio_port_write(GPIOC, 0x204);
@endcode

Example 1: Digital input on port C12

@code
	gpio_set_mode(GPIOC, GPIO_MODE_INPUT, GPIO_CNF_INPUT, GPIO12);
	reg16 = gpio_port_read(GPIOC);
@endcode

LGPL License Terms @ref lgpl_license
*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/gpio.h>
