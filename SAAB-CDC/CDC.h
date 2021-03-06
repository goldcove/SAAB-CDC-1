/*
 * C++ Class for handling CD changer emulator on SAAB I-Bus
 * Copyright (C) 2016  Karlis Veilands
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Created by: Karlis Veilands
 * Created on: Jun 4, 2015
 * Modified by: Karlis Veilands
 * Modified on: November 29, 2016
 */

#ifndef CDC_H
#define CDC_H

#include <Arduino.h>

/**
 * Other useful stuff
 */

#define MODULE_NAME                 "BlueSaab"
#define LAST_EVENT_IN_TIMEOUT       3000    // Milliseconds
#define NODE_STATUS_TX_MSG_SIZE     4       // Decimal; defines how many frames do we need to reply with to '6A1'

/**
 * TX frames:
 */

#define GENERAL_STATUS_CDC          0x3C8
#define NODE_STATUS_TX_CDC          0x6A2
#define SOUND_REQUEST               0x430

/**
 * RX frames:
 */

#define CDC_CONTROL                 0x3C0
#define DISPLAY_RESOURCE_GRANT      0x368
#define NODE_STATUS_RX_IHU          0x6A1
#define STEERING_WHEEL_BUTTONS      0x290
#define IHU_DISPLAY_RESOURCE_REQ	0x348

/**
 * Timer definitions:
 */

#define NODE_STATUS_TX_INTERVAL     140     // Replies to '6A1' request need to be sent with no more than 140ms interval; tolerances +/- 10%
#define CDC_STATUS_TX_BASETIME      950     // The CDC status frame must be sent periodically within this timeframe; tolerances +/- 10%
#define NODE_UPDATE_BASETIME        1000

/**
 * Class:
 */

class CDChandler {
public:
    void printCanTxFrame();
    void printCanRxFrame();
    void openCanBus();
    void handleRxFrame();
    void handleIhuButtons();
    void handleSteeringWheelButtons();
    void handleCdcStatus();
    void sendCdcStatus(boolean event, boolean remote, boolean cdcActive);
    void sendCanFrame(int message_id, unsigned char *msg);
    void checkCanEvent(int frameElement);
};

/**
 * Variables:
 */

extern CDChandler CDC;

#endif
