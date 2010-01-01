/* $Id:  $   */
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
/*  Define the basic components of the ObitTableRow structure       */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableIDI_INTERFEROMETER_MODELRowDef.h
 * ObitTableIDI_INTERFEROMETER_MODELRow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** The center time. */
odouble  Time;
/** Time interval of record */
ofloat  TimeI;
/** Source ID number */
oint  SourID;
/** Antenna number */
oint  antennaNo;
/** Array number */
oint  Array;
/** Frequency ID */
oint  FreqID;
/** Ionospheric Faraday Rotation */
ofloat  IFR;
/** FREQ.VAR (?) */
ofloat*  FreqVar;
/** Phase delay */
odouble*  PDelay1;
/** Group delay */
odouble*  GDelay1;
/** Phase delay rate */
odouble*  PRate1;
/** Group delay rate */
odouble*  GRate1;
/** Dispersion */
ofloat  Disp1;
/** Dispersion rate */
ofloat  DRate1;
/** Phase delay */
odouble*  PDelay2;
/** Group delay */
odouble*  GDelay2;
/** Phase delay rate */
odouble*  PRate2;
/** Group delay rate */
odouble*  GRate2;
/** Dispersion */
ofloat  Disp2;
/** Dispersion rate */
ofloat  DRate2;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
