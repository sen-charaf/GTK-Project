#ifndef LABEL_H
#define LABEL_H

#include "./../global.h"

#define MAX_LABEL_TEXT_SIZE 1024
/* Default values for label configuration */


// Default Margins
#define DEFAULT_LABEL_MARGINS { \
    .top = 0,                  \
    .bottom = 0,               \
    .start = 0,                \
    .end = 0}

#define DEFAULT_LABEL                      \
    {                                      \
        .font_size = 10,                   \
        .label_text = "\0",                \
        .is_markup = FALSE,                \
        .is_underline = FALSE,             \
        .jtype = GTK_JUSTIFY_CENTER,       \
        .ellipsize = PANGO_ELLIPSIZE_NONE, \
        .margins = DEFAULT_LABEL_MARGINS,  \
        .is_wrap = FALSE,                  \
        .text_color = "\0",                \
        .bg_color = "\0",                  \
        .font_family = "\0",               \
        .xalign = 0.0,                     \
        .yalign = 0.0,                     \
        .is_selectable = FALSE}

typedef struct
{
    gint font_size;
    /* Text Content */
    gchar label_text[MAX_LABEL_TEXT_SIZE]; // Pointer for dynamic text allocation
    gboolean is_markup;                    // Parse and render Pango markup
    gboolean is_underline;                 // Mnemonic support for underline

    /* Appearance */
    GtkJustification jtype;                  // Text alignment (left, right, center)
    PangoEllipsizeMode ellipsize;            // Ellipsization mode
    Margins margins;                         // Margins
    gboolean is_wrap;                        // Enable word wrap
    gchar text_color[MAX_COLOR_SIZE];        // Text color
    gchar bg_color[MAX_COLOR_SIZE];          // Background color
    gchar font_family[MAX_FONT_FAMILY_SIZE]; // font family style

    gfloat xalign; // aligne text to display on line start
    gfloat yalign;

    /* Behavior */
    gboolean is_selectable; // Text can be copied by user

    /* Layout */
    gint padding; // Padding around the label
} LabelConfig;

ViewConfig *configure_label_property(LabelConfig *label_config, ViewConfig *view_config, gchar *property, gchar *value);

/**
 * @brief to initialize the label structure
 * @param[in] label_text the label content of the label
 * @return[ou] pointer to new label
 */
ViewConfig *init_label_config(FILE *index, LabelConfig *label_config);

// function to creat lable widget
GtkWidget *create_label(LabelConfig label);
#endif