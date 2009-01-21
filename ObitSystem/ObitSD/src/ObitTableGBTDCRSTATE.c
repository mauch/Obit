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
#include "ObitTableGBTDCRSTATE.h"
#include "ObitTableList.h"
#include "ObitData.h"

/*----------------Obit: Merx mollis mortibus nuperS ------------------*/
/**
 * \file ObitTableGBTDCRSTATE.c
 * ObitTableGBTDCRSTATE class function definitions.
 * This class is derived from the ObitTable class.
 */

/** name of the class defined in this file */
static gchar *myClassName = "ObitTableGBTDCRSTATE";

/**  Function to obtain parent Table ClassInfo - ObitTable */
static ObitGetClassFP ObitParentGetClass = ObitTableGetClass;

/** name of the Row class defined in this file */
static gchar *myRowClassName = "ObitTableGBTDCRSTATERow";

/**  Function to obtain parent TableRow ClassInfo */
static ObitGetClassFP ObitParentGetRowClass = ObitTableRowGetClass;

/*--------------- File Global Variables  ----------------*/
/*----------------  Table Row  ----------------------*/
/**
 * ClassInfo structure ObitTableClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableGBTDCRSTATERowClassInfo myRowClassInfo = {FALSE};

/*------------------  Table  ------------------------*/
/**
 * ClassInfo structure ObitTableGBTDCRSTATEClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableGBTDCRSTATEClassInfo myClassInfo = {FALSE};


/*---------------Private function prototypes----------------*/
/** Private: Initialize newly instantiated Row object. */
void  ObitTableGBTDCRSTATERowInit  (gpointer in);

/** Private: Deallocate Row members. */
void  ObitTableGBTDCRSTATERowClear (gpointer in);

/** Private: Initialize newly instantiated object. */
void  ObitTableGBTDCRSTATEInit  (gpointer in);

/** Private: Deallocate members. */
void  ObitTableGBTDCRSTATEClear (gpointer in);

/** Private: update table specific info */
static void ObitTableGBTDCRSTATEUpdate (ObitTableGBTDCRSTATE *in, ObitErr *err);

/** Private: copy table keywords to descriptor info list */
static void ObitTableGBTDCRSTATEDumpKey (ObitTableGBTDCRSTATE *in, ObitErr *err);

/** Private: Set Class function pointers */
static void ObitTableGBTDCRSTATEClassInfoDefFn (gpointer inClass);

/** Private: Set Row Class function pointers */
static void ObitTableGBTDCRSTATERowClassInfoDefFn (gpointer inClass);
/*----------------------Public functions---------------------------*/

/*------------------  Table Row ------------------------*/
/**
 * Constructor.
 * If table is open and for write, the row is attached to the buffer
 * Initializes Row class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableGBTDCRSTATERow* newObitTableGBTDCRSTATERow (ObitTableGBTDCRSTATE *table)
{
  ObitTableGBTDCRSTATERow* out;
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;

  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableGBTDCRSTATERowClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableGBTDCRSTATERow));

  /* initialize values */
  out->name = g_strdup("TableObitTableGBTDCRSTATE Row");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myRowClassInfo;

  /* initialize other stuff */
  ObitTableGBTDCRSTATERowInit((gpointer)out);
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
} /* end newObitTableSTATERow */

/**
 * Returns ClassInfo pointer for the Row class.
 * \return pointer to the Row class structure.
 */
gconstpointer ObitTableGBTDCRSTATERowGetClass (void)
{
  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableGBTDCRSTATERowClassInit();
  return (gconstpointer)&myRowClassInfo;
} /* end ObitTableGBTDCRSTATERowGetClass */

/*------------------  Table  ------------------------*/
/**
 * Constructor.
 * Initializes class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableGBTDCRSTATE* newObitTableGBTDCRSTATE (gchar* name)
{
  ObitTableGBTDCRSTATE* out;

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTDCRSTATEClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableGBTDCRSTATE));

  /* initialize values */
  if (name!=NULL) out->name = g_strdup(name);
  else out->name = g_strdup("Noname");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* initialize other stuff */
  ObitTableGBTDCRSTATEInit((gpointer)out);

 return out;
} /* end newObitTableGBTDCRSTATE */

/**
 * Returns ClassInfo pointer for the class.
 * \return pointer to the class structure.
 */
