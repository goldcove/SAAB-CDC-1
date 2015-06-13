//
//  CDC.h
//  SAAB-CDC
//
//  Created by Karlis Veilands on 6/5/15.
//
//

#ifndef CDC_H
#define CDC_H

#include "Arduino.h"
#include "CAN.h"

//----------------------------------------------------------------------------
// CLASS
//----------------------------------------------------------------------------

class CDCClass
{
public:
    void open_CAN_bus();
    void handle_CDC_status();
    void print_bus();
    void handle_BT_connection();
    void handle_RX_frame();
    void handle_CDC_control();
    void handle_SID_buttons();
    void send_CDC_status(boolean event, boolean remote);
    void send_display_request();
    void write_text_on_display(char text[]);
};

//----------------------------------------------------------------------------
// VARIABLES
//----------------------------------------------------------------------------

extern CDCClass CDC;

#endif
