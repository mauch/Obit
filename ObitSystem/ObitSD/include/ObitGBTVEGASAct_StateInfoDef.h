/* $Id$  */
/*--------------------------------------------------------------------*/
/*;  Copyright (C) 2013                                               */
/*;  Associated Universities, Inc. Washington DC, USA.                */
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
/*;  Correspondence this software should be addressed as follows:     */
/*;         Internet email: bcotton@nrao.edu.                         */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitGBTDCRStateInfo structure.    */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitGBTVEGASStateInfoListDef.h
 * ObitGBTVEGASStateInfoDef structure members for derived classes.
 */
#include "ObitDef.h"  /* Parent class definitions */
#define MAXNUMVEGASACT_STATE 10
/** Internal primary Signal-Reference indicator. */
gboolean  isigref1[MAXNUMVEGASACT_STATE];
/** Internal secondary Signal-Reference indicator. */
gboolean  isigref2[MAXNUMVEGASACT_STATE];
/** Internal indication of the state of switching Cal noise diode */
gboolean  ical[MAXNUMVEGASACT_STATE];
/** External primary Signal-Reference indicator. */
gboolean  esigref1[MAXNUMVEGASACT_STATE];
/** External secondary Signal-Reference indicator. */
gboolean  esigref2[MAXNUMVEGASACT_STATE];
/** External indication of the state of switching Cal noise diode */
gboolean  ecal[MAXNUMVEGASACT_STATE];
/** Number of states */
olong nVEGASAct_State;