/* $Id: ObitTableIDI_ANTENNARowDef.h 123 2009-09-04 11:26:14Z bill.cotton $   */
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
 * \file ObitTableIDI_ANTENNARowDef.h
 * ObitTableIDI_ANTENNARow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** Time. */
odouble  time;
/** Time interval over which antenna characteristics valid. */
ofloat  time_interval;
/** Station number, used as an index in other tables, uv data */
oint  antenna_no;
/** Subarray number */
oint  array;
/** Frequency group id */
oint  freqid;
/** Quantization of data, no. levels. */
oint  no_levels;
/** Feed A feed poln. type 'R','L','X','Y', actually only one valid character. */
gchar  polTypeA;
/** Feed B feed poln. type 'R','L','X','Y' */
gchar  polTypeB;
/** Station name */
gchar*  AntName;
/** Feed A feed position angle */
ofloat*  PolAngA;
/** Feed A poln. cal parameter. */
ofloat*  PolCalA;
/** Feed B feed position angle */
ofloat*  PolAngB;
/** Feed B poln. cal parameter */
ofloat*  PolCalB;
/** [OPTIONAL] Beam Full Width Half Maximum */
ofloat*  BeamFWHM;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
