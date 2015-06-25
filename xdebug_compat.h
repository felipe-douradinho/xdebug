/*
   +----------------------------------------------------------------------+
   | Xdebug                                                               |
   +----------------------------------------------------------------------+
   | Copyright (c) 2002-2015 Derick Rethans                               |
   +----------------------------------------------------------------------+
   | This source file is subject to version 1.0 of the Xdebug license,    |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://xdebug.derickrethans.nl/license.php                           |
   | If you did not receive a copy of the Xdebug license and are unable   |
   | to obtain it through the world-wide-web, please send a note to       |
   | xdebug@derickrethans.nl so we can mail you a copy immediately.       |
   +----------------------------------------------------------------------+
   | Authors:  Derick Rethans <derick@xdebug.org>                         |
   +----------------------------------------------------------------------+
 */

#ifndef __HAVE_XDEBUG_COMPAT_H__
#define __HAVE_XDEBUG_COMPAT_H__

#include "php.h"

#include "ext/standard/php_var.h"
#define xdebug_php_var_dump php_var_dump

zval *xdebug_zval_ptr(int op_type, const znode_op *node, zend_execute_data *zdata TSRMLS_DC);

#if PHP_VERSION_ID >= 70000
char *xdebug_base64_decode(unsigned char *data, int data_len, int *new_len);
void xdebug_stripcslashes(char *string, int *new_len);
zend_class_entry *xdebug_fetch_class(char *classname, int classname_len, int flags TSRMLS_DC);
int xdebug_get_constant(char *val, int len, zval *const_val TSRMLS_DC);

# define ADD_STRING_COPY

# define XDEBUG_MAKE_STD_ZVAL(zv) \
	zv = ecalloc(sizeof(zval), 1);

#else
# include "ext/standard/base64.h"
# define xdebug_base64_encode php_base64_encode
# define xdebug_base64_decode php_base64_decode
# define xdebug_stripcslashes php_stripcslashes
# define xdebug_fetch_class   zend_fetch_class
# define xdebug_get_constant  zend_get_constant

# define ADD_STRING_COPY , 1

# define XDEBUG_MAKE_STD_ZVAL(zv) \
	MAKE_STD_ZVAL(zv)
#endif

#endif
