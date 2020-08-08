/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * FLSUN HiSpeed V1 (STM32F130VET6) board pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#elif HOTENDS > 1 || E_STEPPERS > 1
  #error "FLSUN hispeed supports up to 1 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "FLSUN HISPEED"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

#if EITHER(NO_EEPROM_SELECTED, FLASH_EEPROM_EMULATION)
  #define FLASH_EEPROM_EMULATION
  // 2K in a AT24C16N
  #define EEPROM_PAGE_SIZE     (0x800U)           // 2KB
  #define EEPROM_START_ADDRESS (0x8000000UL + (STM32_FLASH_SIZE) * 1024UL - (EEPROM_PAGE_SIZE) * 2UL)
  #define MARLIN_EEPROM_SIZE    EEPROM_PAGE_SIZE  // 2KB
#endif

//
// Note: FLSun Hispeed (clone MKS_Robin_miniV2) board is using SPI2 interface.
//
//#define SPI_MODULE 2
#define ENABLE_SPI2

//
// Limit Switches
//
//#define X_DIAG_PIN                          PA15  //-X
//#define Y_DIAG_PIN                          PA12  //-Y
//#define Z_DIAG_PIN                          PA11  //-Z
//#define E0_DIAG_PIN                         PC4   //+Z

#define X_STOP_PIN                          PA15  //-X
#define Y_STOP_PIN                          PA12  //-Y
#define Z_MIN_PIN                           PA11  //-Z
#define Z_MAX_PIN                           PC4   //+Z

//
// Steppers
//
#define X_ENABLE_PIN                        PE4 //X_EN
#define X_STEP_PIN                          PE3 //X_STEP
#define X_DIR_PIN                           PE2 //X_DIR
//#ifndef X_CS_PIN
//  #define X_CS_PIN                          PD5 //FSMC_NWE
//#endif

#define Y_ENABLE_PIN                        PE1 //Y_EN
#define Y_STEP_PIN                          PE0 //Y_STEP
#define Y_DIR_PIN                           PB9 //Y_DIR
//#ifndef Y_CS_PIN
//  #define Y_CS_PIN                          PD7 //FSMC_NE4
//#endif

#define Z_ENABLE_PIN                        PB8 //Z_EN
#define Z_STEP_PIN                          PB5 //Z_STEP
#define Z_DIR_PIN                           PB4 //Z_DIR
//#ifndef Z_CS_PIN
//  #define Z_CS_PIN                          PD4 //FSMC_NOE
//#endif

#define E0_ENABLE_PIN                       PB3 //E0_EN
#define E0_STEP_PIN                         PD6 //E0_STEP
#define E0_DIR_PIN                          PD3 //E0_DIR
//#ifndef E0_CS_PIN
//  #define E0_CS_PIN                         PD9 //FSMC_D14
//#endif

// Motor current PWM pins in orig //
//#define MOTOR_CURRENT_PWM_XY_PIN            PA6 //Vref Control XY
//#define MOTOR_CURRENT_PWM_Z_PIN             PA7 //Vref Control Z
//#define MOTOR_CURRENT_PWM_E_PIN             PB0 //Vref Control E1
//#define MOTOR_CURRENT_PWM_RANGE 1500            // (255 * (1000mA / 65535)) * 257 = 1000 is equal 1.6v Vref in turn equal 1Amp
//#define DEFAULT_PWM_MOTOR_CURRENT  { 1030, 1030, 1030 } // 1.05Amp per driver, here is XY, Z and E. This values determined empirically.

// This is a kind of workaround in case native marlin "digipot" interface won't work.
// Required to enable related code in STM32F1/HAL.cpp
//#ifndef MKS_ROBIN_MINI_VREF_PWM
//  #define MKS_ROBIN_MINI_VREF_PWM
//#endif

#define VREF_XY_PIN                       PA6 //Vref Control XY
#define VREF_Z_PIN                        PA7 //Vref Control Z
#define VREF_E1_PIN                       PB0 //Vref Control E

//
//
// Software SPI pins for TMC2130 stepper drivers
//
//#if ENABLED(TMC_USE_SW_SPI)
//  #ifndef TMC_SW_MOSI
//    #define TMC_SW_MOSI                     PB15  //SPI2_MOSI
//  #endif
//  #ifndef TMC_SW_MISO
//    #define TMC_SW_MISO                     PB14  //SPI2_MISO
//  #endif
//  #ifndef TMC_SW_SCK
//    #define TMC_SW_SCK                      PB13  //SPI2_SCK
//  #endif
//#endif

