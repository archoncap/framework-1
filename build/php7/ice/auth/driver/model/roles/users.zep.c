
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Model user's Roles.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Roles, Users, ice, auth_driver_model_roles_users, ice_mvc_model_ce, ice_auth_driver_model_roles_users_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_roles_users_ce, SL("from"), "roles_users", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize roles-users relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Roles_Users, initialize) {

	zval _5, _7;
	zval auth, _0, _1, _2, _3, _4, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth");
	ZEPHIR_CALL_METHOD(&auth, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "users");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Ice\\Auth\\Driver\\Model\\Users");
	ZEPHIR_CALL_METHOD(&_2, &auth, "getoption", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_5, SL("alias"), SL("User"));
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, 0, &_1, &_2, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_7, SL("alias"), SL("Role"));
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "role_id");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Ice\\Auth\\Driver\\Model\\Roles");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, 0, &_1, &_3, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}
