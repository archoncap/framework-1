
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_View_ViewInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Mvc\\View, ViewInterface, ice, mvc_view_viewinterface, ice_mvc_view_viewinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_Mvc_View_ViewInterface, getEngines);

ZEPHIR_DOC_METHOD(Ice_Mvc_View_ViewInterface, render);

