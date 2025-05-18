MCU = atmega32u4
F_CPU = 16000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os
TARGET = blink
PROGRAMMER = usbasp

all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(TARGET).elf: $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $<

flash: $(TARGET).hex
	avrdude -c $(PROGRAMMER) -p $(MCU) -U flash:w:$(TARGET).hex

fuse:
	avrdude -c $(PROGRAMMER) -p $(MCU) -U lfuse:w:0xdf:m -U hfuse:w:0x99:m -U efuse:w:0xf3:m

clean:
	rm -f *.elf *.hex
