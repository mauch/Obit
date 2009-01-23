/* $Id$  */
/* DO NOT EDIT - file generated by ObitSDTables.pl                    */
/*--------------------------------------------------------------------*/
/*;  Copyright (C)  2008                                              */
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
/*;         Internet email: bcotton@nrao.edu.                        */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitTableGBTDCRRECEIVER  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableGBTDCRRECEIVERDef.h
 * ObitTableGBTDCRRECEIVER structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Scan numbe */
oint  scan;
/** MJD of start tim */
oint  utdate;
/** Start tim */
odouble  utcstart;
/** Column offset for  in table record */
olong  channelidOff;
/** Physical column number for  in table record */
olong  channelidCol;
/** Column offset for  in table record */
olong  testdataOff;
/** Physical column number for  in table record */
olong  testdataCol;