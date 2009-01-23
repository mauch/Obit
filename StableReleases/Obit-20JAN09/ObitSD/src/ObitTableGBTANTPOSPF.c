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
#include "ObitTableGBTANTPOSPF.h"
#include "ObitTableList.h"
#include "ObitData.h"

/*----------------Obit: Merx mollis mortibus nuperS ------------------*/
/**
 * \file ObitTableGBTANTPOSPF.c
 * ObitTableGBTANTPOSPF class function definitions.
 * This class is derived from the ObitTable class.
 */

/** name of the class defined in this file */
static gchar *myClassName = "ObitTableGBTANTPOSPF";

/**  Function to obtain parent Table ClassInfo - ObitTable */
static ObitGetClassFP ObitParentGetClass = ObitTableGetClass;

/** name of the Row class defined in this file */
static gchar *myRowClassName = "ObitTableGBTANTPOSPFRow";

/**  Function to obtain parent TableRow ClassInfo */
static ObitGetClassFP ObitParentGetRowClass = ObitTableRowGetClass;

/*--------------- File Global Variables  ----------------*/
/*----------------  Table Row  ----------------------*/
/**
 * ClassInfo structure ObitTableClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableGBTANTPOSPFRowClassInfo myRowClassInfo = {FALSE};

/*------------------  Table  ------------------------*/
/**
 * ClassInfo structure ObitTableGBTANTPOSPFClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableGBTANTPOSPFClassInfo myClassInfo = {FALSE};


/*---------------Private function prototypes----------------*/
/** Private: Initialize newly instantiated Row object. */
void  ObitTableGBTANTPOSPFRowInit  (gpointer in);

/** Private: Deallocate Row members. */
void  ObitTableGBTANTPOSPFRowClear (gpointer in);

/** Private: Initialize newly instantiated object. */
void  ObitTableGBTANTPOSPFInit  (gpointer in);

/** Private: Deallocate members. */
void  ObitTableGBTANTPOSPFClear (gpointer in);

/** Private: update table specific info */
static void ObitTableGBTANTPOSPFUpdate (ObitTableGBTANTPOSPF *in, ObitErr *err);

/** Private: copy table keywords to descriptor info list */
static void ObitTableGBTANTPOSPFDumpKey (ObitTableGBTANTPOSPF *in, ObitErr *err);

/** Private: Set Class function pointers */
static void ObitTableGBTANTPOSPFClassInfoDefFn (gpointer inClass);

/** Private: Set Row Class function pointers */
static void ObitTableGBTANTPOSPFRowClassInfoDefFn (gpointer inClass);
/*----------------------Public functions---------------------------*/

/*------------------  Table Row ------------------------*/
/**
 * Constructor.
 * If table is open and for write, the row is attached to the buffer
 * Initializes Row class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableGBTANTPOSPFRow* newObitTableGBTANTPOSPFRow (ObitTableGBTANTPOSPF *table)
{
  ObitTableGBTANTPOSPFRow* out;
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;

  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableGBTANTPOSPFRowClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableGBTANTPOSPFRow));

  /* initialize values */
  out->name = g_strdup("TableObitTableGBTANTPOSPF Row");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myRowClassInfo;

  /* initialize other stuff */
  ObitTableGBTANTPOSPFRowInit((gpointer)out);
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
} /* end newObitTableANTPOSPFRow */

/**
 * Returns ClassInfo pointer for the Row class.
 * \return pointer to the Row class structure.
 */
gconstpointer ObitTableGBTANTPOSPFRowGetClass (void)
{
  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableGBTANTPOSPFRowClassInit();
  return (gconstpointer)&myRowClassInfo;
} /* end ObitTableGBTANTPOSPFRowGetClass */

/*------------------  Table  ------------------------*/
/**
 * Constructor.
 * Initializes class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableGBTANTPOSPF* newObitTableGBTANTPOSPF (gchar* name)
{
  ObitTableGBTANTPOSPF* out;

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTANTPOSPFClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableGBTANTPOSPF));

  /* initialize values */
  if (name!=NULL) out->name = g_strdup(name);
  else out->name = g_strdup("Noname");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* initialize other stuff */
  ObitTableGBTANTPOSPFInit((gpointer)out);

 return out;
} /* end newObitTableGBTANTPOSPF */

/**
 * Returns ClassInfo pointer for the class.
 * \return pointer to the class structure.
 */
