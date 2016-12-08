#include "tizen-gpio.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>

int gpio_isinit = 0;
static volatile int *gpio_base[2];

int hello() {
  printf("Hello World\n");
}

int init_gpio() {
    int fd ;

    if ((fd = open ("/dev/mem", O_RDWR | O_SYNC) ) < 0) {
        printf("Unable to open /dev/mem\n");
        return -1;
    }

    gpio_base[0] = (volatile int*)mmap(0, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
                                GPIO0);
    if (gpio_base[0] < 0){
        printf("Mmap failed.\n");
        return -1;
    }

    gpio_base[1] = (volatile int*)mmap(0, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
                                GPIO3);
    if (gpio_base[1] < 0){
        printf("Mmap failed.\n");
        return -1;
    }
    gpio_isinit = 1;
    return 0;
}

int set_pin_mode(int pin, int mode) {
    int port = pin >> 3;
    int offset = pin & 7;

    if (!gpio_isinit) init_gpio();

    volatile int *base = gpio_base[port > 0x100?0:1];
    if (mode)
        *(base + port) |= (1 << offset);
    else
        *(base + port) &= ~(1 << offset);
    return 0;
}

int get_pin_mode(int pin) {
    int port = pin >> 3;
    int offset = pin & 7;

    if (!gpio_isinit) {
        printf("GPIO is not initialized!!\n");
        return -1;
    }

    volatile int *base = gpio_base[port > 0x100?0:1];
    return !!(*(base + port) & (1 << offset));
}

int get_pin_value(int pin) {
    int port = pin >> 3;
    int offset = pin & 7;

    if (!gpio_isinit) {
        printf("GPIO is not initialized!!\n");
        return -1;
    }

    volatile int *base = gpio_base[port > 0x100?0:1];
    return !!(*(base + (port + 1)) & (1 << offset));
}

int set_pin_value(int pin, int value) {
    if (get_pin_mode(pin) != GPIO_OUT) {
        printf("GPIO pin is not on write mode!\n");
        return -1;
    }
    int port = pin >> 3;
    int offset = pin & 7;

    if (!gpio_isinit) {
        printf("GPIO is not initialized!!\n");
        return -1;
    }

    volatile int *base = gpio_base[port > 0x100?0:1];

    if (value)
        *(base + (port + 1)) &= ~(1 << offset);
    else
        *(base + (port + 1)) |= (1 << offset);
    return 0;
}

void set_gpio_callback(int pin, void* callback) {
    printf("Not Implemented");
}
