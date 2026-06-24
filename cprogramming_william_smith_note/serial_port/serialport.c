// serial port program for linux
// This is a way to communicate with serial devices, such as microcontrollers,
// sensors, etc. crucial for embedded systems development and debugging.
//
//
// This chapter introduces serial port programming in C, focusing on how to
// communicate with external hardware devices using serial communication
// (sending data one bit at a time).

// It explains:
// What serial communication is and how it differs from parallel communication
// Why C is well-suited for serial port programming due to its low-level
// hardware control How to: Open and close serial ports Configure port settings
// (baud rate, parity, etc.) Read from and write to ports Handle errors and
// common issues A step-by-step example of building a simple C program that
// communicates with a device over a serial port The chapter is based on POSIX
// systems (Linux/macOS), and notes that Windows requires different APIs. By the
// end, you'll understand how to use C to interact with hardware devices like
// sensors, robotic components, and embedded systems via serial communication.

/************************************************************
 * Serial Port Programming Example (POSIX - Linux/macOS)
 *
 * This program:
 * 1. Opens a serial port
 * 2. Configures it (9600 baud, 8N1)
 * 3. Writes data
 * 4. Reads data
 * 5. Closes the port
 ************************************************************/

#include <errno.h>   // Contains error numbers
#include <fcntl.h>   // Contains file control options (O_RDWR, O_NOCTTY, etc.)
#include <stdio.h>   // Contains printf(), perror()
#include <string.h>  // Contains memset()
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h>  // Contains read(), write(), close()

int main() {

  /************************************************************
   * STEP 1: OPEN THE SERIAL PORT
   ************************************************************/

  // Open the serial port device file
  // O_RDWR    -> Open for both reading and writing
  // O_NOCTTY  -> Do not make this device the controlling terminal
  int fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);

  // Check if open() failed
  if (fd == -1) {
    perror("Error opening serial port");
    return 1;
  }

  printf("Serial port opened successfully.\n");

  /************************************************************
   * STEP 2: CONFIGURE THE SERIAL PORT USING termios
   ************************************************************/

  struct termios options; // Create a termios structure

  // Get current serial port settings and store in 'options'
  if (tcgetattr(fd, &options) != 0) {
    perror("Error getting current port settings");
    close(fd);
    return 1;
  }

  // Set input baud rate to 9600
  cfsetispeed(&options, B9600);

  // Set output baud rate to 9600
  cfsetospeed(&options, B9600);

  // Enable receiver (CREAD)
  // Ignore modem control lines (CLOCAL)
  options.c_cflag |= (CLOCAL | CREAD);

  // Disable parity bit (no parity)
  options.c_cflag &= ~PARENB;

  // Use 1 stop bit (clear CSTOPB)
  options.c_cflag &= ~CSTOPB;

  // Clear current character size mask
  options.c_cflag &= ~CSIZE;

  // Set 8 data bits
  options.c_cflag |= CS8;

  // Disable canonical mode (raw input)
  options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

  // Disable output processing
  options.c_oflag &= ~OPOST;

  // Disable software flow control
  options.c_iflag &= ~(IXON | IXOFF | IXANY);

  // Apply the configuration immediately
  if (tcsetattr(fd, TCSANOW, &options) != 0) {
    perror("Error setting port attributes");
    close(fd);
    return 1;
  }

  printf("Serial port configured (9600 8N1).\n");

  /************************************************************
   * STEP 3: WRITE DATA TO SERIAL PORT
   ************************************************************/

  char *message = "Hello, world!";

  // Write message to serial port
  int bytes_written = write(fd, message, strlen(message));

  if (bytes_written < 0) {
    perror("Error writing to serial port");
    close(fd);
    return 1;
  }

  printf("Wrote %d bytes to serial port.\n", bytes_written);

  /************************************************************
   * STEP 4: READ DATA FROM SERIAL PORT
   ************************************************************/

  char buffer[256];                  // Buffer to store incoming data
  memset(buffer, 0, sizeof(buffer)); // Clear buffer

  // Read up to 255 bytes (leave space for null terminator)
  int bytes_read = read(fd, buffer, sizeof(buffer) - 1);

  if (bytes_read < 0) {
    perror("Error reading from serial port");
    close(fd);
    return 1;
  }

  printf("Read %d bytes: %s\n", bytes_read, buffer);

  /************************************************************
   * STEP 5: CLOSE THE SERIAL PORT
   ************************************************************/

  // Close the file descriptor to release the serial port
  close(fd);

  printf("Serial port closed.\n");

  return 0; // Program finished successfully
}

// sudo usermod -a -G dialout $USER
// sudo ./main
//
//
// To test use a real serial device or a virtual serial port (e.g., using socat
// or a loopback device). sudo apt install socat  # on Ubuntu/Debian
// Create a virtual pair:
// sudo socat -d -d PTY,link=/tmp/ttyV0,raw,echo=0
// PTY,link=/tmp/ttyV1,raw,echo=0
//
//
// ⚠ Summary
// The error is not your code — it’s because /dev/ttyS0 has no device attached.
// To fix:
// Connect real hardware, or
// Use a USB-to-serial device (/dev/ttyUSB0), or
// Create a virtual serial port with socat.
