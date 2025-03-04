#include "./../../include/widgets/text_area.h"

ViewConfig *configure_text_area_property(TextAreaConfig *text_area_config, ViewConfig *view_config, gchar *property, gchar *value)
{
    if (!text_area_config || !property || !value)
        return NULL;

    if (strcmp(property, "font_size") == 0)
    {
        text_area_config->font_size = atoi(value);
    }
    else if (strcmp(property, "text_color") == 0)
    {
        strncpy(text_area_config->text_color, value, MAX_COLOR_SIZE);
    }
    else if (strcmp(property, "background_color") == 0)
    {
        strncpy(text_area_config->bg_color, value, MAX_COLOR_SIZE);
    }
    else if (strcmp(property, "is_editable") == 0)
    {
        text_area_config->is_editable = (strcmp(value, "true") == 0) ? TRUE : FALSE;
    }
    else if (strcmp(property, "width") == 0)
    {
        text_area_config->dimensions.width = atoi(value);
    }
    else if (strcmp(property, "height") == 0)
    {
        text_area_config->dimensions.height = atoi(value);
    }
    else if (strcmp(property, "wrap_mode") == 0)
    {
        if (strcmp(value, "none") == 0)
            text_area_config->wrap_mode = GTK_WRAP_NONE;
        else if (strcmp(value, "char") == 0)
            text_area_config->wrap_mode = GTK_WRAP_CHAR;
        else if (strcmp(value, "word") == 0)
            text_area_config->wrap_mode = GTK_WRAP_WORD;
        else if (strcmp(value, "word-char") == 0)
            text_area_config->wrap_mode = GTK_WRAP_WORD_CHAR;
    }

    SET_VIEW_CONFIG_PROPERTY(property, value, view_config);

    return view_config;
}

ViewConfig *init_text_area_config(FILE *index, TextAreaConfig *text_area_config)
{
    return init_generic_config(index, (void *)text_area_config, (ConfigurePropertyCallback)configure_text_area_property);
}

GtkWidget *create_text_area(TextAreaConfig text_area)
{
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkWidget *text_view = gtk_text_view_new();

    /* Apply properties */
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), text_area.wrap_mode);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), text_area.is_editable);

    if (text_area.font_size > 0)
        widget_set_font_size(text_view, text_area.font_size);

    widget_set_colors(text_view, text_area.bg_color, text_area.text_color);

    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
    if(text_area.dimensions.width > 0 && text_area.dimensions.height > 0)
        set_widget_size(scrolled_window, text_area.dimensions);

    return scrolled_window;
}
