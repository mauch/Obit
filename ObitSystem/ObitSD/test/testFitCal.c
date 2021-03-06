/* $Id$                            */
/*--------------------------------------------------------------------*/
/*;  Copyright (C) 2004                                               */
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
/*;  Correspondence this software should be addressed as follows:     */
/*;         Internet email: bcotton@nrao.edu.                         */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/

#include "ObitOTF.h"
#include "ObitOTFCalUtil.h"
#include "ObitSystem.h"
/* internal prototypes */
int main ( int argc, char **argv )
/*----------------------------------------------------------------------- */
/*   Test bed program                                                     */
/*----------------------------------------------------------------------- */
{
  ObitSystem *mySystem= NULL;
  ObitErr *err= NULL;
  ObitOTF *inData=NULL;
  gchar *FITSdir[] = {"PythonData/"};
  gchar *inFile = "GCLband3C286OTF.fits";
  gint32 dim[MAXINFOELEMDIM] = {1,1,1,1,1};
  ofloat tau0, ATemp[2];
  olong scan[4], nrec, disk;
  olong ierr=0;

  /* Initialize Obit */
  err = newObitErr();
  mySystem = ObitSystemStartup ("test", 1, 0, 0, NULL, 1, FITSdir, 
				(oint)TRUE, (oint)FALSE, err);
  if (err->error) ierr = 1;
  ObitErrLog(err); /* show any error messages on err */
  if (ierr!=0) return ierr;

  /* Set data */
  disk = 1;
  nrec = 1000;
  inData  = newObitOTF("Input data");
  ObitOTFSetFITS(inData,nrec,disk,inFile,err);
  if (err->error) ierr = 1;
  ObitErrLog(err); /* show any error messages on err */
  if (ierr!=0) return ierr;

  /* Open/close input OTF to fully instantiate */
  if ((ObitOTFOpen (inData, OBIT_IO_ReadOnly, err) 
       != OBIT_IO_OK) || (err->error>0))  /* error test */
    Obit_log_error(err, OBIT_Error, "ERROR opening input FITS file %s", inFile);
  
  /* */
  if ((ObitOTFClose (inData, err) != OBIT_IO_OK) || (err->error>0))
    Obit_log_error(err, OBIT_Error, "ERROR closing input file");
  if (err->error) ierr = 1;
  ObitErrLog(err);
  if (ierr!=0) return ierr;
  
  /* Set parameters */
  scan[0] = 16;scan[1] = 17;scan[2] = 18;scan[3] = 19;
  tau0 = 0.01;
  ATemp[0] = 1.0; ATemp[1] = 1.0; 
  dim[0] = 1; dim[1] = 1;
  ObitInfoListPut(inData->info, "TAU0",  OBIT_float, dim, (gpointer*)&tau0, err);
  dim[0] = 2;
  ObitInfoListPut(inData->info, "ATEMP", OBIT_float, dim, ATemp, err);
  dim[0] = 4;
  ObitInfoListPut(inData->info, "Scan",  OBIT_long,   dim, (gpointer*)&scan, err);

  /* Do fitting */
  ObitOTFCalUtilFitCal(inData, -1,  err);
  if (err->error) ierr = 1;
  ObitErrLog(err);
  if (ierr!=0) return ierr;
 
 /* cleanup */
  inData = ObitOTFUnref(inData);
 
  /* Shutdown Obit */
  mySystem = ObitSystemShutdown (mySystem);
  
  return ierr;
} /* end of main */

