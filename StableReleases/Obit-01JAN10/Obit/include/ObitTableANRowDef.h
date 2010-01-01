/* $Id: ObitTableANRowDef.h 123 2009-09-04 11:26:14Z bill.cotton $   */
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
 * \file ObitTableANRowDef.h
 * ObitTableANRow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** Station number, used as an index in other tables, uv data */
oint  noSta;
/** Mount type, 0=altaz, 1=equatorial, 2=orbiting */
oint  mntSta;
/** Axis offset */
ofloat  staXof;
/** Feed A feed position angle */
ofloat  PolAngA;
/** Feed B feed position angle */
ofloat  PolAngB;
/** Station name */
gchar*  AntName;
/** X,Y,Z offset from array center */
odouble*  StaXYZ;
/** Orbital parameters. */
odouble*  OrbParm;
/** Feed A feed poln. type 'R','L','X','Y', actually only one valid character. */
gchar*  polTypeA;
/** Feed A poln. cal parameter. */
ofloat*  PolCalA;
/** Feed B feed poln. type 'R','L','X','Y' */
gchar*  polTypeB;
/** Feed B poln. cal parameter */
ofloat*  PolCalB;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
