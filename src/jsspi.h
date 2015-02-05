/*
 * This file is part of Espruino, a JavaScript interpreter for Microcontrollers
 *
 * Copyright (C) 2013 Gordon Williams <gw@pur3.co.uk>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * ----------------------------------------------------------------------------
 * SPI Utility functions, and software SPI
 * ----------------------------------------------------------------------------
 */

#include "jshardware.h"

typedef JshSPIInfo spi_sender_data; // the larger of JshSPIInfo or IOEventFlags
typedef int (*spi_sender)(int data, spi_sender_data *info);

void jsspiPopulateSPIInfo(JshSPIInfo *inf, JsVar *options);

// Get the correct SPI send function (and the data to send to it)
bool jsspiGetSendFunction(JsVar *spiDevice, spi_sender *spiSend, spi_sender_data *spiSendData);

// Send 8 bits, but with a nibble for each bit - used by jswrap_spi_send4bit
void jsspiSend4bit(IOEventFlags device, unsigned char data, int bit0, int bit1);

// Send 8 bits, but with a byte for each bit - used by jswrap_spi_send8bit
void jsspiSend8bit(IOEventFlags device, unsigned char data, int bit0, int bit1);