#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //

  #define X_SERIAL_TX_PIN                   PA10  //RXD1  /PD5
  #define X_SERIAL_RX_PIN                   PA10  //RXD1  /PD5

  #define Y_SERIAL_TX_PIN                   PA9   //TXD1  /PD7
  #define Y_SERIAL_RX_PIN                   PA9   //TXD1  /PD7

  #define Z_SERIAL_TX_PIN                   PA8   //IO0  /PD4
  #define Z_SERIAL_RX_PIN                   PA8   //IO0  /PD4

  #define E0_SERIAL_TX_PIN                  PC7   //IO1 /PD9 
  #define E0_SERIAL_RX_PIN                  PC7   //IO1 /PD9 

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE 19200
#endif // TMC2208 || TMC2209

//
// Temperature Sensors
//
#define TEMP_0_PIN                          PC1   // TH1
#define TEMP_BED_PIN                        PC0   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PC3   // HEATER1
#define HEATER_BED_PIN                      PA0   // HOT BED

#define FAN_PIN                             PB1   // FAN

//
// Thermocouples
//
//#define MAX6675_SS_PIN                    PE5   // TC1 - CS1
//#define MAX6675_SS_PIN                    PE6   // TC2 - CS2

//
// Misc. Functions
//
#define POWER_LOSS_PIN                      PA2   // PW_DET
#define PS_ON_PIN                           PA3   // PW_OFF

//#define LED_PIN                           PB2

//#define WIFI_IO0_PIN                        PC13
//#define WIFI_IO1_PIN       			            PC7
//#define WIFI_RESET_PIN			              	PA5

#define MT_DET_1_PIN                        PA4 //MT_DET
#define MT_DET_2_PIN                        PE6 //FALA_CTRL /EXT_IRQ
#define MT_DET_PIN_INVERTING false

#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    MT_DET_1_PIN
#endif

//
// SD Card
//
#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION              ONBOARD
#endif

#define SDIO_SUPPORT
//#define SDIO_CLOCK 4500000                        // 4.5 MHz
#define SD_DETECT_PIN                       PD12  //SD_CD
#define ONBOARD_SD_CS_PIN                   PC11  //SD_CS
#define SD_MOSI                             PD2   //SD_MOSI
#define SD_MISO                             PC8   //SD_MISO

/**
 * Note: MKS Robin TFT screens use various TFT controllers.
 * If the screen stays white, disable 'LCD_RESET_PIN'
 * to let the bootloader init the screen.
 */

#if ENABLED(TFT_LVGL_UI_SPI)

  #define SPI_TFT_CS_PIN                    PD7   // NE4 FSMC
  #define SPI_TFT_SCK_PIN                   PA5   // SPI1_SCK
  #define SPI_TFT_MISO_PIN                  PA6   // SPI1_MISO
  #define SPI_TFT_MOSI_PIN                  PA7   // SPI1_MOSI
  #define SPI_TFT_DC_PIN                    PD10  //FSMC_D15
  #define SPI_TFT_RST_PIN                   PC6   //FSMC_RST

  #define LCD_BACKLIGHT_PIN                 PD13  //FSMC_LIGHT

  #define TOUCH_CS_PIN                      PE14  // SPI1_NSS
  #define TOUCH_SCK_PIN                     PA5   // SPI1_SCK
  #define TOUCH_MISO_PIN                    PA6   // SPI1_MISO
  #define TOUCH_MOSI_PIN                    PA7   // SPI1_MOSI

  #define BTN_EN1                           PE8   //FSMC_D5
  #define BTN_EN2                           PE11  //FSMC_D8
  #define BTN_ENC                           PE13  //FSMC_D10

#elif ENABLED(TFT_LITTLE_VGL_UI)        // TFT 3.2 FSMC FLSUN

  #define FSMC_CS_PIN                       PD7   // NE4 FSMC  /NE4
  #define FSMC_RS_PIN                       PD11  // FSMC_A0   /A0

  #define TOUCH_CS_PIN                      PC2   // SPI2_NSS
  #define TOUCH_SCK_PIN                     PB13  // SPI2_SCK
  #define TOUCH_MISO_PIN                    PB14  // SPI2_MISO
  #define TOUCH_MOSI_PIN                    PB15  // SPI2_MOSI

  #define LCD_BACKLIGHT_PIN                 PD13  //FSMC_LIGHT

#endif