gconstpointer ObitTableGBTDCRSTATEGetClass (void)
{
  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTDCRSTATEClassInit();
  return (gconstpointer)&myClassInfo;
} /* end ObitTableGBTDCRSTATEGetClass */

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
ObitTableGBTDCRSTATE* newObitTableGBTDCRSTATEValue (gchar* name, ObitData *file, olong *ver,
 				  ObitIOAccess access,
  		    
		     ObitErr *err)
{
  ObitTableGBTDCRSTATE* out=NULL;
  ObitTable *testTab=NULL;
  ObitTableDesc *desc=NULL;
  ObitTableList *list=NULL;
  ObitInfoList  *info=NULL;
  gboolean exist, optional;
  olong colNo, i, ncol, highVer;
  ObitIOCode retCode;
  gchar *tabType = "STATE";
  gchar *routine = "newObitTableGBTDCRSTATEValue";

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitDataIsA(file));

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTDCRSTATEClassInit();

  /* Check if the table already exists */
  /* Get TableList */
  list = ((ObitData*)file)->tableList;
  info = ((ObitData*)file)->info;

  /* See if it already exists */
  exist = FALSE;
  if (*ver>0) { /* has to be specified */
    exist = ObitTableListGet(list, tabType, ver, &testTab, err);
    if (err->error) /* add traceback,return */
      Obit_traceback_val (err, routine,"", out);
  
    /* if readonly, it must exist to proceed */
    if ((access==OBIT_IO_ReadOnly) && !exist) return out;
    if (testTab!=NULL) { /* it exists, use it if is an ObitTableGBTDCRSTATE */
      if (ObitTableGBTDCRSTATEIsA(testTab)) { /* it is an ObitTableGBTDCRSTATE */
	out = ObitTableRef(testTab);
      } else { /* needs conversion */
 	out = ObitTableGBTDCRSTATEConvert(testTab);
	/* Update the TableList */
	ObitTableListPut(list, tabType, ver, (ObitTable*)out, err);
	if (err->error) Obit_traceback_val (err, routine,"", out);
      }
      testTab = ObitTableUnref(testTab); /* remove reference */
      return out; /* done */
    }
  } /* end of test for previously existing table */
  
  /* If access is ReadOnly make sure one exists */
  if (access==OBIT_IO_ReadOnly) { 
    highVer = ObitTableListGetHigh (list, "STATE");
    if (highVer<=0) return out;
  }
  
  /* create basal table */
  testTab = newObitDataTable ((ObitData*)file, access, tabType,
			       ver, err);
  if (err->error) Obit_traceback_val (err, routine,"", out);
  
  /* likely need to convert */
  if (ObitTableGBTDCRSTATEIsA(testTab)) { 
    out = ObitTableRef(testTab);
  } else { /* needs conversion */
    out = ObitTableGBTDCRSTATEConvert(testTab);
  }
  testTab = ObitTableUnref(testTab); /* remove reference */

  /* Update the TableList */
  ObitTableListPut(list, tabType, ver, (ObitTable*)out, err);
  if (err->error) /* add traceback,return */
    Obit_traceback_val (err, routine,"", out);

  /* if it previously existed merely return it */
  if (exist) return out; 

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* Set values */
  strncpy (out->master, "DCR", MAXKEYCHARTABLESTATE );

  /* initialize descriptor */
  desc = out->myDesc;
  /* How many columns actually in table? */
  ncol = 9 ;
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
  desc->FieldName[colNo] = g_strdup("BLANKTIM");
  desc->FieldUnit[colNo] = g_strdup("SECOND");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("PHASETIM");
  desc->FieldUnit[colNo] = g_strdup("SECOND");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SIGREF");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_byte;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("CAL");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_byte;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SWSIG1 ");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_byte;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SWSIG2 ");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_byte;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SWSIG3 ");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_byte;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SWSIG4");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_byte;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SWSIG5");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_byte;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  /* Add _status column at end */
  desc->FieldName[colNo] = g_strdup("_status");
  desc->FieldUnit[colNo] = g_strdup("        ");
  desc->type[colNo] = OBIT_long;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  
  /* number of fields */
  desc->nfield = colNo + 1;

  /* initialize descriptor keywords */
  ObitTableGBTDCRSTATEDumpKey (out, err);
 
  /* index table descriptor */
  ObitTableDescIndex (desc);

  /* Open and Close to fully instantiate */
  retCode = ObitTableGBTDCRSTATEOpen(out, OBIT_IO_WriteOnly, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out);    
  
  retCode = ObitTableGBTDCRSTATEClose(out, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 

  /* Force update of disk resident info */
  retCode = ObitIOUpdateTables (((ObitData*)file)->myIO, info, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 
  
 return out;
} /* end newObitTableGBTDCRSTATEValue */

/**
 * Convert an ObitTable to an ObitTableGBTDCRSTATE.
 * New object will have references to members of in.
 * \param in  The object to copy, will still exist afterwards 
 *            and should be Unrefed if not needed.
 * \return pointer to the new object.
 */
ObitTableGBTDCRSTATE* ObitTableGBTDCRSTATEConvert (ObitTable* in)
{
  ObitTableGBTDCRSTATE *out;

  /* error check */
  g_assert(ObitTableIsA(in));

  /* create basic object */
  out = newObitTableGBTDCRSTATE(in->name);

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
} /* end ObitTableGBTDCRSTATEConvert */


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
ObitTableGBTDCRSTATE* ObitTableGBTDCRSTATECopy (ObitTableGBTDCRSTATE *in, ObitTableGBTDCRSTATE *out, ObitErr *err)
{
  gchar *routine = "ObitTableGBTDCRSTATECopy";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTDCRSTATEClassInit();

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitIsA(in, &myClassInfo));
  if (out) g_assert (ObitIsA(out, &myClassInfo));

  /* Use parent class to copy */
  out = (ObitTableGBTDCRSTATE*)ObitTableCopy ((ObitTable*)in, (ObitTable*)out, err);
  if (err->error) /* add traceback,return */
    Obit_traceback_val (err, routine,in->name, out);

  /* Copy this class  info */
  strncpy (out->master, in->master, MAXKEYCHARTABLESTATE );
  out->scan = in->scan;
  out->utdate = in->utdate;
  out->utcstart = in->utcstart;
  /* Update class specific info */
  ObitTableGBTDCRSTATEUpdate (out, err);
    
  return out;
} /* end ObitTableGBTDCRSTATECopy */

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
 * \li "FileType" OBIT_long scalar = OBIT_IO_FITS 
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
ObitIOCode ObitTableGBTDCRSTATEOpen (ObitTableGBTDCRSTATE *in, ObitIOAccess access, 
			  ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gint32 dim[MAXINFOELEMDIM] = {1,1,1,1,1};
  olong nRowPIO;
  gchar *routine = "ObitTableGBTDCRSTATEOpen";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTDCRSTATEClassInit();

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
   ObitTableGBTDCRSTATEUpdate (in, err);
   
   return retCode;
} /* end ObitTableGBTDCRSTATEOpen */

