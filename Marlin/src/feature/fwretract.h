/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * fwretract.h - Define firmware-based retraction interface
 */

#include "../inc/MarlinConfigPre.h"

class FWRetract {
private:
  #if EXTRUDERS > 1
    static bool retracted_swap[EXTRUDERS];         // Which extruders are swap-retracted
  #endif

public:
  static fwretract_settings_t settings;

  #if ENABLED(FWRETRACT_AUTORETRACT)
    static bool autoretract_enabled;               // M209 S - Autoretract switch
  #else
    constexpr static bool autoretract_enabled = false;
  #endif

  static bool retracted[EXTRUDERS];                // Which extruders are currently retracted
  static float current_retract[EXTRUDERS],         // Retract value used by planner
               current_hop;                        // Hop value used by planner

  FWRetract() { reset(); }

  static void reset();

  static void refresh_autoretract() {
    LOOP_L_N(i, EXTRUDERS) retracted[i] = false;
  }

  static void enable_autoretract(const bool enable) {
    #if ENABLED(FWRETRACT_AUTORETRACT)
      autoretract_enabled = enable;
      refresh_autoretract();
    #endif
  }

  static void retract(const bool retracting
    #if EXTRUDERS > 1
      , bool swapping = false
    #endif
  );
};

extern FWRetract fwretract;