#if HAS_SPI_LCD

  #if ENABLED(SPI_GRAPHICAL_TFT)           // Emulated DOGM SPI
    #define SPI_TFT_CS_PIN                  PD11  // FSMC_A0   /A0
    #define SPI_TFT_SCK_PIN                 PA5   // SPI1_SCK
    #define SPI_TFT_MISO_PIN                PA6   // SPI1_MISO
    #define SPI_TFT_MOSI_PIN                PA7   // SPI1_MOSI
    #define SPI_TFT_DC_PIN                  PD10  //FSMC_D15
    #define SPI_TFT_RST_PIN                 PC6   //FSMC_RST   

    #define LCD_BACKLIGHT_PIN               PD13  // SPI2_SCK

    #define LCD_READ_ID                     0xD3
    #define LCD_USE_DMA_SPI

    #define TOUCH_BUTTONS_HW_SPI
    #define TOUCH_BUTTONS_HW_SPI_DEVICE     1

    #define TOUCH_SCREEN
    #if NEED_TOUCH_PINS
      #define TOUCH_CS_PIN                  PC2    // SPI1_NSS  CS_XPT2046
      #define TOUCH_SCK_PIN                 PB13   // SPI1_SCK  SCK_XPT2046
      #define TOUCH_MISO_PIN                PB14   // SPI1_MISO SDO_XPT2046
      #define TOUCH_MOSI_PIN                PB15   // SPI1_MOSI SDI_XPT2046

      #ifndef XPT2046_X_CALIBRATION
        #define XPT2046_X_CALIBRATION      12149
      #endif
      #ifndef XPT2046_Y_CALIBRATION
        #define XPT2046_Y_CALIBRATION       -8746
      #endif
      #ifndef XPT2046_X_OFFSET
        #define XPT2046_X_OFFSET             -35
      #endif
      #ifndef XPT2046_Y_OFFSET
        #define XPT2046_Y_OFFSET               256
      #endif
    #endif

    #ifndef FSMC_UPSCALE
      #define FSMC_UPSCALE                     3
    #endif
    #ifndef LCD_FULL_PIXEL_WIDTH
      #define LCD_FULL_PIXEL_WIDTH           480
    #endif
    #ifndef LCD_PIXEL_OFFSET_X
      #define LCD_PIXEL_OFFSET_X              48
    #endif
    #ifndef LCD_FULL_PIXEL_HEIGHT
      #define LCD_FULL_PIXEL_HEIGHT          320
    #endif
    #ifndef LCD_PIXEL_OFFSET_Y
      #define LCD_PIXEL_OFFSET_Y              32
    #endif

    #define BTN_ENC                         PE13  //FSMC_D10
    #define BTN_EN1                         PE8   //FSMC_D5
    #define BTN_EN2                         PE11  //FSMC_D8

    #define LCD_PINS_ENABLE                 PD13
    #define LCD_PINS_RS                     PC6   //FSMC_RST

  #elif ENABLED(MKS_MINI_12864)

    // MKS MINI12864 and MKS LCD12864B
    // If using MKS LCD12864A (Need to remove RPK2 resistor)

    #define LCD_BACKLIGHT_PIN               -1
    #define LCD_RESET_PIN                   -1
    #define DOGLCD_A0                       PD11
    #define DOGLCD_CS                       PE15
    #define DOGLCD_SCK                      PA5
    #define DOGLCD_MOSI                     PA7

    // Required for MKS_MINI_12864 with this board
    #define MKS_LCD12864B
    #undef SHOW_BOOTSCREEN

  #else                                           // !MKS_MINI_12864

    #define LCD_PINS_D4                     PE14
    #if ENABLED(ULTIPANEL)
      #define LCD_PINS_D5                   PE15
      #define LCD_PINS_D6                   PD11
      #define LCD_PINS_D7                   PD10
    #endif

    #ifndef BOARD_ST7920_DELAY_1
      #define BOARD_ST7920_DELAY_1 DELAY_NS(125)
    #endif
    #ifndef BOARD_ST7920_DELAY_2
      #define BOARD_ST7920_DELAY_2 DELAY_NS(125)
    #endif
    #ifndef BOARD_ST7920_DELAY_3
      #define BOARD_ST7920_DELAY_3 DELAY_NS(125)
    #endif

  #endif // !MKS_MINI_12864

#endif // HAS_SPI_LCD

#define SPI_FLASH
#if ENABLED(SPI_FLASH)
  #define W25QXX_CS_PIN                     PB12
  #define W25QXX_MOSI_PIN                   PB15
  #define W25QXX_MISO_PIN                   PB14
  #define W25QXX_SCK_PIN                    PB13
#endif

// Motor current PWM pins
//#define MOTOR_CURRENT_PWM_XY_PIN            PA6
//#define MOTOR_CURRENT_PWM_Z_PIN             PA7
//#define MOTOR_CURRENT_PWM_E_PIN             PB0
//#define MOTOR_CURRENT_PWM_RANGE 1500              // (255 * (1000mA / 65535)) * 257 = 1000 is equal 1.6v Vref in turn equal 1Amp
//#define DEFAULT_PWM_MOTOR_CURRENT  { 1030, 1030, 1030 } // 1.05Amp per driver, here is XY, Z and E. This values determined empirically.

// This is a kind of workaround in case native marlin "digipot" interface won't work.
// Required to enable related code in STM32F1/HAL.cpp
//#ifndef MKS_ROBIN_MINI_VREF_PWM
//  #define MKS_ROBIN_MINI_VREF_PWM
//#endif

//#define VREF_XY_PIN                       PA6
//#define VREF_Z_PIN                        PA7
//#define VREF_E1_PIN                       PB0
