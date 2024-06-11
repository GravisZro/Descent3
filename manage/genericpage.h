/*
* Descent 3 
* Copyright (C) 2024 Parallax Software
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GENERICPAGE_H
#define GENERICPAGE_H

#include "manage.h"
#include "cfile.h"
#include "pstypes.h"
#include "objinfo.h"
#include "robotfirestruct.h"

struct mngs_generic_page {
  object_info objinfo_struct;
  anim_elem anim[NUM_MOVEMENT_CLASSES];
  otype_wb_info static_wb[MAX_WBS_PER_OBJ];
  t_ai_info ai_info;
  pagename_t image_name;
  pagename_t med_image_name;
  pagename_t lo_image_name;
  pagename_t sound_name[MAX_OBJ_SOUNDS];
  pagename_t ai_sound_name[MAX_AI_SOUNDS];
  pagename_t weapon_name[MAX_WBS_PER_OBJ][MAX_WB_GUNPOINTS];
  pagename_t fire_sound_name[MAX_WBS_PER_OBJ][MAX_WB_FIRING_MASKS];
  pagename_t anim_sound_name[NUM_MOVEMENT_CLASSES][NUM_ANIMS_PER_CLASS];
  pagename_t dspew_name[MAX_DSPEW_TYPES];
};

// Generic page functions
//---------------------------------------------------------------

// Given an open file pointer and a generic_page struct, writes that genericpage out
void mng_WriteGenericPage(CFILE *outfile, mngs_generic_page *genericpage);

// Reads a generic page from an open file.  Returns 0 on error.
int mng_ReadGenericPage(CFILE *infile, mngs_generic_page *genericpage);

// Given an open file pointer and a generic_page struct, writes that genericpage out
void mng_WriteNewGenericPage(CFILE *outfile, mngs_generic_page *genericpage);

// Reads a generic page from an open file.  Returns 0 on error.
int mng_ReadNewGenericPage(CFILE *infile, mngs_generic_page *genericpage);

// Reads in the genericpage named "name" into genericpage struct
// Returns 0 on error or couldn't find, else 1 if all is good
int mng_FindSpecificGenericPage(const pagename_t& name, mngs_generic_page *genericpage, int offset = 0);

// Given a generic page, allocs a generic and calls AssignGenericPageToGeneric to actually
// load model and values. Rturns generic handle on success, -1 if fail
int mng_SetAndLoadGeneric(mngs_generic_page *genericpage, CFILE *infile = NULL);

// Given a genericpage and a generic handle, attempts to make generic n correspond to
// to the genericpage.
// Returns 1 on success, 0 otherwise
int mng_AssignGenericPageToObjInfo(mngs_generic_page *genericpage, int n, CFILE *infile = NULL);

// Copies values from a Generic into a generic_page
void mng_AssignObjInfoToGenericPage(int n, mngs_generic_page *genericpage);

// Reads in a generic page from the local table file, superseding any generic
// already in RAM with that same name
void mng_LoadLocalGenericPage(CFILE *);

// Reads in a page off the net
void mng_LoadNetGenericPage(CFILE *, bool overlay = false);

// First searches through the object index to see if the object is already
// loaded.  If not, searches in the table file and loads it.
// Returns index of object found, -1 if not
int mng_GetGuaranteedGenericPage(const pagename_t& name, CFILE *infile);

#endif
