/* $Id: ObitTableIDI_ANTENNADef.h 123 2009-09-04 11:26:14Z bill.cotton $   */
/* DO NOT EDIT - file generated by ObitTables.pl                      */
/*--------------------------------------------------------------------*/
/*;  Copyright (C)  2009                                              */
/*;  Associated Universities, Inc. Washington DC, USA.                */
/*;                                                                   */
/*;  This program is free software; you can redistribute it and/or    */
/*;  modify it under the terms of the GNU General Public License as   */
/*;  published by the Free Software Foundation; either version 2 of   */
/*;  the License, or (at your option) any later version.              */
/*;                                                                   */
/*;  This program is distributed in the hope that it will be useful,  */
/*;  but WITHOUT ANY WARRANTY; without even the implied warranty of   */
/*;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    */
/*;  GNU General Public License for more details.                     */
/*;                                                                   */
/*;  You should have received a copy of the GNU General Public        */
/*;  License along with this program; if not, write to the Free       */
/*;  Software Foundation, Inc., 675 Massachusetts Ave, Cambridge,     */
/*;  MA 02139, USA.                                                   */
/*;                                                                   */
/*;Correspondence about this software should be addressed as follows: */
/*;         Internet email: bcotton@nrao.edu.                         */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitTableIDI_ANTENNA  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableIDI_ANTENNADef.h
 * ObitTableIDI_ANTENNA structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Table format revision number */
oint  tabrev;
/** Number of Stokes parameters */
oint  no_stkd;
/** First Stokes parameter */
oint  stk_1;
/** Number of frequency bands */
oint  no_band;
/** Number of frequency channels */
oint  no_chan;
/** Reference frequency (Hz) */
odouble  ref_freq;
/** Channel bandwidth (Hz) */
odouble  chan_bw;
/** Reference frequency bin */
oint  ref_pixl;
/** Observation project code */
gchar  obscode[MAXKEYCHARTABLEIDI_ANTENNA];
/** Array name */
gchar  ArrName[MAXKEYCHARTABLEIDI_ANTENNA];
/** Reference date as "YYYY-MM-DD" */
gchar  RefDate[MAXKEYCHARTABLEIDI_ANTENNA];
/** Number of polarization calibration constants */
oint  numPCal;
/** Polarization parameterazation type, 'APPR', 'RAPPR', 'ORI-ELP' */
gchar  polType[MAXKEYCHARTABLEIDI_ANTENNA];
/** Column offset for Time. in table record */
olong  timeOff;
/** Physical column number for Time. in table record */
olong  timeCol;
/** Column offset for Time interval over which antenna characteristics valid. in table record */
olong  time_intervalOff;
/** Physical column number for Time interval over which antenna characteristics valid. in table record */
olong  time_intervalCol;
/** Column offset for Station number, used as an index in other tables, uv data in table record */
olong  antenna_noOff;
/** Physical column number for Station number, used as an index in other tables, uv data in table record */
olong  antenna_noCol;
/** Column offset for Subarray number in table record */
olong  arrayOff;
/** Physical column number for Subarray number in table record */
olong  arrayCol;
/** Column offset for Frequency group id in table record */
olong  freqidOff;
/** Physical column number for Frequency group id in table record */
olong  freqidCol;
/** Column offset for Quantization of data, no. levels. in table record */
olong  no_levelsOff;
/** Physical column number for Quantization of data, no. levels. in table record */
olong  no_levelsCol;
/** Column offset for Feed A feed poln. type 'R','L','X','Y', actually only one valid character. in table record */
olong  polTypeAOff;
/** Physical column number for Feed A feed poln. type 'R','L','X','Y', actually only one valid character. in table record */
olong  polTypeACol;
/** Column offset for Feed B feed poln. type 'R','L','X','Y' in table record */
olong  polTypeBOff;
/** Physical column number for Feed B feed poln. type 'R','L','X','Y' in table record */
olong  polTypeBCol;
/** Column offset for Station name in table record */
olong  AntNameOff;
/** Physical column number for Station name in table record */
olong  AntNameCol;
/** Column offset for Feed A feed position angle in table record */
olong  PolAngAOff;
/** Physical column number for Feed A feed position angle in table record */
olong  PolAngACol;
/** Column offset for Feed A poln. cal parameter. in table record */
olong  PolCalAOff;
/** Physical column number for Feed A poln. cal parameter. in table record */
olong  PolCalACol;
/** Column offset for Feed B feed position angle in table record */
olong  PolAngBOff;
/** Physical column number for Feed B feed position angle in table record */
olong  PolAngBCol;
/** Column offset for Feed B poln. cal parameter in table record */
olong  PolCalBOff;
/** Physical column number for Feed B poln. cal parameter in table record */
olong  PolCalBCol;
/** Column offset for [OPTIONAL] Beam Full Width Half Maximum in table record */
olong  BeamFWHMOff;
/** Physical column number for [OPTIONAL] Beam Full Width Half Maximum in table record */
olong  BeamFWHMCol;
