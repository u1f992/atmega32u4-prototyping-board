/*
             LUFA Library
     Copyright (C) Dean Camera, 2021.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2021  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Main source file for the VirtualSerial demo. This file contains the main
 * tasks of the demo and is responsible for the initial application hardware
 * configuration.
 */

#include "VirtualSerial.h"

/** LUFA CDC Class driver interface configuration and state information. This
 * structure is passed to all CDC Class driver functions, so that multiple
 * instances of the same class within a device can be differentiated from one
 * another.
 */
USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface = {
    .Config =
        {
            .ControlInterfaceNumber = INTERFACE_ID_CDC_CCI,
            .DataINEndpoint =
                {
                    .Address = CDC_TX_EPADDR,
                    .Size = CDC_TXRX_EPSIZE,
                    .Banks = 1,
                },
            .DataOUTEndpoint =
                {
                    .Address = CDC_RX_EPADDR,
                    .Size = CDC_TXRX_EPSIZE,
                    .Banks = 1,
                },
            .NotificationEndpoint =
                {
                    .Address = CDC_NOTIFICATION_EPADDR,
                    .Size = CDC_NOTIFICATION_EPSIZE,
                    .Banks = 1,
                },
        },
};

/** Standard file stream for the CDC interface when set up, so that the virtual
 * CDC COM port can be used like any regular character stream in the C APIs.
 */
static FILE USBSerialStream;

/** Main program entry point. This routine contains the overall program flow,
 * including initial setup of all components and the main program loop.
 */
int main(void) {
  SetupHardware();

  /* Create a regular character stream for the interface so that it can be used
   * with the stdio.h functions */
  CDC_Device_CreateStream(&VirtualSerial_CDC_Interface, &USBSerialStream);

  // LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
  GlobalInterruptEnable();

  for (;;) {
    // CheckJoystickMovement();

    /* Must throw away unused bytes from the host, or it will lock up while
     * waiting for the device */
    CDC_Device_ReceiveByte(&VirtualSerial_CDC_Interface);

    CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
    USB_USBTask();

    // int ch;
    // while ((ch = fgetc(stdin)) != EOF) {
    //   fputc(ch, stdout);
    // }
    return 0;
  }
}

/** Configures the board hardware and chip peripherals for the demo's
 * functionality. */
void SetupHardware(void) {
#if (ARCH == ARCH_AVR8)
  /* Disable watchdog if enabled by bootloader/fuses */
  MCUSR &= ~(1 << WDRF);
  wdt_disable();

  /* Disable clock division */
  clock_prescale_set(clock_div_1);
#elif (ARCH == ARCH_XMEGA)
  /* Start the PLL to multiply the 2MHz RC oscillator to 32MHz and switch the
   * CPU core to run from it */
  XMEGACLK_StartPLL(CLOCK_SRC_INT_RC2MHZ, 2000000, F_CPU);
  XMEGACLK_SetCPUClockSource(CLOCK_SRC_PLL);

  /* Start the 32MHz internal RC oscillator and start the DFLL to increase it to
   * 48MHz using the USB SOF as a reference */
  XMEGACLK_StartInternalOscillator(CLOCK_SRC_INT_RC32MHZ);
  XMEGACLK_StartDFLL(CLOCK_SRC_INT_RC32MHZ, DFLL_REF_INT_USBSOF, F_USB);

  PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;
#endif

  /* Hardware Initialization */
  // Joystick_Init();
  // LEDs_Init();
  USB_Init();
}

/** Checks for changes in the position of the board joystick, sending strings to
 * the host upon each change. */
// void CheckJoystickMovement(void) {
//   uint8_t JoyStatus_LCL = Joystick_GetStatus();
//   char *ReportString = NULL;
//   static bool ActionSent = false;

//   if (JoyStatus_LCL & JOY_UP)
//     ReportString = "Joystick Up\r\n";
//   else if (JoyStatus_LCL & JOY_DOWN)
//     ReportString = "Joystick Down\r\n";
//   else if (JoyStatus_LCL & JOY_LEFT)
//     ReportString = "Joystick Left\r\n";
//   else if (JoyStatus_LCL & JOY_RIGHT)
//     ReportString = "Joystick Right\r\n";
//   else if (JoyStatus_LCL & JOY_PRESS)
//     ReportString = "Joystick Pressed\r\n";
//   else
//     ActionSent = false;

//   if ((ReportString != NULL) && (ActionSent == false)) {
//     ActionSent = true;

//     /* Write the string to the virtual COM port via the created character
//     stream
//      */
//     fputs(ReportString, &USBSerialStream);

//     /* Alternatively, without the stream: */
//     // CDC_Device_SendString(&VirtualSerial_CDC_Interface, ReportString);
//   }
// }

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void) {
  // LEDs_SetAllLEDs(LEDMASK_USB_ENUMERATING);
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void) {
  // LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void) {
  bool ConfigSuccess = true;

  ConfigSuccess &= CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);

  // LEDs_SetAllLEDs(ConfigSuccess ? LEDMASK_USB_READY : LEDMASK_USB_ERROR);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void) {
  CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
}

/** CDC class driver callback function the processing of changes to the virtual
 *  control lines sent from the host..
 *
 *  \param[in] CDCInterfaceInfo  Pointer to the CDC class interface
 * configuration structure being referenced
 */
void EVENT_CDC_Device_ControLineStateChanged(
    USB_ClassInfo_CDC_Device_t *const CDCInterfaceInfo) {
  /* You can get changes to the virtual CDC lines in this callback; a common
     use-case is to use the Data Terminal Ready (DTR) flag to enable and
     disable CDC communications in your application when set to avoid the
     application blocking while waiting for a host to become ready and read
     in the pending data from the USB endpoints.
  */
  bool HostReady = (CDCInterfaceInfo->State.ControlLineStates.HostToDevice &
                    CDC_CONTROL_LINE_OUT_DTR) != 0;

  (void)HostReady;
}
