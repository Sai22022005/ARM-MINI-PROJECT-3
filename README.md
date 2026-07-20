# AI Secure Login Authentication System Using LPC2129 with EM-18 RFID Reader and 4x4 Keypad Matrix

## Overview
The AI Secure Login Authentication System is an embedded systems project developed using the LPC2129 ARM7 microcontroller, EM-18 RFID Reader, and a 4x4 Keypad Matrix. It provides dual-level authentication by verifying an RFID card followed by password validation. The system displays authentication status on an LCD and LEDs, ensuring secure access control.

## Features
- Dual-level authentication (RFID + Password)
- EM-18 RFID card verification
- 4x4 Keypad password input
- UART communication support
- LCD-based authentication status
- LED indication for access granted/denied
- AI-like embedded authentication logic

## Hardware Requirements
- LPC2129 Development Board
- EM-18 RFID Reader Module
- RFID Tags/Cards
- 4x4 Keypad Matrix
- 16x2 LCD Display
- LEDs
- Breadboard
- Jumper Wires
- Power Supply

## Software Requirements
- Keil µVision
- Flash Magic
- Tera Term

## Working
1. Initialize the LPC2129, LCD, UART, RFID Reader, and Keypad.
2. Scan an RFID card using the EM-18 RFID Reader.
3. Verify the RFID card with stored credentials.
4. If valid, prompt the user to enter a password through the 4x4 keypad.
5. Compare the entered password with the stored password.
6. Display the authentication result on the LCD, LEDs, and UART terminal.

## Applications
- Smart Door Lock Systems
- Secure Access Control
- RFID Authentication Systems
- Office Security Systems
- Embedded Security Projects

## Advantages
- Dual-layer security
- Contactless RFID authentication
- Password-based verification
- Real-time authentication
- Easy to implement and understand
- Enhances embedded programming skills

## Future Enhancements
- Fingerprint or Face Recognition
- OTP-based authentication
- IoT-based remote access monitoring
- Mobile application integration
- Event logging using SD Card or EEPROM
- Cloud-based authentication system

## Conclusion
This project demonstrates how the LPC2129 microcontroller, EM-18 RFID Reader, and 4x4 Keypad Matrix can be integrated to build a secure authentication system. It provides practical experience in RFID interfacing, keypad communication, UART, and embedded security applications.

## Author
**Edula Saikumar**
