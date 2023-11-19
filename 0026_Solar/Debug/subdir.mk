################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HLCD_program.c \
../HLDR_program.c \
../HServo_program.c \
../MADC_program.c \
../MDIO_program.c \
../MTIMER_program.c \
../main.c 

OBJS += \
./HLCD_program.o \
./HLDR_program.o \
./HServo_program.o \
./MADC_program.o \
./MDIO_program.o \
./MTIMER_program.o \
./main.o 

C_DEPS += \
./HLCD_program.d \
./HLDR_program.d \
./HServo_program.d \
./MADC_program.d \
./MDIO_program.d \
./MTIMER_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


