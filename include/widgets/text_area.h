#ifndef TEXT_AREA_H
#define TEXT_AREA_H

#include "./../global.h"

/* Default values */
#define DEFAULT_TEXT_AREA           \
    {                               \
        .font_size = 12,            \
        .text_color = "\0",         \
        .bg_color = "\0",           \
        .is_editable = TRUE,        \
        .wrap_mode = GTK_WRAP_WORD, \
        .dimensions.width = 0,    \
        .dimensions.height = 0}

typedef struct
{
    gint font_size;                   // Font size for text
    gchar text_color[MAX_COLOR_SIZE]; // Text color
    gchar bg_color[MAX_COLOR_SIZE];   // Background color
    gboolean is_editable;             // Editable state
    GtkWrapMode wrap_mode;            // Wrap mode for text

    // dimensions
    Dimensions dimensions;
} TextAreaConfig;

/**
 * @brief Configure text area properties
 * @param[in] text_area_config pointer to text area configuration
 * @param[in] view_config pointer to view configuration
 * @param[in] property property name to configure
 * @param[in] value property value to set
 * @return ViewConfig pointer
 */
ViewConfig *configure_text_area_property(TextAreaConfig *text_area_config, ViewConfig *view_config, gchar *property, gchar *value);

/**
 * @brief Initialize text area configuration
 * @param[in] index file pointer
 * @param[in] text_area_config text area configuration
 * @return ViewConfig pointer
 */
ViewConfig *init_text_area_config(FILE *index, TextAreaConfig *text_area_config);

/**
 * @brief Create text area widget with configuration
 * @param[in] text_area_config text area configuration structure
 * @return GtkWidget pointer to new text area widget
 */
GtkWidget *create_text_area(TextAreaConfig text_area);

#endif
