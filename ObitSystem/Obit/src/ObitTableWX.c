/* $Id$   */
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
#include "ObitTableWX.h"
#include "ObitTableList.h"
#include "ObitData.h"

/*----------------Obit:  Merx mollis mortibus nuper ------------------*/
/**
 * \file ObitTableWX.c
 * ObitTableWX class function definitions.
 *
 * This class is derived from the #ObitTable class.
 */

/** name of the class defined in this file */
static gchar *myClassName = "ObitTableWX";

/**  Function to obtain parent Table ClassInfo - ObitTable */
static ObitGetClassFP ObitParentGetClass = ObitTableGetClass;

/** name of the Row class defined in this file */
static gchar *myRowClassName = "ObitTableWXRow";

/**  Function to obtain parent TableRow ClassInfo */
static ObitGetClassFP ObitParentGetRowClass = ObitTableRowGetClass;

/*--------------- File Global Variables  ----------------*/
/*----------------  Table Row  ----------------------*/
/**
 * ClassInfo structure ObitTableClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableWXRowClassInfo myRowClassInfo = {FALSE};

/*------------------  Table  ------------------------*/
/**
 * ClassInfo structure ObitTableWXClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableWXClassInfo myClassInfo = {FALSE};

/*---------------Private function prototypes----------------*/
/** Private: Initialize newly instantiated Row object. */
void  ObitTableWXRowInit  (gpointer in);

/** Private: Deallocate Row members. */
void  ObitTableWXRowClear (gpointer in);

/** Private: Initialize newly instantiated object. */
void  ObitTableWXInit  (gpointer in);

/** Private: Deallocate members. */
void  ObitTableWXClear (gpointer in);

/** Private: update table specific info */
static void ObitTableWXUpdate (ObitTableWX *in, ObitErr *err);

/** Private: copy table keywords to descriptor info list */
static void ObitTableWXDumpKey (ObitTableWX *in, ObitErr *err);

/** Private: Set Class function pointers */
static void ObitTableWXClassInfoDefFn (gpointer inClass);

/** Private: Set Row Class function pointers */
static void ObitTableWXRowClassInfoDefFn (gpointer inClass);
/*----------------------Public functions---------------------------*/

/*------------------  Table Row ------------------------*/
/**
 * Constructor.
 * If table is open and for write, the row is attached to the buffer
 * Initializes Row class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableWXRow* newObitTableWXRow (ObitTableWX *table)
{
  ObitTableWXRow* out;
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;

  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableWXRowClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableWXRow));

  /* initialize values */
  out->name = g_strdup("TableWX Row");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myRowClassInfo;

  /* initialize other stuff */
  ObitTableWXRowInit((gpointer)out);
  out->myTable   = (ObitTable*)ObitTableRef((ObitTable*)table);

  /* If writing attach to buffer */
  if ((table->buffer) && (table->myDesc->access != OBIT_IO_ReadOnly) &&
      (table->myStatus != OBIT_Inactive)) {
    /* Typed pointers to row of data */  
    dRow  = (odouble*)table->buffer;
    iRow  = (oint*)table->buffer;
    siRow = (gshort*)table->buffer;
    fRow  = (ofloat*)table->buffer;
    cRow  = (gchar*)table->buffer;
    lRow  = (gboolean*)table->buffer;
    bRow  = (guint8*)table->buffer;
  
    /* Set row pointers to buffer */
  } /* end attaching row to table buffer */

 return out;
} /* end newObitTableWXRow */

/**
 * Returns ClassInfo pointer for the Row class.
 * \return pointer to the Row class structure.
 */
gconstpointer ObitTableWXRowGetClass (void)
{
  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableWXRowClassInit();
  return (gconstpointer)&myRowClassInfo;
} /* end ObitTableWXRowGetClass */

