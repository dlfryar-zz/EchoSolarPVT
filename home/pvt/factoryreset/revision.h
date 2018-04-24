/* Copyright PVT Solar, Inc. 2008 */

#ifndef REVISION_H_
#define REVISION_H_

#define CONTROLLER_SOFTWARE_REVISION "3.128"
#define PVT_CONTROLLER_SOFTWARE_REVISION "PVT Solar Rev. " \
                                         CONTROLLER_SOFTWARE_REVISION


/*
To do:

- DO HEM LIFETIME


Know bugs:


Notes:


Revision History:

3.128
- Ticket #788 [transterm.cpp] Modified Echo notice codes for SmartComm test
  temperature abort conditions.
- [transterm.cpp] Turn pool pump off at SmartComm aborts.


3.127
- Ticket #787 [transterm.cpp] Slave DHW pump to primary pump, Modify
  waitTranstermKey() to continually poll for temp limits when WAIT_FOREVER is
  specified. Prevent DHW pump from turning OFF when Echo Primary pump is ON in
  DHW menu. [templimits.cpp] Modify isHighTemp() to double sample T1 when
  Transterm is plugged into Echo system.
- Ticket #788 [transterm.cpp] Echo SmartComm modifications.
- Ticket #781 [zigbee.c] Re-sync the clock during the CT-80 blackout period.
- Ticket #783 [systemmanager.cpp] Comment out Echo re-sampling schedule.


3.126
- [transterm.cpp] Change Echo DHW delta drive from 10C to 8C. Change
  Echo DHW temperature deadband from 4C to 7C.


3.125
- [systemmanager.cpp, templimits.cpp, transterm.cpp] Added changes implemented
  in 3.13e Ticket #745, 746 regarding Transterm/SmartComm.
- [transterm.cpp] Monitor temperature limits when polling the keyboard and turn
  off blower/primary pump if limits are detected.


3.124
- [systemmanager.cpp] Add code to abort Echo warm-up period or opportunistic
  heating when High temp or Low temp is detected. Abort Echo warm-up when DHW
  load is not ready (load temp > setpoint). In either case, turn off pumps and
  wait until next sampling period. Changed high temp deadband from 18C to 36C.
  Pool is assumed to be not installed.
- [configdefs.h, config.org] Decrease default warm-up period from 42 (2500 sec.)
  to 15 minutes (900 sec.).
- [transterm.cpp] Set DHW temperature setpoint to 70C/65C for Echo/Echo+. Change
  Echo DHW delta drive from 6C to 10C.


3.123
- Branch


3.122
- [systemmanager.cpp] Added the following conditions for Night Flush sampling:
  If ZigBee is installed, at least one thermostat must be in COOLING mode.
- [localinterface.cpp] BUG! Increased size of buffer for logging debug messages.
  This caused memory violations and, as a result,  process termination.
- [zone.cpp] BUG! Noticed that max_num_zones in the function isZoneReady() was
  set to 1. This would prevent ventilation in Zone 2 and NF sampling on behalf
  of Zone 2 for Echo+. Changed this value to 2.


3.121
- [systemmanager.cpp] BUG (Typo) found after release of 3.12 at call to Night
  Flush array sample. Wrong function called. Replaced call to sampleArrayEcho()
  with sampleArrayEchoPlus().


3.12a
- [socketipc.cpp] Added handler for SIGPIPE.

3.12b
- [localinterface.cpp] Added JSON support.
- [build, backup, clean, pvt.mak mkjansson] Manage two versions of the JASON
  library (PVT-1000 and CTR-2).

3.12c
- [localinterface.cpp] Implemented, debugged and tested proposed specification
  08-08-12 sc102.json.txt

3.12d
- [localinterface.cpp] Refactored

3.12e
- [runpvt.sh] Copy pvt and libjansson.so.4 to backup directory.
- Ticket #664 [pvtupdaterled.cpp] Created pvtupdaterled to flash leds when
  executing pvtupdater.
- Ticket #665 [runpvt.sh] Added code to create and populate the factory reset
  directory. The files for the remote update will be called
  pvt_factoryreset.tar.gz and ws_factoryreset.tar.gz. Commented out for now.
- Ticket #664 [pvtupdaterled.cpp] Modified to flash the TS-7500 red and green
  LEDs as well as the CTR-2 interface board LEDs.
- [runpvt.sh] Uncommented factory reset support. (See above).

3.12f
- Ticket #667 [transterm.cpp] Fix bug that prevented the transterm from
  rebooting the system after entering a system ID on a FRU SD card. The
  excepton handling code jumped over the reboot code.

3.12g
- Ticket #665 [runpvt.sh] Use the following file names for the Web Services
  factory reset remote updates:
     ws_factoryreset_PVT-CPU.tar.gz & ws_factoryreset_TS-7500.tar.gz
- [circloopflow.lut, circlooptemp.lut] Updated. See email 08-28-12.
- [ethernet.c] Fixed bug with return value.
- [socketipc.cpp] Added code to restrict to clients with the same IP address as
  the CPU. This is configurable.
- [localinterface.cpp] Update restrict flag above using "Telnet_Enable" in
  wattsOnThread(). If Telnet_Enable is zero, restriction is enforced.

3.12h
- [build] Moved updaterled runtime files to updaterled.tar
- [runpvt.sh] Removed (commented out) updaterled platform mamagement. Moved this
  code to the TS-7500 SD card configure script.
- [socketipc.cpp, localinterface.cpp] Added debug logging to socketipc.cpp.
  Allow local connections from DHCP served address or 127.0.0.1 when restrict
  flag is on.

3.12i
- [runpvt.sh] Disable ssh if TELNET_ENABLE 0.
- [systemmanager.cpp] Added a call to processConfigurationParameters() while
  suspending the control logic in a high temp condition. This allows
  TELNET_ENABLE to be evaluated prior to entering the main control loop. It
  allows telnet to work on hardware without sensors.

3.12j
- [killpvt] A script to kill the pvt application.

3.12k
Ticket #674
- [ashrae.cpp, fancycling.cpp, ventcycle.cpp, ventecho.cpp] Added modules for
  Echo ventilation & fan cycling.
- [ventahu.cpp] Eliminate Echo dependencies, refactored testGlobalConditions()
  to testVentilationExtremeGlobalConditions in ventglobal.cpp.
- [ventcontrol.cpp] Added ventecho & fancycling dependency. Added conditional to
  isVentilationArraySample() which tests for Echo+.
- [ventglobal.cpp] Added testVentilationExtremeGlobalConditions() &
  getAmbientTemperature(). Removed NO_ETM.
- [ventnoahu.cpp] Added fan cycling.
- [configdefs.h] Added "Fan_Cycling_Interval", Fan_Cycling_Duration" and
  "Fan_Cycling_Mode".
- [transterm.cpp] Evaluate Echo ASHRAE during system test and post error 500
  if ASHRAE minutes per hour < 22.
- [databuffer.c, ventdata.c] Do fan cycling reporting.
- Ticket #678, 689 [systemmanager.cpp] Commented out code that applies the polynomial
  transfer function to the pump speed for Echo(Lite).

3.12l
- HEM development.

3.12m
- Ticket #695 Echo re-sampling
- [configdefs.h, config.dat] Added Array_Stagnation_Sample_Time 400 and
  Array_Thermal_Time_Constant 575
- [databuffer.cpp] Converted to C++ and added access to array energy.
- [systemmanager.cpp] Removed 'state change delay' code. Added code to implement
  the new Echo re-sampling algorithm.
- [echolite.cpp] Removed code to linearize primary pump. Added code to
  calculate Qnew and T2 for Echo re-sampling.
- [loadcontrol.cpp] Add functions to drive Echo loads.
- [exhaustload.cpp, spacecoolingload.cpp, spaceheatingload.cpp, thermalload.cpp]  Change drive() to return int.
- [thermalload.cpp] Added getApproachTemperature(), isReady() and isDeltaDrive()
- Ticket #702 [systemmanager.cpp] Prevent Night Flush sampling in humid
  climates.
- [fancycling.cpp] Added Quiet mode, when set, prevents fan cycling between
  10:00 PM and 6:00 AM.
- [configdefs.h, config.dat] Added Fan_Cycling_Quiet.
- [calendar.c, fancycling.cpp] Skip fan cycling for the hour if all thermostats
  are in AWAY.

3.12n
- [abstractio.c, pvt_io_3.c, pvtupdaterled.cpp] Changed mechanism for opening
  the Echo serial port for remote I/O. This keeps the port open for a PVT-1000
  and allows HEM communications.
- [hem.cpp] Added configuration and menu.
- Ticket #684 [transterm.cpp] Show flow when blower / pump is off in
  displayBlowerStatus()
- Ticket #705 [configdefs.h] Changed DEFAULT_ARRAY_TEMPERATURE_SAMPLE_TIME to
  200 from 120,
  [transterm.cpp] Set "Array_Temperature_Sample_Time" to 300 when Echo is
  configured.
- Ticket #699 [alerts.h] Start ZigBee repeaters at Thermostat 5 to
  differentiate between thermostats and repeaters.
- [fancycling.cpp, ventahu.cpp, systemmanager.cpp, databuffer.cpp, hvac.cpp]
  Detect, report, and test for fan cycling.
  [swthermostat.c] Change < to <= and > to >=
- [pv_meter.cpp] Retain last energy on communication errors.
- Ticket #669 [databuffer.cpp, pvmeter.cpp] Add lifetime energy values.
- Ticket #692 [temperature2.lut] Replaced with version attached to email
  11-16-12 (Book3.xlsx)

3.12o
- [hem.cpp] Change BUS_ADDRESS from 3 to 8.
- Ticket #717 [transterm.cpp] Possible bug
- Ticket #720 [ventecho.cpp] Multiply intermittent ventilation duration (10
  hours) by
  percent of ASHRAE.
- Ticket #722 [fancycling.cpp] Changed to flag HVAC 'start', not 'state' when
  NOT fan cycling.
- [systemmanager.cpp] In Echo re-sampling, multiply Q1 by 4 instead of
  divide by 4.

3.12p
- [databuffer.cpp] Memory leak bug!!! Add calls to fclose() to functions
  readLifetimeEnergy() and writeLifetimeEnergy() to fix.

3.12q
- Ticket #716 [transterm.cpp] Add external fan configuration menu to system
  configuration.
- Ticket #730 [hvac.cpp] Filter HVAC status by thermostat mode.
- Ticket #724 [hvac.cpp, databuffer.cpp] HVAC and Thermostat mode in the
  interval data file is: 0 - HEATING, 1 - COOLING, 2 - OFF
- Ticket #725 [hvac.cpp] Set deadband according to HUMID_CLIMATE:
  0 (CT-30) = 1.0F, 1 (CT-80) = 2.5F.
- Ticket #695 [systmmanager.cpp] Do not schedule an array sample while the
  primary pump is on in the Echo(Lite) configuration. This causes an array
  sample when the DHW load drops out after an extended time even though the
  pool has an opportunity to run.
- [fancycling.h] Remove code that detects HVAC transitions, and reveret back to
  the state to determine whether the HVAC came on in the last hour.

3.12r
- Ticket #695 [systmmanager.cpp] Changed the logic for Echo(Lite) to schedule
  an array re-sample when the DHW load has not run for a specified time. The
  solution in 3.12q is not a valid solution.
- Ticket #716 [transterm.cpp, ventdata.c] Implemented Vent Options in transterm
  to replace Economizer installed and External fan installed. Changed opetation
  logic to select AHU-style ventilation if either economizer OR external fan
  is installed.
- Ticket #705 [configdefs.h] Change DEFAULT_ARRAY_TEMPERATURE_SAMPLE_TIME from
  120 to 200

3.12s
- [zone.cpp, ventglobal.cpp] Bug!!! Modify isZoneReady() to process zones 3 & 4
  for Echo(lite) ventilation.
- Ticket #716 [transterm.cpp] Change "Economizer" label to "External Fan" in
  Advanced Diagnostics | Set Outputs if external fan is installed.

3.12
- Ticket #737 [pvmeter.cpp] Fix PV energy lifetime reporting. Failed to add the
  current lifetime energy to the daily totals when writing to the file at the
  end of the day.
              [databuffer.cpp] Report PV lifetime energy in kWh instead of Wh.
- Ticket #736 [config.org, configdefs.h] Reduce water heating temperature
  setpoint from 70C to 65 C.
- [systemmanager.cpp] Unconditionally set blower speed to low speed during an
  array re-sample for Echo+ systems.
- Released code 01-10-13


3.11
- [socketipc.cpp] Refactored socketipc.c using C++ constructs.
- [localinterface.cpp] Simplified main loop into one loop and reduced code
  size. Check_System_Id now gets processed in the same loop, and will respond
  after the initial authentication.
- [databuffer.c] Change PV energy calculation from logging the difference
  between periods to integrating the sum of the power from each inverter. This
  is to eliminate spikes resulting from communication timeout errors and reasons
  that have yet to be explained.


3.10a
- Ventilation 3.0

3.10b
- First compiled version, initial test.

3.10c
- More testing/ debugging.
- Debugged the AHU and ETM ventilation schedulers.

3.10d
- More testing/ debugging.
- [zone.cpp] Fixed backward logic for isZoneMaximumApproaqchTemperature()
- [ventcontrol.cpp, ventpause.c] - Power-up in AHU configuraton with Pause=0

3.10e
- [systemmanager.cpp] Schedule night flush array samples on behalf of
  ventilation
- [pid.cpp, blowerpid.cpp, loadcontrol.cpp] Expose tuning parameters via menu
  for EchoLite.
- [zone.cpp] Remove 47C approach temperature cut-off (humid) for zones.
- [configdefs.h] Added config.dat entry "System_Type" for EchoLite.
- [systemmanager.cpp] Add Delay On State Change for EchoLite configuration.
- This version may be used for continued ventilation testing.

3.10f
- [abstractio.c] Added EchoLite configuration.
- [lookuptable.c, .h, pvt.h] Added circlooptemp.lut & circloopflow.lut for the
  EchoLite Grundfos flow sensor.
- [transterm.cpp] Added EchoLite & Pool entries to System Configuration
- [transterm.cpp, zigbee.c] Prevent fan commands during system test.
- [echolite.cpp] Added power calcs for EchoLite.
- [databuffer.c] Added EchoLite power/energy reporting
- [transterm.cpp] Force space heating not installed and not enabled in the case
  of EchoLite.
- [ventnoahu.cpp] prevent ventilation in the case of EchoLite.
- [ventahu.cpp] Only AHU ventilation in the case of EchoLite.

3.10g
- [abstractio.c] Fixed EchoLite I/O mapping issues.
- [systemmanager.cpp] Swapped the meanings for the config.dat entries
  Active_Period_Array_Sample_Interval & Active_Period_Array_Sample_Interval_Idle

3.10h
- [circloopflow.lut] Original file was for the Grundfos sensor 20 l/min.
  Replaced with 40 l/min.
- [swthermostat.c] Ticket # 462 Changed hysteresis method from 2 to 1 (turn off
  at threshold)
- [databuffer.c] Log glycol flow for V_trunk in the case of EchoLite.
- [abstractio.h] Map Trunk 4 to Exhaust sensor for EchoLite with no pool.

3.10i
- [systemmanager.cpp] Override EchoLite state change restrictions for high &
  low temp cutouts.
- [databuffer.c] Calculate array power using exhaust temperature in the case of
  EchoLite.
- [databuffer.c] Prevent negative thermal power.

3.10j
- [abstractio.c] Modified isRtdOpenCircuit() to accomodate the EchoLite Grundfos
  temperature sensor.
- [transterm.cpp] Refactored the system test to accomodate EchoLite.

3.10k
- [localinterface.c] Changed to .cpp, simplified using C++ exception handling.
- [socketipc.c] Cleaned up
- [systemmanager.cpp] Ticket #539 In the case for EchoLite, use a 100 sec
  startup delay for the primary pump. Do not delay if pump is already on.
- [transterm.cpp] Ticket #535 Fix HX effectiveness event logging to report the
  value instead of the description.
- [systemmanager.cpp, echolite.cpp] Add a transfer function to linearize
  EchoLite primary pump speed vs flow.

3.10l
- [ventglobal.cpp] Bug fix. The sense for ventilation enable test was reversed. 
- [ventdata.c] Bug fix. Moved Current volume cap from sumVentilationVolume() to
  getVentilationVolume() to allow current volume to be > 125% of target at
  initialization.
- [delta.cpp] Added support for Delta inverter.
- [transterm.cpp] Ticket #544 Change Echo / EchoLite to Echo+ / Echo. Eliminate
  status updates of flow during system test. Change Fresh Air Damp to
  Economizer. Expand precision to 2 decimal places for primary loop flow (gpm).
  System Test % complete issue is not addressed.
- [loadcontrol.cpp] Ticket #548 Modify default tuning parameters for EchoLite
  to: P = 0.02, I = 0.0005, D = 0.
- [systemmanager.cpp] Ticket #547 Prevent Night flush array samples in the
  EchoLite configuration.
- [blowerpid.cpp, loadcontrol.cpp, ventnoahu.cpp] Cleaned up PID loop code for
  the three configurations.

3.10m
No tickets:
- [delta.cpp] Simplify.
- [serial.c] Add TS-7500 XUART support. Specifically, allow changing baud rate
  at runtime. Not yet tested. Changes are in serial_.c
- [ventglobal.cpp] Fix hysteresis bug in function isZoneWithinComfortBand().
- [build, runpvt.sh] Added yasdi_TS-7500.ini for future CTR-2/SMA support.

Tickets:
- Ticket #560 [ventglobal.cpp, ventahu.cpp] Fix AC Assist bug. Parameters
  passed to getZoneSetpoint() were reversed.
- Ticket #562 [ventdata.c] Fix bug testing for target achieved. Calculated
  target needs to be divided by 100.
- Ticket #552 [ventnoahu.cpp] Relabeled "Ventilation" to "Ventilation target
  achieved. No wider implications.
- Ticket #566 [transterm.cpp] Turn off all fans when transterm is unplugged.
- Ticket #557 [pvtcontroller.c, systemmanager.cpp] Change EchoLite to Echo,
  Echo to Echo+ in main menu.
- Ticket #568 [ventcontrol.cpp] Fixed. Changed from always TRUE to isEchoLite()
  and added dependancy on echolite.h. No impact on system operation. This needs
  to be revisited for HEMA configuration.
- Ticket #305 [ventdata.c] Target cap on accumulator removed as a result of
  adding the lifetime ventilation accumulator (See Ticket #580).
- Ticket #580 [ventdata.c databuffer.c] Removed support for Vent_min & Vent_pct.
  Add support for lifetime volume accumulator and record this instead of the
  daily accumulator. Lifetime volume is stored onto flash every 15 minutes.
- Ticket #565 [abstractio.c] Remapped Pool pump to Interface Board RELAY 1 for
  CTR-2. As a result, DHW heating element was moved to an invalid output.
  Remapped Economizer damper to Interface board PWM 1 for PVT-1000, ETM PWM 1
  for PVT-1000 with remote ETM, RELAY 2 for CTR-2.
- Ticket #581 [zone.cpp] Modified getNumZones() to return number of ZigBee
  thermostats in the case of Echo(Lite), Mofified isZoneReady() to bypass
  isZoneInstalled() in the case of Echo(Lite) to allow AHU ventilation to run
  in the Echo(Lite) configuration.
- Ticket #595 [ventahu.cpp] Fixed Typo. Ahu minutes per hour were dislayed for
  both ETM and AHU.
- Ticket #582 [config.c] Transterm Economizer flow shows 211900 when first
  powered up.  Also, entering 100 CFM yields 106 when read again. The 211900
  shows up when the initial value in config.dat is 100 CFM. This value should
  be stored as m3/s. The 106 results from a rounding error caused by only
  storing 2 decimal places in config.dat. Increased floats to 4 decimal places.
- Ticket #591 [transterm.cpp] Load effectiveness not always reported in
  SmartComm. The static structure loop[] was initialized with the address of an
  automatic variable (&dhw_insialled, &pool_installed). Changed dhw_installed &
  pool_installed to static variables so that loop[] is initialized with static
  (fixed) instead of automatic addresses.
- Ticket #592 [config.dat, configdefs.h] Set default AHU flow to 100 cfm
  converted to m^3/s
- Ticket #590 [ventahu.cpp] (a) When all Tstats in OFF, defer to AHU_MODE.
  (b) Divide Energy Save limit by 2, compare against (mode) setpoint instead of
  zone temperature. (c) Test Energy Save Limit as a condition of ETM mode
  determination and Lock out the zones that exceed this limit during ETM
  ventilation.
- Ticket #593 [ventahu.cpp] ASHRAE calculations incorrect. Supplied formula
  uses English units.
- Ticket #594 [ventahu.cpp] Allowing scheduleEtm() in debug mode could break
  the state machine while the control logic is running. Need to somehow present
  the ETM calculations for testing. Added menu item to log ETM calculations.
  These are based on the last scheduled ETM flow sample, and the last AHU
  calculations.
- Ticket #581 [databuffer.c] Add FRESH_AIR_DAMPER to list of digital I/O.
- Ticket #598 Same as Ticket #581

No action taken:
- Ticket #563 No action taken - Spec does not apply these constraints for the
  no AHU configuration
- Ticket #569 No action taken - This variable is only used for ETM
  configuration. Not used for Echo ventilation.
- Ticket #596 - Misunderstanding of the code.
- Ticket #597 - Not applicable. See Ticket #590

Cannot Reproduce:
- Ticket #564 Freeze re-circ - Could not demonstrate this issue on the
  simulator.
- Ticket #558 Transterm hangs up on pool relay in Transterm advanced diagnostics

Tickets pending:
- Ticket #547 System 20479 Still some blower activity in Echo(Lite)
  configuration.

3.10n
- Ticket #583 [pvt.mak, zigbee.c] Add code to detect CT-80 blackout window
  (11:58 PM to 12:10 AM) and replace setpoint query commamnd with setpoint
  set command during this window. This prevents local thermostat setpoint
  changes during this window.
- [calendar.c] Fixed the Dollar Sign Roundoff problem. In the function
  setCalendarSetpoint(), changed getOptionalPropertAsInt() calls to
  getOptonalPropertyAsFloat() when calculating the delta.
- [transterm.cpp, pvmeter.c, delta.cpp serial.c] Added support for Delta
  inverter.
- Ticket #580 [ventdata.c] Fixed reporting lifetime ventilation volume in the
  interval data file.

3.10o
- [ventahu.cpp] Fixed application crash. In function testEtmModeCondtions(), at
  the first call to sprintf() testing for ZONE_EXCEEDS_ENERGY_SAVE, a misplaced
  comma in the format string which results in a skewed argument list.

3.10p
- Ticket #580 [databuffer.c] Present ventilation volume as an integer in the
  interval data file.
- Ticket #619 [ventnoahu.cpp] Do not turn on fan during no-AHU ventilation.
  Instead, force off.
- Ticket #560 [ventglobal.cpp, zonesettings.cpp] Bug!!! - Evaluate AC_ASSIST
  using the HVAC setpoint instead of the PVT setpoint.
- [ventahu.cpp] Bug!!! Fixed ENERGY_SAVE calculation and comparison.
  The division by 2 was incorrectly applied to the difference instead of the
  limit. Also compare incoming air (T4) with the zone HVAC setpoint instead of
  the PVT setpoint.
- Ticket #621 [ventahu.cpp, calendar.c, configdefs.h] Use existing delta
  (comfort band) for ENERGY Save restriction. Remove the config.dat entry
  "Energy_Save_Limit" from the code.
- [zone.cpp] Force a 6F ($$) comfort band for Echo(Lite) ventilation.

3.10q
- [delta.cpp] Added comments, some rearranging & readability mods.
- Ticket #627 [abstractio.c, systemmanager.cpp] Added abstract I/O point
  ZONE_1_DAMPER_DEFEAT_SWITCH. Assigned to SWITCH #2 Interface board for both
  PVT-1000 and CTR-2. This input will defeat the Zone 1 damper for the Khosla
  installation.
- [ventpause.c] Do not pause as a result of config.dat changes for ETM/AHU
  ventilation.
- Ticket #626 [zigbee.c, ventahu.cpp, ventnoahu.cpp] Only update fan state
  while in AHU ventilation mode.

3.10r
- Ticket #330 Multi-inverter interface.
- [delta.cpp] Improved STX synchronization, other improvements.
- [kaco.cpp, veris.cpp] Re-wrote using C++ constructs. Restructured the code
  similar to the Delta implementation.
- Ticket #509 [delta.cpp, kaco.cpp, pvmeter.cpp] Poll inverters unconditionally
  and only update error stats during the active heating period. This accomodates
  board testing before the active heating period. Note that modivation was NOT
  energy production as the ticket suggests.
- [pvmeter.cpp] Adjust communications error blinking LED according to inverter.
- [transterm.cpp] Accomodate multiple inverters for System Test, System
  Configuration, and Advanced Diagnostics. SmartComm inverter communications
  error codes now start at 301.
- [pvmeter.cpp] Indicate inverter communications via LED using blink patterns
  which identify the failed inverter(s).
- [transterm.cpp] Bug fix. The SmartComm notice code for error 228 was
  incorrectly encoded as 225. Changed to 228.
- [pvmeter.cpp, veris.cpp] Reset Veris energy accumulator at 12:00AM.
- [datalogger.h] Increased max line length from 400 tyo 1000.
- [databuffer.c] Added the entries for 3 additional inverters.
- [config.dat] Change Glycol_Concentraton from 50 to 35.
- Ticket #634 [configdefs.h, ventahu.cpp, transterm.cpp] Added
  "Ventilation_External_Fan" entry to config.dat. If TRUE, ZigBee Fan ON
  commands will not be sent to the thermostats.
- Ticket #625 [transterm.cpp] Read and write House Area as float instead of
  int.
- Ticket #632 [ventpause.c] Do not modify ventilation accumulator at start of
  pause. This is so that ventilation may continue if pause is aborted.
- [transterm.cpp] Added RS-485 test under Advanced diagnostics.
- [alerts.c, pvmeter.c] Appended three bit fields for the additional inverters.
- Ticket #635 [systemmanager.cpp] Added sampling logic for Echo(Lite) to
  terminate sample when DHW delta drive is achieved, and force blower on for a
  specified time. Blower is set to minimum speed when there is no master load.
  Added the config.dat entry Array_Warm_Up_Period with a default of 2500 sec.
- [databuffer.c] Modified the code to integrate PV power for SMA PV energy.
- Ticket #591 [transterm.cpp] Still doesn't work. Removed static initialization
  and updated the static structure at run-time using brute force.
- Ticket #633 [ventpause.c] Initialize 24 hr pause and vacation pause to OFF
  at start-up.
  [ventdata.c] Remove vent enable indicator (-1000) and vent pause indicator
  (-999). One less than the lifetime accumulator value for vent pause indicator
  will not work as suggested since active SH & NF accumulate ventilation volume
  independent of ventilation pause.
  [ventnoahu.cpp] Remove code to initialize vent accumulator to 150%.
- Ticket #638 [ventcontrol.cpp] Test ETM global conditions and affect zone
  dampers before calling ventilation functions so that active ventilation can
  be evaluated, specifically, AHU ventilation. This bug prevented AHU
  ventilation at night when conditions were OK for NF, but global ETM
  conditions were not.

3.10s
- [ventpause.c] Fix application crash when "Ventilation_Vacation_Pause" is set
  to 1. Increased buffer size for the debug print code.

3.10t
- Ticket #646 [transterm.cpp] Preset DHW delta drive and deadband to 10, 2 for
  Echo+ or 6, 4 for Echo(Lite) respectively.
- Ticket #564 [systemmanager.cpp] Re-wrote low temp detection and behavior
  according to the specification. Commented out pool pump.
- [localinterface.cpp] Bug!!! Added space separator for "Protocol_Version " &
  "Controller_Software_Version " responses.
- Ticket #509 [pvmeter.cpp] Changed to report measurements on any successful
  poll of the inverter(s), not just during the active heating period.
- Ticket #650 - Confirmed that the pool pump is mapped to interface board
  RELAY #1 and the economizer is mapped to RELAY #2 for a CTR-2 with the
  Transterm against the relay LEDs and a 75W light bulb. No action taken.

3.10u
- Ticket #651 [loadcontrol.cpp, thermalload.h, thermalload.cpp] Defeat the
  exhaust load for Echo(Lite). Add NOT_USED_IN_ECHO code.
- [systemmanager.cpp] Change Echo(lite) sampling algorithm to run the primary
  pump at at max speed during the sampling and warm-up periods.
- Ticket #634 [transterm.cpp] Commented out Ventilation external fan from
  system configuration.

3.10v
- [systemmanager.cpp] Control logic starts up in a high temp condition which
  prevents an array sample and causes the Echo Delay On State Change to take
  effect due to the initial glycol flow change. This delays the DHW pump to
  turn on for 10 minutes. Added code to wait until the high temp condition
  goes away before entering the main loop.
- Ticket #651 [exhaustload.cpp] Bug!!! Modified code to reset the load's state
  when defeated.

3.10w
- Ticket #635 [systemmanager.cpp] No State Change Delay during the Echo(Lite)
  warm up period. Also added code to force a State Change Delay coming out
  of the warm-up period.
- [applicationstartup] Added the following lines for low latency web sockets:

   if test -f /home/pvt/runwebsock.sh
   then
      chmod 744 /home/pvt/runwebsock.sh
      /home/pvt/runwebsock.sh &
   fi

3.10
- Released 7-13-12


3.0a - Re-factoring effort
- [transterm.cpp] Change transterm.c to .cpp, Remove code that manually
  unwinds the stack when the USB adaptor is unplugged. Use C++ exception
  handling instead. Remove unused / commented out code.
- [console.c] Remove serial port support.
- [arraysimulation.c] Removed, not used.
- [watchdogtimer.c] Removed, not used.
- [pvarray.c] Removed, not used.
- [thermostat.cpp -> swthermostat.c] - Re-designed as C functions.
- [tempcontrol.cpp] - Added temperature control thread for the lab. Enabled
  by config.dat entry Temperature_Control 1

3.0b
- [zsetpoints.c] Fixed runtime memory violation when hold manual is
  terminated with an end time.
3.0c
- Initial debug, fixed exception handling by adding (int) casts to enumeration.
- Fixed isHighTemp() function
- Added dump/diplay functions to pid.cpp, blowercontrol.cpp
3.0d
- [*.cpp] Removed all CTR-2 C++ warnings generated from string constants.
- [transterm.cpp] BUG Fix!!! Missing commas on SmartComm diagnostics label
  structure which would cause a memory violation on indeterminant results.
3.0e
- [systemmanager.cpp] Fixed bug with isLowTemp(), added menu items to debug.
- [zone.cpp] Added menu items to debug
- [debugstring.cpp] Added CDebugString to allow reading / writng debug strings
  in a thread safe way.
3.0f
- Incorporated the changes in 2.02o
- Incorporated the changes in 2.02p
3.0g
- Added real-time local interface
- Added support for the Wattson power transducer
3.0h
- [socketipc.c] Added adaptive buffer size using a VLA in writeStringToSocket()
3.0i
- [zigbee.c] In light of devices continually announcing themselves during
  transmit failures with v1.7.7, commented out time of last response update so
  that a communication failure can be detected, and only update zigbee.dat
  if new device in the event of a device announcement.
- [socketipc.c] Free dynamic memory on failure to create threads
- [socketipc.c, localinterface.c] Added code instrumentation and imposed limit
  for number of connections. 
3.0j
- [localinterface.c] Add code to reset daily energy at 1:00 AM local time.
3.0k
- [wattson.c, localinterface.c] Add WattsOn log capability via telnet menu.
- [wattson.c] Detect communication failure during poll, and zero power and
  current values in this case.
3.0l
- [socketipc.c] Impose a receive timeout and return SOCKET_ERROR. This will
  automatically kill orphan connections.
- [wattson.c] Added instrumentation to debug memory faults that occur on Art's
  house. Communication errors (timeouts & CRC) appear here.
- [wattson.c] Memory faults occur when an invalid packet received. Filter these
  out, and flush the serial receive buffer when detected.
3.0m
- [socketipc.c, localinterface.c] Refactor to make socketipc.c more generic.
  Move code that adds LF to strings from socketipc.c to localinterface.c.
  Socketipc.c now writes unaltered strings.
- [wattson.c] Record and display error reset time stamp.
3.0n
- Develop ventilation 3.0 (newvent.c)
- [localinterface.c] - Inactivity processing added, removed from socketipc.c,
  added response to any string received, added request commands for
  protocol version and controller version.
- [socketipc.c] Added timeout parameter to receiveStringFromSocket().
- [zigbee.c] Added support for v1.7x firmware


2.03
- [calendar.c] Fixed the Dollar Sign Roundoff problem. In the function
  setCalendarSetpoint(), changed getOptionalPropertAsInt() calls to
  getOptonalPropertyAsFloat() when calculating the delta.


2.02a
- [serial.c] Changed simulator address from 3 to 1
- [blower.cpp, abstractio.c] Fix triac upper limits for the triacs configured
  for digital operation.

  Changed the lines in the function setOutput():

      case TRIAC_OUTPUT_TYPE:
         switch (getConversionType(io_point))
         {
            case BLOWER_SPEED_CONVERSION_TYPE:
               {
                  percent = (float) value / MAX_DAC_VALUE * 100;

                  int index = -1;

                  switch(io_point)
                  {
                      case BLOWER_SPEED_OUTPUT:
                         index = 0;
                         break;

                      case DHW_PUMP_OUTPUT:
                         index = 1;
                         break;

                      case POOL_PUMP_OUTPUT:
                         index = 2;
                         break;
                  }

                  if (index >= 0)
                     if (percent > Triac_maximum_duty_cycle[index])
                        percent = Triac_maximum_duty_cycle[index];
               }
               break;

            case DIGITAL_IO_CONVERSION_TYPE:
               percent = value ? 100.0 : 0;
               break;
         }

         switch (getIoSubsystem(io_point))
         {
            case PVT_IO_2_SUBSYSTEM:
               setPvtIo2TriacDutyCycle(getIoChannel(io_point), percent);
               break;

            case PVT_IO_3_SUBSYSTEM:
               setPvtIo3TriacDutyCycle(getIoChannel(io_point), percent);
               break;
         }
         break;

  to:

      case TRIAC_OUTPUT_TYPE:
         {
            int type;

            switch (type = getConversionType(io_point))
            {
               case BLOWER_SPEED_CONVERSION_TYPE:
                  percent = (float) value / MAX_DAC_VALUE * 100;
                  break;

               case DIGITAL_IO_CONVERSION_TYPE:
                  percent = value ? 100.0 : 0;
                  break;
            }

            int index = -1;

            switch(io_point)
            {
                case BLOWER_SPEED_OUTPUT:
                   index = 0;
                   break;

                case DHW_PUMP_OUTPUT:
                   index = 1;
                   break;

                case POOL_PUMP_OUTPUT:
                   index = 2;
                   break;
            }

            if (index >= 0)
               if (percent > Triac_maximum_duty_cycle[index])
                  percent = Triac_maximum_duty_cycle[index];

            switch (getIoSubsystem(io_point))
            {
               case PVT_IO_2_SUBSYSTEM:
                  setPvtIo2TriacDutyCycle(getIoChannel(io_point), percent);
                  break;

               case PVT_IO_3_SUBSYSTEM:
                  if (type == DIGITAL_IO_CONVERSION_TYPE)
                     percent = value ? 100.0 : 0;

                  setPvtIo3TriacDutyCycle(getIoChannel(io_point), percent);
                  break;
            }
         }
         break;

  Added the following lines to the function setOutputMaximumValue():

   if (percent > 100.0) //Do this for backward compatibility
      percent /= 100.0;

  Changed the lines in the function blowerThread():

         setOutputMaximumValue(DHW_PUMP_OUTPUT, getOptionalPropertyAsFloat((char *) MAXIMUM_DHW_PUMP_SPEED_STR, DEFAULT_MAXIMUM_DHW_PUMP_SPEED) / 100.0);

         setOutputMaximumValue(POOL_PUMP_OUTPUT, getOptionalPropertyAsFloat((char *) MAXIMUM_POOL_PUMP_SPEED_STR, DEFAULT_MAXIMUM_POOL_PUMP_SPEED) / 100.0);

  to:

         setOutputMaximumValue(DHW_PUMP_OUTPUT, getOptionalPropertyAsFloat((char *) MAXIMUM_DHW_PUMP_SPEED_STR, DEFAULT_MAXIMUM_DHW_PUMP_SPEED));

         setOutputMaximumValue(POOL_PUMP_OUTPUT, getOptionalPropertyAsFloat((char *) MAXIMUM_POOL_PUMP_SPEED_STR, DEFAULT_MAXIMUM_POOL_PUMP_SPEED));

2.02b (5-23-11)
  [databuffer.c] - Modified data buffer thread to accomodate time sync with
  the hub.

  Changed the lines in the function tieredDataBufferThread():

   time_t next = time(NULL) + SECONDS_BETWEEN_DATA_SAMPLES;
   for (;;)
   {
      if (time(NULL) >= next)
      {
         next = time(NULL) + SECONDS_BETWEEN_DATA_SAMPLES;
         tieredDatabufferService();
      }

      usleep(100000l); //poll the system clock every 100 ms
   }

  to:

   time_t now, next = time(NULL) + SECONDS_BETWEEN_DATA_SAMPLES;

   for (;;)
   {
      do
      {
         usleep(100000l); //poll the system clock every 100 ms

         now = time(NULL);

         if ((next - now) > SECONDS_BETWEEN_DATA_SAMPLES) //Clock adjusted
            break;                                        //backwards
      } while (now < next);

      next = now + SECONDS_BETWEEN_DATA_SAMPLES;

      tieredDatabufferService();
   }

- [transterm.c, webservices.c] Check web services version before SmartComm
  System Test and Form ZigBee Network.
- [transterm.c] Cap ZigBee connectivity test at 100%
- [transterm.c] Fix bug that prevented DHW_installed=0 during Smartcom config.
- [transterm.c] Display air flow (cfm) during SmartComm System Test delays for
  air flow stability
- [transterm.c] Increase SmartComm System Test delay for blower stability from
  30 to 60 sec.
- [transterm.c] Add 100 ms delay during each SmartComm System Test delay.
- [abstractio.c] Reset remote ETM alert when Remote_ETM is set to 0.
- [transterm.c] Refactored functions that provide the interface to the Web
  Services client into a new module webservices.c
- [transterm.c] Refactored functions that provide the interface to the local
  network into a new module ethernet.c

2.02c (6-3-11)
- [blower.cpp, occc.cpp] Modified the OCCC control logic according to the
  document
  'Proposal for first iteration of software for OCCC rev 2.pdf'

2.02d
- [abstractio.c] Added thread to continually refresh outputs. This is to
  recover from comm errors during output operations.
- [serial.c] Added stand-alone program to test CTR-2 RS-485 ports.
- [console.c] Add comments, minimal refactoring
- [transterm.c] Ticket #382 Report EUIDs after a remote SmartComm system test.

   Changed the lines:

   if (getOptionalPropertyAsInt(SMARTCOMM_SYSTEM_TEST_STR,
                                DEFAULT_SMARTCOMM_SYSTEM_TEST))
   {
      systemTest();
      setOptionalPropertyAsInt(SMARTCOMM_SYSTEM_TEST_STR, 0);
   }

   to:

   if (getOptionalPropertyAsInt(SMARTCOMM_SYSTEM_TEST_STR,
                                DEFAULT_SMARTCOMM_SYSTEM_TEST))
   {
      systemTest();

      recordZigBeeDeviceIds();

      setOptionalPropertyAsInt(SMARTCOMM_SYSTEM_TEST_STR, 0);
   }

- [pvt_io_3.c, databuffer.c] Ticket #384 Change remote ETM alert detection from
  an instantaeous sample to an error rate > 5% over a 15 minute period.
- [pvmeter.c, databuffer.c] Ticket #384 Change PV meter alert detection from
  an instantaeous sample to an error rate > 5% over a 15 minute period.
- [transterm.c] Ticket #348 Start blower at 30% prior to the ETM comm test.

2.02e
- [transterm.c, systemid.c] Add functionality to change the system ID only if
  the system ID is 99999.
- [transterm.c] Change the power units displayed from kW to W.
- [systemid.c] Incorporated the standalone program pvtsdconfig into this
  module.

2.02f
- [systemid.c] Added call to fflush() in two places prior to closing files.
- [transterm.c] Added the following sequence prior to reboot:

     sync();
     sleep(5);
     reboot(RB_AUTOBOOT);

- [transterm.c] Remove the ability to change the system ID from the
  Advanced Diagnostics | Status | System ID menu. Code is commented out.
- [blower.cpp] Ticket #367 Changed system mode determination such that Zone 2
  determines system mode if Zone 1 is OFF.

2.02g
- [pvmeter,c, databuffer.c] Ticket #280 Add daily energy as reported by the
   Kaco inverter to the interval data file under the heading E_inverter (Wh).
- [pvt_io_3.c] Ticket #185 Change error detection from 5 consecutive errors to
  300 to eliminate temperature spikes on the UI graphs.

2.02h
- [ventilation.c] - Prevent ventilation on the 1st period after power-up by
  initialzing the total accumulated volume to the target volume, and resetting
  this volume conditional on a first time through flag.

Added the line:

static int First_time_through_flag = 1;

Added the following lines to initVentilation()

   //Initialize Total_volume to Target_volume at power-up
   int house_area, num_bedrooms;
   getPropertyAsInt((char *) HOUSE_AREA_STR, &house_area);
   getPropertyAsInt((char *) NUM_BEDROOMS_STR, &num_bedrooms);
   isVentilationRequired(house_area, num_bedrooms); //calculate target volume
   Total_volume = Target_volume;

Changed the function resetVentilationVolume()

from:

   Total_volume = Incremental_volume = 0.0;

to:

   if (First_time_through_flag == 0)
      Total_volume = Incremental_volume = 0.0;

   First_time_through_flag = 0;

2.02i
- [runts.sh] Uncommented for loop, changed '> /dev/null' to '&> /dev/null' to
  supress output in the TS-7500 case. Tested on both a PVT-1000 and CTR-2.

2.02j
- [pvt_io_3] Fixed triac initialization bug introduced in rev d. It prevented
  triac struct from being initialized. Moved this initialization from after the
  calls to open() to before.
- [zsetpoints.c] Fixed runtime memory violation when hold manual is
  terminated with an end time (aka the 2:00 AM restart).

2.02k
- [blower.cpp, ventilation.c] Ticket #435 Add 24 hour ventilation pause feature.
  Added the config.dat entry 'Ventilation_Pause'.
- [blower.cpp] Ticket #437 Added ambient cut-out (38C) for ventilation.
- [ventilation.c, databuffer.c] Ticket #441 Clear signal of ventilation
  disabled.
- [abstractio.c] Fixed bug that reported 999 in the interval data file for
  zones 3 & 4.
- [runpvt.sh] Added code to install the ZigBee driver on a PVT-1000 if necessary

2.02l
- [zigbee.c] Added support to handle ZigBee USB stick 1.7 that replaces
  ANNOUNCE frame with DEVICE_EVENT frame. Both frames are now recognized for
  backward compatibility.
- [transterm.c] Modified the ZigBee Temperature menu to only display
  temperatures for the number of thermostats installed. Replaced the calls
  to getNumZigBeeDevices() with readNumThermostats().

2.02m
- [transterm.c] Remove the "CLEAR-EXIT" text from setSystemIdMenu()

2.02n
- [transterm.c] Changed the text "Invalid system ID" to "Generic memory card".
- [transterm.c] BUG Fix!!! Missing commas on SmartComm diagnostics label
  structure which would cause a memory violation on indeterminant results.

2.02o
- [thermaload.cpp blower.cpp transterm.cpp] Ticket #477 Added the config.dat
  entry "Humid_Climate" which sets space heating max approach temperature to
  70C when set to 0 and 47C when set to 1. Added transterm menu item to System
  Configuration.
- [abstractio.h] Ticket #478 Addressed the transterm response problem when
  the system cannot communicate with a remote ETM. Removed direct output
  operation when an output is in the list of outputs serviced by the output
  scan thread. All control logic outputs are now serviced solely by the output
  scan thread. When such an output is read, the state is read from the
  data structure maintained by the output scan thread instead of a direct read.

2.02p
- Added 'Humid_Climate 0' to the default config.dat file along with a valid
  checksum.

2.02q
- [zigbee.c] Added support for v1.7x. Added DEVICE_TABLE_RREQUEST,
  DEVICE_TABLE_RESPONSE, and CLEAR_DEVICE_TABLE. For versions > 1.7.0,
  CLEAR_DEVICE_TABLE is used instead of CLEAR_BINDING_TABLE when forming a
  network. Also added support for logging UTILITY_HEADER - ERROR.
- [zigbee.c] Moved the call to logFrame() from reveiveThread() to receiveFrame()
- [***** BEFORE RELEASE, TURN OFF DEBUG FLAG IN ZIGBEE.C *****]

2.02r
- [zigbee.c] Turn off debug flag

2.02s
- [blower.cpp] Re-wrote isHeatingMode(). Fixed typo.

2.02t
- [zigbee.c] Ignore device announcements initiated by permit joining commands
  from communication failures or remote command from hub.
- [blower.cpp] Add remote 'Permit Joining' to inactive heating period loop.
- [config.dat] Updated config.dat. Checksum is valid.
               Active_Period_End_Hour             100 -> 400
               Night_Flush_1_Maximum_Blower_Speed  70 -> 45


2.01a (1-25-11)
- [veris8031.c, kaco.c, pvmeter.c] Simplified the code for inverter
  initialization.
- [pvmeter.c] Refactored
- [blower.cpp] Removed code to support incorrect spelling of
  "Active_Period_Array_Sample_Interval"
- [blower.cpp] Remove T_Zone_1..4 config.dat entries
- [transterm.c] Add Map ZigBee Devices menu to transterm interface
- [alerts.c] Make status word non-volatile
- [zigbee.c] Make 'num form networks' non-volatile

- [pvtcontroller.c, abstractio.c, blower.cpp] Allow zone 2 RTD in a ZigBee
  (one thermostat) system.
- [abstractio.c, blower.cpp] - Allow ZigBee or RTD zone temperature input / mode
- Added the config.dat entries "Zone_1_ZigBee_Enable" & "Zone_2_ZigBee_Enable".
  0 = RTD, 1 = ZigBee. Both default to 1.

- [blower.cpp, diagnosticslogger.c] - Record ZigBee EUI64s
- [diagnosticslogger.c] - Store in RAM, overwrite duplicate entries (type)

- [transterm.c] - Only map 2 ZigBee thermostats
- [dagnosticslogger.c] - Don't write the file if entry hasn't changed.

- [abstractio.c] - Fixes bug where blower would not get limited to max blower
  speed.

2.01b
- [blower.cpp] Change EUI64 labels from ZigBee_1_EUI64 to Th1_EUID, add
  Rp_1_EUID for repeaters.
- [configfile.c, blower.cpp, transterm.c, numthermostats.c] Removed config.dat
  file entry "Num_Thermostats_Installed". Store in it's own file instead
  (zigbee_num_thermostats.dat)

2.01c (2-17-11)
- [diagnosticslogger.c] Add "PERM" level, Modify to append any entry that
  is not "REF", misc. clean-up and commenting.
- [abstractio.c] Swapped I/O assignments for DHW top and bottom sensors for
  V2.0 hardware
- [diagnosticslogger.c] Modified to process multiple files.

2.01d
- [transterm.c] Added SmartComm

2.01e
- [diagnosticslogger.c] Modified to append entries of type "PERM".
- [transterm.c] Debugged SmartCom (except ZigBee test)

2.01f
- [transterm.c] Debugged SmartCom (ZigBee)
- [diagnosticslogger.c] Modify to conditionally append to file.
- [transterm.c] Increase System Test damper delays from 30 to 60 sec.
- [transterm.c] System Configuration - Conditionally prompt for remote ETM.
- [transterm.c] System Test - Conditionally test remote ETM.
- [transterm.c] System Test - Added beep at end of test.

2.01g
- [transterm.c] Ticket #254 SmartComm - Add 2 sec delay before logging Finish
  event
- [transterm.c] Ticket #247 SmartComm - Do not test RTDs that are not installed
- [transterm.c] Ticket #250 SmartComm - Open a damper and delay before closing
  others. Remove a 30 second delay for Air flow / water test.
- [transterm.c] Ticket #253 SmartComm - Change tank sensor test event log entry
  to SC_T_Tank_Sensor_Delta.
- [transterm.c] Ticket #246 SmartComm - Start progress indicator at 5%
  others. Remove a 30 second delay for Air flow / water test.
- [abstractio.c] Ticket #256 Add write-only config.dat entry "Controller_Type"

2.01h
- [transterm.c] Removed ZigBee repeater setup from SmartComm configuration and
  moved it to Advanced Diagnostics | ZigBee
- [transterm.c] Fixed behavior of top level menus in Advanced diagnostics when
  CLEAR is pressed.
- [transterm.c] Modified mapZigBeeDevicesMenu() to affect only two devices.

2.01i
- [transterm.c] SmartComm - Record all EUIDs with non-existing devices set to
  0.
- [abstractio.c] Removed config.dat entry "Controller_Type" (Ticket #256)
- [abstractio.c] Process "Remote_ETM" config.dat entry in I/O scan thread to
  make changes immediate.
- [blower.cpp] Fixed bug with logic in determining conditions for Night Flush
  array sampling.

  Changed the lines:

                     if (NightFlush1Load.isEnabled() || NightFlush2Load.isEnabled())
                        if (NightFlush1Load.isSolarReady() || NightFlush2Load.isSolarReady())

  to:

                     if ((NightFlush1Load.isEnabled() &&
                          NightFlush1Load.isSolarReady()) ||
                         (NightFlush2Load.isEnabled() &&
                          NightFlush2Load.isSolarReady()))

- [transterm.c] Commented out all code referencing ventilation
- [transterm.c] Commented out all code referencing pool heating. Pool pump
  control is re-labeled to Aux pump, pool & exhaust RTDs are commented out of
  the SmartComm system test.

2.01j
- [blower.cpp, thermalload.cpp] Fixed ventilation bug where the wrong setpoints
  were used for determining solar ready. The setpoints used depended on
  thermostat mode. The fix is to remove this dependency. Also, add
  isInstalled() to the list of conditions for controlling ventilation. Do this
  for both the active and inactive heating periods.

  Changed the lines:

                  if (ventilation_flag)
                     if (NightFlush1Load.isSolarReady() || NightFlush2Load.isSolarReady())
                     {

  to:

                  if (ventilation_flag)
                  {
                     NightFlush1Load.setLoadTemperatureSetpoint(
                  getZoneTemperatureSetpoint(ZONE_1, COOLING_MODE, PVT_SYSTEM));
                     NightFlush2Load.setLoadTemperatureSetpoint(
                  getZoneTemperatureSetpoint(ZONE_2, COOLING_MODE, PVT_SYSTEM));

                     if ((NightFlush1Load.isSolarReady() &&
                          NightFlush1Load.isInstalled()) ||
                         (NightFlush2Load.isSolarReady() &&
                          NightFlush2Load.isInstalled()))
                        {

  Changed the lines:

                        if (SpaceHeating1Load.isSolarReady())
                           Output[ZONE_1_DAMPER_OUTPUT].ivalue = 1;
                        if (SpaceHeating2Load.isSolarReady())
                           Output[ZONE_2_DAMPER_OUTPUT].ivalue = 1;

  to:

                        if (NightFlush1Load.isSolarReady() &&
                            NightFlush1Load.isInstalled())
                           Output[ZONE_1_DAMPER_OUTPUT].ivalue = 1;

                        if (NightFlush2Load.isSolarReady() &&
                            NightFlush2Load.isInstalled())
                           Output[ZONE_2_DAMPER_OUTPUT].ivalue = 1;

2.01k
- [blower.cpp] Modified the above code to work correctly with RTDs.

  Changed the lines:

                  if (ventilation_flag)
                  {
                     NightFlush1Load.setLoadTemperatureSetpoint(
                  getZoneTemperatureSetpoint(ZONE_1, COOLING_MODE, PVT_SYSTEM);
                     NightFlush2Load.setLoadTemperatureSetpoint(
                  getZoneTemperatureSetpoint(ZONE_2, COOLING_MODE, PVT_SYSTEM));

  to:

                  if (ventilation_flag)
                  {
                     NightFlush1Load.setLoadTemperatureSetpoint(
                       getVentilationTemperatureSetpoint(ZONE_1, COOLING_MODE));
                     NightFlush2Load.setLoadTemperatureSetpoint(
                       getVentilationTemperatureSetpoint(ZONE_2, COOLING_MODE));

Do this for the active heating period as well.

- [ventilation.c] Fix ventilation fraction to 8.5 hrs (0.354)
- [blower.cpp] Remove 90 minute delay for night ventilation
- [ventilation.c] Stop accumulating volume after target is reached.

  Added the lines:

   if (Total_volume >= Target_volume) //Cap accumulation at target
      volume = 0;

- [databuffer.c] Fixed bug where ventilation volume was accumulated and
  recorded when both dampers are closed.

  Changed the lines:

   if (getInput(ZONE_1_DAMPER_OUTPUT) || getInput(ZONE_2_DAMPER_OUTPUT))
      sumVentilationVolume(flowRate, SECONDS_BETWEEN_AVERAGINGS);

  to:

   if (!getInput(ZONE_1_DAMPER_OUTPUT) && !getInput(ZONE_2_DAMPER_OUTPUT))
      flowRate = 0;

   sumVentilationVolume(flowRate, SECONDS_BETWEEN_AVERAGINGS);

- [databuffer.c, ventilation.c] Do not record thermal power for zones 1 & 2
  when ventilation is active.

  Added the lines in databuffer.c:

      if ((gatingIoNumber ==  ZONE_1_DAMPER_OUTPUT) || 
          (gatingIoNumber ==  ZONE_2_DAMPER_OUTPUT))
         if (isVentilationActive())
            thermalPower = 0;
 
2.01l (2-11-11)
- [blower.cpp] Fixed bug where ventilation volume does not accumulate during
  night flush. The problem lies in the order of the evaluation of the conditions
  that allow active ventilation. The fix is to call isVentiation()
  unconditionally so that a target volume is calculated.

  Changed the lines:

         if (master_load_index == -1)
            if (getOptionalPropertyAsInt((char *) VENTILATION_ENABLE_STR, DEFAULT_VENTILATION_ENABLE))
               if (isVentilation(house_area, num_bedrooms))
               {

  to:

         if (isVentilation(house_area, num_bedrooms)) //This must be called
                                                      //unconditionally
            if (master_load_index == -1)
               if (getOptionalPropertyAsInt((char *) VENTILATION_ENABLE_STR, DEFAULT_VENTILATION_ENABLE))
               {

- [transterm.c] Added the config.dat entry "SmartComm_System_Test" to perform
  a system test remotely.

2.01m
- [transterm.c] Changed EUID reporting from diagnostics.csv to commission.csv
  so that they get reported at the time of network formation. This gets the
  data to the hub ASAP, and eliminates loss of EUIDs if a system is rebooted
  before they are sent to the hub.

2.01n
- [blower.cpp] Allow ventilation during water heating

  Changed the lines:

         if (isVentilation(house_area, num_bedrooms)) //This must be called
                                                      //unconditionally
            if (master_load_index == -1)
               if (getOptionalPropertyAsInt((char *) VENTILATION_ENABLE_STR, DEFAULT_VENTILATION_ENABLE))

  to:

         //This must be called unconditionally
         if (isVentilationRequired(house_area, num_bedrooms))
            if ((Output[ZONE_1_DAMPER_OUTPUT].ivalue == 0) &&
                (Output[ZONE_2_DAMPER_OUTPUT].ivalue == 0))
               if (getOptionalPropertyAsInt((char *) VENTILATION_ENABLE_STR, DEFAULT_VENTILATION_ENABLE))

  Changed the lines:

                  {
                     VentPid.populate(20, //+++getOptionalPropertyAsFloat((char *) BLOWER_PROPORTIONAL_GAIN_STR, DEFAULT_BLOWER_PROPORTIONAL_GAIN),

  to:

                     / *
                        if nothing is driving the blower, drive it with
                        ventilation
                     * /

                     if (master_load_index == -1)
                     {
                        VentPid.populate(20, //+++getOptionalPropertyAsFloat((char *) BLOWER_PROPORTIONAL_GAIN_STR, DEFAULT_BLOWER_PROPORTIONAL_GAIN),

- [databuffer.c] Report ventilation as total accumulated volume instead of
  incremental volume.

  Inserted the line:

   sprintf(buffer, ",%.4f", getVentilationTotalVolume()); //+++ For now

- [blower.cpp] Fix "Double Ventilation" bug where ventilation may get reset
  twice in one day via mode change from the home owner.

  Changed the lines:

      if (isHeatingMode())
         resetVentilationVolume();

  to:

      if (isHeatingMode())
         if (getTotalVolume() >= getTargetVolume())
            resetVentilationVolume();

  Do this for the inactive period as well.

- [transterm.c] Ticket #253 SmartComm - Change tank sensor test event log entry
  to SC_T_Tank_Sensor_Delta. Fixed bug that didn't report the resulting value.

2.01o
- [blower.cpp] Fixed the deadband bug for determining solar ready during
  ventilation.

  Changed the lines:

                  SpaceHeating1Load.setLoadTemperatureSetpoint(
                       getVentilationTemperatureSetpoint(ZONE_1, HEATING_MODE));
                  SpaceHeating2Load.setLoadTemperatureSetpoint(
                       getVentilationTemperatureSetpoint(ZONE_2, HEATING_MODE));

                  if ((SpaceHeating1Load.isSolarReady() &&
                       SpaceHeating1Load.isInstalled()) ||
                      (SpaceHeating2Load.isSolarReady() &&
                       SpaceHeating2Load.isInstalled()))
                  {
                                       .
                                       .
                                       .

                     if (SpaceHeating1Load.isSolarReady() &&
                         SpaceHeating1Load.isInstalled())
                        Output[ZONE_1_DAMPER_OUTPUT].ivalue = 1;

                     if (SpaceHeating2Load.isSolarReady() &&
                         SpaceHeating2Load.isInstalled())
                        Output[ZONE_2_DAMPER_OUTPUT].ivalue = 1;

  to:

                  int zone_1_vent, zone_2_vent;

                  zone_1_vent = isVentilationSolarReady(ZONE_1, HEATING_MODE) &&
                                                SpaceHeating1Load.isInstalled();
                  zone_2_vent = isVentilationSolarReady(ZONE_2, HEATING_MODE) &&
                                                SpaceHeating2Load.isInstalled();

                  if (zone_1_vent || zone_2_vent)
                  {
                                       .
                                       .
                                       .

                     if (zone_1_vent)
                        Output[ZONE_1_DAMPER_OUTPUT].ivalue = 1;

                     if (zone_2_vent)
                        Output[ZONE_2_DAMPER_OUTPUT].ivalue = 1;

   Do the same for the inactive period.

- [blower.cpp, thermaload.cpp] Disable ambient temperature cutout for heating
  if zone is ZigBee

  Changed the lines [blower.cpp]:

         if (SpaceHeating1Load.isInstalled())
         {
            if (isZigBeeInstalled())
               if (getOptionalPropertyAsInt((char *) ZONE_1_ZIGBEE_ENABLE_STR,
                                            DEFAULT_ZONE_1_ZIGBEE_ENABLE))
                  if (getZigBeeMode(ZONE_1) != HEATING_MODE)
                     SpaceHeating1Load.setEnable(0);

  to:

         if (SpaceHeating1Load.isInstalled())
         {
            if (isZigBeeInstalled())
               if (getOptionalPropertyAsInt((char *) ZONE_1_ZIGBEE_ENABLE_STR,
                                            DEFAULT_ZONE_1_ZIGBEE_ENABLE))
               {
                  setEnableTemperatureSetpoint(); //Disable

                  if (getZigBeeMode(ZONE_1) != HEATING_MODE)
                     SpaceHeating1Load.setEnable(0);

  Do the same for zone 2

- [transterm.c] [Ticket #281] Remove Setup Menu and all sub menus
- [transterm.c] [Ticket #282] Add Night Flush to zone setup in Sysyem
  Configuration menu

2.01p
- [transterm.cpp] [Ticket #283] Change the order of SmartComm top level menus
  from System Config, Advanced Diag, System Test to System Config, System Test,
  Advanced Diag
- [thermostat.cpp] Change how the deadband is applied to temperature
  comparisons. Change from ON < (setpoint - deadband), OFF > setpoint to
  ON <= setpoint, OFF > (setpoint + deadband) [heating]. Change cooling
  accordingly. Simplified and cleaned up the code for readability.

  Changed the lines:

      case HEATING_THERMOSTAT:
         if (m_state == 0)
         {
            if (temperature < m_setpoint - m_deadband)
               m_state = 1;
         }
         else
            if (temperature > m_setpoint)
               m_state = 0;
         break;

  to:

      case HEATING_THERMOSTAT:
         if (temperature <= m_setpoint)
            m_state = 1;

         if (temperature > (m_setpoint + m_deadband))
            m_state = 0;
         break;

- [blower.cpp] Fix bug that prevents night ventilation from working until
  an array sample can occur. This is due to the uninitialized variable
  master_load_index. Initialize it to -1.

2.01q
- [abstractio.c pvt_io_3.c, blower.cpp, transterm.c] [ticket # 201] Added
  GREEN_LED_OUTPUT and RED_LED_OUTPUT to the list of abstract I/O, flash green
  LED when control logic is running, solid green LED when transterm is plugged
  in. Modified the TS-7500 channel assignment convention to assume
  channels < 100 for I/O on the CPU card. Current implementation is a
  work-around to a problem using sbus.c. See ts7500.c for details.

- [blower.cpp] [Ticket #242] Modify array sample code to set blower speed to
  maximum  blower speed for 4 seconds and then sample at minimum blower speed.
- [blower.cpp] Limit minimum blower speed to the config.dat entry
  "Minimum_Blower_Speed" and maximum  blower speed to the config.dat entry
  "Maximum_Blower_Speed".

- [transterm.c] [Ticket #286] Modify system configuration to preserve number
  of thermostats when ZigBee thermostats configuration is aborted. Change
  "Abort" to "Skip".

  Changed the lines in the function systemConfigurationMenu():

                        if (return_code == 0)
                           writeNumThermostats(num_ZigBee_thermostats);

  to:

                        if (return_code == 0)
                           if (num_ZigBee_thermostats)
                              writeNumThermostats(num_ZigBee_thermostats);

  Changed the lines in the function systemTest():

   //Test ZigBee

   if (return_code == 0)
   {

  to:

   //Test ZigBee

   if (return_code == 0)
      if (isZigBeeInstalled())
      {

- [transterm.c] [Ticket #276] Fixed bug where system test would abort immediately if no inverter specified. This was due to an uninitialized variable.

 Changed the lines in the function systemTest():

   int return_code;

  to:

   int return_code = 0;

- [zigbee.c, blower.cpp, alerts.c] [Ticket #263] Added the config.dat entry "ZigBee_USB_Detected" to indicate whether the ZigBee stick is unplugged, or plugged in.

  Added the line:

         setOptionalPropertyAsInt((char *) ZIGBEE_USB_DETECTED_STR,
                                                    isZigBeePluggedIn()? 1 : 0);

  Do this for the inactive heating period as well.

  Also added an alert to indicate ZigBee stick is unplugged.

- [transterm.c] [Ticket #285] Transterm menu cleanup
  - Fix bug with Analog Input menu (uninitialized variable)
  - Eliminate Float Switch from I/O menu
  - Remove ZigBee Map Devices menu. Did NOT enable RTD when zones > thermostats
    as there may be mapping conflicts.
  - Fix setup complete messages for thermostat and repeater network formation.
  - Change legacy F1-Next to <F1 F2> navigation.

- [blower.cpp] [Ticket #251] Turn off DHW pump during array sample

2.01r
- [transterm.c] [Ticket #297] Re-organize I/O menu tree per SmartComm spec.
- [kaco.c, pvmeter.c, databuffer.c ] [Ticket 200] Added code to extract
  and record inverter temperature from the Kaco inverter.
- [transterm.c] Add line to close joining after forming a ZigBee network.
- [ts7500.c] Change the calls to system("ts7500ctl ..."); to use a fully
  qualified filename system("/initrd/ts7500ctl ..."); so that it works from
  the auto boot environment.
- [blower.cpp] Moved the flashing green LED from the control logic to a
  separate thread so that it flashes at a constant rate when the control
  logic is bogged down due to communication errors with V2.0 I/O.

2.01s
- [transterm.c] Removed "Mating Interval Timeout" from ZigBee form network menu.
- [transterm.c] Limit ZigBee joining window only when controller is actively
  waiting for a device.
- [blower.cpp] Change Flashing green LED period from 1 sec to 0.5 sec.

2.01t
- [thermalload.h] BUG fix. Space heating load would not run in ZigBee mode.
  Changed default parameter for setEnableTemperatureSetpoint() from -999 to
  999.
- [zsetpoints.c] Change monitor screen to display parameters for the number of
  ZigBee thermostats installed.
- [blower.cpp] Changed where the thermal load dumps occur in debug mode during
  heating. They used to update only when the blower was driven. Now they update
  unconditionally.
- [zsetpoints.c] Modified the code to use the debug logger. Removed unused code.

2.01u
- [blower.cpp, thermalload.cpp] Drop out cooling loads when
  ambient temperature < enable temperature setpoint.
- [blower.cpp, zsetpoints.c] Changed how the zsetpoints monitor screen works so
  that conflicting queries for a setpoint doesn't alternate the mode displayed.
- [zsetpoints.c] Display OFF for setpoints in the monitor screen when the
  mode is OFF
- Updated the default config.dat file
- Modified runpvt.sh to delay 30 sec before initializing the serial ports for
  a TS-7500. This is to avoid the problem that occurs when the system is booted
  with a memory stick plugged into a USB port. In this case, the ports are left
  at the 115 kBaud default.

2.01v
- [serial.c] Modify the standalone term program to wait 10ms for a received
  character instead of no wait. This fixes the 97% CPU utilization. 
- [runpvt.sh] Move the xuart initializtion to applicationstartup. Remove 30
  sec delay added in 2.01u

2.01
- [build] Added applicationstartup to the runtime set of files.
- [config.org] Remove checksum entry
- Released 5-9-11


2.0a (12-21-10)
- [transterm.c] Redesign ZigBee menus
- [blower.cpp] Added config.dat entries "Zone_1_ZigBee_Device" to map zones to
  ZigBee devices
- [zsetpoints.c, h] Change max number of devices from 6 to 4
- [zsetpoints.c] Control all zones with one global calendar
- [zsetpoints.c] Remove all reference to 'Energy Save'
2.0b (1-5-11)
- [transterm.c] Add config.dat file entry "Num_Thermostats_Installed". This
  entry must exist in the default config.dat file with an initial value of 0.
  It is written by the controller and read by the UI. 
- [blower.cpp] Added the config file entry "Night_Flush_Enable_Temperature" and
  defaults to 12C. It is implemented as an additional condition for NF array
  sampling.
- [configfile.h] Changed the defaults for Space_Heating_1_Enable_Temperature_Setpoint and Space_Heating_2_Enable_Temperature_Setpoint from 16C to 18C
- Added thermostat entries to the default config.dat file
- [zsetpoints.c] Changed default values according to spec.
2.00c (1-6-11)
- [zsetpoints.c] Change calendar from thermostat specific to global (all pointed
  to TH1).
2.00d (1-10-11)
- [zsetpoints.c] Change scenes from global to thermostat specific (each pointed
  to it's corresponding thermostat).
2.00e (1-10-11)
- [zigbee.c, alerts.c] Report 999 (invalid) measured temperature if
  communication timeout detected
- [thermalload.cpp] Drop out thermal load if 999 (invalid) temperature
  detected.
- [blower.cpp] Added a write-only configuration entry "ZigBee_Installed"
- [blower.cpp] Poll for Transterm during array sample
- [pvt_io_3.c] Fixed slow response on V2.0. I/O was timing out on RTD reference
  inputs. Abstract I/O scan rate is now < 1 sec.
- Updated default config.dat to standard version
2.00f (1-19-11)
- [abstractio.c] Inverted the polarity for V2.0 digital inputs
- [abstractio.c] Added Zones 3 & 4 to the list of I/O points such that they are
  added to the interval data file
- [blower.cpp] Changed ZigBee mapping to alter the I/O channel of the abstract
  I/O point.
- [transterm.c] Added ZigBee temperature menu
- [blower.cpp] Fixed mode for thermstats 3 & 4
2.00g (1-21-11)
- [zsetpoints.h] Fixed typo for thermostat config.dat entries 'THn_' -> 'Thn'
2.00 (1-24-11)
- Updated default config.dat to include 4 ZigBee thermostats


1.09a (6-1-10)
   - [thermalload.cpp] Fixed bug which turns off the DHW pump when T4 > 70C by re-factoring. (Move all space heating specific items from CThermalLoad to CSpaceHeatingLoad)
   - [occc.cpp] Completed control logic for Florida project.
   - [transterm.c] Prevent 'Form network" if ZigBee not installed
   - [ts-7350.c] Developed and tested the tach interface.
   - [zigbee.c] Re-factored the debug logging, log more info, added timestamps (Ticket #125)
   - [zigbee.c] Added menu item to alter join duration
   - [blower.cpp] Added OFF_MODE for ZigBee thermostats
   - [flowmeter.c] Added support for the remote ETM board
1.09b
   - [zigbee.c] - Update node ID if an existing device announces itself.
   - [databuffer.c] - Zero Thermal production if blower is off (Ticket #55)
   - Implement ASHRAE standard for ventilation (Ticket #174)
   - [databufer.c] - add DC voltage and current to interval data (Ticket #58)
   - [datalogger.c] - manage existing interval data file via header change
   - Provide common interface for PV modules (W instead of kW)
   - [blower.cpp] - Add heat dump mode (Ticket #130)
   - [thermalload.cpp] - Simplified the code (got rid of unnecessary functions)
   - [pid.cpp] - Simplified the code (got rid of unnecessary functions)
   - Added PV status column (PV_status) to interval data file
   - [transterm.c] Added PV status menu
   - [databuffer.c] Add PV status to interval data file
   - [databuffer.c] Increase entry buffer size from 10 to 80
1.09c
   - [pvmeter.c kaco.c veris8031.c] - Allow multiple device names to support different hardware platforms
   - [thermalload.cpp] - Refactoring
1.09d
   - [thermalload.cpp] - Separate isEnabled() from isSolarReady()
   - Calculate active heating period fraction for ventilation
   - [blower.cpp] - Default to nighttime ventilation unless a space heating
     load is enabled.
   - [blower.cpp] - Allow ventilation if no heating/cooling loads are enabled by removing 'enabled' condition from isSolarReady() in thermalload.cpp.
   - [zigbee.c] - Automatically form network when a communications timeout is detected.
   - [databuffer.c] - append number of ZigBee form networks (Z_resets)
   - [runpvt.sh] - Added a 30 second sleep
   - [transterm.c] - Allow setting blower speed in 10% increments.
1.09
   - Ticket summary:  55, 58, 125, 130, 174

1.091 (8-10-10)
   - [zsetpoints.c] - Turn off energy save mode when in manual mode via reverse
     config. Apply energy save offset to manual settings from UI.

1.092 (9-21-10)
   - [datalogger.h] Header is now > 300. Increased DEFAULT_INTERVAL_LINE_LENGTH
     from 300 to 400.

1.093a (8-11-10)
   - Ts-7500 support
   - [databuffer.c] SIG_ALARM mechanism causes xuart errors. Need an alternative
   - [zigbee.c] Added the CLEAR_BINDING_TABLE command.
1.093b (9-1-10)
   - [pvt.cpp] Added command line argument -remote_etm_address
   - [abstractio.c] Added configuration entry Remote_ETM_Address
   - [databuffer.c] Poll system clock instead of SIG_ALARM
1.093c (9-3-10)
   - [abstractio.c] Add input scan thread
   - [abstractio.c] Assigned I/O points to interface board
1.093d (9-14-10)
   - [runts.sh] Modified for TS-7500 support
   - [runpvt.sh] Modified for TS-7500 support
   - [pvt.mak] Remove '-mcpu=arm9' for the TS-7500
        Note: Rev 1.10c exhibits a repeatable problem with an "Illegal
        instruction" at ~2:36 when invoked on a TS-7500 with the following
        command line arguments at the shell prompt:
           ./pvt -q -remote_etm_address 1
   - [pvt_io_3.c] - Added 0.00025 sec triac offset
   - [pvt_io_3.c] - Added triac deadband at upper limit. If value falls within
     this deadband, set to full on.
   - [build] Added an empty pvtrestart.log to pvt_runtime.tar
   - [build, backup, clean, runpvt.sh] Accomodate two pvt binaries built on a
     PVT-CPU and a TS-7500
1.093e (9-20-10)
   - [abstractio.c] For Art's house, read air flow from interface board in a
     remote ETM configuration.
   - [transterm.c] Replace getInput() with getInputRaw() for digital I/O
   - [zigbee.c] log Permit Joining
   - [zigbee.c] Eliminate Leave Network
   - [zigbee.c] Force Node ID to 0xFFFF
   - [zigbee.c] Turn off Permit Joining after first announcement
1.093 (9-28-10)
   - [runpvt.sh] chmod the pvt executable after the move
   - [pvt_runtime.tar] Add revision.h

1.0931 (9-30-10)
   - [abstractio.c] Filter out invalid digital I/O channels for v2.0 hardware to
     prevent delays for the data buffer. Specifically, the two production LED's
   - [pvt_io_3.c] Calculate Triac percent read back to match output value
   - [blower.cpp] Fix ventilation fraction calculations.

1.0932a (10-5-10)
   - Revised temperature look-up table temperature2.lut (ETM_RTD_LUT.txt from
     Don)
   - [databuffer.c] accumulate and report ventilation volume as float
   - [pvtcontroller.c] display more precision for air flow in System Monitor
     screen
   - [ventilation.c] Display more precision in menu
   - [blower.cpp] Make ventilation 90 minute delay configurable.
     'Cooling_Period_Ventilation_Delay' Number of seconds after start of
     inactive period to start venting. Defaults to 5400 (90 minutes)
1.0932a (10-6-10)
   - Released
1.0933 (10-12-10)
   - [abstractio.c] Swapped I/O assignments for Array & T4 temps in v1.0
      hardware with remote ETM
1.0934a (10-12-10)
   - [pvt_io_3.c] - Add the utility pvtio2 to support ETM v2.0 calibration
1.0934 (10-13-10)
   - [abstractio.c] Fixed I/O assignments for Exhaust temp in v1.0 hardware
     with remote ETM
   - [zigbee.c] - Allow node id updates
   - [zigbee.c] - Delay commands after device announcement
   - [blower.cpp] - Fix Zone 2 temp reading 0 in ZigBee mode. Only consider
     zone 1 as a ZigBee thermostat in getTemperatureSetpoint() for now. Need to
     revisit this when we allow 2 ZigBee zones.
   - [zigbee.c] - Add CLEAR_BINDING_TABLE to FORM_NETWORK sequence
 
1.0935 (10-19-10)
   - Updated airflow2.lut from alpha to final version

1.0936a (10-21-10)
   - Added airflow_art2.lut for Art's configuration
   - [abstractio.c]Updated remote ETM assignments for float switch, humidity,
     and pyranometer inputs
   - [abstractio.c] Refactored remote ETM I/O re-assignments to one function
   - [databuffer.c] Fix Thermal Power LED bug which indicated production when
     blower was off

1.0936b (10-27-10)
   - Refactor get/set system ID -> systemid.c
   - Refactor delayMs() & getUptimeMs() -> millisec.c
   - [lookuptable.c] Widened mutex protection in lookupValue()
   - [pvmeter.c] Add call to alert function
   - [transterm.c] Add ZigBee thermostat status
   - [databuffer.c] Add "Alert" column to interval data file
   - [transterm.c] Fixed lock-up bug when disconnecting the Transterem while
     in the ZigBee Form network / Status screen
   - [zigbee.c] Add call to alert functon
   - [blower.cpp] Add calls to alert functions
   - [pvt_io_3] Add call to alert function

1.0936 (11-1-10)
   - [transterm.c] Remove damper open requirement for turning the blower on
   - Released to Beta test site

1.0937 (11-1-10)
   - [abstractio.c] Initialize temperature and airflow look-up tables to V1.0
     to fix missing look-up table entries when system is started with a remote
     ETM.

1.0938a (11-2-10)
   - [transterm.c] Limit blower speed when dampers are closed. Add config.dat
     entry "Max_Blower_Speed_Dampers_Closed", default to 50%
   - [zigbee.c] Changed ZCL_GENERAL_HEADER from 0x01 to 0x04 (v1.6 r5)
   - [zigbee.c] Changed IDENTIFY from 0x00 to 0x10 (v1.6 r5)
   - [zigbee.c] Force Node ID to 0xFFFF if USB stick version >= 1.6.3

1.0938b (11-3-10)
   - [transterm.c] Read PV Monitor Type directly from config.dat instead of
     pv monitor thread so that changes are perceived to be immediate.

1.0938c (11-8-10)
   - [debuglogger.c] Open/close file during enable/disable instead of print
   - [zigbee.c] - Add Fan control, recognize flow control

1.0938d (11-8-10)
   - [pvt_io_3.c] Fixed 'Flat Line Temperature' bug when run on a TS-7500.
     (PWM array out of bounds in adjacent module pvt_io_3.c)
   - [pvt_io_3.c] Mask temperature spikes due to comm errors, do the same for
     analog inputs
   - [zigbee.c] ANNOUNCE no longer stops devices from joining
   - [transterm.c] Add ZigBee Stop Joining menu

1.0938e (11-16-10)
   - [zigbee.c] Automatic permit joining in the event of communication timeout
     (In case someone hits the 'Mate' button on a remote device)

1.0938f (11-18-10)
   - [blower.cpp, configfile.h] Added the config.dat entry "Permit_Joining" to
     enable permit joining for 254 sec.
   - [zigbee.c] Simplified recoverFromMate()

1.0938 (11-18-10)
   - Released

1.0939a (12-09-10)
   - Prevent Night Flush array samples when loads are disabled
   - Modify runpvt.sh to allow applicationstartup update

1.0939 (1-13-11)
   - Add Remote ETM configuration to Transterm

1.0940 (2-2-11)
- [pvtcontroller.c, abstractio.c, blower.cpp] Allow zone 2 RTD in a ZigBee
  (one thermostat) system.


1.08a
   - Misc. refactoring and cleanup
      - Eliminated timing.c, h
      - Removed disablewdt.c
      - Removed lutgenerator.c, h
      - testveris.c
      - Updated pvt.mak
   - [blower.cpp] Both correct and incorrect spelling recognized for Active_Period_Array_Sample_Interval
   - [setup_os] Modified to copy ZigBee serial driver to proper location
   - [zigbee.c] Added code to read and write the on-board clock
1.08b
   - [configuration.c] Modified to read a secondary file for configuration entries without hub intervention.
   - [zigbee.c] Added code to write the thermostat system mode
   - [zigbee.c] Added code to read and write the time zone
   - [zigbee.c] Added code to read and write the cooling setpoint
1.08c
   - [blower.cpp] Added code to support ZigBee heating and cooling for 2 zones
   - [zigbee.c] Added code to calculate DST start and end dates
   - [zigbee.c] Fixed core dump on menu item 18
   - [abstractio.c] Added FLOAT_SWITCH digital input
   - [configfile.h] Added the entry "Float_Switch_Installed", "Pool_Pump_Ready"
   - [blower.cpp] Added code to process the FLOAT_SWITCH digital input
1.08d
   - [serial.c, h] more refactoring
   - [configfile.h] Changed the entry "Pool_Pump_Ready" to "Float_Switch_Tripped"
   - [blower.cpp] Reversed the logic for the entry "Float_Switch_Tripped"
1.08e
   - [configuration.c] Fixed checksum bug
   - [configuration.c] Allow writes to secondary configuration file
   - [configfile.h] Changed default space heating enable temperature setpoint from 12C to 16C
   - [configfile.h] Added the configuration entry "Time_Zone" and "Daylight_Saving_Time_Enable"
   - [zigbee.c] Add real-time display of setpoints to ease device identification
1.08f
   - [configuration.c] Added menu for debug
1.08g
   - [pvt_remote.c, pvt_comm.c] Added remote communication modules for remote ETM
   -[blower.cpp] Removed compilation warnings when compiled on a TS-7500
1.08h
   - [zigbee.c] Remove zigbee.dat when leaving current network, devices managed better, correctly display Eui64s
1.08i
   - [zigbee.c] Added temperature, mode, and  time of last Rx to device monitor screen
   - [pvt.cpp] Added the command line switch "-noavg" to turn off A/D averaging
1.08j
   - [zigbee.c] Update ZigBee clock once per day.
   - [abstractio.c] Integrated PVT I/O Generation 3 code
   - [transterm.c] Disabled the hex key (S2 SPACE). This sequence caused the
function keys to stop working until a valid hex code was entered.
   - [zigbee.c] Modified to send commands no quicker than one every 60 sec.
1.08k
1.08l
   - [pvmeter.c] Debugged KACO inverter
1.08m
   - Added changes of 1.07
1.08n   (1-26-10)
   - [kaco.c] Added more diagnostic information to Kaco interface
   - [veris8031.c] Added more diagnostic information to Veris interface
   - More refactoring and simplification of the PV meter subsystem
1.08o   (1-29-10)
   - [sma.c] Refactored to conform to the other devices
   - [sma.c] Added more diagnostic information to SMA interface
1.08p   (2-1-10)
   - [configuration.c] Changed MAX_NUM_PROPERTIES_PER_FILE from 150 to 500
   - [pvmeter.c] Limit PV diagnostic string to 80 characters.
   - [pvt_io_3.c] Defined timing resolution for remote I/O
   - [pvt_remote.c, pvt_comm.c] Eliminated warnings from both hardware platforms
   - [pvt_remote.c, pvt_comm.c] Added diagnostic information
1.08q   (2-15-10)
   - [abstractio.c] Allow changing I/O configuration 'on the fly'
   - [pvt_remote.c] Added retries
1.08r   (2-26-10)
   - [zsetpoints.c, blower.cpp] Implemented calendar function
   - [zsetpoints.c] Removed Vacation scene
   - [zsetpoints.c] Changed day 1 from Sunday to Monday
   - [abstractio.c] Debugged remote I/O
   - [pvt_io_3.c] Debugged triac
   - [lookuptable.c] Refactored lookup table code into one module, removed old code
   - [abstractio.c] Added informal configuration entry "Art" intended for config2.dat, if set to one selects the correct air flow lookup table for Art's home
   - [configuration.c] - the 'set' functions update config.dat file on changes
   - [zsetpoints.c] Added reverse config entry "Th1_Scenduled_Scene" to report the current scene to the UI (where n = thermostat)
1.08s (3-11-10)
   - [blower.cpp] Add reverse configurable zone temperature setpoints
   - [datalogger.c] Added config entries Interval_Log_Path" and "Max_Interval_Log_File_Size"
   - [transterm.c] Add ZigBee support for status and forming a network
   - [transterm.c] Change "Trunk 4" label to "ETM Outlet"
   - [zigbee.c] Add a function to form a network
   - Added configuration file entry "Form_ZigBee_Network"
1.08t (4-13-10)
   - [configuration.c] Ensure that file timestamp changes when written
   - [configuration.c] Read/write files via separate thread to better sync with Web Services
   - [transterm.c] Display current PV monitor type
   - [transterm.c] Allow setting PV monitor type via Transterm
   - [configfile.h] Change default PV monitor type from Veris to Kaco
   - [configuration.c] Fix file locking bug
1.08u (4-23-10)
   - [zsetpoints.c] Do not apply energy saving offsets in manual mode
   - [transterm.c] Add Setup and Diagnostics menus, change main menu
        F3 - Setup Menu
           F1 - Display system ID
           F2 - Display controller software version
           F3 - Display / Set power meter type
        F4 - Diagnostics Menu
           F1 - Display network connectivity
1.08v (4-28-10)
   - [transterm.c] Complete re-design
   - [pvt_comm.c] Remove writeSerialEncoded()
   - [blower.cpp] Start array sample at 80% blower speed for 2 seconds.
   - [pvmeter.c] Prevent communications with Kaco or SMA during inactive
heating periods
   - [transterm.c] Disable setup mode via keyboard
   - [pvmeter.c] Zero PV power when changing PV monitor type
   - [transterm.c] Save setup to EEPROM if necessary
   - [transterm.c] Display PV comm error
   - [zigbee.c] Change send command interval from 10 to 30 sec.
   - [transterm.c] Add ETM Serial Number
1.08
   - Released 5-13-10


1.081 (6-8-10)
   - [blower.cpp] Fixed night flush bug where the heating setpoint was used for night flush in the non- ZigBee mode of operation.
   - [blower.cpp] Fix bug that would continuously form a ZigBee network


1.082 (6-11-10)
   - [configuration.c] Turn off debug flag (Oops).


1.07
   - [kaco.c] Added module to interface with a KACO inverter
   - [pvmeter.c] Integrated the KACO inverter
   - Added PV monitor selection via config.dat
   - Added the configuration file entry PV_Monitor_Type
     (1 - Veris, 2 - SMA, 3 - Kaco)
   - All PV monitor devices assigned to COM1
   - Added the configuration file entry Num_PV_Monitor_Units (for future)
   - Added PV monitor diagnostics file /tmp/logs/pvdiagnostics.log


1.06
   - [ts7350.c] Permanently disable watchdog timer


1.05
   - [console.c] Fixed %CPU utilization problem when running in quiet mode


1.04a
   - Added support for the MMB Reasearch RapidSE ZigBee interface
   - Modified the triac test program to turn off all LEDs
   - Integrated ZigBee temperature measurement for zone 1
1.04b
   - Integrated ZigBee temperature setpoint for zone 1
   - Added functionality to test program (pvtio) to include relay output
   - Open issues:
        - ZigBee stick detection not reliable when pvt is restarted
        - Thermostat euid not consistent when pvt is restarted. Must remove
          zigbee.dat, and form a new network.
1.04c
   - Fixed ZigBee thermostat eui64 consistency bug.
   - Modified the power meter initialization for additional fault tolerance.
   - Drop out a zone heating load if approach temp > 70 C.
1.04d
   - Log watchdog timer events with the watchdog timer disabled
1.04e
   - Add watchdog timer menu
   - Changed watchdog timer FPGA register access from 8 to 16 bits
   - Enable watchdog timer


1.03a
   - Modified the source to compile on the TS-7500
      - blower.cpp: Cast string constants to (char *)
      - thermalload.cpp: Change string constants to (const char *)
      - pvt.cpp: Include <cstring.h>
      - pvt.mak: Change link option for specifying libraries
      - clean: Added -f to rm commands
      - pvt.mak: added conditional link flags for the TS-7500 and TS-7350
      - build: Added conditional make for the TS-7500 and TS-7350
   - Added a test program (pvtio) to control the triacs (see ts7350.c)
1.03b
   - Added functionality to above test program to include analog input
   - Removed TS-7200 RS-485 support from serial.c
   - Removed TS-7200 local LCD display support from pvtcontroller.c
1.03c
   - Had to add '-L .' to the link for the 7350
   - Added enhancements to the operation of the Transterm commissioning tool
1.03d
   - Added watchdog timer
   - applicationstartup will execute pvtinit if found on a USB stick
   - Changed default maximum night flush blower speed from  95 to 80
   - Fixed negative thermal power resulting from T4 temp > array temp
   - Modified serial.c to ignore all control characters
1.03
   - Synchronize system clock to battery backed clock every 24 hours


1.02a
   - Added SMA yasdi source code to source distribution
   - Automated the build process
   - Use backup to create a source code distribution
   - Added the creation of a runtime distribution
1.02b
   - Modify pvt.mak to include SMA yasdi code
   - Incorporate yasdishell into the pvt executable
1.02c
   - Added communications interface to SMA inverter
1.02d
   - Conditionally poll SMA during active heating period (just for test)
1.02e
   - Added dual zone heating
   - Added the fields P_air_space2 and P_night_flush2 to the 30 sec data file
   - Added the fields E_air_space2 and E_Night_flush2 to the interval data file
   - Added the configuration file entry Space_Heating_1_Power_Allocation_Factor
   - Added the configuration file entry Space_Heating_1_Sub_Priority
   - Added the configuration file entry Space_Heating_2_Sub_Priority
   - Added the configuration file entry Night_Flush_1_Sub_Priority
   - Added the configuration file entry Night_Flush_2_Sub_Priority
1.02f
   - Restart pvt upon detection of a lockup with the SMA inverter
   - Modify how master load is determined for space heating loads
1.02g
   - Added the configuration file entry PV_Installed
   - PV_Installed set to 0 prevents any communication with power metering devices (Veris, SMA, etc.)
   - Fixed master load determination bug when space heating loads are driving
     the blower
1.02h
   - Fixed bug which reported negative energy values due to variable roll-over


1.01
   - Changed data logging numeric format to the following:
        Blower speed:     x.y    (1 decimal place)
        Power and energy: x.yyyy (4 decimal places)
        Pyranometer:      x      (0 decimal places)
        Air flow:         x.yyyy (4 decimal places)
   - Fix flashing brackets on system monitor screen during night flush when load drops out due to delta drive
   - Turn off all dampers under overheat or freeze recirc conditions during night flush
   - Added commisioning functionality via a Transterm 5 data terminal connected to a USB port
   - Simplified deadband entries in configfile.h. Removed distinction between temerature and delta drive deadbands
   - Updated pyranometer.lut scaled to a 0-10V analog input
   - Updated correctionfactor.lut to use SI units. Elevation must now be sepcified in meters
   - Fixed Transterm bug preventing detection of USB adaptor during F1
   - Interval data records percent ON for digital I/O entries
   - Cleaned up transterm.c, improved readability
   - Replaced thermal capacitance references with specific heat for readability and accuracy
   - Added specificheat.lut to replace thermalcapacitance.lut
   - Removed thermalcapacitance.lut
   - Modified serial.c to record serial data to aid in interfacing to an SMA inverter
   - Modified serial.c to support 1200 baud with the new bitstream
   - Bug 7: Added configuration file entry Maximum_DHW_Pump_Speed  (% * 100)
   - Bug 7: Added configuration file entry Maximum_Pool_Pump_Speed (% * 100)
   - Revised airflow.lut dated 6-1-09


1.0
   - Added T_tank1_bottom, T_zone2, MD_exhaust1 and MD_zone2 labels to the data log files
   - Changed the content under T_tank1_top to reflect top sensor measurements
   - Changed the column order to be consistent with physical I/O assignments
   - Removed legacy look-up tables and config files
   - Renamed correction_factor.lut to correctionfactor.lut for naming consistency
   - Simplified the abstract I/O names
   - Changed default values in configfile.h and config.dat specified in email 3-30-09


0.9.985
   - Changed overheat temps to 93C threshold and 18C deadband
   - Changed freeze recirc threshold to lower of array or T4
   - Turn off blower under freeze conditions
   - New temperature look-up table to detect failed or unplugged RTD's


0.9.984d
   - Fixed the exhaust damper blower delay bug (typo)
   - Added configuration file entry Exhaust_Damper_Blower_Delay (sec)
   - Added code to the startup script that allows file transfers via a USB memory stick


0.9.984c
   - Added code to average the Analog measurements over time (TS-7350)
   - Added temperature lookup table based on a 2.5V reference. The old lookup table is renamed to temperature.old.lut


0.9.984b
   - Modified air flow measurements to compensate for 5V inconsistencies via A/D channel 8
   - Added configuration file entry ETM_Offset (n * 1e7)
   - Added configuration file entry ETM_Scale (n * 1e10)
   - Added configuration file entry Power_Supply_Voltage (V * 1000)
   - Commented out the lines of code that makes use of a stored approach temperature
   - Added a 10 sec delay before opening the exhaust damper


0.9.984a
   - Modified thermal energy calculation
   - Added configuration file entry Elevation (m)
   - Added configuration file entry Density_Calibration (kg/m3 * 1000)


0.9.983
   - Added code to detect Low temperature and turn on DHW pump
   - Added configuration file entry Water_Heater_1_Open_Loop (0 or 1)
   - Added configuration file entry Freeze_Recirc_Temperature_Setpoint (deg C)
   - Added configuration file entry Freeze_Recirc_Temperature_Deadband (deg C)
   - Modified setup_os to execute pvt in a loop
   - Reversed the relay assignments for zone 1 & 2 dampers
   - Low temp monitoring checks for invalid measurements (-900 C)


0.9.982
   - Added code to detect high temperature and turn off blower
   - Modified thermostats to compare against a single-ended deadband
   - Fixed blower control polarity with respect to the exhaust load


0.9.981
   - Added code to average the RTD measurements over time (TS-7350)
   - Modified heating element control to turn off when disabled
   - Modified temperature average thread to record instantaneous values
   - Added code to operate the new damper I/O configuration for the ETM
   - Added code to average the RTD measurements over time (TS-7200)


0.9.97
   - Fixed monitor I/O screen bug related to displaying the master load
   - Fixed bug where DHW pump stays on
   - Added configuration file entry Maximum_Blower_Speed (%)


0.9.96
   - Added comment headers to code
   - Fixed bug with simulator
   - Added RTD calibration
   - Added the config entry RTD_Offset_Counts for testing
   - Removed the air flow scale factor
   - Added new look-up tables for temperature and air flow


0.9.95
   - Prevent LCD writes when running on custom hardware (TS-7350)
   - Implemented watchdog timer functionality for custom hardware (TS-7350)
   - Changed the I/O assignments for pyranometer and humidity inputs (TS7350)
   - Fixed bug that recorded blower speed as 0 in log files
   - Added the ability to store comments ('#' or "//")in lookup table files
   - Changed look-up table file names:
        PT1000lut.dat          -> temperature.lut
        flowmeter.dat          -> airflow.lut
        thermalcapacitance.dat -> thermalcapacitance.lut
        pyranometer.dat        -> pyranometer.lut
   - Added processing for the PV and thermal power LEDs
   - Added processing for the communications and diagnostics LEDs
   - Added processing for the controller power LED


0.9.94
   - Add minimum delay for triac channels to prevent flicker at 100%
   - Fixed problem displaying Veris data to console via telnet
   - Add killpvt script


0.9.93
   - Add functionality for custom hardware (TS-7350)
   - Add I/O Monitor screen
   - Fixed ambient temperature bug during simulation
   - Reserve COM1 (/dev/ttyAM1) for login


0.9.92
   - Added configuration file entry Minimum_Blower_Speed (%)


0.9.91
   - Fixed config file typo for 'Water_Heater_Heating_Element_Enable'
   - Fixed syntax error and typo in setup script


0.9.9
   - Active_Period_Start_Hour and Active_Period_End_Hour now include minutes
   - Fix lock-up problem with proper signal handler in databuffer.c
   - Configuration key words and defaults changed to match the data dictionary
   - Can run on the TS-7350 CPU card with the command: pvt -ts7350
   - Code includes integrated software simulator
*/


#endif /*REVISION_H_*/
