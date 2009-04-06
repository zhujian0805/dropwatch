/*
 * Copyright (C) 2009, Neil Horman <nhorman@redhat.com>
 * 
 * This program file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program in a file named COPYING; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 */

/*
 * This is a translator.  given an input address, this will convert it into a
 * function and offset.  Unless overridden, it will automatically determine
 * tranlations using the following methods, in order of priority:
 * 1) /usr/lib/debug/<kernel version> using libbfd
 * 2) /proc/kallsyms
 */



/*
 * Initalization routine
 * INPUTS:
 *   method - enum describing how to do translation
 *          * METHOD_AUTO : automatic search for best method
 *          * METHOD_DEBUGINFO : use debuginfo package
 *          * METHOD_KALLSYMS : use /proc/kallsyms
 *   returns:
 *          * 0   : initalization succeded
 *          * < 0 : initalization failed
 */
typedef enum {
	METHOD_AUTO = 0,
	METHOD_DEBUGINFO,
	METHOD_KALSYMS
} lookup_init_method_t;

int init_lookup(lookup_init_method_t method);


struct lookup_methods {
        int (*lookup_init)(void);
	char *(*get_symbol)(void *pc);
};