/*------------------  Table  ------------------------*/
/**
 * Constructor.
 * Initializes class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableWX* newObitTableWX (gchar* name)
{
  ObitTableWX* out;

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableWXClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableWX));

  /* initialize values */
  if (name!=NULL) out->name = g_strdup(name);
  else out->name = g_strdup("Noname");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* initialize other stuff */
  ObitTableWXInit((gpointer)out);

 return out;
} /* end newObitTableWX */

/**
 * Returns ClassInfo pointer for the class.
 * \return pointer to the class structure.
 */
gconstpointer ObitTableWXGetClass (void)
{
  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableWXClassInit();

  return (gconstpointer)&myClassInfo;
} /* end ObitWXGetClass */

/**
 * Constructor from values.
 * Creates a new table structure and attaches to the TableList of file.
 * If the specified table already exists then it is returned.
 * Initializes class if needed on first call.
 * Forces an update of any disk resident structures (e.g. AIPS header).
 * \param name   An optional name for the object.
 * \param file   ObitData which which the table is to be associated.
 * \param ver    Table version number. 0=> add higher, value used returned
 * \param access access (OBIT_IO_ReadOnly, means do not create if it doesn't exist.
 * \param err Error stack, returns if not empty.
 * \return the new object, NULL on failure.
 */