/**
 * Read a table row and return an easily digested version.
 * Scalar values are copied but for array values, pointers 
 * into the data array are returned.
 * \param in       Table to read
 * \param iSTATERow   Row number, -1 -> next
 * \param row      Table Row structure to receive data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableGBTDCRSTATEReadRow  (ObitTableGBTDCRSTATE *in, olong iSTATERow, ObitTableGBTDCRSTATERow *row,
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
  gchar *routine = "ObitTableGBTDCRSTATEReadRow";
  
  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "ObitTableGBTDCRSTATE Table is inactive for  %s ", in->name);
    return retCode;
 }

  /* read row iSTATERow */
  retCode = ObitTableRead ((ObitTable*)in, iSTATERow, NULL,  err);
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
  row->blanktim = dRow[in->blanktimOff];
  row->phasetim = dRow[in->phasetimOff];
  row->sigref = bRow[in->sigrefOff];
  row->cal = bRow[in->calOff];
  row->swsig1 = bRow[in->swsig1Off];
  row->swsig2 = bRow[in->swsig2Off];
  row->swsig3 = bRow[in->swsig3Off];
  row->swsig4 = bRow[in->swsig4Off];
  row->swsig5 = bRow[in->swsig5Off];
  row->status = iRow[in->myDesc->statusOff];

  return retCode;
} /*  end ObitTableGBTDCRSTATEReadRow */

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
ObitTableGBTDCRSTATESetRow  (ObitTableGBTDCRSTATE *in, ObitTableGBTDCRSTATERow *row,
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
		   "STATE Table is inactive for  %s ", in->name);
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

} /*  end ObitTableGBTDCRSTATESetRow */

