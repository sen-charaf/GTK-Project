#include "./../../include/builder.h"
/**
 * @brief structure for handle signales parametres
 * //todo variable: checck if on_cllick signal activate or not and also for other signales
 */
typedef struct
{
    gchar params[PARAM_COUNT][MAX_SIGNAL_NAME_SIZE]; // First function parameter
} ParamNode;

static void sig_change_self_bg_color(GtkWidget *widget, gpointer data)
{

    ParamNode *param_array = (ParamNode *)data;
    if (!param_array)
    {
        g_print("\nError: sig_change_friend_bg_color(), passing argument.\n");
        return;
    }

    widget_set_colors(widget, param_array->params[0], param_array->params[1]);
}

static void sig_change_friend_bg_color(GtkWidget *widget, gpointer data)
{

    ParamNode *param_array = (ParamNode *)data;
    if (!param_array)
    {
        g_print("\nError: sig_change_friend_bg_color(), passing argument.\n");
        return;
    }
    View *friend = find_view_by_id(param_array->params[0], root_view_gloabl);
    widget_set_colors(friend->widget, param_array->params[1], param_array->params[2]);
}
static void sig_dialog_message(GtkWidget *widget, gpointer data)
{
    ParamNode *param_array = (ParamNode *)data;
    MessageDialogConfig message_dialog_config = DEFAULT_MESSAGE_DIALOG_CONFIG;
    strcpy(message_dialog_config.message, param_array->params[0]);
    GtkWidget *dialog_widget = create_message_dialog(message_dialog_config);

    show_dialog(dialog_widget);
}




void connect_signales(View *view)
{
    void *callback_fuction = NULL;

    if (view->view_config->onclick[0] != '\0')
    {

        // apply name of function
        if (strcmp(view->view_config->onclick, "sig_change_self_bg_color") == 0)
            callback_fuction = sig_change_self_bg_color;
        else if (strcmp(view->view_config->onclick, "sig_dialog_message") == 0)
            callback_fuction = sig_dialog_message;

        else if (strcmp(view->view_config->onclick, "sig_change_friend_bg_color") == 0)
            callback_fuction = sig_change_friend_bg_color;

        

        // Connect the callback function
        if (callback_fuction)
            g_signal_connect(G_OBJECT(view->widget), "clicked", G_CALLBACK(callback_fuction), (ParamNode *)view->view_config->param);
        
            return; // exit the function
    }
}


// Link signals
// if (view_config->onclick[0] != '\0')
// {
//     if (g_strcmp0(view_config->onclick, "click1") == 0)
//         g_signal_connect(G_OBJECT(button_widget), "clicked", G_CALLBACK(click1), NULL);
//     else if (g_strcmp0(view_config->onclick, "click2") == 0)
//         g_signal_connect(G_OBJECT(button_widget), "clicked", G_CALLBACK(click2), NULL);
// }

// if (view_config->onclick[0] != '\0')
// {
//     if (g_strcmp0(view_config->onclick, "menu_onclick") == 0)
//         g_signal_connect(G_OBJECT(menu_item_widget), "activate", G_CALLBACK(menu_item_onclick), NULL);
//     else if (g_strcmp0(view_config->onclick, "menu_onclick1") == 0)
//         g_signal_connect(G_OBJECT(menu_item_widget), "activate", G_CALLBACK(menu_item_onclick), NULL);
//     }