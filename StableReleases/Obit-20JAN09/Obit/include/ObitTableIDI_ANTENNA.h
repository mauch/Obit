/* $Id$   */
/* DO NOT EDIT - file generated by ObitTables.pl                      */
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
#ifndef OBITTABLEIDI_ANTENNA_H 
#define OBITTABLEIDI_ANTENNA_H 

#include "Obit.h"
#include "ObitErr.h"
#include "ObitTable.h"
#include "ObitData.h"

/*-------- Obit: Merx mollis mortibus nuper ------------------*/
/**
 * \file ObitTableIDI_ANTENNA.h
 * ObitTableIDI_ANTENNA class definition.
 *
 * This class is derived from the #ObitTable class.
 *
 * This class contains tabular data and allows access.
 * This table is part of the IDI uv data format.
 * "IDI\_ANTENNA" contains information about the characteristics
 * of antennas in a UV data set.
 * Polarization calibration information is included. 
 *
 * This class contains tabular data and allows access.
 * "IDI_ANTENNA" table
 * An ObitTableIDI_ANTENNA is the front end to a persistent disk resident structure.
 * Only FITS (as Tables) are supported.
 *
 * \section TableDataStorage Table data storage
 * In memory tables are stored in a fashion similar to how they are 
 * stored on disk - in large blocks in memory rather than structures.
 * Due to the word alignment requirements of some machines, they are 
 * stored by order of the decreasing element size: 
 * double, float long, int, short, char rather than the logical order.
 * The details of the storage in the buffer are kept in the 
 * #ObitTableIDI_ANTENNADesc.
 *
 * In addition to the normal tabular data, a table will have a "_status"
 * column to indicate the status of each row.
 *
 * \section ObitTableIDI_ANTENNASpecification Specifying desired data transfer parameters
 * The desired data transfers are specified in the member ObitInfoList.
 * In the following an ObitInfoList entry is defined by 
 * the name in double quotes, the data type code as an #ObitInfoType enum 
 * and the dimensions of the array (? => depends on application).
 *
 * The following apply to both types of files:
 * \li "nRowPIO", OBIT_int, Max. Number of visibilities per 
 *     "Read" or "Write" operation.  Default = 1.
 *
 * \subsection TableFITS FITS files
 * This implementation uses cfitsio which allows using, in addition to 
 * regular FITS images, gzip compressed files, pipes, shared memory 
 * and a number of other input forms.
 * The convenience Macro #ObitTableIDI_ANTENNASetFITS simplifies specifying the 
 * desired data.
 * Binary tables are used for storing visibility data in FITS.
 * For accessing FITS files the following entries in the ObitInfoList 
 * are used:
 * \li "FileName" OBIT_string (?,1,1) FITS file name.
 * \li "TabName"  OBIT_string (?,1,1) Table name (e.g. "AIPS CC").
 * \li "Ver"      OBIT_int    (1,1,1) Table version number
 *
 *
 * \section ObitTableIDI_ANTENNAaccess Creators and Destructors
 * An ObitTableIDI_ANTENNA can be created using newObitTableIDI_ANTENNAValue which attaches the 
 * table to an ObitData for the object.  
 * If the output ObitTableIDI_ANTENNA has previously been specified, including file information,
 * then ObitTableIDI_ANTENNACopy will copy the disk resident as well as the memory 
 * resident information.
 *
 * A copy of a pointer to an ObitTableIDI_ANTENNA should always be made using the
 * ObitTableIDI_ANTENNARef function which updates the reference count in the object.
 * Then whenever freeing an ObitTableIDI_ANTENNA or changing a pointer, the function
 * ObitTableIDI_ANTENNAUnref will decrement the reference count and destroy the object
 * when the reference count hits 0.
 *
 * \section ObitTableIDI_ANTENNAUsage I/O
 * Visibility data is available after an input object is "Opened"
 * and "Read".
 * I/O optionally uses a buffer attached to the ObitTableIDI_ANTENNA or some external
 * location.
 * To Write an ObitTableIDI_ANTENNA, create it, open it, and write.
 * The object should be closed to ensure all data is flushed to disk.
 * Deletion of an ObitTableIDI_ANTENNA after its final unreferencing will automatically
 * close it.
 */

/*--------------Class definitions-------------------------------------*/

/** Number of characters for Table keyword */
 #define MAXKEYCHARTABLEIDI_ANTENNA 24

/** ObitTableIDI_ANTENNA Class structure. */
typedef struct {
#include "ObitTableIDI_ANTENNADef.h"   /* this class definition */
} ObitTableIDI_ANTENNA;

/** ObitTableIDI_ANTENNARow Class structure. */
typedef struct {
#include "ObitTableIDI_ANTENNARowDef.h"   /* this class row definition */
} ObitTableIDI_ANTENNARow;