/**
 * Write a table row.
 * Before calling this routine, the row structure needs to be initialized
 * and filled with data. The array members of the row structure are  
 * pointers to independently allocated memory.  These pointers can be set to the 
 * correct table buffer locations using ObitTableGBTDCRSTATESetRow  
 * \param in       Table to read
 * \param iSTATERow   Row number, -1 -> next
 * \param row      Table Row structure containing data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableGBTDCRSTATEWriteRow  (ObitTableGBTDCRSTATE *in, olong iSTATERow, ObitTableGBTDCRSTATERow *row,
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
  gchar *routine = "ObitTableGBTDCRSTATEWriteRow";
  

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "ObitTableGBTDCRSTATE Table is inactive for %s ", in->name);
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
  dRow[in->blanktimOff] = row->blanktim;
  dRow[in->phasetimOff] = row->phasetim;
  bRow[in->sigrefOff] = row->sigref;
  bRow[in->calOff] = row->cal;
  bRow[in->swsig1Off] = row->swsig1;
  bRow[in->swsig2Off] = row->swsig2;
  bRow[in->swsig3Off] = row->swsig3;
  bRow[in->swsig4Off] = row->swsig4;
  bRow[in->swsig5Off] = row->swsig5;

  /* copy status */
  iRow[in->myDesc->statusOff] = row->status;
   
  /* Write one row */
  in->myDesc->numRowBuff = 1;
 
  /* Write row iSTATERow */
  retCode = ObitTableWrite ((ObitTable*)in, iSTATERow, NULL,  err);
  if (err->error) 
    Obit_traceback_val (err, routine,in->name, retCode);

  return retCode;
} /*  end ObitTableGBTDCRSTATEWriteRow */

/**
 * Shutdown I/O.
 * \param in Pointer to object to be closed.
 * \param err ObitErr for reporting errors.
 * \return error code, OBIT_IO_OK=> OK
 */
ObitIOCode ObitTableGBTDCRSTATEClose (ObitTableGBTDCRSTATE *in, ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gchar *routine = "ObitTableGBTDCRSTATEClose";

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA((Obit*)in, &myClassInfo));
  /* Something going on? */
  if (in->myStatus == OBIT_Inactive) return OBIT_IO_OK;

  /* Update keywords on descriptor if not ReadOnly*/
  if (in->myDesc->access != OBIT_IO_ReadOnly) 
    ObitTableGBTDCRSTATEDumpKey (in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  /* Close */
  retCode = ObitTableClose ((ObitTable*)in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  return retCode;
} /* end ObitTableGBTDCRSTATEClose */

/*---------------Private functions--------------------------*/
/*----------------  ObitTableGBTDCRSTATE Row  ----------------------*/
/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableGBTDCRSTATERowInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTDCRSTATERow *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */
  /* Set array members to NULL */

} /* end ObitTableGBTDCRSTATERowInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableGBTDCRSTATERow* cast to an Obit*.
 */
void ObitTableGBTDCRSTATERowClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTDCRSTATERow *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myRowClassInfo));

  /* delete this class members */
  /* Do not free data array pointers as they were not malloced */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableGBTDCRSTATERowClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableGBTDCRSTATERowClassInit (void)
{
  if (myRowClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myRowClassInfo.ClassName   = g_strdup(myRowClassName);
  myRowClassInfo.ParentClass = ObitParentGetRowClass();

  /* Set function pointers */
  ObitTableGBTDCRSTATERowClassInfoDefFn ((gpointer)&myRowClassInfo);
 
  myRowClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableGBTDCRSTATERowClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableGBTDCRSTATERowClassInfoDefFn (gpointer inClass)
{
  ObitTableGBTDCRSTATERowClassInfo *theClass = (ObitTableGBTDCRSTATERowClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myRowClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myRowClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableGBTDCRSTATERowClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableGBTDCRSTATERowClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableGBTDCRSTATERowGetClass;
  theClass->newObit         = NULL;
  theClass->newObitTableRow = (newObitTableRowFP)newObitTableGBTDCRSTATERow;
  theClass->ObitCopy        = NULL;
  theClass->ObitClone       = NULL;
  theClass->ObitClear       = (ObitClearFP)ObitTableGBTDCRSTATERowClear;
  theClass->ObitInit        = (ObitInitFP)ObitTableGBTDCRSTATERowInit;

} /* end ObitTableGBTDCRSTATERowClassDefFn */

/*------------------  ObitTableGBTDCRSTATE  ------------------------*/

/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableGBTDCRSTATEInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTDCRSTATE *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */

} /* end ObitTableGBTDCRSTATEInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableGBTDCRSTATE* cast to an Obit*.
 */
void ObitTableGBTDCRSTATEClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTDCRSTATE *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myClassInfo));

  /* delete this class members */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableGBTDCRSTATEClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableGBTDCRSTATEClassInit (void)
{
  if (myClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myClassInfo.ClassName   = g_strdup(myClassName);
  myClassInfo.ParentClass = ObitParentGetClass();

  /* Set function pointers */
  ObitTableGBTDCRSTATEClassInfoDefFn ((gpointer)&myClassInfo);
 
  myClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableGBTDCRSTATEClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableGBTDCRSTATEClassInfoDefFn (gpointer inClass)
{
  ObitTableGBTDCRSTATEClassInfo *theClass = (ObitTableGBTDCRSTATEClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableGBTDCRSTATEClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableGBTDCRSTATEClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableGBTDCRSTATEGetClass;
  theClass->newObit       = (newObitFP)newObitTableGBTDCRSTATE;
  theClass->ObitCopy      = (ObitCopyFP)ObitTableGBTDCRSTATECopy;
  theClass->ObitClone     = (ObitCloneFP)ObitTableClone;
  theClass->ObitClear     = (ObitClearFP)ObitTableGBTDCRSTATEClear;
  theClass->ObitInit      = (ObitInitFP)ObitTableGBTDCRSTATEInit;
  theClass->ObitTableConvert = (ObitTableConvertFP)ObitTableGBTDCRSTATEConvert;
  theClass->ObitTableOpen    = (ObitTableOpenFP)ObitTableGBTDCRSTATEOpen;
  theClass->ObitTableClose   = (ObitTableCloseFP)ObitTableGBTDCRSTATEClose;
  theClass->ObitTableRead    = (ObitTableReadFP)ObitTableRead;
  theClass->ObitTableReadSelect = 
    (ObitTableReadSelectFP)ObitTableReadSelect;
  theClass->ObitTableWrite = (ObitTableWriteFP)ObitTableWrite;
  theClass->ObitTableReadRow = 
    (ObitTableReadRowFP)ObitTableGBTDCRSTATEReadRow;
  theClass->ObitTableWriteRow = 
    (ObitTableWriteRowFP)ObitTableGBTDCRSTATEWriteRow;

} /* end ObitTableGBTDCRSTATEClassDefFn */

/**
 * Get table specific information from the infolist or descriptor
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableGBTDCRSTATEUpdate (ObitTableGBTDCRSTATE *in, ObitErr *err)
{
  olong i;
  ObitInfoType type;
  gint32 dim[MAXINFOELEMDIM];
  ObitTableDesc *desc;
   union ObitInfoListEquiv InfoReal; 

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Get Keywords */
   /* master */
  strncpy (in->master, "DCR", MAXKEYCHARTABLESTATE); 
  ObitInfoListGetTest(in->myDesc->info, "MASTER", &type, (gint32*)&dim, 
		       (gpointer)&in->master);
   /* scan */
  if (!ObitInfoListGet(in->myDesc->info, "SCAN", &type, (gint32*)&dim, 
		       (gpointer)&in->scan, err)) return;
   /* utdate */
  if (!ObitInfoListGet(in->myDesc->info, "UTDATE", &type, (gint32*)&dim, 
		       (gpointer)&in->utdate, err)) return;
   /* utcstart */
  if (!ObitInfoListGet(in->myDesc->info, "UTCSTART", &type, (gint32*)&dim, 
		       (gpointer)&InfoReal, err)) return;
  if (type==OBIT_double) in->utcstart = InfoReal.dbl;
  if (type==OBIT_float)  in->utcstart = InfoReal.flt;

  /* initialize column numbers/offsets */
  in->blanktimOff = -1;
  in->blanktimCol = -1;
  in->phasetimOff = -1;
  in->phasetimCol = -1;
  in->sigrefOff = -1;
  in->sigrefCol = -1;
  in->calOff = -1;
  in->calCol = -1;
  in->swsig1Off = -1;
  in->swsig1Col = -1;
  in->swsig2Off = -1;
  in->swsig2Col = -1;
  in->swsig3Off = -1;
  in->swsig3Col = -1;
  in->swsig4Off = -1;
  in->swsig4Col = -1;
  in->swsig5Off = -1;
  in->swsig5Col = -1;
  /* Find columns and set offsets */
  desc = in->myDesc;
  if (desc->FieldName) {
    for (i=0; i<desc->nfield; i++) {
      if (!strncmp (desc->FieldName[i], "BLANKTIM", 8)) {
	 in->blanktimOff = desc->offset[i];
 	 in->blanktimCol = i;
      }
      if (!strncmp (desc->FieldName[i], "PHASETIM", 8)) {
	 in->phasetimOff = desc->offset[i];
 	 in->phasetimCol = i;
      }
      if (!strncmp (desc->FieldName[i], "SIGREF", 6)) {
	 in->sigrefOff = desc->offset[i];
 	 in->sigrefCol = i;
      }
      if (!strncmp (desc->FieldName[i], "CAL", 3)) {
	 in->calOff = desc->offset[i];
 	 in->calCol = i;
      }
      if (!strncmp (desc->FieldName[i], "SWSIG1 ", 7)) {
	 in->swsig1Off = desc->offset[i];
 	 in->swsig1Col = i;
      }
      if (!strncmp (desc->FieldName[i], "SWSIG2 ", 7)) {
	 in->swsig2Off = desc->offset[i];
 	 in->swsig2Col = i;
      }
      if (!strncmp (desc->FieldName[i], "SWSIG3 ", 7)) {
	 in->swsig3Off = desc->offset[i];
 	 in->swsig3Col = i;
      }
      if (!strncmp (desc->FieldName[i], "SWSIG4", 6)) {
	 in->swsig4Off = desc->offset[i];
 	 in->swsig4Col = i;
      }
      if (!strncmp (desc->FieldName[i], "SWSIG5", 6)) {
	 in->swsig5Off = desc->offset[i];
 	 in->swsig5Col = i;
      }
     }
  }

  Obit_return_if_fail((in->blanktimOff > -1), err,
       "ObitTableSTATEUpdate: Could not find column blanktim");
  Obit_return_if_fail((in->phasetimOff > -1), err,
       "ObitTableSTATEUpdate: Could not find column phasetim");
  Obit_return_if_fail((in->sigrefOff > -1), err,
       "ObitTableSTATEUpdate: Could not find column sigref");
  Obit_return_if_fail((in->calOff > -1), err,
       "ObitTableSTATEUpdate: Could not find column cal");
  Obit_return_if_fail((in->swsig1Off > -1), err,
       "ObitTableSTATEUpdate: Could not find column swsig1");
  Obit_return_if_fail((in->swsig2Off > -1), err,
       "ObitTableSTATEUpdate: Could not find column swsig2");
  Obit_return_if_fail((in->swsig3Off > -1), err,
       "ObitTableSTATEUpdate: Could not find column swsig3");
  Obit_return_if_fail((in->swsig4Off > -1), err,
       "ObitTableSTATEUpdate: Could not find column swsig4");
} /* end ObitTableGBTDCRSTATEUpdate */

/**
 * Copy table specific (keyword) information  to infolist.
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableGBTDCRSTATEDumpKey (ObitTableGBTDCRSTATE *in, ObitErr *err)
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
  /* master */
  type  = OBIT_string;
  dim[0] = MAXKEYCHARTABLESTATE;
  ObitInfoListAlwaysPut(info, "MASTER", type, (gint32*)&dim, 
		  (gpointer)&in->master);
  /* scan */
  type  = OBIT_oint;
  dim[0] = 1;
  ObitInfoListAlwaysPut(info, "SCAN", type, (gint32*)&dim, 
		  (gpointer)&in->scan);
  /* utdate */
  type  = OBIT_oint;
  dim[0] = 1;
  ObitInfoListAlwaysPut(info, "UTDATE", type, (gint32*)&dim, 
		  (gpointer)&in->utdate);
  /* utcstart */
  type  = OBIT_double;
  dim[0] = 1;
  ObitInfoListAlwaysPut(info, "UTCSTART", type, (gint32*)&dim, 
		  (gpointer)&in->utcstart);
   
} /* end ObitTableGBTDCRSTATEDumpKey */
