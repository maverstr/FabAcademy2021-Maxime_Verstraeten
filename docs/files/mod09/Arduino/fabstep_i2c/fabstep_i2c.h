// I2C
#define PIN_PULL 15
#define PIN_SDA 16
#define PIN_SCL 17
#define PIN_LED 7

#define I2C_ADDR_OFFSET 8
#define I2C_FREQ 400000
#define ADDR_UNKNOWN 255

// topology
#define PIN_TX 10
#define PIN_RX 11
#define PIN_PREV 9
#define PIN_NEXT 14

// stepper control
#define PIN_VREF 2
#define PIN_1A 0
#define PIN_1B 1
#define PIN_2A 3
#define PIN_2B 4
#define VREF_LEVEL 50

#define MAX_MSG_LENGTH 128
#define MAX_VAL_LENGTH 16

#define MIN_POS -80
#define MAX_POS 80

#define MAX_SPEED 100.0

void processI2C(int numBytes);
