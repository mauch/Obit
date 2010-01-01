/* $Id: ObitTableMCRowDef.h 123 2009-09-04 11:26:14Z bill.cotton $   */
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
 * \file ObitTableMCRowDef.h
 * ObitTableMCRow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** The center time. */
odouble  Time;
/** Source ID number */
oint  SourID;
/** Antenna number */
oint  antennaNo;
/** Array number */
oint  Array;
/** Frequency ID */
oint  FreqID;
/** Atmospheric delay */
odouble  atmos;
/** Time derivative of ATMOS */
odouble  Datmos;
/** Group delay */
odouble  GDelay;
/** Group delay rate */
odouble  GRate;
/** "Clock" epoch error */
odouble  clock1;
/** Time derivative of CLOCK */
odouble  Dclock1;
/** LO Offset */
ofloat  LOOffset1;
/** Time derivative of LO offset */
ofloat  DLOOffset1;
/** Dispersive delay (sec at wavelength = 1m)for Poln # 1 */
ofloat  disp1;
/** Time derivative of DISPfor Poln # 1 */
ofloat  Ddisp1;
/** "Clock" epoch error */
odouble  clock2;
/** Time derivative of CLOCK */
odouble  Dclock2;
/** LO Offset */
ofloat  LOOffset2;
/** Time derivative of LO offset */
ofloat  DLOOffset2;
/** Dispersive delay (sec at wavelength = 1m)for Poln # 2 */
ofloat  disp2;
/** Time derivative of DISPfor Poln # 2 */
ofloat  Ddisp2;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
