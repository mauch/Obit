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
#ifndef ObitTableOTFTarget_H 
#define ObitTableOTFTarget_H 

#include "Obit.h"
#include "ObitErr.h"
#include "ObitTable.h"
#include "ObitData.h"

/*-------- Obit: Merx mollis mortibus nuper ------------------*/
/**
 * \file ObitTableOTFTarget.h
 * ObitTableOTFTarget class definition.
 *
 * This class contains tabular data and allows access.
 * OTFTarget contains information about astronomical sources.
 * An ObitTableOTFTarget is the front end to a persistent disk resident structure.
 * Only FITS cataloged data are supported.
 * This class is derived from the ObitTable class. 
 *
 * This class contains tabular data and allows access.
 * ObitTableOTFTarget" 
 * An ObitTableOTFTarget is the front end to a persistent disk resident structure.
 * This class is derived from the ObitTable class.
 *
 * \section TableDataStorage Table data storage
 * In memory tables are stored in a fashion similar to how they are 
 * stored on disk - in large blocks in memory rather than structures.
 * Due to the word alignment requirements of some machines, they are 
 * stored by order of the decreasing element size: 
 * double, float long, int, short, char rather than the logical order.
 * The details of the storage in the buffer are kept in the 
 * #ObitTableOTFTargetDesc.
 *
 * In addition to the normal tabular data, a table will have a "_status"
 * column to indicate the status of each row.
 * The status value is read from and written to (some modification) AIPS 
 * tables but are not written to externally generated FITS tables which
 * don't have these colummns.  It will be written to Obit generated tables
 * which will have these columns.
 * Status values:
 * \li status = 0 => normal
 * \li status = 1 => row has been modified (or created) and needs to be
 *                   written.
 * \li status = -1 => row has been marked invalid.
 *
 * \section ObitTableOTFTargetSpecification Specifying desired data transfer parameters
 * The desired data transfers are specified in the member ObitInfoList.
 * There are separate sets of parameters used to specify the FITS 
 * data files.
 * In the following an ObitInfoList entry is defined by 
 * the name in double quotes, the data type code as an #ObitInfoType enum 
 * and the dimensions of the array (? => depends on application).
 * To specify whether the underlying data files are FITS
 * \li "FileType" OBIT_int (1,1,1) OBIT_IO_FITS 
 * which are values of an #ObitIOType enum defined in ObitIO.h.
 *
 * The following apply to both types of files:
 * \li "nRowPIO", OBIT_int, Max. Number of visibilities per 
 *     "Read" or "Write" operation.  Default = 1.
 *
 * \subsection TableFITS FITS files
 * This implementation uses cfitsio which allows using, in addition to 
 * regular FITS images, gzip compressed files, pipes, shared memory 
 * and a number of other input forms.
 * The convenience Macro #ObitTableOTFTargetSetFITS simplifies specifying the 
 * desired data.
 * Binary tables are used for storing visibility data in FITS.
 * For accessing FITS files the following entries in the ObitInfoList 
 * are used:
 * \li "FileName" OBIT_string (?,1,1) FITS file name.
 * \li "TabName"  OBIT_string (?,1,1) Table name (e.g. "AIPS CC").
 * \li "Ver"      OBIT_int    (1,1,1) Table version number
 *
 *
 * \section ObitTableOTFTargetaccess Creators and Destructors
 * An ObitTableOTFTarget can be created using newObitTableOTFTargetValue which attaches the 
 * table to an ObitData for the object.  
 * If the output ObitTableOTFTarget has previously been specified, including file information,
 * then ObitTableOTFTargetCopy will copy the disk resident as well as the memory 
 * resident information.
 *
 * A copy of a pointer to an ObitTableOTFTarget should always be made using the
 * ObitTableOTFTargetRef function which updates the reference count in the object.
 * Then whenever freeing an ObitTableOTFTarget or changing a pointer, the function
 * ObitTableOTFTargetUnref will decrement the reference count and destroy the object
 * when the reference count hits 0.
 *
 * \section ObitTableOTFTargetUsage I/O
 * Visibility data is available after an input object is "Opened"
 * and "Read".
 * I/O optionally uses a buffer attached to the ObitTableOTFTarget or some external
 * location.
 * To Write an ObitTableOTFTarget, create it, open it, and write.
 * The object should be closed to ensure all data is flushed to disk.
 * Deletion of an ObitTableOTFTarget after its final unreferencing will automatically
 * close it.
 */

/*--------------Class definitions-------------------------------------*/