gconstpointer ObitTableGBTANTPOSPFGetClass (void)
{
  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTANTPOSPFClassInit();
  return (gconstpointer)&myClassInfo;
} /* end ObitTableGBTANTPOSPFGetClass */

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
ObitTableGBTANTPOSPF* newObitTableGBTANTPOSPFValue (gchar* name, ObitData *file, olong *ver,
 				  ObitIOAccess access,
  		    
		     ObitErr *err)
{
  ObitTableGBTANTPOSPF* out=NULL;
  ObitTable *testTab=NULL;
  ObitTableDesc *desc=NULL;
  ObitTableList *list=NULL;
  ObitInfoList  *info=NULL;
  gboolean exist, optional;
  olong colNo, i, ncol, highVer;
  ObitIOCode retCode;
  gchar *tabType = "ANTPOSPF";
  gchar *routine = "newObitTableGBTANTPOSPFValue";

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitDataIsA(file));

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTANTPOSPFClassInit();

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
    if (testTab!=NULL) { /* it exists, use it if is an ObitTableGBTANTPOSPF */
      if (ObitTableGBTANTPOSPFIsA(testTab)) { /* it is an ObitTableGBTANTPOSPF */
	out = ObitTableRef(testTab);
      } else { /* needs conversion */
 	out = ObitTableGBTANTPOSPFConvert(testTab);
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
    highVer = ObitTableListGetHigh (list, "ANTPOSPF");
    if (highVer<=0) return out;
  }
  
  /* create basal table */
  testTab = newObitDataTable ((ObitData*)file, access, tabType,
			       ver, err);
  if (err->error) Obit_traceback_val (err, routine,"", out);
  
  /* likely need to convert */
  if (ObitTableGBTANTPOSPFIsA(testTab)) { 
    out = ObitTableRef(testTab);
  } else { /* needs conversion */
    out = ObitTableGBTANTPOSPFConvert(testTab);
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
  desc->FieldName[colNo] = g_strdup("DMJD    ");
  desc->FieldUnit[colNo] = g_strdup("DAY");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("RAJ2000 ");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("DECJ2000");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("MNT_AZ ");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("MNT_EL  ");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("REFRACT ");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("MAJOR ");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("MINOR ");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("PF_FOCUS");
  desc->FieldUnit[colNo] = g_strdup("MM");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("PF_ROTATION");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("PF_X  ");
  desc->FieldUnit[colNo] = g_strdup("MM");
  desc->type[colNo] = OBIT_double;
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
  ObitTableGBTANTPOSPFDumpKey (out, err);
 
  /* index table descriptor */
  ObitTableDescIndex (desc);

  /* Open and Close to fully instantiate */
  retCode = ObitTableGBTANTPOSPFOpen(out, OBIT_IO_WriteOnly, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out);    
  
  retCode = ObitTableGBTANTPOSPFClose(out, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 

  /* Force update of disk resident info */
  retCode = ObitIOUpdateTables (((ObitData*)file)->myIO, info, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 
  
 return out;
} /* end newObitTableGBTANTPOSPFValue */

/**
 * Convert an ObitTable to an ObitTableGBTANTPOSPF.
 * New object will have references to members of in.
 * \param in  The object to copy, will still exist afterwards 
 *            and should be Unrefed if not needed.
 * \return pointer to the new object.
 */
ObitTableGBTANTPOSPF* ObitTableGBTANTPOSPFConvert (ObitTable* in)
{
  ObitTableGBTANTPOSPF *out;

  /* error check */
  g_assert(ObitTableIsA(in));

  /* create basic object */
  out = newObitTableGBTANTPOSPF(in->name);

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
} /* end ObitTableGBTANTPOSPFConvert */


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
ObitTableGBTANTPOSPF* ObitTableGBTANTPOSPFCopy (ObitTableGBTANTPOSPF *in, ObitTableGBTANTPOSPF *out, ObitErr *err)
{
  gchar *routine = "ObitTableGBTANTPOSPFCopy";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTANTPOSPFClassInit();

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitIsA(in, &myClassInfo));
  if (out) g_assert (ObitIsA(out, &myClassInfo));

  /* Use parent class to copy */
  out = (ObitTableGBTANTPOSPF*)ObitTableCopy ((ObitTable*)in, (ObitTable*)out, err);
  if (err->error) /* add traceback,return */
    Obit_traceback_val (err, routine,in->name, out);

  /* Copy this class  info */
  /* Update class specific info */
  ObitTableGBTANTPOSPFUpdate (out, err);
    
  return out;
} /* end ObitTableGBTANTPOSPFCopy */

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
ObitIOCode ObitTableGBTANTPOSPFOpen (ObitTableGBTANTPOSPF *in, ObitIOAccess access, 
			  ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gint32 dim[MAXINFOELEMDIM] = {1,1,1,1,1};
  olong nRowPIO;
  gchar *routine = "ObitTableGBTANTPOSPFOpen";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTANTPOSPFClassInit();

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
   ObitTableGBTANTPOSPFUpdate (in, err);
   
   return retCode;
} /* end ObitTableGBTANTPOSPFOpen */

/**
 * Read a table row and return an easily digested version.
 * Scalar values are copied but for array values, pointers 
 * into the data array are returned.
 * \param in       Table to read
 * \param iANTPOSPFRow   Row number, -1 -> next
 * \param row      Table Row structure to receive data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableGBTANTPOSPFReadRow  (ObitTableGBTANTPOSPF *in, olong iANTPOSPFRow, ObitTableGBTANTPOSPFRow *row,
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
  gchar *routine = "ObitTableGBTANTPOSPFReadRow";
  
  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "ObitTableGBTANTPOSPF Table is inactive for  %s ", in->name);
    return retCode;
 }

  /* read row iANTPOSPFRow */
  retCode = ObitTableRead ((ObitTable*)in, iANTPOSPFRow, NULL,  err);
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
  row->dmjd = dRow[in->dmjdOff];
  row->raj2000 = dRow[in->raj2000Off];
  row->decj2000 = dRow[in->decj2000Off];
  row->mntAaz = dRow[in->mntAazOff];
  row->mntEl = dRow[in->mntElOff];
  row->refract = dRow[in->refractOff];
  row->major = dRow[in->majorOff];
  row->minor = dRow[in->minorOff];
  row->pfFocus = dRow[in->pfFocusOff];
  row->pfRotation = dRow[in->pfRotationOff];
  row->pfX = dRow[in->pfXOff];
  row->status = iRow[in->myDesc->statusOff];

  return retCode;
} /*  end ObitTableGBTANTPOSPFReadRow */

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
ObitTableGBTANTPOSPFSetRow  (ObitTableGBTANTPOSPF *in, ObitTableGBTANTPOSPFRow *row,
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
		   "ANTPOSPF Table is inactive for  %s ", in->name);
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

} /*  end ObitTableGBTANTPOSPFSetRow */

