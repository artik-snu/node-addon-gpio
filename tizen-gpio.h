#define BLOCK_SIZE 4096
#define GPIO0   0x13400000
#define GPIO3   0x14010000

typedef enum {
      GPIO_IN = 0,
          GPIO_OUT = 1
} gpio_direction_e;

int hello();
int init_gpio();
int set_pin_mode(int pin, int mode);
int get_pin_mode(int pin);
int get_pin_value(int pin);
int set_pin_value(int pin, int value);
void set_gpio_callback(int pin, void* callback);
