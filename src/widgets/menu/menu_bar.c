#include "./../../../include/widgets/menu/menu_bar.h"

ViewConfig *configure_menu_bar_property(MenuBarConfig *menu_bar_config, ViewConfig *view_config, gchar *property, gchar *value)
{
    if (!menu_bar_config || !property || !value)
        return NULL;

    if (g_strcmp0(property, "pack_direction") == 0)
    {
        if (g_strcmp0(value, "LTR") == 0)
            menu_bar_config->pack_direction = GTK_PACK_DIRECTION_LTR;

        if (g_strcmp0(value, "RTL") == 0)
            menu_bar_config->pack_direction = GTK_PACK_DIRECTION_RTL;

        if (g_strcmp0(value, "TTB") == 0)
            menu_bar_config->pack_direction = GTK_PACK_DIRECTION_TTB;

        if (g_strcmp0(value, "BTT") == 0)
            menu_bar_config->pack_direction = GTK_PACK_DIRECTION_BTT;
    }

    if (g_strcmp0(property, "tooltip") == 0)
        strcpy(menu_bar_config->tooltip, value);

    // Margins
    if (g_strcmp0(property, "margin_top") == 0)
        menu_bar_config->margins.top = atoi(value);

    if (g_strcmp0(property, "margin_bottom") == 0)
        menu_bar_config->margins.bottom = atoi(value);

    if (g_strcmp0(property, "margin_left") == 0)
        menu_bar_config->margins.start = atoi(value);

    if (g_strcmp0(property, "margin_right") == 0)
        menu_bar_config->margins.end = atoi(value);

    // Dimensions
    if (g_strcmp0(property, "width") == 0)
        menu_bar_config->dimensions.width = atoi(value);

    if (g_strcmp0(property, "height") == 0)
        menu_bar_config->dimensions.height = atoi(value);

    // Colors
    if (g_strcmp0(property, "bg_color") == 0)
        strcpy(menu_bar_config->bg_color, value);

    if (g_strcmp0(property, "text_color") == 0)
        strcpy(menu_bar_config->text_color, value);

    SET_VIEW_CONFIG_PROPERTY(property, value, view_config);

    return view_config;
}

ViewConfig *init_menu_bar_config(FILE *index, MenuBarConfig *menu_bar_config)
{
    return init_generic_config(index, (void *)menu_bar_config, (ConfigurePropertyCallback)configure_menu_bar_property);
}

GtkWidget *create_menu_bar(MenuBarConfig menu_bar_config)
{
    GtkWidget *menu_bar = NULL;

    // Creation
    menu_bar = gtk_menu_bar_new();

    gtk_menu_bar_set_pack_direction(GTK_MENU_BAR(menu_bar), menu_bar_config.pack_direction);

    // Set the tooltip
    gtk_widget_set_tooltip_text(menu_bar, menu_bar_config.tooltip);

    // Set dimensions
    if (menu_bar_config.dimensions.width > 0 && menu_bar_config.dimensions.height > 0)
    {
        gtk_widget_set_size_request(menu_bar, menu_bar_config.dimensions.width, menu_bar_config.dimensions.height);
    }

    // Set colors
    widget_set_colors(menu_bar, menu_bar_config.bg_color, menu_bar_config.text_color);

    widget_set_margins(menu_bar, menu_bar_config.margins);

    return menu_bar;
}