/**
 * Write a table row.
 * Before calling this routine, the row structure needs to be initialized
 * and filled with data. The array members of the row structure are  
 * pointers to independently allocated memory.  These pointers can be set to the 
 * correct table buffer locations using ObitTableGBTANTPOSPFSetRow  
 * \param in       Table to read
 * \param iANTPOSPFRow   Row number, -1 -> next
 * \param row      Table Row structure containing data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableGBTANTPOSPFWriteRow  (ObitTableGBTANTPOSPF *in, olong iANTPOSPFRow, ObitTableGBTANTPOSPFRow *row,
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
  gchar *routine = "ObitTableGBTANTPOSPFWriteRow";
  

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "ObitTableGBTANTPOSPF Table is inactive for %s ", in->name);
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
  dRow[in->dmjdOff] = row->dmjd;
  dRow[in->raj2000Off] = row->raj2000;
  dRow[in->decj2000Off] = row->decj2000;
  dRow[in->mntAazOff] = row->mntAaz;
  dRow[in->mntElOff] = row->mntEl;
  dRow[in->refractOff] = row->refract;
  dRow[in->majorOff] = row->major;
  dRow[in->minorOff] = row->minor;
  dRow[in->pfFocusOff] = row->pfFocus;
  dRow[in->pfRotationOff] = row->pfRotation;
  dRow[in->pfXOff] = row->pfX;

  /* copy status */
  iRow[in->myDesc->statusOff] = row->status;
   
  /* Write one row */
  in->myDesc->numRowBuff = 1;
 
  /* Write row iANTPOSPFRow */
  retCode = ObitTableWrite ((ObitTable*)in, iANTPOSPFRow, NULL,  err);
  if (err->error) 
    Obit_traceback_val (err, routine,in->name, retCode);

  return retCode;
} /*  end ObitTableGBTANTPOSPFWriteRow */

/**
 * Shutdown I/O.
 * \param in Pointer to object to be closed.
 * \param err ObitErr for reporting errors.
 * \return error code, OBIT_IO_OK=> OK
 */
