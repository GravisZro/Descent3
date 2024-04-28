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
#ifndef LOAD_LIB_PTHREAD
#define LOAD_LIB_PTHREAD

// System
#include <pthread.h>

// Project
#include "module.h"

namespace pthread
{
  bool load(void);
  bool unload(void);

  extern int (*pthread_create)(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg);
  extern void (*pthread_exit)(void* value_ptr);
  extern int (*pthread_detach)(pthread_t thread);
  extern pthread_t (*pthread_self)(void);
}

#endif
