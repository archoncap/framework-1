
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/iterator.h"


/**
 * Model user's Tokens.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Tokens) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Users, Tokens, ice, auth_driver_model_users_tokens, ice_mvc_model_ce, ice_auth_driver_model_users_tokens_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_users_tokens_ce, SL("_from"), "user_tokens", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize token's relations, remove expired tokens
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, initialize) {

	zend_bool _9, _11;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1 = NULL, *_2, *_3, _4, _5, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_13 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	add_assoc_stringl_ex(_0, SS("alias"), SL("User"), 1);
	zephir_array_update_string(&_0, SL("foreignKey"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, _1, _2, _3, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 100);
	ZEPHIR_CALL_FUNCTION(&_6, "mt_rand", &_7, &_4, &_5);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(_6, 1)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteexpired", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "expires", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_9 = zephir_is_true(_8);
	if (_9) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "expires", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_9 = zephir_is_true(_10);
	}
	_11 = _9;
	if (_11) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "expires", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_13, "time", NULL);
		zephir_check_call_status();
		_11 = ZEPHIR_LT(_12, _13);
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate a new unique token and create the token
 *
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, create) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_generate",  NULL);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), _0 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_users_tokens_ce, this_ptr, "create", &_1, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes all expired tokens
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, deleteExpired) {

	zend_object_iterator *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;
	zval *token = NULL, *expired = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "<", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_CALL_FUNCTION(&_3, "time", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(_1, _3);
	zephir_array_update_string(&_0, SL("expires"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&expired, this_ptr, "load", NULL, _0);
	zephir_check_call_status();
	_4 = zephir_get_iterator(expired TSRMLS_CC);
	_4->funcs->rewind(_4 TSRMLS_CC);
	for (;_4->funcs->valid(_4 TSRMLS_CC) == SUCCESS && !EG(exception); _4->funcs->move_forward(_4 TSRMLS_CC)) {
		{ zval **tmp; 
		_4->funcs->get_current_data(_4, &tmp TSRMLS_CC);
		token = *tmp;
		}
		ZEPHIR_CALL_METHOD(NULL, token, "remove", NULL);
		zephir_check_call_status();
	}
	_4->funcs->dtor(_4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate a new unique token and update the token
 *
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, update) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_generate",  NULL);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), _0 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_users_tokens_ce, this_ptr, "update", &_1, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a new unique token
 *
 * @return string
 * @uses Text::random()
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, _generate) {

	zval *_8 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	zval *token = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	do {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 32);
		ZEPHIR_CALL_CE_STATIC(&_0, ice_text_ce, "random", &_1, _2, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4, "uniqid", &_5, _0, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&token, "sha1", &_6, _4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8);
		array_init_size(_8, 2);
		zephir_array_update_string(&_8, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_SELF(&_0, "findone", &_7, _8);
		zephir_check_call_status();
	} while (zephir_is_true(_0));
	RETURN_CCTOR(token);

}

