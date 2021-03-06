/* $Id$  */
/*--------------------------------------------------------------------*/
/*;  Copyright (C) 2004-2009                                          */
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
/*;Correspondence about this software should be addressed as follows: */
/*;         Internet email: bcotton@nrao.edu.                         */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitObitDConCleanWindow ClassInfo structure */
/* This is intended to be included in a classInfo structure definition  */
#include "ObitClassDef.h"  /* Parent class ClassInfo definition file */
/** Function pointer to Constructor. */
ObitDConCleanWindowCreateFP ObitDConCleanWindowCreate;
/** Function pointer to Constructor foe 1 field. */
ObitDConCleanWindowCreate1FP ObitDConCleanWindowCreate1;
/** Function pointer to Ask window info*/
ObitDConCleanWindowInfoFP ObitDConCleanWindowInfo;
/** Function pointer to window search*/
ObitDConCleanWindowSearchFP ObitDConCleanWindowSearch;
/** Function pointer to Add window */
ObitDConCleanWindowAddFP ObitDConCleanWindowAdd;
/** Function pointer to Delete window */
ObitDConCleanWindowDelFP ObitDConCleanWindowDel;
/** Function pointer to Modify window */
ObitDConCleanWindowUpdateFP ObitDConCleanWindowUpdate;
/** Function pointer to set outer window */
ObitDConCleanWindowOuterFP ObitDConCleanWindowOuter;
/** Function pointer to Check Image */
ObitDConCleanWindowImageFP ObitDConCleanWindowImage;
/** Function pointer to Check Row */
ObitDConCleanWindowRowFP ObitDConCleanWindowRow;
/** Function pointer to Check Outer Row */
ObitDConCleanWindowOuterRowFP ObitDConCleanWindowOuterRow;
/** Function pointer to Check Size */
ObitDConCleanWindowSizeFP ObitDConCleanWindowSize;
/** Function pointer to Count pixels */
ObitDConCleanWindowCountFP ObitDConCleanWindowCount;
/** Function pointer to find values needed for autoWindow */
ObitDConCleanWindowAutoWindowFP ObitDConCleanWindowAutoWindow;
/** Function pointer to replace windows in a field */
ObitDConCleanWindowReplaceFieldFP ObitDConCleanWindowReplaceField;
/** Function pointer to add field */
ObitDConCleanWindowAddFieldFP ObitDConCleanWindowAddField;
/** Function pointer to row box mask */
ObitDConCleanWindowInnerRowFP ObitDConCleanWindowInnerRow;
/** Function pointer to row unbox mask */
ObitDConCleanWindowUnrowFP ObitDConCleanWindowUnrow;
/** Function pointer to image stats */
ObitDConCleanWindowStatsFP ObitDConCleanWindowStats;