ObitTableWX* newObitTableWXValue (gchar* name, ObitData *file, olong *ver,
 	                    ObitIOAccess access,
  		    
		     ObitErr *err)
{
  ObitTableWX* out=NULL;
  ObitTable *testTab=NULL;
  ObitTableDesc *desc=NULL;
  ObitTableList *list=NULL;
  ObitInfoList  *info=NULL;
  gboolean exist, optional;
  olong colNo, i, ncol, highVer;
  ObitIOCode retCode;
  gchar *tabType = "AIPS WX";
  gchar *routine = "newObitTableWXValue";

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitDataIsA(file));

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableWXClassInit();

  /* Check if the table already exists */
  /* Get TableList */
  list = ((ObitData*)file)->tableList;
  info = ((ObitData*)file)->info;

  /* Get highest version number if not specified */
  if (*ver==0) { 
    highVer = ObitTableListGetHigh (list, "AIPS WX");
    if (access==OBIT_IO_ReadOnly) *ver = highVer;
    else if (access==OBIT_IO_ReadWrite) *ver = highVer;
    else if (access==OBIT_IO_WriteOnly) *ver = highVer+1;
  }
  /* See if it already exists */
  exist = FALSE;
  if (*ver>0) { /* has to be specified */
    exist = ObitTableListGet(list, tabType, ver, &testTab, err);
    if (err->error) /* add traceback,return */
      Obit_traceback_val (err, routine,"", out);
  
    /* if readonly, it must exist to proceed */
    if ((access==OBIT_IO_ReadOnly) && !exist) return out;
    if (testTab!=NULL) { /* it exists, use it if is an ObitTableWX */
      if (ObitTableWXIsA(testTab)) { /* it is an ObitTableWX */
	out = ObitTableRef(testTab);
      } else { /* needs conversion */
 	out = ObitTableWXConvert(testTab);
	/* Update the TableList */
	ObitTableListPut(list, tabType, ver, (ObitTable*)out, err);
	if (err->error) /* add traceback,return */
	  Obit_traceback_val (err, routine,"", out);
      }
      testTab = ObitTableUnref(testTab); /* remove reference */
      return out; /* done */
    }
  } /* end of test for previously existing table */
  
  /* If access is ReadOnly make sure one exists */
  if (access==OBIT_IO_ReadOnly) { 
    highVer = ObitTableListGetHigh (list, "AIPS WX");
    if (highVer<=0) return out;
  }
  
  /* create basal table */
  testTab = newObitDataTable ((ObitData*)file, access, tabType,
			       ver, err);
  if (err->error) Obit_traceback_val (err, routine,"", out);
  
  /* likely need to convert */
  if (ObitTableWXIsA(testTab)) { 
    out = ObitTableRef(testTab);
  } else { /* needs conversion */
    out = ObitTableWXConvert(testTab);
  }
  testTab = ObitTableUnref(testTab); /* remove reference */

  /* Update the TableList */
  ObitTableListPut(list, tabType, ver, (ObitTable*)out, err);
  if (err->error) Obit_traceback_val (err, routine,"", out);

  /* if it previously existed merely return it */
  if (exist) return out; 

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* Set values */
  out->revision = 3;
  strncpy (out->obscode, "AA000", MAXKEYCHARTABLEWX );
  strncpy (out->RefDate, "YYYYMMDD", MAXKEYCHARTABLEWX );

  /* initialize descriptor */
  desc = out->myDesc;
  /* How many columns actually in table? */
  ncol = 11 ;
  desc->FieldName = g_malloc0((ncol+1)*sizeof(gchar*));
  desc->FieldUnit = g_malloc0((ncol+1)*sizeof(gchar*));
  desc->type      = g_malloc0((ncol+1)*sizeof(ObitInfoType));
  desc->dim       = g_malloc0((ncol+1)*sizeof(gint32*));
  for (i=0; i<ncol+1; i++) 
    desc->dim[i] = g_malloc0(MAXINFOELEMDIM*sizeof(gint32));

  desc->TableName = g_strdup(tabType);
  desc->sort[0] = 0;
  desc->sort[1] = 0;
  colNo = 0;

  /* Define Columns */
  desc->FieldName[colNo] = g_strdup("TIME    ");
  desc->FieldUnit[colNo] = g_strdup("DAYS");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("TIME INTERVAL");
  desc->FieldUnit[colNo] = g_strdup("DAYS");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("ANTENNA NO.");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_oint;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SUBARRAY");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_oint;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("TEMPERATURE");
  desc->FieldUnit[colNo] = g_strdup("CENTIGRA");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("PRESSURE");
  desc->FieldUnit[colNo] = g_strdup("MILLIBAR");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("DEWPOINT");
  desc->FieldUnit[colNo] = g_strdup("CENTIGRA");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("WIND_VELOCITY");
  desc->FieldUnit[colNo] = g_strdup("M/SEC");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("WIND_DIRECTION");
  desc->FieldUnit[colNo] = g_strdup("DEGREES");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("WVR_H2O");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("ONOS_ELECTRON");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  /* Add _status column at end */
  desc->FieldName[colNo] = g_strdup("_status");
  desc->FieldUnit[colNo] = g_strdup("        ");
  desc->type[colNo] = OBIT_short;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  
  /* number of fields */
  desc->nfield = colNo + 1;

  /* initialize descriptor keywords */
  ObitTableWXDumpKey (out, err);
 
  /* index table descriptor */
  ObitTableDescIndex (desc);

  /* Open and Close to fully instantiate */
  retCode = ObitTableWXOpen(out, OBIT_IO_WriteOnly, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out);    
  
  retCode = ObitTableWXClose(out, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 

  /* Force update of disk resident info */
  retCode = ObitIOUpdateTables (((ObitData*)file)->myIO, info, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 
  
 return out;
} /* end newObitTableWXValue */

/**
 * Convert an ObitTable to an ObitTableWX.
 * New object will have references to members of in.
 * \param in  The object to copy, will still exist afterwards 
 *            and should be Unrefed if not needed.
 * \return pointer to the new object.
 */
ObitTableWX* ObitTableWXConvert (ObitTable* in)
{
  ObitTableWX *out;

  /* error check */
  g_assert(ObitTableIsA(in));

  /* create basic object */
  out = newObitTableWX(in->name);

  /* Delete structures on new */
  out->info   = ObitInfoListUnref(out->info);
  out->thread = ObitThreadUnref(out->thread);
  out->myDesc = ObitTableDescUnref(out->myDesc);
  out->mySel  = ObitTableSelUnref(out->mySel);
  
  /* Reference members of in */
  
  out->info   = ObitInfoListRef(in->info);
  out->thread = ObitThreadRef(in->thread);
  out->myDesc = ObitTableDescRef(in->myDesc);
  out->mySel  = ObitTableSelRef(in->mySel);

  /* Remember who I am */
 out->tabType = g_strdup(in->tabType);
 out->tabVer  = in->tabVer;
  /* Secret reference to host */ 
 out->myHost  = in->myHost;

  return out;
} /* end ObitTableWXConvert */


/**
 * Make a deep copy of input object.
 * Copies are made of complex members including disk files; these 
 * will be copied applying whatever selection is associated with the input.
 * Objects should be closed on input and will be closed on output.
 * In order for the disk file structures to be copied, the output file
 * must be sufficiently defined that it can be written.
 * The copy will be attempted but no errors will be logged until
 * both input and output have been successfully opened.
 * ObitInfoList and ObitThread members are only copied if the output object
 * didn't previously exist.
 * Parent class members are included but any derived class info is ignored.
 * \param in  The object to copy
 * \param out An existing object pointer for output or NULL if none exists.
 * \param err Error stack, returns if not empty.
 * \return pointer to the new object.
 */
ObitTableWX* ObitTableWXCopy (ObitTableWX *in, ObitTableWX *out, ObitErr *err)
{
  gchar *routine = "ObitTableWXCopy";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableWXClassInit();

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitIsA(in, &myClassInfo));
  if (out) g_assert (ObitIsA(out, &myClassInfo));

  /* Use parent class to copy */
  out = (ObitTableWX*)ObitTableCopy ((ObitTable*)in, (ObitTable*)out, err);
  if (err->error) /* add traceback,return */
    Obit_traceback_val (err, routine,in->name, out);

  /* Copy this class  info */
  out->revision = in->revision;
  strncpy (out->obscode, in->obscode, MAXKEYCHARTABLEWX );
  strncpy (out->RefDate, in->RefDate, MAXKEYCHARTABLEWX );
  /* Update class specific info */
  ObitTableWXUpdate (out, err);
    
  return out;
} /* end ObitTableWXCopy */

