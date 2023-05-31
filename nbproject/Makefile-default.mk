#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/7_segement/ecu_7_segement.c ECU_Layer/button/hal_button.c ECU_Layer/LCD/ecu_char_lcd.c ECU_Layer/LED/ecu_led.c ECU_Layer/ecu_layer_init.c MCAL_Layer/ADC/hal_adc.c MCAL_Layer/CCP/CCP1/hal_ccp1.c MCAL_Layer/EEPROM/hal_eeprom.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/Interrupt/mcal_internal_interrupt.c MCAL_Layer/Interrupt/mcal_interrupt_manager.c MCAL_Layer/Interrupt/mcal_external_interrupt.c MCAL_Layer/Timer/Timer0/hal_timer0.c MCAL_Layer/Timer/Timer1/hal_timer1.c MCAL_Layer/Timer/Timer2/hal_timer2.c MCAL_Layer/Timer/Timer3/hal_timer3.c MCAL_Layer/USART/hal_usart.c MCAL_Layer/device_config.c application.c MCAL_Layer/SPI/hal_SPI.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1 ${OBJECTDIR}/ECU_Layer/button/hal_button.p1 ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1 ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1 ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1 ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1 ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1 ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1 ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1.d ${OBJECTDIR}/ECU_Layer/button/hal_button.p1.d ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1.d ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1.d ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1.d ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1.d ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1.d ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1 ${OBJECTDIR}/ECU_Layer/button/hal_button.p1 ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1 ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1 ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1 ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1 ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1 ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1 ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1

# Source Files
SOURCEFILES=ECU_Layer/7_segement/ecu_7_segement.c ECU_Layer/button/hal_button.c ECU_Layer/LCD/ecu_char_lcd.c ECU_Layer/LED/ecu_led.c ECU_Layer/ecu_layer_init.c MCAL_Layer/ADC/hal_adc.c MCAL_Layer/CCP/CCP1/hal_ccp1.c MCAL_Layer/EEPROM/hal_eeprom.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/Interrupt/mcal_internal_interrupt.c MCAL_Layer/Interrupt/mcal_interrupt_manager.c MCAL_Layer/Interrupt/mcal_external_interrupt.c MCAL_Layer/Timer/Timer0/hal_timer0.c MCAL_Layer/Timer/Timer1/hal_timer1.c MCAL_Layer/Timer/Timer2/hal_timer2.c MCAL_Layer/Timer/Timer3/hal_timer3.c MCAL_Layer/USART/hal_usart.c MCAL_Layer/device_config.c application.c MCAL_Layer/SPI/hal_SPI.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1: ECU_Layer/7_segement/ecu_7_segement.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/7_segement" 
	@${RM} ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1 ECU_Layer/7_segement/ecu_7_segement.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.d ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/button/hal_button.p1: ECU_Layer/button/hal_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/button/hal_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/button/hal_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/button/hal_button.p1 ECU_Layer/button/hal_button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/button/hal_button.d ${OBJECTDIR}/ECU_Layer/button/hal_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/button/hal_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1: ECU_Layer/LCD/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1 ECU_Layer/LCD/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.d ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1: ECU_Layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ECU_Layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.d ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1: ECU_Layer/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1 ECU_Layer/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_layer_init.d ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1: MCAL_Layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1 MCAL_Layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.d ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1: MCAL_Layer/CCP/CCP1/hal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/CCP/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1 MCAL_Layer/CCP/CCP1/hal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.d ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1: MCAL_Layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1 MCAL_Layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1: MCAL_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 MCAL_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1: MCAL_Layer/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 MCAL_Layer/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1: MCAL_Layer/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 MCAL_Layer/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1: MCAL_Layer/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1: MCAL_Layer/Timer/Timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1 MCAL_Layer/Timer/Timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1: MCAL_Layer/Timer/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1 MCAL_Layer/Timer/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1: MCAL_Layer/Timer/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1 MCAL_Layer/Timer/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1: MCAL_Layer/Timer/Timer3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1 MCAL_Layer/Timer/Timer3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1: MCAL_Layer/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 MCAL_Layer/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.d ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1: MCAL_Layer/SPI/hal_SPI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1 MCAL_Layer/SPI/hal_SPI.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.d ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1: ECU_Layer/7_segement/ecu_7_segement.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/7_segement" 
	@${RM} ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1 ECU_Layer/7_segement/ecu_7_segement.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.d ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/7_segement/ecu_7_segement.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/button/hal_button.p1: ECU_Layer/button/hal_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/button/hal_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/button/hal_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/button/hal_button.p1 ECU_Layer/button/hal_button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/button/hal_button.d ${OBJECTDIR}/ECU_Layer/button/hal_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/button/hal_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1: ECU_Layer/LCD/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1 ECU_Layer/LCD/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.d ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LCD/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1: ECU_Layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ECU_Layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.d ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1: ECU_Layer/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1 ECU_Layer/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_layer_init.d ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1: MCAL_Layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1 MCAL_Layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.d ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1: MCAL_Layer/CCP/CCP1/hal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/CCP/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1 MCAL_Layer/CCP/CCP1/hal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.d ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/CCP/CCP1/hal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1: MCAL_Layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1 MCAL_Layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1: MCAL_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 MCAL_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1: MCAL_Layer/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1 MCAL_Layer/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1: MCAL_Layer/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1 MCAL_Layer/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1: MCAL_Layer/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1 MCAL_Layer/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1: MCAL_Layer/Timer/Timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1 MCAL_Layer/Timer/Timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/Timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1: MCAL_Layer/Timer/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1 MCAL_Layer/Timer/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1: MCAL_Layer/Timer/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1 MCAL_Layer/Timer/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1: MCAL_Layer/Timer/Timer3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1 MCAL_Layer/Timer/Timer3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.d ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/Timer3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1: MCAL_Layer/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1 MCAL_Layer/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.d ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1: MCAL_Layer/SPI/hal_SPI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1 MCAL_Layer/SPI/hal_SPI.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.d ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/SPI/hal_SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/LCD_Driver.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
