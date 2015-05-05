################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
OLED_SSD1306_Driver1.lss \

FLASH_IMAGE += \
OLED_SSD1306_Driver1.hex \

EEPROM_IMAGE += \
OLED_SSD1306_Driver1.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: OLED_SSD1306_Driver1.elf secondary-outputs

# Tool invocations
OLED_SSD1306_Driver1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,OLED_SSD1306_Driver1.map -mmcu=atmega16 -o "OLED_SSD1306_Driver1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

OLED_SSD1306_Driver1.lss: OLED_SSD1306_Driver1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S OLED_SSD1306_Driver1.elf  >"OLED_SSD1306_Driver1.lss"
	@echo 'Finished building: $@'
	@echo ' '

OLED_SSD1306_Driver1.hex: OLED_SSD1306_Driver1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex OLED_SSD1306_Driver1.elf  "OLED_SSD1306_Driver1.hex"
	@echo 'Finished building: $@'
	@echo ' '

OLED_SSD1306_Driver1.eep: OLED_SSD1306_Driver1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex OLED_SSD1306_Driver1.elf  "OLED_SSD1306_Driver1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: OLED_SSD1306_Driver1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 OLED_SSD1306_Driver1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) OLED_SSD1306_Driver1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