/*----------------- Macroes ---------------------------*/
/** 
 * Macro to unreference (and possibly destroy) an ObitTableIDI_ANTENNA
 * returns an ObitTableIDI_ANTENNA*.
 * in = object to unreference
 */
#define ObitTableIDI_ANTENNAUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitTableIDI_ANTENNA.
 * returns an ObitTableIDI_ANTENNA*.
 * in = object to reference
 */
#define ObitTableIDI_ANTENNARef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitTableIDI_ANTENNAIsA(in) ObitIsA (in, ObitTableIDI_ANTENNAGetClass())

/** 
 * Macro to unreference (and possibly destroy) an ObitTableIDI_ANTENNARow
 * returns an ObitTableIDI_ANTENNARow*.
 * in = object to unreference
 */
#define ObitTableIDI_ANTENNARowUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitTableIDI_ANTENNARow.
 * returns an ObitTableIDI_ANTENNARow*.
 * in = object to reference
 */
#define ObitTableIDI_ANTENNARowRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitTableIDI_ANTENNARowIsA(in) ObitIsA (in, ObitTableIDI_ANTENNARowGetClass())

/*---------------Public functions---------------------------*/
/*----------------Table Row Functions ----------------------*/
/** Public: Row Class initializer. */
void ObitTableIDI_ANTENNARowClassInit (void);

/** Public: Constructor. */
ObitTableIDI_ANTENNARow* newObitTableIDI_ANTENNARow (ObitTableIDI_ANTENNA *table);

/** Public: ClassInfo pointer */
gconstpointer ObitTableIDI_ANTENNARowGetClass (void);

/*------------------Table Functions ------------------------*/
/** Public: Class initializer. */
void ObitTableIDI_ANTENNAClassInit (void);

/** Public: Constructor. */
ObitTableIDI_ANTENNA* newObitTableIDI_ANTENNA (gchar* name);

/** Public: Constructor from values. */
ObitTableIDI_ANTENNA* 
newObitTableIDI_ANTENNAValue (gchar* name, ObitData *file, olong *ver,
  		     ObitIOAccess access,
                     oint no_band, oint numPCal,
		     ObitErr *err);

/** Public: Class initializer. */
void ObitTableIDI_ANTENNAClassInit (void);

/** Public: ClassInfo pointer */
gconstpointer ObitTableIDI_ANTENNAGetClass (void);

/** Public: Copy (deep) constructor. */
ObitTableIDI_ANTENNA* ObitTableIDI_ANTENNACopy  (ObitTableIDI_ANTENNA *in, ObitTableIDI_ANTENNA *out, 
			   ObitErr *err);

/** Public: Copy (shallow) constructor. */
ObitTableIDI_ANTENNA* ObitTableIDI_ANTENNAClone (ObitTableIDI_ANTENNA *in, ObitTableIDI_ANTENNA *out);

/** Public: Convert an ObitTable to an ObitTableIDI_ANTENNA */
ObitTableIDI_ANTENNA* ObitTableIDI_ANTENNAConvert  (ObitTable *in);

/** Public: Create ObitIO structures and open file */
ObitIOCode ObitTableIDI_ANTENNAOpen (ObitTableIDI_ANTENNA *in, ObitIOAccess access, 
			  ObitErr *err);

/** Public: Read a table row */
ObitIOCode 
ObitTableIDI_ANTENNAReadRow  (ObitTableIDI_ANTENNA *in, olong iIDI_ANTENNARow, ObitTableIDI_ANTENNARow *row,
		     ObitErr *err);

/** Public: Init a table row for write */
void 
ObitTableIDI_ANTENNASetRow  (ObitTableIDI_ANTENNA *in, ObitTableIDI_ANTENNARow *row,
		     ObitErr *err);

/** Public: Write a table row */
ObitIOCode 
ObitTableIDI_ANTENNAWriteRow  (ObitTableIDI_ANTENNA *in, olong iIDI_ANTENNARow, ObitTableIDI_ANTENNARow *row,
		     ObitErr *err);

/** Public: Close file and become inactive */
ObitIOCode ObitTableIDI_ANTENNAClose (ObitTableIDI_ANTENNA *in, ObitErr *err);

/*----------- ClassInfo Structure -----------------------------------*/
/**
 * ClassInfo Structure.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitTableIDI_ANTENNAClassDef.h"
} ObitTableIDI_ANTENNAClassInfo; 

/**
 * ClassInfo Structure For TableIDI_ANTENNARow.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitTableIDI_ANTENNARowClassDef.h"
} ObitTableIDI_ANTENNARowClassInfo; 
#endif /* OBITTABLEIDI_ANTENNA_H */ 