ObitIOCode ObitTableGBTANTPOSPFClose (ObitTableGBTANTPOSPF *in, ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gchar *routine = "ObitTableGBTANTPOSPFClose";

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA((Obit*)in, &myClassInfo));
  /* Something going on? */
  if (in->myStatus == OBIT_Inactive) return OBIT_IO_OK;

  /* Update keywords on descriptor if not ReadOnly*/
  if (in->myDesc->access != OBIT_IO_ReadOnly) 
    ObitTableGBTANTPOSPFDumpKey (in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  /* Close */
  retCode = ObitTableClose ((ObitTable*)in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  return retCode;
} /* end ObitTableGBTANTPOSPFClose */

/*---------------Private functions--------------------------*/
/*----------------  ObitTableGBTANTPOSPF Row  ----------------------*/
/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableGBTANTPOSPFRowInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTANTPOSPFRow *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */
  /* Set array members to NULL */

} /* end ObitTableGBTANTPOSPFRowInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableGBTANTPOSPFRow* cast to an Obit*.
 */
void ObitTableGBTANTPOSPFRowClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTANTPOSPFRow *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myRowClassInfo));

  /* delete this class members */
  /* Do not free data array pointers as they were not malloced */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableGBTANTPOSPFRowClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableGBTANTPOSPFRowClassInit (void)
{
  if (myRowClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myRowClassInfo.ClassName   = g_strdup(myRowClassName);
  myRowClassInfo.ParentClass = ObitParentGetRowClass();

  /* Set function pointers */
  ObitTableGBTANTPOSPFRowClassInfoDefFn ((gpointer)&myRowClassInfo);
 
  myRowClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableGBTANTPOSPFRowClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableGBTANTPOSPFRowClassInfoDefFn (gpointer inClass)
{
  ObitTableGBTANTPOSPFRowClassInfo *theClass = (ObitTableGBTANTPOSPFRowClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myRowClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myRowClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableGBTANTPOSPFRowClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableGBTANTPOSPFRowClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableGBTANTPOSPFRowGetClass;
  theClass->newObit         = NULL;
  theClass->newObitTableRow = (newObitTableRowFP)newObitTableGBTANTPOSPFRow;
  theClass->ObitCopy        = NULL;
  theClass->ObitClone       = NULL;
  theClass->ObitClear       = (ObitClearFP)ObitTableGBTANTPOSPFRowClear;
  theClass->ObitInit        = (ObitInitFP)ObitTableGBTANTPOSPFRowInit;

} /* end ObitTableGBTANTPOSPFRowClassDefFn */

/*------------------  ObitTableGBTANTPOSPF  ------------------------*/

/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableGBTANTPOSPFInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTANTPOSPF *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */

} /* end ObitTableGBTANTPOSPFInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableGBTANTPOSPF* cast to an Obit*.
 */
void ObitTableGBTANTPOSPFClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTANTPOSPF *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myClassInfo));

  /* delete this class members */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableGBTANTPOSPFClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableGBTANTPOSPFClassInit (void)
{
  if (myClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myClassInfo.ClassName   = g_strdup(myClassName);
  myClassInfo.ParentClass = ObitParentGetClass();

  /* Set function pointers */
  ObitTableGBTANTPOSPFClassInfoDefFn ((gpointer)&myClassInfo);
 
  myClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableGBTANTPOSPFClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableGBTANTPOSPFClassInfoDefFn (gpointer inClass)
{
  ObitTableGBTANTPOSPFClassInfo *theClass = (ObitTableGBTANTPOSPFClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableGBTANTPOSPFClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableGBTANTPOSPFClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableGBTANTPOSPFGetClass;
  theClass->newObit       = (newObitFP)newObitTableGBTANTPOSPF;
  theClass->ObitCopy      = (ObitCopyFP)ObitTableGBTANTPOSPFCopy;
  theClass->ObitClone     = (ObitCloneFP)ObitTableClone;
  theClass->ObitClear     = (ObitClearFP)ObitTableGBTANTPOSPFClear;
  theClass->ObitInit      = (ObitInitFP)ObitTableGBTANTPOSPFInit;
  theClass->ObitTableConvert = (ObitTableConvertFP)ObitTableGBTANTPOSPFConvert;
  theClass->ObitTableOpen    = (ObitTableOpenFP)ObitTableGBTANTPOSPFOpen;
  theClass->ObitTableClose   = (ObitTableCloseFP)ObitTableGBTANTPOSPFClose;
  theClass->ObitTableRead    = (ObitTableReadFP)ObitTableRead;
  theClass->ObitTableReadSelect = 
    (ObitTableReadSelectFP)ObitTableReadSelect;
  theClass->ObitTableWrite = (ObitTableWriteFP)ObitTableWrite;
  theClass->ObitTableReadRow = 
    (ObitTableReadRowFP)ObitTableGBTANTPOSPFReadRow;
  theClass->ObitTableWriteRow = 
    (ObitTableWriteRowFP)ObitTableGBTANTPOSPFWriteRow;

} /* end ObitTableGBTANTPOSPFClassDefFn */

/**
 * Get table specific information from the infolist or descriptor
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableGBTANTPOSPFUpdate (ObitTableGBTANTPOSPF *in, ObitErr *err)
{
  olong i;
  ObitTableDesc *desc;
   

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Get Keywords */

  /* initialize column numbers/offsets */
  in->dmjdOff = -1;
  in->dmjdCol = -1;
  in->raj2000Off = -1;
  in->raj2000Col = -1;
  in->decj2000Off = -1;
  in->decj2000Col = -1;
  in->mntAazOff = -1;
  in->mntAazCol = -1;
  in->mntElOff = -1;
  in->mntElCol = -1;
  in->refractOff = -1;
  in->refractCol = -1;
  in->majorOff = -1;
  in->majorCol = -1;
  in->minorOff = -1;
  in->minorCol = -1;
  in->pfFocusOff = -1;
  in->pfFocusCol = -1;
  in->pfRotationOff = -1;
  in->pfRotationCol = -1;
  in->pfXOff = -1;
  in->pfXCol = -1;
  /* Find columns and set offsets */
  desc = in->myDesc;
  if (desc->FieldName) {
    for (i=0; i<desc->nfield; i++) {
      if (!strncmp (desc->FieldName[i], "DMJD    ", 8)) {
	 in->dmjdOff = desc->offset[i];
 	 in->dmjdCol = i;
      }
      if (!strncmp (desc->FieldName[i], "RAJ2000 ", 8)) {
	 in->raj2000Off = desc->offset[i];
 	 in->raj2000Col = i;
      }
      if (!strncmp (desc->FieldName[i], "DECJ2000", 8)) {
	 in->decj2000Off = desc->offset[i];
 	 in->decj2000Col = i;
      }
      if (!strncmp (desc->FieldName[i], "MNT_AZ ", 7)) {
	 in->mntAazOff = desc->offset[i];
 	 in->mntAazCol = i;
      }
      if (!strncmp (desc->FieldName[i], "MNT_EL  ", 8)) {
	 in->mntElOff = desc->offset[i];
 	 in->mntElCol = i;
      }
      if (!strncmp (desc->FieldName[i], "REFRACT ", 8)) {
	 in->refractOff = desc->offset[i];
 	 in->refractCol = i;
      }
      if (!strncmp (desc->FieldName[i], "MAJOR ", 6)) {
	 in->majorOff = desc->offset[i];
 	 in->majorCol = i;
      }
      if (!strncmp (desc->FieldName[i], "MINOR ", 6)) {
	 in->minorOff = desc->offset[i];
 	 in->minorCol = i;
      }
      if (!strncmp (desc->FieldName[i], "PF_FOCUS", 8)) {
	 in->pfFocusOff = desc->offset[i];
 	 in->pfFocusCol = i;
      }
      if (!strncmp (desc->FieldName[i], "PF_ROTATION", 11)) {
	 in->pfRotationOff = desc->offset[i];
 	 in->pfRotationCol = i;
      }
      if (!strncmp (desc->FieldName[i], "PF_X  ", 6)) {
	 in->pfXOff = desc->offset[i];
 	 in->pfXCol = i;
      }
     }
  }

  Obit_return_if_fail((in->dmjdOff > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column dmjd");
  Obit_return_if_fail((in->raj2000Off > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column raj2000");
  Obit_return_if_fail((in->decj2000Off > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column decj2000");
  Obit_return_if_fail((in->mntAazOff > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column mntAaz");
  Obit_return_if_fail((in->mntElOff > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column mntEl");
  Obit_return_if_fail((in->refractOff > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column refract");
  Obit_return_if_fail((in->majorOff > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column major");
  Obit_return_if_fail((in->minorOff > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column minor");
  Obit_return_if_fail((in->pfFocusOff > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column pfFocus");
  Obit_return_if_fail((in->pfRotationOff > -1), err,
       "ObitTableANTPOSPFUpdate: Could not find column pfRotation");
} /* end ObitTableGBTANTPOSPFUpdate */

/**
 * Copy table specific (keyword) information  to infolist.
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableGBTANTPOSPFDumpKey (ObitTableGBTANTPOSPF *in, ObitErr *err)
{
  ObitInfoList *info=NULL;

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Set Keywords */
  if (in->myIO!=NULL) info = ((ObitTableDesc*)(in->myIO->myDesc))->info;
  else info = in->myDesc->info;
   
} /* end ObitTableGBTANTPOSPFDumpKey */