/** Number of characters for Table keyword */
 #define MAXKEYCHARTABLEOTFTarget 24

/** ObitTableOTFTarget Class structure. */
typedef struct {
#include "ObitTableOTFTargetDef.h"   /* this class definition */
} ObitTableOTFTarget;

/** ObitTableOTFTargetRow Class structure. */
typedef struct {
#include "ObitTableOTFTargetRowDef.h"   /* this class row definition */
} ObitTableOTFTargetRow;

/*----------------- Macroes ---------------------------*/
/** 
 * Macro to unreference (and possibly destroy) an ObitTableOTFTarget
 * returns an ObitTableOTFTarget*.
 * in = object to unreference
 */
#define ObitTableOTFTargetUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitTableOTFTarget.
 * returns an ObitTableOTFTarget*.
 * in = object to reference
 */
#define ObitTableOTFTargetRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitTableOTFTargetIsA(in) ObitIsA (in, ObitTableOTFTargetGetClass())

/** 
 * Macro to unreference (and possibly destroy) an ObitTableOTFTargetRow
 * returns an ObitTableOTFTargetRow*.
 * in = object to unreference
 */
#define ObitTableOTFTargetRowUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitTableOTFTargetRow.
 * returns an ObitTableOTFTargetRow*.
 * in = object to reference
 */
#define ObitTableOTFTargetRowRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitTableOTFTargetRowIsA(in) ObitIsA (in, ObitTableOTFTargetRowGetClass())

/*---------------Public functions---------------------------*/
/*----------------Table Row Functions ----------------------*/
/** Public: Row Class initializer. */
void ObitTableOTFTargetRowClassInit (void);

/** Public: Constructor. */
ObitTableOTFTargetRow* newObitTableOTFTargetRow (ObitTableOTFTarget *table);

/** Public: ClassInfo pointer */
gconstpointer ObitTableOTFTargetRowGetClass (void);

/*------------------Table Functions ------------------------*/
/** Public: Class initializer. */
void ObitTableOTFTargetClassInit (void);

/** Public: Constructor. */
ObitTableOTFTarget* newObitTableOTFTarget (gchar* name);

/** Public: Constructor from values. */
ObitTableOTFTarget* 
newObitTableOTFTargetValue (gchar* name, ObitData *file, olong *ver,
  		     ObitIOAccess access,
                    
		     ObitErr *err);

/** Public: ClassInfo pointer */
gconstpointer ObitTableOTFTargetGetClass (void);

/** Public: Copy (deep) constructor. */
ObitTableOTFTarget* ObitTableOTFTargetCopy  (ObitTableOTFTarget *in, ObitTableOTFTarget *out, 
			   ObitErr *err);

/** Public: Copy (shallow) constructor. */
ObitTableOTFTarget* ObitTableOTFTargetClone (ObitTableOTFTarget *in, ObitTableOTFTarget *out);

/** Public: Convert an ObitTable to an ObitTableOTFTarget */
ObitTableOTFTarget* ObitTableOTFTargetConvert  (ObitTable *in);

/** Public: Create ObitIO structures and open file */
ObitIOCode ObitTableOTFTargetOpen (ObitTableOTFTarget *in, ObitIOAccess access, 
			  ObitErr *err);

/** Public: Read a table row */
ObitIOCode 
ObitTableOTFTargetReadRow  (ObitTableOTFTarget *in, olong iOTFTargetRow, ObitTableOTFTargetRow *row,
		     ObitErr *err);

/** Public: Init a table row for write */
void 
ObitTableOTFTargetSetRow  (ObitTableOTFTarget *in, ObitTableOTFTargetRow *row,
		     ObitErr *err);

/** Public: Write a table row */
ObitIOCode 
ObitTableOTFTargetWriteRow  (ObitTableOTFTarget *in, olong iOTFTargetRow, ObitTableOTFTargetRow *row,
		     ObitErr *err);

/** Public: Close file and become inactive */
ObitIOCode ObitTableOTFTargetClose (ObitTableOTFTarget *in, ObitErr *err);

/*----------- ClassInfo Structure -----------------------------------*/
/**
 * ClassInfo Structure.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitTableOTFTargetClassDef.h"
} ObitTableOTFTargetClassInfo; 

/**
 * ClassInfo Structure For TableObitTableOTFTargetRow.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitTableOTFTargetRowClassDef.h"
} ObitTableOTFTargetRowClassInfo; 
#endif /* ObitTableOTFTarget_H */ 
