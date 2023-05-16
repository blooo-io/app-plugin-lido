#include "lido_plugin.h"

void handle_finalize(void *parameters) {
    ethPluginFinalize_t *msg = (ethPluginFinalize_t *) parameters;
    lido_parameters_t *context = (lido_parameters_t *) msg->pluginContext;
    PRINTF("handle finalize\n");
    if (context->valid) {
       switch (context->selectorIndex) {
        case SUBMIT:
        case UNWRAP:
        case WRAP:
            msg->numScreens = 1;
            break;
        case REQUEST_WITHDRAWALS_WITH_PERMIT:
            msg->numScreens = 2;
            break;
        }
        msg->uiType = ETH_UI_TYPE_GENERIC;
        msg->result = ETH_PLUGIN_RESULT_OK;
    } else {
        PRINTF("Invalid context\n");
        msg->result = ETH_PLUGIN_RESULT_FALLBACK;
    }
}