/**
 * Initialize structures and open file.
 * The image descriptor is read if OBIT_IO_ReadOnly or 
 * OBIT_IO_ReadWrite and written to disk if opened OBIT_IO_WriteOnly.
 * After the file has been opened the member, buffer is initialized
 * for reading/storing the table unless member bufferSize is <0.
 * If the requested version ("Ver" in InfoList) is 0 then the highest
 * numbered table of the same type is opened on Read or Read/Write, 
 * or a new table is created on on Write.
 * The file etc. info should have been stored in the ObitInfoList:
 * \li "FileType" OBIT_long scalar = OBIT_IO_FITS or OBIT_IO_AIPS 
 *               for file type (see class documentation for details).
 * \li "nRowPIO" OBIT_long scalar = Maximum number of table rows
 *               per transfer, this is the target size for Reads (may be 
 *               fewer) and is used to create buffers.
 * \param in Pointer to object to be opened.
 * \param access access (OBIT_IO_ReadOnly,OBIT_IO_ReadWrite,
 *               or OBIT_IO_WriteOnly).
 *               If OBIT_IO_WriteOnly any existing data in the output file
 *               will be lost.
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode ObitTableWXOpen (ObitTableWX *in, ObitIOAccess access, 
			  ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gint32 dim[MAXINFOELEMDIM] = {1,1,1,1,1};
  olong nRowPIO;
  gchar *routine = "ObitTableWXOpen";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableWXClassInit();

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

   /* Do one row at a time */
   nRowPIO = 1;
   ObitInfoListPut(in->info, "nRowPIO", OBIT_long, dim, (gconstpointer)&nRowPIO, err);
   if (err->error) /* add traceback,return */
     Obit_traceback_val (err, routine, in->name, retCode);
   
   /* use parent class open */
   retCode = ObitTableOpen ((ObitTable*)in, access, err);
   if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
     Obit_traceback_val (err, routine, in->name, retCode);
   
   /* Update class specific info */
   ObitTableWXUpdate (in, err);
   
   return retCode;
} /* end ObitTableWXOpen */

