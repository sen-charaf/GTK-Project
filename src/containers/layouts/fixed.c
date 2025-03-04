#include "./../../../include/containers/layouts/fixed.h"

ViewConfig *configure_fixed_property(FixedConfig *fixed_config, ViewConfig *view_config, gchar *property, gchar *value)
{
    if (!fixed_config || !property || !value)
        return NULL;

    // Margins
    if (g_strcmp0(property, "margin_top") == 0)
        fixed_config->margins.top = atoi(value);

    if (g_strcmp0(property, "margin_bottom") == 0)
        fixed_config->margins.bottom = atoi(value);

    if (g_strcmp0(property, "margin_left") == 0)
        fixed_config->margins.start = atoi(value);

    if (g_strcmp0(property, "margin_right") == 0)
        fixed_config->margins.end = atoi(value);

    // Dimensions
    if (g_strcmp0(property, "width") == 0)
        fixed_config->dimensions.width = atoi(value);

    if (g_strcmp0(property, "height") == 0)
        fixed_config->dimensions.height = atoi(value);

    if (g_strcmp0(property, "bg_color") == 0)
        strcpy(fixed_config->bg_color, value);

    if (g_strcmp0(property, "text_color") == 0)
        strcpy(fixed_config->text_color, value);

    // Icon image and icon

    SET_VIEW_CONFIG_PROPERTY(property, value, view_config);

    return view_config;
}

ViewConfig *init_fixed_config(FILE *index, FixedConfig *fixed_config)
{
    return init_generic_config(index,(void*)fixed_config,(ConfigurePropertyCallback)configure_fixed_property);
}
GtkWidget *create_fixed(FixedConfig fixed_config)
{
    GtkWidget *fixed = NULL;

    // Creation
    fixed = gtk_fixed_new();

    // Set dimensions
    if (fixed_config.dimensions.width > 0 || fixed_config.dimensions.height)
        gtk_widget_set_size_request(fixed, fixed_config.dimensions.width, fixed_config.dimensions.height);

    // Set colors
    widget_set_colors(fixed, fixed_config.bg_color, fixed_config.text_color);

    
    widget_set_colors(fixed, fixed_config.bg_color, fixed_config.text_color);

    // Set margins
    widget_set_margins(fixed, fixed_config.margins);

    return fixed;
}

void add_fixed(GtkWidget *widget, gint x, gint y)
{
    gtk_fixed_put(GTK_FIXED(widget), widget, x, y);
}