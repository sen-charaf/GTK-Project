
#include "./../../../include/widgets/button/switch_button.h"



ViewConfig *configure_switch_button_property(SwitchButtonConfig *switch_button_config, ViewConfig *view_config, gchar *property, gchar *value)
{
    if (!switch_button_config || !property || !value)
        return NULL;

    // Tooltip
    if (g_strcmp0(property, "tooltip") == 0)
    {
        strcpy(switch_button_config->tooltip, value);
        return view_config;
    }

    // Visibility
    if (g_strcmp0(property, "is_visible") == 0)
    {
        switch_button_config->is_visible = g_strcmp0(value, "true") == 0;
        return view_config;
    }

    // Active state
    if (g_strcmp0(property, "is_active") == 0)
    {
        switch_button_config->is_active = g_strcmp0(value, "true") == 0;
        return view_config;
    }

    // State
    if (g_strcmp0(property, "state") == 0)
    {
        switch_button_config->state = g_strcmp0(value, "true") == 0;
        return view_config;
    }

        // Margins
    if (g_strcmp0(property, "margin_top") == 0)
        switch_button_config->margins.top = atoi(value);

    if (g_strcmp0(property, "margin_bottom") == 0)
        switch_button_config->margins.bottom = atoi(value);

    if (g_strcmp0(property, "margin_left") == 0)
        switch_button_config->margins.start = atoi(value);

    if (g_strcmp0(property, "margin_right") == 0)
        switch_button_config->margins.end = atoi(value);

    // Dimensions
    if (g_strcmp0(property, "width") == 0)
        switch_button_config->dimensions.width = atoi(value);

    if (g_strcmp0(property, "height") == 0)
        switch_button_config->dimensions.height = atoi(value);

    if (g_strcmp0(property, "bg_color") == 0)
        strcpy(switch_button_config->bg_color, value);

    if (g_strcmp0(property, "text_color") == 0)
        strcpy(switch_button_config->text_color, value);

    SET_VIEW_CONFIG_PROPERTY(property, value, view_config);

    return view_config;
}

ViewConfig *init_switch_button_config(FILE *index, SwitchButtonConfig *switch_button_config)
{
    return init_generic_config(index,(void*)switch_button_config,(ConfigurePropertyCallback)configure_switch_button_property);
}

GtkWidget *create_switch_button(SwitchButtonConfig switch_button_config)
{
    GtkWidget *switch_button = NULL;

    // Creation
    switch_button = gtk_switch_new();

    // Set dimensions
    if (switch_button_config.dimensions.width > 0 && switch_button_config.dimensions.height > 0)
    {
        gtk_widget_set_size_request(switch_button, switch_button_config.dimensions.width, switch_button_config.dimensions.height);
    }

    // Set colors (background and/or text colors)
    widget_set_colors(switch_button, switch_button_config.bg_color, switch_button_config.text_color);

    // Enable or disable the switch
    gtk_switch_set_active(GTK_SWITCH(switch_button), switch_button_config.is_active);

    // Set visibility
    if (switch_button_config.is_visible)
        gtk_widget_show(switch_button);

    // Set a tooltip
    gtk_widget_set_tooltip_text(switch_button, switch_button_config.tooltip);

    // Set the state to ON or OFF like active but this one controll the switch during transition not only the final state
    gtk_switch_set_state(GTK_SWITCH(switch_button), switch_button_config.state);

    // Set margins
    widget_set_margins(switch_button, switch_button_config.margins);

    return switch_button;
}
