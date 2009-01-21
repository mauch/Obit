/* $Id$  */
/* DO NOT EDIT - file generated by ObitSDTables.pl                    */
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
/*;         Internet email: bcotton@nrao.edu.                        */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitTableSNRow structure       */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableGBTSPRECEIVERRowDef.h
 * ObitTableGBTSPRECEIVERRow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/**  */
oint  rcvrid;
/**  */
odouble  obsfreq;
/**  */
odouble  iff;
/**  */
odouble  freqres;
/**  */
ofloat  bandwd;
/**  */
ofloat  tcal;
/**  */
ofloat  tplevel;
/**  */
ofloat  fasttim;
/**  */
ofloat  slowtim;
/**  */
ofloat  clip;
/**  */
ofloat  thresh;
/**  */
guint8  synthl;
/**  */
guint8  overl;
/**  */
guint8  imodf;
/**  */
guint8  ifsynth;
/**  */
guint8  taperoff;
/**  */
guint8  rfiexc;
/**  */
guint8  clksrc;
/**  */
guint8  iflo;
/**  */
guint8  ifside;
/**  */
guint8  rfside;
/**  */
gchar*  taper;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
