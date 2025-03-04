#include "./../../../include/containers/layouts/paned.h"

ViewConfig *configure_paned_property(PanedConfig *paned_config, ViewConfig *view_config, gchar *property, gchar *value)
{
    if (!paned_config || !property || !value)
        return NULL;

    if (g_strcmp0(property, "orientation") == 0)
    {
        if (g_strcmp0(value, "horizontal") == 0)
            paned_config->orientation = GTK_ORIENTATION_HORIZONTAL;
        else if (g_strcmp0(value, "vertical") == 0)
            paned_config->orientation = GTK_ORIENTATION_VERTICAL;
    }

    if (g_strcmp0(property, "position") == 0)
        paned_config->position = atoi(value);

    if (g_strcmp0(property, "is_wide") == 0)
        paned_config->is_wide = g_strcmp0(value, "true") == 0 ? TRUE : FALSE;

    // Margins
    if (g_strcmp0(property, "margin_top") == 0)
        paned_config->margins.top = atoi(value);
    if (g_strcmp0(property, "margin_bottom") == 0)
        paned_config->margins.bottom = atoi(value);
    if (g_strcmp0(property, "margin_left") == 0)
        paned_config->margins.start = atoi(value);
    if (g_strcmp0(property, "margin_right") == 0)
        paned_config->margins.end = atoi(value);

    // Colors
    if (g_strcmp0(property, "bg_color") == 0)
        strcpy(paned_config->bg_color, value);

    if (g_strcmp0(property, "text_color") == 0)
        strcpy(paned_config->text_color, value);

    // Dimensions
    if (g_strcmp0(property, "width") == 0)
        paned_config->dimensions.width = atoi(value);
    if (g_strcmp0(property, "height") == 0)
        paned_config->dimensions.height = atoi(value);

    SET_VIEW_CONFIG_PROPERTY(property, value, view_config);

    return view_config;
}

ViewConfig *init_paned_config(FILE *index, PanedConfig *paned_config)
{
    return init_generic_config(index, (void *)paned_config, (ConfigurePropertyCallback)configure_paned_property);
}

GtkWidget *create_paned(PanedConfig paned_config)
{
    GtkWidget *paned = NULL;

    // Creation
    paned = gtk_paned_new(paned_config.orientation);

    // Enable or disable wide handle
    gtk_paned_set_wide_handle(GTK_PANED(paned), paned_config.is_wide);

    // Set paned position of the separator
    gtk_paned_set_position(GTK_PANED(paned), paned_config.position);

    // Set dimensions
    if (paned_config.dimensions.width > 0 || paned_config.dimensions.height)
        gtk_widget_set_size_request(paned, paned_config.dimensions.width, paned_config.dimensions.height);

    // Set colors
    widget_set_colors(paned, paned_config.bg_color, paned_config.text_color);

    // Set margins
    widget_set_margins(paned, paned_config.margins);

    // Set spacing
    // gtk_paned_set_spacing(GTK_PANED(paned), paned_config.spacing);
    // Set packing
    // gtk_paned_set_child_packing(GTK_PANED(paned), child_widget, is_expand, is_fill, padding, GTK_PACK_START)

    return paned;
}