/**
 * Read a table row and return an easily digested version.
 * Scalar values are copied but for array values, pointers 
 * into the data array are returned.
 * \param in       Table to read
 * \param iWXRow   Row number, -1 -> next
 * \param row      Table Row structure to receive data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableWXReadRow  (ObitTableWX *in, olong iWXRow, ObitTableWXRow *row,
		     ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;
  gchar *routine = "ObitTableWXReadRow";
  
  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "AIPS WX Table is inactive for  %s ", in->name);
    return retCode;
 }

  /* read row iWXRow */
  retCode = ObitTableRead ((ObitTable*)in, iWXRow, NULL,  err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  /* Typed pointers to row of data */  
  dRow  = (odouble*)in->buffer;
  iRow  = (oint*)in->buffer;
  siRow = (gshort*)in->buffer;
  fRow  = (ofloat*)in->buffer;
  cRow  = (gchar*)in->buffer;
  lRow  = (gboolean*)in->buffer;
  bRow  = (guint8*)in->buffer;
  
  /* Copy scalar fields, for arrays only set pointer*/
  row->Time = dRow[in->TimeOff];
  row->TimeI = fRow[in->TimeIOff];
  row->antNo = iRow[in->antNoOff];
  row->SubA = iRow[in->SubAOff];
  row->temperature = fRow[in->temperatureOff];
  row->pressure = fRow[in->pressureOff];
  row->dewpoint = fRow[in->dewpointOff];
  row->windVelocity = fRow[in->windVelocityOff];
  row->windDirection = fRow[in->windDirectionOff];
  row->wvrH2O = fRow[in->wvrH2OOff];
  row->onosElectron = fRow[in->onosElectronOff];
  row->status = iRow[in->myDesc->statusOff];

  return retCode;
} /*  end ObitTableWXReadRow */

/**
 * Attach an ObitTableRow to the buffer of an ObitTable.
 * This is only useful prior to filling a row structure in preparation .
 * for a WriteRow operation.  Array members of the Row structure are .
 * pointers to independently allocated memory, this routine allows using .
 * the table IO buffer instead of allocating yet more memory..
 * This routine need only be called once to initialize a Row structure for write..
 * \param in  Table with buffer to be written 
 * \param row Table Row structure to attach 
 * \param err ObitErr for reporting errors.
 */
void 
ObitTableWXSetRow  (ObitTableWX *in, ObitTableWXRow *row,
		     ObitErr *err)
{
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;
  
  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));
  g_assert (ObitIsA(row, &myRowClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "WX Table is inactive for  %s ", in->name);
    return;
 }

  /* Typed pointers to row of data */  
  dRow  = (odouble*)in->buffer;
  iRow  = (oint*)in->buffer;
  siRow = (gshort*)in->buffer;
  fRow  = (ofloat*)in->buffer;
  cRow  = (gchar*)in->buffer;
  lRow  = (gboolean*)in->buffer;
  bRow  = (guint8*)in->buffer;
  
  /* Set row pointers to buffer */

} /*  end ObitTableWXSetRow */

