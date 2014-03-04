/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_GPIO_API_H
#define MBED_GPIO_API_H

#include "device.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Set the given pin as GPIO
 * @param pin The pin to be set as GPIO
 * @return The GPIO port mask for this pin
 **/
uint32_t gpio_set(PinName pin);

/* GPIO object */
void gpio_init(gpio_t *obj, PinName pin);

void gpio_mode (gpio_t *obj, PinMode mode);
void gpio_dir  (gpio_t *obj, PinDirection direction);

void gpio_write(gpio_t *obj, int value);
int  gpio_read (gpio_t *obj);

#define GPIO_INIT_IN(obj, pin, mode) \
    gpio_init(obj, pin), \
    gpio_mode(obj, mode), \
    gpio_dir(obj, PIN_INPUT)
    
#define GPIO_INIT_OUT(obj, pin, mode, value) \
    gpio_init(obj, pin), \
    gpio_write(obj, value), \
    gpio_dir(obj, PIN_OUTPUT), \
    gpio_mode(obj, mode)

#ifdef __cplusplus
}
#endif

#endif
