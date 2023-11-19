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
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
0026_HLDR.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: 0026_HLDR.elf secondary-outputs

# Tool invocations
0026_HLDR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,0026_HLDR.map -mmcu=atmega32 -o "0026_HLDR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

0026_HLDR.lss: 0026_HLDR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 0026_HLDR.elf  >"0026_HLDR.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 0026_HLDR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 0026_HLDR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 0026_HLDR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