/**
 * Write a table row.
 * Before calling this routine, the row structure needs to be initialized
 * and filled with data. The array members of the row structure are  
 * pointers to independently allocated memory.  These pointers can be set to the 
 * correct table buffer locations using ObitTableWXSetRow  
 * \param in       Table to read
 * \param iWXRow   Row number, -1 -> next
 * \param row Table Row structure containing data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableWXWriteRow  (ObitTableWX *in, olong iWXRow, ObitTableWXRow *row,
		      ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gshort    *siRow;
  odouble   *dRow;
  oint      *iRow, i;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;
  gchar *routine = "ObitTableWXWriteRow";
  

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "AIPS WX Table is inactive for %s ", in->name);
    return retCode;
 }

  /* Typed pointers to row of data */  
  dRow  = (odouble*)in->buffer;
  siRow = (gshort*)in->buffer;
  iRow  = (oint*)in->buffer;
  fRow  = (ofloat*)in->buffer;
  cRow  = (gchar*)in->buffer;
  lRow  = (gboolean*)in->buffer;
  bRow  = (guint8*)in->buffer;
  
  /* Make full copy of all data */
  dRow[in->TimeOff] = row->Time;
  fRow[in->TimeIOff] = row->TimeI;
  iRow[in->antNoOff] = row->antNo;
  iRow[in->SubAOff] = row->SubA;
  fRow[in->temperatureOff] = row->temperature;
  fRow[in->pressureOff] = row->pressure;
  fRow[in->dewpointOff] = row->dewpoint;
  fRow[in->windVelocityOff] = row->windVelocity;
  fRow[in->windDirectionOff] = row->windDirection;
  fRow[in->wvrH2OOff] = row->wvrH2O;
  fRow[in->onosElectronOff] = row->onosElectron;

  /* copy status */
  iRow[in->myDesc->statusOff] = row->status;
   
  /* Write one row */
  in->myDesc->numRowBuff = 1;
 
  /* Write row iWXRow */
  retCode = ObitTableWrite ((ObitTable*)in, iWXRow, NULL,  err);
  if (err->error) 
    Obit_traceback_val (err, routine,in->name, retCode);

  return retCode;
} /*  end ObitTableWXWriteRow */

/**
 * Shutdown I/O.
 * \param in Pointer to object to be closed.
 * \param err ObitErr for reporting errors.
 * \return error code, OBIT_IO_OK=> OK
 */
ObitIOCode ObitTableWXClose (ObitTableWX *in, ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gchar *routine = "ObitTableWXClose";

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA((Obit*)in, &myClassInfo));
  /* Something going on? */
  if (in->myStatus == OBIT_Inactive) return OBIT_IO_OK;

  /* Update keywords on descriptor if not ReadOnly*/
  if (in->myDesc->access != OBIT_IO_ReadOnly) 
    ObitTableWXDumpKey (in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  /* Close */
  retCode = ObitTableClose ((ObitTable*)in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  return retCode;
} /* end ObitTableWXClose */

/*---------------Private functions--------------------------*/
/*----------------  TableWX Row  ----------------------*/
/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableWXRowInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableWXRow *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */
  /* Set array members to NULL */

} /* end ObitTableWXRowInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableWXRow* cast to an Obit*.
 */
void ObitTableWXRowClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableWXRow *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myRowClassInfo));

  /* delete this class members */
  /* Do not free data array pointers as they were not malloced */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableWXRowClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableWXRowClassInit (void)
{
  if (myRowClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myRowClassInfo.ClassName   = g_strdup(myRowClassName);
  myRowClassInfo.ParentClass = ObitParentGetRowClass();

  /* Set function pointers */
  ObitTableWXRowClassInfoDefFn ((gpointer)&myRowClassInfo);
 
  myRowClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableWXRowClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableWXRowClassInfoDefFn (gpointer inClass)
{
  ObitTableWXRowClassInfo *theClass = (ObitTableWXRowClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myRowClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myRowClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableWXRowClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableWXRowClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableWXRowGetClass;
  theClass->newObit         = NULL;
  theClass->newObitTableRow = (newObitTableRowFP)newObitTableWXRow;
  theClass->ObitCopy        = NULL;
  theClass->ObitClone       = NULL;
  theClass->ObitClear       = (ObitClearFP)ObitTableWXRowClear;
  theClass->ObitInit        = (ObitInitFP)ObitTableWXRowInit;

} /* end ObitTableWXRowClassDefFn */

/*------------------  TableWX  ------------------------*/

/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableWXInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableWX *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */

} /* end ObitTableWXInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableWX* cast to an Obit*.
 */
void ObitTableWXClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableWX *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myClassInfo));

  /* delete this class members */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableWXClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableWXClassInit (void)
{
  if (myClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myClassInfo.ClassName   = g_strdup(myClassName);
  myClassInfo.ParentClass = ObitParentGetClass();

  /* Set function pointers */
  ObitTableWXClassInfoDefFn ((gpointer)&myClassInfo);
 
  myClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableWXClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableWXClassInfoDefFn (gpointer inClass)
{
  ObitTableWXClassInfo *theClass = (ObitTableWXClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableWXClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableWXClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableWXGetClass;
  theClass->newObit       = (newObitFP)newObitTableWX;
  theClass->ObitCopy      = (ObitCopyFP)ObitTableWXCopy;
  theClass->ObitClone     = (ObitCloneFP)ObitTableClone;
  theClass->ObitClear     = (ObitClearFP)ObitTableWXClear;
  theClass->ObitInit      = (ObitInitFP)ObitTableWXInit;
  theClass->ObitTableConvert = (ObitTableConvertFP)ObitTableWXConvert;
  theClass->ObitTableOpen    = (ObitTableOpenFP)ObitTableWXOpen;
  theClass->ObitTableClose   = (ObitTableCloseFP)ObitTableWXClose;
  theClass->ObitTableRead    = (ObitTableReadFP)ObitTableRead;
  theClass->ObitTableReadSelect = 
    (ObitTableReadSelectFP)ObitTableReadSelect;
  theClass->ObitTableWrite = (ObitTableWriteFP)ObitTableWrite;
  theClass->ObitTableReadRow = 
    (ObitTableReadRowFP)ObitTableWXReadRow;
  theClass->ObitTableWriteRow = 
    (ObitTableWriteRowFP)ObitTableWXWriteRow;

} /* end ObitTableWXClassDefFn */

/**
 * Get table specific information from the infolist or descriptor
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableWXUpdate (ObitTableWX *in, ObitErr *err)
{
  olong i;
  ObitInfoType type;
  gint32 dim[MAXINFOELEMDIM];
  ObitTableDesc *desc;
   

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Get Keywords */
   /* revision */
  in->revision = 3; 
  ObitInfoListGetTest(in->myDesc->info, "TABREV", &type, dim, 
		       (gpointer)&in->revision);
   /* obscode */
  strncpy (in->obscode, "AA000", MAXKEYCHARTABLEWX); 
  ObitInfoListGetTest(in->myDesc->info, "OBSCODE", &type, dim, 
		       (gpointer)&in->obscode);
   /* RefDate */
  strncpy (in->RefDate, "YYYYMMDD", MAXKEYCHARTABLEWX); 
  ObitInfoListGetTest(in->myDesc->info, "RDATE", &type, dim, 
		       (gpointer)&in->RefDate);

  /* initialize column numbers/offsets */
  in->TimeOff = -1;
  in->TimeCol = -1;
  in->TimeIOff = -1;
  in->TimeICol = -1;
  in->antNoOff = -1;
  in->antNoCol = -1;
  in->SubAOff = -1;
  in->SubACol = -1;
  in->temperatureOff = -1;
  in->temperatureCol = -1;
  in->pressureOff = -1;
  in->pressureCol = -1;
  in->dewpointOff = -1;
  in->dewpointCol = -1;
  in->windVelocityOff = -1;
  in->windVelocityCol = -1;
  in->windDirectionOff = -1;
  in->windDirectionCol = -1;
  in->wvrH2OOff = -1;
  in->wvrH2OCol = -1;
  in->onosElectronOff = -1;
  in->onosElectronCol = -1;
  /* Find columns and set offsets */
  desc = in->myDesc;
  if (desc->FieldName) {
    for (i=0; i<desc->nfield; i++) {
      if (!strncmp (desc->FieldName[i], "TIME    ", 8)) {
	 in->TimeOff = desc->offset[i];
 	 in->TimeCol = i;
      }
      if (!strncmp (desc->FieldName[i], "TIME INTERVAL", 13)) {
	 in->TimeIOff = desc->offset[i];
 	 in->TimeICol = i;
      }
      if (!strncmp (desc->FieldName[i], "ANTENNA NO.", 11)) {
	 in->antNoOff = desc->offset[i];
 	 in->antNoCol = i;
      }
      if (!strncmp (desc->FieldName[i], "SUBARRAY", 8)) {
	 in->SubAOff = desc->offset[i];
 	 in->SubACol = i;
      }
      if (!strncmp (desc->FieldName[i], "TEMPERATURE", 11)) {
	 in->temperatureOff = desc->offset[i];
 	 in->temperatureCol = i;
      }
      if (!strncmp (desc->FieldName[i], "PRESSURE", 8)) {
	 in->pressureOff = desc->offset[i];
 	 in->pressureCol = i;
      }
      if (!strncmp (desc->FieldName[i], "DEWPOINT", 8)) {
	 in->dewpointOff = desc->offset[i];
 	 in->dewpointCol = i;
      }
      if (!strncmp (desc->FieldName[i], "WIND_VELOCITY", 13)) {
	 in->windVelocityOff = desc->offset[i];
 	 in->windVelocityCol = i;
      }
      if (!strncmp (desc->FieldName[i], "WIND_DIRECTION", 14)) {
	 in->windDirectionOff = desc->offset[i];
 	 in->windDirectionCol = i;
      }
      if (!strncmp (desc->FieldName[i], "WVR_H2O", 7)) {
	 in->wvrH2OOff = desc->offset[i];
 	 in->wvrH2OCol = i;
      }
      if (!strncmp (desc->FieldName[i], "ONOS_ELECTRON", 13)) {
	 in->onosElectronOff = desc->offset[i];
 	 in->onosElectronCol = i;
      }
     }
  }

  /* Check required columns */
  Obit_return_if_fail((in->TimeOff > -1), err,
       "ObitTableWXUpdate: Could not find column Time");
  Obit_return_if_fail((in->TimeIOff > -1), err,
       "ObitTableWXUpdate: Could not find column TimeI");
  Obit_return_if_fail((in->antNoOff > -1), err,
       "ObitTableWXUpdate: Could not find column antNo");
  Obit_return_if_fail((in->SubAOff > -1), err,
       "ObitTableWXUpdate: Could not find column SubA");
  Obit_return_if_fail((in->temperatureOff > -1), err,
       "ObitTableWXUpdate: Could not find column temperature");
  Obit_return_if_fail((in->pressureOff > -1), err,
       "ObitTableWXUpdate: Could not find column pressure");
  Obit_return_if_fail((in->dewpointOff > -1), err,
       "ObitTableWXUpdate: Could not find column dewpoint");
  Obit_return_if_fail((in->windVelocityOff > -1), err,
       "ObitTableWXUpdate: Could not find column windVelocity");
  Obit_return_if_fail((in->windDirectionOff > -1), err,
       "ObitTableWXUpdate: Could not find column windDirection");
  Obit_return_if_fail((in->wvrH2OOff > -1), err,
       "ObitTableWXUpdate: Could not find column wvrH2O");
} /* end ObitTableWXUpdate */

/**
 * Copy table specific (keyword) information  to infolist.
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableWXDumpKey (ObitTableWX *in, ObitErr *err)
{
  ObitInfoList *info=NULL;
  ObitInfoType type;
  gint32 dim[MAXINFOELEMDIM] = {1,1,1,1,1};

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Set Keywords */
  if (in->myIO!=NULL) info = ((ObitTableDesc*)(in->myIO->myDesc))->info;
  else info = in->myDesc->info;
  /* revision */
  type  = OBIT_oint;
  dim[0] = 1;
  ObitInfoListAlwaysPut(info, "TABREV", type, dim, 
		  (gpointer)&in->revision);
  /* obscode */
  type  = OBIT_string;
  dim[0] = MAXKEYCHARTABLEWX;
  ObitInfoListAlwaysPut(info, "OBSCODE", type, dim, 
		  (gpointer)&in->obscode);
  /* RefDate */
  type  = OBIT_string;
  dim[0] = MAXKEYCHARTABLEWX;
  ObitInfoListAlwaysPut(info, "RDATE", type, dim, 
		  (gpointer)&in->RefDate);
   
} /* end ObitTableWXDumpKey */
